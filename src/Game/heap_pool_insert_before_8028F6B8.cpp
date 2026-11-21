// Reserve a fixed-size pool slot (growing and rebasing the pool array when it
// is full) and link it in front of an existing pool.
typedef unsigned long Word;

struct Record {
    unsigned char* memory;
    unsigned char first;
    unsigned char freeCount;
    unsigned char unknown[2];
};

struct Pool {
    Pool* next;
    Pool* previous;
    Word size;
    unsigned char capacity;
    unsigned char unknown[3];
    Record* records;
    Word count;
    Record* current;
    Record* selected;

    inline void initialize(Word blockSize, Pool* before);
};

struct Heap {
    Pool* first;
    Pool* current;
    Pool* pools;
    Pool* array;
    Word capacity;
    Word count;
    Word unknown18;
    Word limit;
};

extern "C" {
extern char lbl_801EF5C8[];
extern char lbl_802AFB58[];
extern char lbl_802AFB68[];
void* fn_801EF83C(void*, void*, unsigned long, const char*, const char*,
    unsigned long);
}

inline void Pool::initialize(Word blockSize, Pool* before) {
    size = blockSize;
    records = 0;
    count = 0;
    current = 0;
    selected = 0;
    next = before;
    previous = before->previous;
    if (previous)
        previous->next = this;
    before->previous = this;
    Word n = 1024 / blockSize;
    if (n > 255)
        n = 255;
    else if (!n)
        n = blockSize << 3;
    capacity = n;
}

inline Word poolIndex(Pool* p, Pool* base) {
    return ((Word)p - (Word)base) / sizeof(Pool);
}

extern "C" Pool* fn_8028F6B8(Heap* self, Word size, Pool* before) {
    Pool* slot;
    if (self->count < self->capacity) {
        slot = self->array + self->count;
        ++self->count;
    } else {
        Pool* old = self->array;
        self->capacity += 8;
        self->array = (Pool*)fn_801EF83C(lbl_801EF5C8, self->array,
            self->capacity * sizeof(Pool), lbl_802AFB58, lbl_802AFB68, 0x238);
        slot = self->array + self->count;
        if (self->first)
            self->first = self->array + poolIndex(self->first, old);
        if (self->current)
            self->current = self->array + poolIndex(self->current, old);
        self->pools = self->array + poolIndex(self->pools, old);
        for (Word i = 0; i < self->count; ++i) {
            if (self->array[i].next)
                self->array[i].next = self->array + poolIndex(self->array[i].next, old);
            if (self->array[i].previous)
                self->array[i].previous = self->array + poolIndex(self->array[i].previous, old);
        }
        ++self->count;
        before = self->array + poolIndex(before, old);
    }
    if (slot)
        slot->initialize(size, before);
    return slot;
}
