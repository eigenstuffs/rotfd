/* Model record stream reader: base fields, a native Handle array, a raw
 * 8-byte pair array, then groups of keyed records that each own two 8-byte
 * pair arrays, and an optional two-registry binding keyed by the owner's
 * handle metadata.  Compiled with -O4,p -opt nocse (exceptions off). */
typedef unsigned long ModelRecordStreamWord;

struct Handle_801F7F10 {
    union {
        ModelRecordStreamWord value;
        struct { signed int tag:8, index:24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct ModelRecordInputStream { void* position; };

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, ModelRecordStreamWord, ModelRecordStreamWord);
void* fn_8028FF24(void*, ModelRecordStreamWord);
void fn_8028FD50(void*, void*, ModelRecordStreamWord);
void* fn_801E9F40(void*, const void*, int);
void fn_801F86C8(void*, const Handle_801F7F10*, int);
void fn_801B41B8(void*, ModelRecordStreamWord*, ModelRecordInputStream*);
}

inline void* operator new(unsigned long, void* p) { return p; }

struct ModelRecordStreamManager;
struct ModelRecordStreamGlobals {
    char unknown00[0x118];
    ModelRecordStreamManager* manager;
    char unknown11C[0x28];
    void* firstService;
    char unknown148[0x10];
    void* secondService;
};
extern "C" ModelRecordStreamGlobals lbl_801E9D24;

struct ModelRecordStreamZero : Handle_801F7F10 {
    ModelRecordStreamZero() { value = 0; }
    ~ModelRecordStreamZero() {}
};
struct ModelRecordStreamSecond : ModelRecordStreamZero {
    ModelRecordStreamSecond() { value = 0; }
    ~ModelRecordStreamSecond() {}
};
struct ModelRecordStreamValue : ModelRecordStreamSecond {
    ModelRecordStreamValue() { value = 0; }
    ~ModelRecordStreamValue() {}
    ModelRecordStreamValue& operator=(const ModelRecordStreamValue& other)
    {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = other.value;
        fn_801F86C8(lbl_801E9D24.manager, &other, 1);
        return *this;
    }
};

template <class T> struct ModelRecordStreamArray {
    int count, capacity;
    T* items;
    T& operator[](int i) { return items[i]; }
    void reserve(int n)
    {
        if (n) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items, capacity * sizeof(T), n * sizeof(T));
            else
                items = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
        capacity = n;
    }
    void resize(int n)
    {
        int i;
        if (n > count) {
            reserve(n);
            for (i = count; i < n; ++i)
                new (items + i) T;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; --i)
                items[i].~T();
            reserve(n);
            count = n;
        }
    }
};

struct ModelRecordStreamPair {
    char bytes[8];
    ModelRecordStreamPair() {}
    ~ModelRecordStreamPair() {}
};
struct ModelRecordStreamSub {
    unsigned short key;
    char unknown02[2];
    ModelRecordStreamArray<ModelRecordStreamPair> first, second;
};
struct ModelRecordStreamGroup {
    unsigned long key;
    ModelRecordStreamArray<ModelRecordStreamSub> records;
    ModelRecordStreamSub& operator[](int i) { return records[i]; }
};
struct ModelRecordStreamOwner {
    char unknown00[0x74];
    ModelRecordStreamArray<ModelRecordStreamGroup> groups;
    ModelRecordStreamArray<ModelRecordStreamValue> handles;
    ModelRecordStreamArray<ModelRecordStreamPair> pairs;
};

struct ModelRecordStreamEntry {
    void* object;
    void* metadata;
    char unknown08[4];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct ModelRecordStreamManager {
    int count, capacity;
    ModelRecordStreamEntry* entries;
    ModelRecordStreamEntry& operator[](int i) { return entries[i]; }
};
struct ModelRecordStreamIndex {
    const int value;
    ModelRecordStreamIndex(int v) : value(v) {}
    operator int() const { return value; }
};

inline void* metadata(ModelRecordStreamGlobals& g, const Handle_801F7F10& h)
{
    ModelRecordStreamManager* m = g.manager;
    signed char tag = h.bits.tag;
    const ModelRecordStreamIndex index(h.bits.index);
    int valid = 0;
    if (index < m->count && tag == m->entries[index].getTag())
        valid = 1;
    return valid ? (*m)[index].metadata : 0;
}

extern "C" {
void fn_80243E44(void*, ModelRecordInputStream*);
void fn_801D4A1C(ModelRecordStreamArray<ModelRecordStreamGroup>*, int, int);
void fn_801D4734(ModelRecordStreamArray<ModelRecordStreamSub>*, int, int);
void fn_801F67E4(void*, ModelRecordStreamOwner*, void**, ModelRecordInputStream*);
}

extern "C" void fn_801D3F04(ModelRecordStreamOwner* self, ModelRecordInputStream* stream)
{
    fn_80243E44(self, stream);
    int i;
    int count;
    stream->position = fn_801E9F40(&count, stream->position, 4);
    self->handles.resize(count);
    ModelRecordStreamGlobals& g = lbl_801E9D24;
    for (i = 0; i < self->handles.count; ++i)
        fn_801B41B8(g.manager, &self->handles[i].value, stream);
    stream->position = fn_801E9F40(&count, stream->position, 4);
    self->pairs.resize(count);
    stream->position = fn_801E9F40(self->pairs.items, stream->position, count * 8);
    stream->position = fn_801E9F40(&count, stream->position, 4);
    fn_801D4A1C(&self->groups, count, 0);
    for (i = 0; i < self->groups.count; ++i) {
        stream->position = fn_801E9F40(&self->groups[i].key, stream->position, 4);
        stream->position = fn_801E9F40(&count, stream->position, 4);
        fn_801D4734(&self->groups[i].records, count, 0);
        for (int j = 0; j < count; ++j) {
            stream->position = fn_801E9F40(&self->groups[i][j].key, stream->position, 2);
            int size;
            stream->position = fn_801E9F40(&size, stream->position, 4);
            self->groups[i][j].first.resize(size);
            stream->position = fn_801E9F40(self->groups[i][j].first.items, stream->position, size * 8);
            stream->position = fn_801E9F40(&size, stream->position, 4);
            self->groups[i][j].second.resize(size);
            stream->position = fn_801E9F40(self->groups[i][j].second.items, stream->position, size * 8);
        }
    }
    signed char active;
    stream->position = fn_801E9F40(&active, stream->position, 1);
    if (active) {
        void* meta = metadata(g, *(Handle_801F7F10*)((char*)self + 4));
        fn_801F67E4(lbl_801E9D24.firstService, self, &meta, stream);
        fn_801F67E4(lbl_801E9D24.secondService, self, &meta, stream);
    }
}
