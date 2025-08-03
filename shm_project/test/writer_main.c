#include <stdio.h>
#include "shared_mem.h"

extern int extract_next_nalu(FILE* fp, uint8_t* out_buf, size_t* out_len);
extern int write_nalu_to_shm(SharedMemory* shm, uint8_t* data, size_t size);

int main() {
    SharedMemory* shm = shm_create_or_open(1);
    FILE* fp = fopen("input.264", "rb");

    if (!fp || !shm) return 1;

    uint8_t buffer[MAX_NALU_SIZE];
    size_t size;
    while (extract_next_nalu(fp, buffer, &size)) {
        write_nalu_to_shm(shm, buffer, size);
    }

    fclose(fp);
    shm_cleanup();
    return 0;
}
