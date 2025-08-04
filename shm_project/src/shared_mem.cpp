#include "shared_mem.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

static int shm_fd = -1;
static SharedMemory* shm_ptr = nullptr;

SharedMemory* shm_create_or_open(bool create) {
    int flags = create ? (O_CREAT | O_RDWR) : O_RDWR;
    shm_fd = shm_open(SHM_NAME, flags, 0666);
    if (shm_fd < 0) return nullptr;

    if (create)
        ftruncate(shm_fd, sizeof(SharedMemory));

    shm_ptr = static_cast<SharedMemory*>(mmap(nullptr, sizeof(SharedMemory),
                PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (shm_ptr == MAP_FAILED) return nullptr;

    if (create) {
        pthread_mutexattr_t mattr;
        pthread_condattr_t cattr;

        pthread_mutexattr_init(&mattr);
        pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(&shm_ptr->mutex, &mattr);

        pthread_condattr_init(&cattr);
        pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED);
        pthread_cond_init(&shm_ptr->cond_read, &cattr);
        pthread_cond_init(&shm_ptr->cond_write, &cattr);

        shm_ptr->write_index = shm_ptr->read_index = 0;
        for (int i = 0; i < BUFFER_COUNT; ++i)
            shm_ptr->buffers[i].ready = 0;
    }

    return shm_ptr;
}

void shm_cleanup(bool unlink_flag) {
    if (shm_ptr) {
        munmap(shm_ptr, sizeof(SharedMemory));
        shm_ptr = nullptr;
    }
    if (shm_fd != -1) {
        close(shm_fd);
        shm_fd = -1;
    }
    if (unlink_flag) {
        shm_unlink(SHM_NAME);
    }
}

bool write_nalu_to_shm(SharedMemory* shm, const uint8_t* data, size_t size) {
    pthread_mutex_lock(&shm->mutex);
    while (shm->buffers[shm->write_index].ready)
        pthread_cond_wait(&shm->cond_write, &shm->mutex);

    std::memcpy(shm->buffers[shm->write_index].data, data, size);
    shm->buffers[shm->write_index].size = size;
    shm->buffers[shm->write_index].ready = 1;

    shm->write_index = (shm->write_index + 1) % BUFFER_COUNT;

    pthread_cond_signal(&shm->cond_read);
    pthread_mutex_unlock(&shm->mutex);
    return true;
}

bool read_nalu_from_shm(SharedMemory* shm, uint8_t* out_buf, size_t* out_size) {
    pthread_mutex_lock(&shm->mutex);
    while (!shm->buffers[shm->read_index].ready)
        pthread_cond_wait(&shm->cond_read, &shm->mutex);

    *out_size = shm->buffers[shm->read_index].size;
    std::memcpy(out_buf, shm->buffers[shm->read_index].data, *out_size);
    shm->buffers[shm->read_index].ready = 0;
    shm->read_index = (shm->read_index + 1) % BUFFER_COUNT;

    pthread_cond_signal(&shm->cond_write);
    pthread_mutex_unlock(&shm->mutex);
    return true;
}

static bool is_start_code(const uint8_t* buf) {
    return (buf[0] == 0x00 && buf[1] == 0x00 &&
           ((buf[2] == 0x01) || (buf[2] == 0x00 && buf[3] == 0x01)));
}

bool extract_next_nalu(FILE* fp, uint8_t* out_buf, size_t* out_len) {
    static uint8_t buffer[MAX_NALU_SIZE + 4];
    size_t len = 0;
    bool start_found = false;

    while (!feof(fp)) {
        int byte = fgetc(fp);
        if (byte == EOF) break;
        buffer[len++] = static_cast<uint8_t>(byte);

        if (len >= 4 && is_start_code(&buffer[len - 4])) {
            if (start_found) {
                *out_len = len - 4;
                std::memcpy(out_buf, buffer, *out_len);
                fseek(fp, -4, SEEK_CUR);
                return true;
            } else {
                start_found = true;
                len = 0;
            }
        }
    }

    if (start_found && len > 0) {
        *out_len = len;
        std::memcpy(out_buf, buffer, len);
        return true;
    }

    return false;
}