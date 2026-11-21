// Registry slot and free-index array growth reconstructed from GSQE78.
typedef unsigned long u32;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void fn_8028FD50(void*, void*, u32);
}

inline void* operator new(unsigned long, void* address) { return address; }

struct PoolSlot {
    void* object;
    u32 hash;
    short key, references;
    char generation, active;

    PoolSlot() {
        hash = 0;
        object = 0;
        references = 0;
        generation = 1;
        active = 0;
    }
    ~PoolSlot() {}
};

template<class T> struct PoolArray {
    int size, capacity;
    T* data;

    T& operator[](int index) {
        T* base = data;
        return base[index];
    }

    void storage(int count) {
        if (count) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data,
                                      capacity * sizeof(T), count * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, count * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }

    void resize(int count) {
        if (count > size) {
            storage(count);
            capacity = count;
            for (int i = size; i < count; ++i)
                new (data + i) T;
            size = count;
        } else if (count < size) {
            for (int i = size - 1; i >= count; --i)
                data[i].~T();
            storage(count);
            capacity = count;
            size = count;
        }
    }
};

struct HandlePool {
    PoolArray<PoolSlot> slots;
    PoolArray<int> free;
    int limit, freeCount;
    char autoDestroy;
};

extern "C" void fn_801F88AC(HandlePool* pool, int count) {
    int newSize = pool->limit + count;
    pool->slots.resize(newSize);
    pool->free.resize(newSize);
    pool->freeCount = count;
    pool->limit = newSize;
    for (long i = 0; i < count; ++i)
        pool->free[i] = --newSize;
}
