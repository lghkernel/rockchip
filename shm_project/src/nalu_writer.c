#include "shared_mem.h"
#include <stdio.h>
#include <string.h>

static int is_start_code(uint8_t* buf) {
    return (buf[0] == 0x00 && buf[1] == 0x00 &&
           ((buf[2] == 0x01) || (buf[2] == 0x00 && buf[3] == 0x01)));
}

// Đọc từng NALU từ file
int extract_next_nalu(FILE* fp, uint8_t* out_buf, size_t* out_len) {
    static uint8_t buffer[MAX_NALU_SIZE + 4];
    size_t len = 0;
    int start_found = 0;

    while (!feof(fp)) {
        int byte = fgetc(fp);
        if (byte == EOF) break;
        buffer[len++] = (uint8_t)byte;

        if (len >= 4 && is_start_code(&buffer[len - 4])) {
            if (start_found) {
                *out_len = len - 4;
                memcpy(out_buf, buffer, *out_len);
                fseek(fp, -4, SEEK_CUR);
                return 1;
            } else {
                start_found = 1;
                len = 0;
            }
        }
    }

    if (start_found && len > 0) {
        *out_len = len;
        memcpy(out_buf, buffer, len);
        return 1;
    }

    return 0;
}

// Ghi NALU vào shared memory
int write_nalu_to_shm(SharedMemory* shm, uint8_t* data, size_t size) {
    pthread_mutex_lock(&shm->mutex);
    while (shm->buffers[shm->write_index].ready)
        pthread_cond_wait(&shm->cond_write, &shm->mutex);

    memcpy(shm->buffers[shm->write_index].data, data, size);
    shm->buffers[shm->write_index].size = size;
    shm->buffers[shm->write_index].ready = 1;

    shm->write_index = (shm->write_index + 1) % BUFFER_COUNT;

    pthread_cond_signal(&shm->cond_read);
    pthread_mutex_unlock(&shm->mutex);

    return 0;
}
