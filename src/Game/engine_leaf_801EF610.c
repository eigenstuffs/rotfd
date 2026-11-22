struct Used {
    unsigned int size;
    struct Used *prev, *next;
};

struct Free {
    struct Used *anchor;
    unsigned int size;
    struct Free *prev, *next;
};

struct Heap {
    char pad[8];
    struct Free *head, *tail;
    char gap[0xc];
    unsigned int free_bytes, allocation_count;
    char gap2[4];
    unsigned int header_bytes;
};

void fn_801EF610(struct Heap *heap, void *pointer) {
    struct Free *previous;
    struct Free *next = heap->head;
    struct Free *block = (struct Free *)((char *)pointer - 12);
    unsigned int size = ((struct Used *)block)->size + 12;
    struct Used *after;
    struct Used *before = ((struct Used *)block)->prev;
    after = ((struct Used *)block)->next;

    while (next < block)
        next = next->next;
    previous = next->prev;
    before->next = after;
    after->prev = before;

    if (previous > (struct Free *)before && previous != heap->head) {
        previous->size += size;
        block = previous;
    } else {
        previous->next = block;
        next->prev = block;
        block->next = next;
        block->prev = previous;
        block->size = size;
        block->anchor = before;
    }

    if (next < (struct Free *)after && next != heap->tail) {
        next->next->prev = block;
        block->next = next->next;
        block->size += next->size;
    }
    --heap->allocation_count;
    heap->free_bytes += size;
    heap->header_bytes -= 12;
}
