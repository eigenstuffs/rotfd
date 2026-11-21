#ifndef GAME_SPATIAL_REGISTRY_DESTRUCTOR_H
#define GAME_SPATIAL_REGISTRY_DESTRUCTOR_H

typedef unsigned long Word;
extern "C" {
extern char lbl_802EC310[], lbl_801EF5C8[], lbl_8028F698[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
void fn_801F5CA4(void*, void*, const Word*);
void fn_8024D3AC(void*, short);
void fn_80243E90(void*, short);
}

struct KeyHandle {
    union {
        Word word;
        struct { signed int tag : 8, index : 24; } bits;
    };
    int getIndex() const { return bits.index; }
};
struct Entry {
    void* object;
    Word key;
    char unknown08[4];
    signed char tag;
    char unknown0D[3];
};
struct Manager {
    int count, capacity;
    Entry* entries;
    template<class T> T& field(int index, int offset) {
        return *(T*)((char*)entries + index * sizeof(Entry) + offset);
    }
    int valid(int index, signed char tag) {
        int valid = 0;
        if (index < count && tag == field<signed char>(index, 12)) valid = 1;
        return valid;
    }
    Word key(const KeyHandle& h) {
        signed char tag = h.bits.tag;
        int index = h.getIndex();
        if (valid(index, tag)) return field<Word>(index, 4);
        return 0;
    }
};
struct Context {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x28];
    void* first;
    char unknown148[0x10];
    void* second;
};
extern "C" Context lbl_801E9D24;
inline Word getKey(const KeyHandle& h) { return lbl_801E9D24.manager->key(h); }

struct Handle_801F7F10 { Word word; ~Handle_801F7F10(); };
struct SpatialRegistryHandle1 : Handle_801F7F10 { ~SpatialRegistryHandle1() {} };
struct SpatialRegistryHandle2 : SpatialRegistryHandle1 { ~SpatialRegistryHandle2() {} };
struct SpatialRegistryHandle3 : SpatialRegistryHandle2 { ~SpatialRegistryHandle3() {} };
struct EmptyRecord { Word words[2]; ~EmptyRecord() {} };
template<class T> struct RegistryArray {
    int count, capacity;
    T* data;
    ~RegistryArray() {
        if (data) {
            for (int i = 0; i < count; ++i) data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};
struct RegistryObject {
    Word unknown00;
    KeyHandle key;
    void* table;
    char unknown0C[0x68];
    char inner[12];
    RegistryArray<SpatialRegistryHandle3> handles;
    RegistryArray<EmptyRecord> records;
};
#endif
