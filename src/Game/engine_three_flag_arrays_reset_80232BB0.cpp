/* Resizes three flag arrays to source array counts, then restores their defaults.
 * The source array elements are not inspected here; only their counts are known.
 */
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
}

inline void* operator new(unsigned long, void* storage) { return storage; }

struct ThreeFlags_80232BB0 {
    unsigned short first, second, third, extra;
    void reset() { first = second = third = 1; extra = 0; }
    ThreeFlags_80232BB0() { reset(); }
    ~ThreeFlags_80232BB0() {}
};

struct EightFlags_80232BB0 {
    unsigned short first, second, third, fourth, fifth, sixth, seventh, eighth;
    void reset() {
        first = second = third = fourth = fifth = sixth = seventh = eighth = 1;
    }
    EightFlags_80232BB0() { reset(); }
    ~EightFlags_80232BB0() {}
};

struct ScalarFlag_80232BB0 {
    unsigned short value;
    void reset() { value = 1; }
    ScalarFlag_80232BB0() { reset(); }
    ~ScalarFlag_80232BB0() {}
};

template<class T> struct FlagArray_80232BB0 {
    int count, capacity;
    T* data;

    void reserve(int size) {
        if (size) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data,
                    capacity * sizeof(T), size * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
        capacity = size;
    }

    void resize(int size) {
        if (size > count) {
            reserve(size);
            for (int i = count; i < size; ++i)
                new (&data[i]) T;
            count = size;
        } else if (size < count) {
            for (int i = count - 1; i >= size; --i)
                data[i].~T();
            reserve(size);
            count = size;
        }
    }
};

struct FlagArrays_80232BB0 {
    FlagArray_80232BB0<ThreeFlags_80232BB0> triples;
    FlagArray_80232BB0<EightFlags_80232BB0> eights;
    FlagArray_80232BB0<ScalarFlag_80232BB0> scalars;

    void reset() {
        int i, size;
        size = triples.count;
        for (i = 0; i < size; ++i)
            triples.data[i].reset();
        size = eights.count;
        for (i = 0; i < size; ++i)
            eights.data[i].reset();
        size = scalars.count;
        for (i = 0; i < size; ++i) {
            ScalarFlag_80232BB0& flag = scalars.data[i];
            flag.reset();
        }
    }
};

struct SourceArrayCount_80232BB0 {
    int count;
    unsigned char remaining[8];
};
struct SourceCounts_80232BB0 {
    unsigned char prefix[12];
    SourceArrayCount_80232BB0 triples, eights, scalars;
};
typedef char ThreeFlagsSize_80232BB0[sizeof(ThreeFlags_80232BB0) == 8 ? 1 : -1];
typedef char EightFlagsSize_80232BB0[sizeof(EightFlags_80232BB0) == 16 ? 1 : -1];
typedef char ScalarFlagSize_80232BB0[sizeof(ScalarFlag_80232BB0) == 2 ? 1 : -1];
typedef char FlagArraysSize_80232BB0[sizeof(FlagArrays_80232BB0) == 36 ? 1 : -1];

extern "C" void fn_80232BB0(FlagArrays_80232BB0* self, SourceCounts_80232BB0* source) {
    self->triples.resize(source->triples.count);
    self->eights.resize(source->eights.count);
    self->scalars.resize(source->scalars.count);
    self->reset();
}
