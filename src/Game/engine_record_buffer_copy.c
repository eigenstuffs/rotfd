#include "Game/engine_record_buffers.h"

static inline void resizeItems(struct EngineRecordBufferItems* self, int amount)
{
    if (amount) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items, self->capacity * 24, amount * 24);
        else
            self->items = fn_8028FF24(lbl_8028F698, amount * 24);
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * 24);
        self->items = 0;
    }
}

static inline void copyItem(struct EngineRecordBufferItem* output, const struct EngineRecordBufferItem* source)
{
    struct EngineRecordBufferHandle* handle = &output->handle;
    output->key = source->key;
    __ct__15Handle_801F7F10Fv(handle);
    handle->value = 0;
    *handle = source->handle;
    fn_801F86C8(lbl_801E9D24.manager, &source->handle, 1);
    output->a = source->a;
    output->b = source->b;
    output->c = source->c;
    output->d = source->d;
}

static inline void appendItem(struct EngineRecordBufferItems* self, const struct EngineRecordBufferItem* row)
{
    struct EngineRecordBufferItem* output;
    if (self->count + 1 > self->capacity) {
        resizeItems(self, self->capacity + 32);
        self->capacity += 32;
    }
    output = &self->items[self->count++];
    if (output)
        copyItem(output, row);
}

struct EngineRecordBufferItems* fn_8024B5D8(struct EngineRecordBufferItems* self, const struct EngineRecordBufferItems* source)
{
    int i;
    fn_8024B744(self);
    fn_80025898(self, source->count);
    for (i = 0; i < source->count; i++)
        appendItem(self, &source->items[i]);
    return self;
}

extern void fn_80025954(struct EngineRecordBufferItems*, int, int);

void fn_8024B744(struct EngineRecordBufferItems* self)
{
    fn_80025954(self, 0, 1);
}
