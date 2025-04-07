#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stddef.h>

typedef struct MemoryPool {
    void* memory;
    size_t block_size;
    size_t total_blocks;
    size_t free_blocks;
    void** free_list;
} MemoryPool;

MemoryPool* create_pool(size_t block_size, size_t total_blocks);

void* allocate_block(MemoryPool* pool);

void free_block(MemoryPool* pool, void* block);

void destroy_pool(MemoryPool* pool);

#endif // MEMORY_POOL_H