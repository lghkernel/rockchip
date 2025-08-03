#include <iostream>
#include "shared_mem.h"

extern bool read_nalu_from_shm(SharedMemory* shm, uint8_t* out_buf, size_t* out_len);

int main() {
    SharedMemory* shm = shm_create_or_open(0);
    if (!shm) return 1;

    uint8_t buffer[MAX_NALU_SIZE];
    size_t size;

    while (read_nalu_from_shm(shm, buffer, &size)) {
        std::cout << "[Reader] NALU size: " << size << " bytes\n";
    }

    shm_cleanup();
    return 0;
}
