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

static void node_swap(heap_node* a, heap_node* b) 
{
    heap_node temp = *a;
    *a = *b;
    *b = temp;
}

void __heap_shift_down(heap* h)
{
    assert(h->size > 0);

    size_t current_index = 0;

    while (1) {
        heap_node* current = node_at(h, current_index);

        size_t left_index = (current_index << 1) + 1;
        size_t right_index = left_index + 1;

        if (left_index < h->size) {
            heap_node* left = node_at(h, left_index);
            heap_node* child_with_less_cost = left;

            if (right_index < h->size) {
                heap_node* right = node_at(h, right_index);
                if (right->cost < left->cost) {
                    child_with_less_cost = right;
                }
            }

            if (child_with_less_cost->cost < current->cost) {
                node_swap(child_with_less_cost, current);
            }
            else {
                return;
            }
        }

        return; // Any node after current
    }
}

void __heap_shift_up(heap* h)
{
    assert(h->size > 0);

    size_t current_index = (h->size - 1);

    while (current_index > 0) {
        size_t parent_index = ((current_index - 1) >> 1);
        heap_node* current = node_at(h, current_index);
        heap_node* parent = node_at(h, parent_index);

        if (current->cost < parent->cost) {
            node_swap(parent, current);
            current_index = parent_index;
        }
        else {
            break;
        }
    }
}