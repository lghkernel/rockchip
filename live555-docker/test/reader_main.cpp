// reader.cpp
#include "shared_mem.hh"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

void print_nalu_hex(const uint8_t* buf, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%02X ", buf[i]); // In 2 chữ số hex, in hoa
        if ((i + 1) % 16 == 0) printf("\n"); // Xuống dòng mỗi 16 byte
    }
    printf("\n");
}

int main() {
    SharedMemory* shm = shm_create_or_open(/*create=*/0);
    if (!shm) {
        fprintf(stderr, "Failed to open shared memory\n");
        return 1;
    }

    uint8_t nalu_buf[MAX_NALU_SIZE];
    size_t nalu_size;
    uint8_t val = 2;
    while (true) {
        if (!read_nalu_from_shm(shm, nalu_buf, &nalu_size))
            continue;

        printf("Read NALU of size %zu bytes:\n", nalu_size);
        if (val) {
            print_nalu_hex(nalu_buf, nalu_size);
            val--;
        }
        usleep(1000);
    }

    shm_cleanup(true);
    return 0;
}
