#include <stdio.h>
#include "memory_pool.h"

int main() {
    MemoryPool* pool = create_pool(32, 10); // 10 блоков по 32 байта

    if (!pool) {
        printf("Failed to create memory pool!\n");
        return 1;
    }

    void* block1 = allocate_block(pool);
    void* block2 = allocate_block(pool);

    printf("Allocated block1 at %p\n", block1);
    printf("Allocated block2 at %p\n", block2);

    free_block(pool, block1);
    free_block(pool, block2);

    destroy_pool(pool);

    return 0;
}