#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include <pthread.h>
#include <stdint.h>
#include <stddef.h>

#define SHM_NAME "/h264_nalu_shm"
#define MAX_NALU_SIZE 65536
#define BUFFER_COUNT 8

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    size_t size;
    uint8_t data[MAX_NALU_SIZE];
    int ready;
} NaluBuffer;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond_read;
    pthread_cond_t cond_write;
    NaluBuffer buffers[BUFFER_COUNT];
    int write_index;
    int read_index;
} SharedMemory;

// Shared memory interface
SharedMemory* shm_create_or_open(int create);
void shm_cleanup();

#ifdef __cplusplus
}
#endif

#endif
