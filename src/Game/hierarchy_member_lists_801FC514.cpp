// Hierarchy membership lists (0x801FC514..0x801FD3EC): remove, add,
// unique-append, erase and create. Private layout views; offsets verified
// against GSQE78. Same flags as Game/hierarchy_apply.cpp; -inline deferred
// emits functions in reverse source order, so they are written last-to-first.
// Matching notes: comparisons go through sameObject() (left resolve first,
// right array base loaded early); the member-list self handle copy in
// fn_801FC514 must come from the context() accessor (keeps the r30 address);
// fn_801FCF20's lookup argument needs the getTag() resolve form and the
// group134 compare needs the uncached-entries resolveRelated() form.
typedef unsigned long u32;
struct Handle_801F7F10 {
    union { u32 word; struct { signed int tag : 8; signed int index : 24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Node;
struct Entry {
    Node* object; u32 unknown04[2]; signed char tag; char unknown0D[3];
    bool matchesGeneration(signed char generation) const { return tag == generation; }
    signed char getTag() const { return tag; }
};
struct Manager { u32 unknown00[2]; Entry* entries; };
struct RelatedManagerView { u32 unknown00[2]; Entry* entries; };
struct Key { u32 word; };
extern "C" struct Globals {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x14C - 0x11C];
    void* factory;
} lbl_801E9D24;
extern "C" {
extern char lbl_8028F698[];
void* memcpy(void*, const void*, unsigned long);
void fn_801F86C8(Manager*, const Handle_801F7F10*, short);
u32 fn_801F7EB8(const Handle_801F7F10*);
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void fn_8028FD50(void*, void*, u32);
}
inline void* operator new(unsigned long, void* p) { return p; }

template<int N> struct Zero : Zero<N - 1> {
    Zero() { this->word = 0; }
    ~Zero() {}
};
template<> struct Zero<1> : Handle_801F7F10 {
    Zero() { word = 0; }
    ~Zero() {}
};
struct Zero0 : Handle_801F7F10 {
    Zero0(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
template<int N> struct Owned : Zero<N> {
    Owned() {}
    Owned(const Handle_801F7F10& h) {
        this->word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    Owned(const Owned& h) {
        this->word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    Owned& operator=(const Handle_801F7F10& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        this->word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct Handle_80020478 : Handle_801F7F10 { Handle_80020478() { word = 0; } ~Handle_80020478() {} };
struct Handle_80020834 : Handle_80020478 {
    Handle_80020834() { word = 0; }
    Handle_80020834(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~Handle_80020834() {}
};
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} };
struct Handle_80020B90 : Handle_8001FF78 { Handle_80020B90() { word = 0; } ~Handle_80020B90() {} };

template<class T, int Grow> struct List {
    int count, capacity;
    T* data;
    void storage(int size) {
        if (size) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data, capacity * 4, size * 4);
            else
                data = (T*)fn_8028FF24(lbl_8028F698, size * 4);
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * 4);
            data = 0;
        }
    }
    void append(const Handle_801F7F10& h) {
        if (count + 1 > capacity) {
            storage(capacity + Grow);
            capacity += Grow;
        }
        new (&data[count++]) T(h);
    }
    void removeAt(int i) {
        data[i].~T();
        T* destination = &data[i];
        int n = --count;
        memcpy(destination, destination + 1, (n - i) * sizeof(T));
    }
};

struct NodePrefix { u32 unknown00[2]; };
struct Node : NodePrefix {
    virtual void slot008();
    virtual void slot00C();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01C();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02C();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03C();
    virtual void attach(const Handle_801F7F10&);
    virtual void detach(const Handle_801F7F10&);
    char unknown0C[0x30 - 0x0C];
    Handle_801F7F10 parent30;
    char unknown34[0x58 - 0x34];
    Handle_801F7F10 owner58;
    char unknown5C[0x134 - 0x5C];
    int group134;
};

struct Hierarchy {
    u32 unknown00;
    Handle_801F7F10 context04;
    u32 unknown08;
    Handle_801F7F10 owner0C;
    char unknown10[0x90 - 0x10];
    List<Owned<2>, 8> members90;
    char unknown9C[0xA8 - 0x9C];
    List<Owned<7>, 0> slotsA8;
    char unknownB4[0xC4 - 0xB4];
    List<Owned<1>, 100> childrenC4;
    List<Owned<4>, 0> slotsD0;
    char unknownDC[0xE8 - 0xDC];
    signed char quietE8;
    const Handle_801F7F10& context() const { return context04; }
};

static inline Node* resolve(const Handle_801F7F10& h) {
    Entry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->tag == h.bits.tag ? e->object : 0;
}
struct HandleIndex {
    int value;
    HandleIndex(int v) : value(v) {}
    operator int() const { return value; }
};
static inline Node* resolveUnique(const Handle_801F7F10& handle) {
    Manager* manager = lbl_801E9D24.manager;
    const HandleIndex index(handle.bits.index);
    signed char generation = handle.bits.tag;
    if (manager->entries[index].matchesGeneration(generation))
        return manager->entries[index].object;
    return 0;
}
static inline bool sameObject(const Handle_801F7F10& a, const Handle_801F7F10& b) {
    Node* x = resolveUnique(a);
    return x == resolveUnique(b);
}
static inline Node* resolveMenu(const Handle_801F7F10& h) {
    int i = h.bits.index; Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[i].getTag();
    if (tag == h.bits.tag) return m->entries[i].object;
    return 0;
}
static inline Node* resolveRelated(const Handle_801F7F10& h) {
    Entry* e = ((RelatedManagerView*)lbl_801E9D24.manager)->entries + h.bits.index;
    return e->tag == h.bits.tag ? e->object : 0;
}

extern "C" {
void fn_80240120(Node*, int);
void fn_80269FE0(Node*);
Zero0 fn_80263308(void*, const Key&);
void fn_8023E994(Node*, Owned<2>&, int);
void fn_802408BC(Node*, Owned<1>, int);
void fn_8023D8D8(Node*);
void fn_8023DE28(Node*);
signed char fn_801FD4EC(Hierarchy*, const Handle_801F7F10&, Key);

void fn_801FC514(Hierarchy* self, Owned<1> target);

inline void notify(Hierarchy* self, const Handle_801F7F10* target) {
    fn_80240120(resolveRelated(resolve(*target)->owner58), 0);
    fn_80269FE0(resolve(self->owner0C));
}

Handle_80020834 fn_801FCF20(Hierarchy* self, const Key& name, Key key, const Handle_80020B90& parent) {
    Owned<1> resource(fn_80263308(lbl_801E9D24.factory, name));
    if (!fn_801F7EB8(&resource))
        return Handle_80020834();
    Owned<2> created;
    fn_8023E994(resolveMenu(resource), created, 0);
    Node* owner = resolve(self->owner0C);
    if (fn_801F7EB8(&parent)) {
        fn_802408BC(resolve(parent), Owned<1>(created), 0);
        fn_8023D8D8(resolve(created));
    } else {
        fn_802408BC(resolve(owner->parent30), Owned<1>(created), 0);
    }
    int group = resolve(created)->group134;
    if (group == resolveRelated(owner->parent30)->group134) {
        fn_80269FE0(owner);
        fn_8023DE28(resolve(owner->parent30));
    }
    int index = self->childrenC4.count;
    if (!fn_801FD4EC(self, created, key))
        return Handle_80020834();
    if (!self->quietE8) {
        Zero0 context(self->context());
        resolve(self->childrenC4.data[index])->attach(context);
    }
    return Handle_80020834(self->childrenC4.data[index]);
}

void fn_801FCCF4(Hierarchy* self, const Handle_801F7F10* child) {
    int i;
    for (i = 0; i < self->childrenC4.count; ++i) {
        if (sameObject(*child, self->childrenC4.data[i])) {
            self->childrenC4.removeAt(i);
            fn_801FC514(self, Owned<1>(*child));
            notify(self, child);
            return;
        }
    }
}

void fn_801FCB3C(Hierarchy* self, const Handle_801F7F10* child) {
    int i;
    for (i = 0; i < self->childrenC4.count; ++i) {
        if (sameObject(self->childrenC4.data[i], *child))
            return;
    }
    self->childrenC4.append(*child);
}

void fn_801FC998(Hierarchy* self, const Owned<2>& member) {
    self->members90.append(member);
    resolve(member)->attach(Zero0(self->context()));
}

void fn_801FC514(Hierarchy* self, Owned<1> target) {
    Zero0 context(self->context());
    int i;
    for (i = 0; i < self->childrenC4.count; ++i) {
        if (sameObject(target, self->childrenC4.data[i])) {
            self->childrenC4.removeAt(i);
            resolve(target)->detach(context);
            return;
        }
    }
    for (i = 0; i < self->slotsA8.count; ++i) {
        if (sameObject(target, self->slotsA8.data[i])) {
            self->slotsA8.data[i] = Zero<7>();
            resolve(target)->detach(context);
            return;
        }
    }
    for (i = 0; i < self->slotsD0.count; ++i) {
        if (sameObject(target, self->slotsD0.data[i])) {
            self->slotsD0.data[i] = Zero<4>();
            resolve(target)->detach(context);
            return;
        }
    }
}
}
