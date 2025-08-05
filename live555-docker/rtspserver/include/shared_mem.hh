// shared_mem.hpp
#ifndef SHARED_MEM_HPP
#define SHARED_MEM_HPP

#include <cstdint>
#include <cstddef>
#include <pthread.h>
#include <cstdio>

#define SHM_NAME "/h264_nalu_shm"
constexpr size_t MAX_NALU_SIZE = 200000;
constexpr int BUFFER_COUNT = 8;

struct NaluBuffer {
    size_t size;
    uint8_t data[MAX_NALU_SIZE];
    int ready;
};

struct SharedMemory {
    pthread_mutex_t mutex;
    pthread_cond_t cond_read;
    pthread_cond_t cond_write;
    NaluBuffer buffers[BUFFER_COUNT];
    int write_index;
    int read_index;
};

SharedMemory* shm_create_or_open(bool create);
void shm_cleanup(bool unlink_flag = false);
bool write_nalu_to_shm(SharedMemory* shm, const uint8_t* data, size_t size);
bool read_nalu_from_shm(SharedMemory* shm, uint8_t* out_buf, size_t* out_size);
bool extract_next_nalu(FILE* fp, uint8_t* out_buf, size_t* out_len);

#endif // SHARED_MEM_HPP