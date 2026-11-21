#include "Game/engine_array_operations_more.h"

static inline void allocate144(ArrayOpsArray144 *self, int capacity)
{
    if (capacity) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items,
                self->capacity * sizeof(ArrayOpsItem144), capacity * sizeof(ArrayOpsItem144));
        else
            self->items = fn_8028FF24(lbl_8028F698, capacity * sizeof(ArrayOpsItem144));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(ArrayOpsItem144));
        self->items = 0;
    }
}

static inline void allocatePointer(ArrayOpsPointerArray *self, int capacity)
{
    if (capacity) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items,
                self->capacity * sizeof(ArrayOpsItem144 *), capacity * sizeof(ArrayOpsItem144 *));
        else
            self->items = fn_8028FF24(lbl_8028F698, capacity * sizeof(ArrayOpsItem144 *));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(ArrayOpsItem144 *));
        self->items = 0;
    }
}

static inline void copy(ArrayOpsItem144 *to, const ArrayOpsItem144 *from)
{
    to->blob = from->blob;
    to->value80 = from->value80;
    to->value84 = from->value84;
    to->value88 = from->value88;
    to->value8C = from->value8C;
}

static inline int append144(ArrayOpsArray144 *self, const ArrayOpsItem144 *source)
{
    ArrayOpsItem144 *out;
    if (self->count + 1 > self->capacity) {
        allocate144(self, self->capacity + 32);
        self->capacity += 32;
    }
    out = &self->items[self->count++];
    if (out)
        copy(out, source);
    return self->count - 1;
}

static inline int appendPointer(ArrayOpsPointerArray *self, ArrayOpsItem144 *source)
{
    ArrayOpsItem144 **out;
    if (self->count + 1 > self->capacity) {
        allocatePointer(self, self->capacity + 32);
        self->capacity += 32;
    }
    out = &self->items[self->count++];
    if (out)
        *out = source;
    return self->count - 1;
}

int fn_8021C558(ArrayOpsPairOwner *self, const ArrayOpsItem144 *source)
{
    int index = append144(&self->records, source);
    return appendPointer(&self->pointers, &self->records.items[index]);
}
