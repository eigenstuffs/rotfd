#include "Game/engine_record_append.h"

extern "C" {
extern char lbl_8028F698[];
void *fn_8028FAF4(void *, void *, int, int);
void *fn_8028FF24(void *, int);
void fn_8028FD50(void *, void *, int);
}

static inline void resize(AppendArray *self, int capacity)
{
    if (capacity) {
        if (self->data)
            self->data = (AppendRecord *)fn_8028FAF4(lbl_8028F698, self->data,
                self->capacity * sizeof(AppendRecord), capacity * sizeof(AppendRecord));
        else
            self->data = (AppendRecord *)fn_8028FF24(lbl_8028F698,
                capacity * sizeof(AppendRecord));
    } else if (self->data) {
        fn_8028FD50(lbl_8028F698, self->data, self->capacity * sizeof(AppendRecord));
        self->data = 0;
    }
}

inline void *operator new(unsigned long, void *address) { return address; }

extern "C" int fn_80210014(AppendArray *self, const AppendRecord *value)
{
    if (self->count + 1 > self->capacity) {
        resize(self, self->capacity + 8);
        self->capacity += 8;
    }
    new (self->data + self->count++) AppendRecord(*value);
    return self->count - 1;
}
