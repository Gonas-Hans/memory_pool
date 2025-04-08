#include <stdio.h>
#include "memory_pool.h"

int main() {
    MemoryPool* pool = create_pool(32, 6); // 6 блоков по 32 байта

    if (!pool) {
        printf("Failed to create memory pool!\n");
        return 1;
    }

    printf("Total blocks: %zu\n", pool->total_blocks);

    // Аллоцируем блоки
    void* block0 = allocate_block(pool);
    void* block1 = allocate_block(pool);
    void* block2 = allocate_block(pool);
    void* block3 = allocate_block(pool);
    void* block4 = allocate_block(pool);
    void* block5 = allocate_block(pool);

    printf("Allocated blocks:\n");
    printf("block0 = %p\n", block0);
    printf("block1 = %p\n", block1);
    printf("block2 = %p\n", block2);
    printf("block3 = %p\n", block3);
    printf("block4 = %p\n", block4);
    printf("block5 = %p\n", block5);

    // Освобождаем block2 и block3
    free_block(pool, block2);
    free_block(pool, block3);

    printf("\nFreed block2 and block3!\n");

    // Снова аллоцируем два блока
    void* new_block_a = allocate_block(pool);
    void* new_block_b = allocate_block(pool);

    printf("\nAllocated again:\n");
    printf("new_block_a = %p\n", new_block_a);
    printf("new_block_b = %p\n", new_block_b);

    destroy_pool(pool);
    return 0;
}