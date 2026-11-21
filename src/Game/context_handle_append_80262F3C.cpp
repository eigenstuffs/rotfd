/* Append a named resource handle to the context list unless already present. */
typedef unsigned long Word;

struct Handle_801F7F10 {
    union { Word word; struct { signed int tag:8, index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Target;
struct Entry {
    Target* object;
    Word opaque04, opaque08;
    signed char generation0C;
    char opaque0D[3];
};
struct Name;
struct ManagerPrefix {
    Word count, capacity;
    Entry* entries;
    char opaque0C[0x18];
};
struct Manager : ManagerPrefix {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual Handle_801F7F10 find(const Name&);
};
extern "C" struct Global {
    char opaque00[0x110];
    void* logger;
    char opaque114[4];
    Manager* manager;
} lbl_801E9D24;

extern "C" {
extern char lbl_8028F698[];
extern const char lbl_802AEF84[];
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
Word fn_801F7EB8(const Handle_801F7F10*);
void fn_801F9D68(void*, const char*, ...);
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
}

inline void* operator new(unsigned long, void* p) { return p; }

struct ZeroHandle : Handle_801F7F10 {
    ZeroHandle() { word = 0; }
    ~ZeroHandle() {}
};
struct LocalHandle : ZeroHandle {
    LocalHandle(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~LocalHandle() {}
};

inline Target* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    signed char htag = h.bits.tag;
    signed char tag = m->entries[index].generation0C;
    if (tag == htag) return m->entries[index].object;
    return 0;
}

struct Self {
    char opaque00[0xC];
    int count, capacity;
    LocalHandle* items;
    void grow(int size) {
        if (size) {
            if (items)
                items = (LocalHandle*)fn_8028FAF4(lbl_8028F698, items, capacity * sizeof(LocalHandle), size * sizeof(LocalHandle));
            else
                items = (LocalHandle*)fn_8028FF24(lbl_8028F698, size * sizeof(LocalHandle));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(LocalHandle));
            items = 0;
        }
    }
    void append(const Handle_801F7F10& h) {
        if (count + 1 > capacity) {
            grow(capacity + 32);
            capacity += 32;
        }
        new (&items[count++]) LocalHandle(h);
    }
};

extern "C" int fn_80262F3C(Self* self, const Name& name) {
    LocalHandle handle(lbl_801E9D24.manager->find(name));
    if (!fn_801F7EB8(&handle)) return 0;
    for (int i = 0; i < self->count; ++i) {
        if (resolve(self->items[i]) == resolve(handle)) {
            fn_801F9D68(lbl_801E9D24.logger, lbl_802AEF84, &name);
            return 1;
        }
    }
    self->append(handle);
    return 1;
}
