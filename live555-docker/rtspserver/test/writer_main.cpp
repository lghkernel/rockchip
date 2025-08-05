#include "shared_mem.hh"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <h264_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    SharedMemory* shm = shm_create_or_open(1);
    if (!shm) {
        fprintf(stderr, "Failed to open shared memory\n");
        return 1;
    }

    uint8_t nalu_buf[MAX_NALU_SIZE];
    size_t nalu_size;

    while (extract_next_nalu(fp, nalu_buf, &nalu_size)) {
        write_nalu_to_shm(shm, nalu_buf, nalu_size);
        printf("Wrote NALU of size %zu bytes\n", nalu_size);
        usleep(5000); // Ghi chậm để dễ quan sát
    }

    printf("Writer finished.\n");
    shm_cleanup();
    return 0;
}
