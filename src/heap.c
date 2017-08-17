#include "include/heap.h"

heap* heap_create(size_t type_size)
{
    heap* h = (heap*) malloc(sizeof(heap));

    h->type_size = type_size;
    h->size = 0;
    h->vec = vector_create(2, sizeof(heap_node));

    return h;
}

void heap_destroy(heap* h)
{
    assert(h != NULL);

    vector_destroy(h->vec);
    free(h);
}

void heap_push(heap* h, int cost, void* item)
{
    assert(h != NULL && item != NULL);

    heap_node* node = malloc(sizeof(heap_node));
    node->cost = cost;
    node->data = (uint8_t*) malloc(h->type_size);
    memcpy(node->data, item, h->type_size);

    vector_push(h->vec, node);
    ++(h->size);

    if (h->size > 1) {
        __heap_shift_up(h);
    }
}

heap_node* heap_top(heap* h)
{
    assert(h != NULL);
    assert(h->size > 0);

    return vector_at(h->vec, 0);
}

void heap_pop(heap* h)
{
    assert(h != NULL);
    assert(h->size > 0);

    heap_node* first = vector_at(h->vec, 0);
    heap_node* last = vector_at(h->vec, h->vec->size - 1);

    free(first->data);

    memcpy(first, last, sizeof(heap_node));

    --(h->size);
    --(h->vec->size);

    if (h->size > 1) {
        __heap_shift_down(h);
    }
}

static heap_node* node_at(heap* h, size_t n) 
{
    if (n >= h->vec->size) {
        return NULL;
    }
    return vector_at(h->vec, n);
}

static inline size_t left_node(size_t n) 
{
    return (n << 1) + 1;
}

static inline size_t right_node(size_t n) 
{
    return (n << 1) + 2;
}   

static inline size_t parent_node(size_t n) 
{
    return ((n - 1) >> 1);
}

static void node_swap(heap_node* a, heap_node* b) 
{
    heap_node temp = *a;
    *a = *b;
    *b = temp;
}

void __heap_shift_down(heap* h)
{
    assert(h->size > 0);

    // Current node and cost
    size_t cnode = 0;

    while (1) {
        heap_node* current = node_at(h, cnode);
        heap_node* left = node_at(h, left_node(cnode));
        heap_node* right = node_at(h, right_node(cnode));

        bool left_is_small = (left != NULL && left->cost < current->cost);
        bool right_is_small = (right != NULL && right->cost < current->cost);

        if (left_is_small && right_is_small) {
            if (left->cost <= right->cost) {
                cnode = left_node(cnode);
                node_swap(left, current);
            }
            else {
                cnode = right_node(cnode);
                node_swap(right, current);
            }
        }
        else if (left_is_small) {
            cnode = left_node(cnode);
            node_swap(left, current);
        }
        else if (right_is_small) {
            cnode = right_node(cnode);
            node_swap(right, current);
        }
        else break;
    }
}

void __heap_shift_up(heap* h)
{
    assert(h->size > 0);

    // Current node and cost
    size_t cnode = (h->size - 1);

    while (cnode > 0) {
        heap_node* current = node_at(h, cnode);
        heap_node* parent = node_at(h, parent_node(cnode));

        if (current->cost < parent->cost) {
            cnode = parent_node(cnode);
            node_swap(parent, current);
        }
        else break;
    }
}