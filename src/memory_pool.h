//Copyright (c) 2025 Alexander Goncharov. All Rights Reserved.

#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stddef.h>

typedef struct MemoryPool {
    void* memory;           // Начало всего выделенного блока памяти
    void* free_list_head;   // Голова списка свободных блоков
    size_t block_size;      // Размер одного блока
    size_t total_blocks;    // Всего блоков
    size_t free_blocks;     // Сколько свободных
} MemoryPool;

MemoryPool* create_pool(size_t block_size, size_t total_blocks);

void* allocate_block(MemoryPool* pool);

void free_block(MemoryPool* pool, void* block);

void destroy_pool(MemoryPool* pool);

#endif // MEMORY_POOL_H