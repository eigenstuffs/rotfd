#include "Game/engine_record_buffers.h"

struct EngineRecordBufferRows* fn_8024B76C(struct EngineRecordBufferRows* self, const struct EngineRecordBufferRows* source)
{
    int i;
    fn_8024BC7C(self);
    fn_8024BBB8(self, source->count);
    for (i = 0; i < source->count; i++)
        fn_8024B7F4(self, &source->items[i]);
    return self;
}

static inline void resizeItems(struct EngineRecordBufferRows* self, int amount)
{
    if (amount) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items, self->capacity * 12, amount * 12);
        else
            self->items = fn_8028FF24(lbl_8028F698, amount * 12);
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * 12);
        self->items = 0;
    }
}

int fn_8024B7F4(struct EngineRecordBufferRows* self, const struct EngineRecordBufferWords* row)
{
    struct EngineRecordBufferWords* output;
    if (self->count + 1 > self->capacity) {
        resizeItems(self, self->capacity + 8);
        self->capacity += 8;
    }
    output = &self->items[self->count++];
    if (output)
        fn_8024B8E0(output, row);
    return self->count - 1;
}

static inline void resizeMemory(struct EngineRecordBufferWords* self, int capacity)
{
    if (capacity) {
        if (self->items)
            self->items = fn_8028FAF4(lbl_8028F698, self->items, self->capacity * 4, capacity * 4);
        else
            self->items = fn_8028FF24(lbl_8028F698, capacity * 4);
    } else if (self->items) {
        fn_8028FD50(lbl_8028F698, self->items, self->capacity * 4);
        self->items = 0;
    }
}

static inline void allocateWords(struct EngineRecordBufferWords* self, int capacity)
{
    resizeMemory(self, capacity);
    self->capacity = capacity;
}

static inline void resizeWords(struct EngineRecordBufferWords* self, int count)
{
    int i;
    if (count > self->count) {
        allocateWords(self, count);
        for (i = self->count; i < count; i++) {}
        self->count = count;
    } else if (count < self->count) {
        for (i = self->count - 1; i >= count; i--) {}
        allocateWords(self, count);
        self->count = count;
    }
}

static inline void reserveWords(struct EngineRecordBufferWords* self, int capacity)
{
    if (capacity < self->count)
        resizeWords(self, capacity);
    else
        allocateWords(self, capacity);
}

static inline void appendWord(struct EngineRecordBufferWords* self, const unsigned int* word)
{
    unsigned int* output;
    if (self->count + 1 > self->capacity) {
        resizeMemory(self, self->capacity + 8);
        self->capacity += 8;
    }
    output = &self->items[self->count++];
    if (output)
        *output = *word;
}

struct EngineRecordBufferWords* fn_8024B8E0(struct EngineRecordBufferWords* self, const struct EngineRecordBufferWords* source)
{
    int i;
    self->count = 0;
    self->capacity = 0;
    self->items = 0;
    reserveWords(self, source->count);
    for (i = 0; i < source->count; i++)
        appendWord(self, &source->items[i]);
    return self;
}

void fn_8024BBB8(struct EngineRecordBufferRows* self, int capacity)
{
    if (capacity < self->count) {
        fn_801D3088(self, capacity, 0);
    } else {
        if (capacity) {
            if (self->items)
                self->items = fn_8028FAF4(lbl_8028F698, self->items, self->capacity * 12, capacity * 12);
            else
                self->items = fn_8028FF24(lbl_8028F698, capacity * 12);
        } else if (self->items) {
            fn_8028FD50(lbl_8028F698, self->items, self->capacity * 12);
            self->items = 0;
        }
        self->capacity = capacity;
    }
}

void fn_8024BC7C(struct EngineRecordBufferRows* self)
{
    fn_801D3088(self, 0, 1);
}
