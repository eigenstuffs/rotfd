#ifndef GAME_ENGINE_RESOURCE_OWNER_TEARDOWN_H
#define GAME_ENGINE_RESOURCE_OWNER_TEARDOWN_H

/* Partial layout used by the original C-entry destruction routine. */
typedef unsigned long ResourceOwnerTeardownWord;

extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[], lbl_802ED148[];
extern char __vt__17Resource_802E9E20[];
extern struct ResourceOwnerTeardownGlobals {
    char unknown00[0x14C];
    void* manager;
} lbl_801E9D24;
void* fn_801F7EB8(const void*);
void fn_80263524(void*, const void*);
void fn_8028FD50(void*, void*, int);
void fn_801EF610(void*, void*);
void* __dt__12BaseObject_ZFv(void*, short);
}

struct Handle_801F7F10 {
    ResourceOwnerTeardownWord word;
    ~Handle_801F7F10();
};
struct ResourceOwnerTeardownHandle1 : Handle_801F7F10 {
    ~ResourceOwnerTeardownHandle1() {}
};
struct ResourceOwnerTeardownHandle2 : ResourceOwnerTeardownHandle1 {
    ~ResourceOwnerTeardownHandle2() {}
};
struct ResourceOwnerTeardownHandle3 : ResourceOwnerTeardownHandle2 {
    ~ResourceOwnerTeardownHandle3() {}
};
struct ResourceOwnerTeardownHandle4 : ResourceOwnerTeardownHandle3 {
    ~ResourceOwnerTeardownHandle4() {}
};
struct ResourceOwnerTeardownHandle5 : ResourceOwnerTeardownHandle4 {
    ~ResourceOwnerTeardownHandle5() {}
};
struct ResourceOwnerTeardownElement4 {
    ResourceOwnerTeardownWord word;
    ~ResourceOwnerTeardownElement4() {}
};
struct ResourceOwnerTeardownElement16 {
    ResourceOwnerTeardownWord word[4];
    ~ResourceOwnerTeardownElement16() {}
};
struct ResourceOwnerTeardownElement20 {
    ResourceOwnerTeardownWord word[5];
    ~ResourceOwnerTeardownElement20() {}
};
struct ResourceOwnerTeardownElement40 {
    ResourceOwnerTeardownWord word[10];
    ~ResourceOwnerTeardownElement40() {}
};

template<class T> struct ResourceOwnerTeardownArray {
    int count, capacity;
    T* data;

    ~ResourceOwnerTeardownArray() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};

struct BitSet_80207EE8 {
    int count, capacity;
    ResourceOwnerTeardownWord* data;
    int bits;
    ~BitSet_80207EE8();

    const ResourceOwnerTeardownWord& word(int i) const {
        return data[i];
    }
    signed char test(int i) const {
        const ResourceOwnerTeardownWord& flags = word(i >> 5);
        return ((1UL << (i & 31)) & flags) ? 1 : 0;
    }
    void clear(int i) {
        data[i >> 5] &= ~(1UL << (i & 31));
    }
};

struct ResourceOwnerTeardownSparseRecords {
    int count, capacity;
    ResourceOwnerTeardownElement16* data;

    ~ResourceOwnerTeardownSparseRecords() {
        if (data) {
            if (data) {
                fn_8028FD50(lbl_8028F698, data,
                    capacity * sizeof(ResourceOwnerTeardownElement16));
                data = 0;
            }
            data = 0;
        }
    }
};

struct ResourceOwnerTeardownSparse : ResourceOwnerTeardownSparseRecords {
    BitSet_80207EE8 occupied;
    int limit, used;

    const ResourceOwnerTeardownWord& word(int i) const {
        ResourceOwnerTeardownWord* p = occupied.data;
        return p[i];
    }
    signed char test(int i) const {
        return (word(i >> 5) & (1UL << (i & 31))) ? 1 : 0;
    }
    ~ResourceOwnerTeardownSparse() {
        for (int i = 0; i < limit; ++i) {
            if (occupied.test(i)) {
                data[(unsigned int)i].~ResourceOwnerTeardownElement16();
                occupied.clear(i);
                --used;
            }
        }
    }
};

template<class T> struct ResourceOwnerTeardownFixed {
    char raw[32];
    int count;

    ~ResourceOwnerTeardownFixed() {
        for (int i = 0; i < count; ++i)
            ((T*)raw)[(unsigned int)i].~T();
    }
};

struct ResourceOwnerTeardownGroup {
    char unknown00[0x28];
    ResourceOwnerTeardownArray<ResourceOwnerTeardownElement4> indices;
    ResourceOwnerTeardownArray<ResourceOwnerTeardownElement20> records;
    char unknown40[0x4004];
    ~ResourceOwnerTeardownGroup() {}
};

struct ResourceOwnerTeardown {
    ResourceOwnerTeardownWord unknown00, identity;
    void* table;
    ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle2> array0C, array18, array24;
    ResourceOwnerTeardownHandle2 handle30;
    ResourceOwnerTeardownGroup group34, group4078, group80BC;
    ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle1> arrayC100;
    ResourceOwnerTeardownWord unknownC10C;
    ResourceOwnerTeardownFixed<ResourceOwnerTeardownHandle5> fixedC110;
    ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle3> arrayC134;
    ResourceOwnerTeardownFixed<ResourceOwnerTeardownHandle5> fixedC140;
    ResourceOwnerTeardownHandle2 handleC164, handleC168;
    ResourceOwnerTeardownWord unknownC16C;
    ResourceOwnerTeardownSparse sparseC170;
    char unknownC194[0xDA00 - 0xC194];
    ResourceOwnerTeardownArray<ResourceOwnerTeardownElement40> arrayDA00;
};

typedef char ResourceOwnerTeardownSizeCheck[
    sizeof(ResourceOwnerTeardown) == 0xDA0C ? 1 : -1];
extern "C" ResourceOwnerTeardown* fn_8026A710(ResourceOwnerTeardown*, short);

#endif
