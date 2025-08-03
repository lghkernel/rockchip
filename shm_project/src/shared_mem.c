#include "shared_mem.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

static int shm_fd = -1;
static SharedMemory* shm_ptr = NULL;

SharedMemory* shm_create_or_open(int create) {
    int flags = create ? (O_CREAT | O_RDWR) : O_RDWR;
    shm_fd = shm_open(SHM_NAME, flags, 0666);
    if (shm_fd < 0) return NULL;

    if (create)
        ftruncate(shm_fd, sizeof(SharedMemory));

    shm_ptr = (SharedMemory*) mmap(NULL, sizeof(SharedMemory),
                                   PROT_READ | PROT_WRITE,
                                   MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) return NULL;

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

        shm_ptr->write_index = 0;
        shm_ptr->read_index = 0;
        for (int i = 0; i < BUFFER_COUNT; i++)
            shm_ptr->buffers[i].ready = 0;
    }

    return shm_ptr;
}

void shm_cleanup() {
    if (shm_ptr) {
        munmap(shm_ptr, sizeof(SharedMemory));
        shm_ptr = NULL;
    }
    if (shm_fd != -1) {
        close(shm_fd);
        shm_fd = -1;
    }
}
