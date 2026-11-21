/* Context root binding: resolve the named root handle, register the keyed
 * entry, scan the item handles for the key and link the keyed child handle. */
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
    char opaque00[0x118];
    Manager* manager;
} lbl_801E9D24;

extern "C" {
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
Word fn_801F7EB8(const Handle_801F7F10*);
Word fn_801F948C(void*, const char*);
extern const char lbl_8037B5D8[7];
extern const char lbl_8037B5E0[7];
}

struct Key {
    Word value;
    Key(const char* text) { value = fn_801F948C(this, text); }
};

struct ZeroHandle : Handle_801F7F10 {
    ZeroHandle() { word = 0; }
    ~ZeroHandle() {}
};
struct CopyHandle : ZeroHandle {
    CopyHandle(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~CopyHandle() {}
};
struct LocalHandle : ZeroHandle {
    LocalHandle(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~LocalHandle() {}
};
struct LinkHandle : ZeroHandle {
    LinkHandle() {}
    LinkHandle(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~LinkHandle() {}
    LinkHandle& operator=(const LinkHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};

inline Target* resolveItem(const Handle_801F7F10& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->generation0C == h.bits.tag) return e->object;
    return 0;
}
inline Target* resolve(const Handle_801F7F10& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    return e->generation0C == h.bits.tag ? e->object : 0;
}

struct Child {
    char opaque00[0xB8];
    LinkHandle handleB8;
};

struct Self {
    char opaque00[0xC];
    int count, capacity;
    LinkHandle* items;
    LinkHandle handle18;
    char opaque1C[0x24];
    char member40[0x240];
    LinkHandle handle280;
};

extern "C" {
CopyHandle fn_80263308(Self*, const Key*);
CopyHandle fn_802631B0(Self*, const Key*);
void fn_801E52EC(void*, const Handle_801F7F10*);
signed char fn_8026413C(Target*, const Key*);
}

inline void findEntry(Self* self, const Key& key) {
    int off;
    int i;
    for (i = 0, off = 0; i < self->count; ++i) {
        if (fn_8026413C(resolveItem(*(LinkHandle*)((char*)self->items + off)), &key)) break;
        off += 4;
    }
}
inline void selectEntries(Self* self) {
    LocalHandle current(fn_80263308(self, &Key(lbl_8037B5D8)));
    fn_801E52EC(self->member40, &current);
    findEntry(self, Key(lbl_8037B5D8));
}

/* The validity test keeps its result in a named signed char local inside an
 * inline helper; this places the returned value in r29 like the original. */
inline signed char isValidHandle(const Handle_801F7F10* h) {
    signed char valid = fn_801F7EB8(h) != 0;
    return valid;
}
extern "C" signed char fn_80262AFC(Self* self, const Name& name) {
    self->handle18 = LinkHandle(lbl_801E9D24.manager->find(name));
    selectEntries(self);
    LocalHandle child(fn_802631B0(self, &Key(lbl_8037B5E0)));
    if (fn_801F7EB8(&child))
        self->handle280 = ((Child*)resolve(child))->handleB8;
    return isValidHandle(&self->handle18);
}
