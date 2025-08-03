#include "shared_mem.h"
#include <cstring>
#include <iostream>

// Đọc NALU từ shared memory
bool read_nalu_from_shm(SharedMemory* shm, uint8_t* out_buf, size_t* out_size) {
    pthread_mutex_lock(&shm->mutex);
    while (!shm->buffers[shm->read_index].ready)
        pthread_cond_wait(&shm->cond_read, &shm->mutex);

    *out_size = shm->buffers[shm->read_index].size;
    memcpy(out_buf, shm->buffers[shm->read_index].data, *out_size);

    shm->buffers[shm->read_index].ready = 0;
    shm->read_index = (shm->read_index + 1) % BUFFER_COUNT;

    pthread_cond_signal(&shm->cond_write);
    pthread_mutex_unlock(&shm->mutex);

    return true;
}

