#include "Game/engine_array_operations_more.h"

static inline void construct2(short *p)
{
    if (p)
        *p = 1;
}

static inline void construct8(ArrayOpsItem8 *p)
{
    if (p) {
        p->c = 1;
        p->b = 1;
        p->a = 1;
        p->d = 0;
    }
}

static inline void construct16(ArrayOpsItem16 *p)
{
    if (p) {
        p->h = 1;
        p->g = 1;
        p->f = 1;
        p->e = 1;
        p->d = 1;
        p->c = 1;
        p->b = 1;
        p->a = 1;
    }
}

static inline void allocate2(ArrayOpsArray2 *self, int count)
{
    if (count) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items,
                self->capacity * sizeof(short), count * sizeof(short));
        else
            self->items = fn_8028FF24(lbl_8028F698, count * sizeof(short));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(short));
        self->items = 0;
    }
}

static inline void resize2(ArrayOpsArray2 *self, int count)
{
    int i;
    if (count > self->count) {
        allocate2(self, count);
        self->capacity = count;
        for (i = self->count; i < count; i++)
            construct2(&self->items[i]);
        self->count = count;
    } else if (count < self->count) {
        for (i = self->count - 1; i >= count; i--) {}
        allocate2(self, count);
        self->capacity = count;
        self->count = count;
    }
}

static inline void allocate8(ArrayOpsArray8 *self, int count)
{
    if (count) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items,
                self->capacity * sizeof(ArrayOpsItem8), count * sizeof(ArrayOpsItem8));
        else
            self->items = fn_8028FF24(lbl_8028F698, count * sizeof(ArrayOpsItem8));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(ArrayOpsItem8));
        self->items = 0;
    }
}

static inline void resize8(ArrayOpsArray8 *self, int count)
{
    int i;
    if (count > self->count) {
        allocate8(self, count);
        self->capacity = count;
        for (i = self->count; i < count; i++)
            construct8(&self->items[i]);
        self->count = count;
    } else if (count < self->count) {
        for (i = self->count - 1; i >= count; i--) {}
        allocate8(self, count);
        self->capacity = count;
        self->count = count;
    }
}

static inline void allocate16(ArrayOpsArray16 *self, int count)
{
    if (count) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items,
                self->capacity * sizeof(ArrayOpsItem16), count * sizeof(ArrayOpsItem16));
        else
            self->items = fn_8028FF24(lbl_8028F698, count * sizeof(ArrayOpsItem16));
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * sizeof(ArrayOpsItem16));
        self->items = 0;
    }
}

static inline void resize16(ArrayOpsArray16 *self, int count)
{
    int i;
    if (count > self->count) {
        allocate16(self, count);
        self->capacity = count;
        for (i = self->count; i < count; i++)
            construct16(&self->items[i]);
        self->count = count;
    } else if (count < self->count) {
        for (i = self->count - 1; i >= count; i--) {}
        allocate16(self, count);
        self->capacity = count;
        self->count = count;
    }
}

ArrayOpsTripleOwner *fn_802358E8(ArrayOpsTripleOwner *self)
{
    self->first.count = 0;
    self->first.capacity = 0;
    self->first.items = 0;
    self->second.count = 0;
    self->second.capacity = 0;
    self->second.items = 0;
    self->third.count = 0;
    self->third.capacity = 0;
    self->third.items = 0;
    resize2(&self->third, 0);
    resize16(&self->second, 0);
    resize8(&self->first, 0);
    return self;
}
