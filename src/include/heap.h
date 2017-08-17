#ifndef __heap_H__
#define __heap_H__

#include "ccommon.h"
#include "vector.h"

typedef struct {
    int cost;
    uint8_t* data;
} heap_node;

// Min-binary-heap
typedef struct {
    size_t type_size;
    size_t size;
    vector* vec;
} heap;

heap* heap_create(size_t type_size);
void heap_destroy(heap* s);
void heap_push(heap* s, int cost, void* item);
heap_node* heap_top(heap* s);
void heap_pop(heap* s);
void __heap_shift_down(heap* s);
void __heap_shift_up(heap* h);

#endif