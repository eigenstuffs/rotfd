#include "Game/engine_heap_pool_allocate.h"

extern "C" {
extern char lbl_801EF5C8[];
extern char lbl_802AFB58[];
extern char lbl_802AFB68[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*,
    unsigned long, unsigned long);
void* fn_801EF83C(void*, void*, unsigned long, const char*, const char*,
    unsigned long);
EngineHeapPoolAllocate::Pool* fn_8028F6B8(EngineHeapPoolAllocate::Heap*,
    unsigned long, EngineHeapPoolAllocate::Pool*);
}

namespace EngineHeapPoolAllocate {

inline void Record::initialize(Word size, unsigned char capacity) {
    memory = (unsigned char*)fn_801EFA1C(lbl_801EF5C8, size * capacity,
        lbl_802AFB58, lbl_802AFB68, 0x13, 32);
    first = 0;
    freeCount = capacity;
    unsigned char i = 0;
    unsigned char* p = memory;
    while (i != capacity) {
        *p = ++i;
        p += size;
    }
}

inline void* Record::acquire(Word size) {
    if (!freeCount)
        return 0;
    unsigned char* p = memory + first * size;
    first = *p;
    --freeCount;
    return p;
}

inline void Pool::initialize(Word blockSize) {
    size = blockSize;
    records = 0;
    count = 0;
    current = 0;
    selected = 0;
    next = 0;
    previous = 0;
    Word n = 1024 / blockSize;
    if (n > 255)
        n = 255;
    else if (!n)
        n = blockSize << 3;
    capacity = n;
}

inline void* Pool::acquire() {
    if (!current || !current->freeCount) {
        Word i;
        for (i = 0; i < count; ++i) {
            if (records[i].freeCount) {
                current = &records[i];
                break;
            }
        }
        if (i == count) {
            if (records)
                records = (Record*)fn_801EF83C(lbl_801EF5C8, records,
                    (count + 1) * sizeof(Record), lbl_802AFB58,
                    lbl_802AFB68, 0xE9);
            else
                records = (Record*)fn_801EFA1C(lbl_801EF5C8,
                    (count + 1) * sizeof(Record), lbl_802AFB58,
                    lbl_802AFB68, 0xED, 32);
            records[count].initialize(size, capacity);
            current = &records[count];
            selected = records;
            ++count;
        }
    }
    return current->acquire(size);
}

inline Word poolIndex(Pool* p, Pool* base) {
    return ((Word)p - (Word)base) / sizeof(Pool);
}

inline Pool* Heap::reserve() {
    Pool* slot;
    Pool* old = array;
    if (!old) {
        array = (Pool*)fn_801EFA1C(lbl_801EF5C8, 1024, lbl_802AFB58,
            lbl_802AFB68, 0x25D, 32);
        slot = array;
        capacity = 32;
        count = 1;
    } else if (count < capacity) {
        slot = array + count;
        ++count;
    } else {
        capacity += 8;
        array = (Pool*)fn_801EF83C(lbl_801EF5C8, array,
            capacity * sizeof(Pool), lbl_802AFB58, lbl_802AFB68, 0x288);
        slot = array + count;
        if (first)
            first = array + poolIndex(first, old);
        if (current)
            current = array + poolIndex(current, old);
        pools = array + poolIndex(pools, old);
        for (Word i = 0; i < count; ++i) {
            if (array[i].next)
                array[i].next = array + poolIndex(array[i].next, old);
            if (array[i].previous)
                array[i].previous = array + poolIndex(array[i].previous, old);
        }
        ++count;
    }
    return slot;
}

}

using namespace EngineHeapPoolAllocate;

extern "C" void* fn_8028FF24(Heap* self, Word size) {
    if (size > self->limit)
        return fn_801EFA1C(lbl_801EF5C8, size, lbl_802AFB58,
            lbl_802AFB68, 0x18E, 32);
    {
        Pool* cached = self->first;
        if (cached && size == cached->size)
            return cached->acquire();
    }
    Pool* pool;
    if (!self->pools) {
        Pool* pool = self->reserve();
        if (pool)
            pool->initialize(size);
        self->pools = pool;
        self->first = self->pools;
        return self->first->acquire();
    }
    pool = self->pools;
    self->first = 0;
    while (pool && pool->size < size) {
        self->first = pool;
        pool = pool->next;
    }
    if (!pool) {
        Pool* slot = self->reserve();
        if (slot)
            slot->initialize(size);
        pool = slot;
        pool->previous = self->first;
        if (self->first)
            self->first->next = pool;
    } else if (size != pool->size) {
        if (self->pools != pool)
            pool = fn_8028F6B8(self, size, pool);
        else {
            pool = fn_8028F6B8(self, size, pool);
            self->pools = pool;
        }
    }
    return pool->acquire();
}
