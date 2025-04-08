#include "memory_pool.h"
#include <stdlib.h>
#include <string.h>

MemoryPool* create_pool(size_t block_size, size_t total_blocks) {
    MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
    if (!pool) return NULL;

    pool->block_size = (block_size < sizeof(void*)) ? sizeof(void*) : block_size;
    pool->total_blocks = total_blocks;
    pool->free_blocks = total_blocks;

    pool->memory = malloc(pool->block_size * total_blocks);
    if (!pool->memory) {
        free(pool);
        return NULL;
    }

    // Ставим голову списка на начало всей памяти
    pool->free_list_head = pool->memory;

    // Строим односвязный список внутри самой памяти
    char* current = (char*)pool->memory;
    for (size_t i = 0; i < total_blocks - 1; ++i) 
    {
        *((void**)current) = (void*)(current + pool->block_size);
        current += pool->block_size;
    }
    *((void**)current) = NULL; // Последний блок указывает на NULL

    return pool;
}

void* allocate_block(MemoryPool* pool) {
    if (!pool->free_list_head) {
        return NULL; // Нет свободных блоков
    }

    void* block = pool->free_list_head;
    pool->free_list_head = *((void**)block);
    pool->free_blocks--;

    return block;
}

void free_block(MemoryPool* pool, void* block) {
    *((void**)block) = pool->free_list_head;
    pool->free_list_head = block;
    pool->free_blocks++;
}

void destroy_pool(MemoryPool* pool) {
    free(pool->memory);
    free(pool);
}