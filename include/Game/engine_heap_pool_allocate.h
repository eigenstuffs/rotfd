#ifndef GAME_ENGINE_HEAP_POOL_ALLOCATE_H
#define GAME_ENGINE_HEAP_POOL_ALLOCATE_H

namespace EngineHeapPoolAllocate {

typedef unsigned long Word;

struct Record {
    unsigned char* memory;
    unsigned char first;
    unsigned char freeCount;
    unsigned char unknown[2];

    void initialize(Word size, unsigned char capacity);
    void* acquire(Word size);
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

    void initialize(Word blockSize);
    void* acquire();
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

    Pool* reserve();
};

typedef char RecordSize[(sizeof(Record) == 8) ? 1 : -1];
typedef char PoolSize[(sizeof(Pool) == 32) ? 1 : -1];
typedef char HeapSize[(sizeof(Heap) == 32) ? 1 : -1];

}

extern "C" void* fn_8028FF24(EngineHeapPoolAllocate::Heap* self,
    EngineHeapPoolAllocate::Word size);

#endif
