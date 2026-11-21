#include "Game/engine_group_record_append.h"

extern "C" {
extern char lbl_8028F698[];
void *fn_8028FAF4(void *, void *, int, int);
void *fn_8028FF24(void *, int);
void fn_8028FD50(void *, void *, int);
}

template<class T> static inline void resize(GroupAppendArray<T> *self, int capacity)
{
    if (capacity) {
        if (self->data)
            self->data = (T *)fn_8028FAF4(lbl_8028F698, self->data,
                self->capacity * sizeof(T), capacity * sizeof(T));
        else
            self->data = (T *)fn_8028FF24(lbl_8028F698, capacity * sizeof(T));
    } else if (self->data) {
        fn_8028FD50(lbl_8028F698, self->data, self->capacity * sizeof(T));
        self->data = 0;
    }
}

inline void *operator new(unsigned long, void *address) { return address; }

template<class T> static inline int append(GroupAppendArray<T> *self,
    const T &value, int growth)
{
    if (self->count + 1 > self->capacity) {
        resize(self, self->capacity + growth);
        self->capacity += growth;
    }
    new (self->data + self->count++) T(value);
    return self->count - 1;
}

extern "C" int fn_8021AFE0(GroupAppendOwner *self, const GroupAppendRecord *value)
{
    int index = append(&self->records, *value, 24);
    return append(&self->pointers, self->records.data + index, 32);
}
