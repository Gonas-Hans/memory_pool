#include "memory_pool.h"
#include <stdlib.h>
#include <string.h>

MemoryPool* create_pool(size_t block_size, size_t total_blocks) {
    MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
    if (!pool) return NULL;

    pool->memory = malloc(block_size * total_blocks);
    if (!pool->memory) {
        free(pool);
        return NULL;
    }

    pool->block_size = block_size;
    pool->total_blocks = total_blocks;
    pool->free_blocks = total_blocks;

    pool->free_list = (void**)malloc(sizeof(void*) * total_blocks);
    if (!pool->free_list) {
        free(pool->memory);
        free(pool);
        return NULL;
    }

    for (size_t i = 0; i < total_blocks; ++i) {
        pool->free_list[i] = (char*)pool->memory + i * block_size;
    }

    return pool;
}

void* allocate_block(MemoryPool* pool) {
    if (pool->free_blocks == 0) {
        return NULL;
    }
    return pool->free_list[--pool->free_blocks];
}

void free_block(MemoryPool* pool, void* block) {
    pool->free_list[pool->free_blocks++] = block;
}

void destroy_pool(MemoryPool* pool) {
    free(pool->free_list);
    free(pool->memory);
    free(pool);
}