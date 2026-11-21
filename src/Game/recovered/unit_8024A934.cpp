/* fn_8024A934: clone an owner (resource-handle owner, see
 * owner_resource_handles_reindex_801D0CBC.cpp) into a freshly created object
 * and remap its handle arrays onto the cloned node hierarchy. */
typedef unsigned long Word;
struct Handle_801F7F10 {
    union {
        Word value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
    signed char getTag() const { return bits.tag; }
    int getIndex() const { return bits.index; }
};
struct Name {
    Word value;
    Name(const char*);
};
struct Node;
struct Entry {
    Node* object;
    Word key, unknown;
    signed char tag;
    char tail[3];
    int getTag() const { return tag; }
    Word getKey() const { return key; }
};
struct Manager { int count, capacity; Entry* entries; };
struct Registry;
struct Globals { char unknown[0x118]; Manager* manager; char unknown11C[0x28]; Registry* registry; };
struct Owner;
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_8028F698[];
extern const char lbl_8037B440[5];
void* fn_8028FAF4(void*, void*, Word, Word);
void* fn_8028FF24(void*, Word);
void fn_8028FD50(void*, void*, Word);
void fn_801F86C8(Manager*, const void*, short);
Node* fn_801F7EB8(const Handle_801F7F10*);
Word fn_801F948C(void*, const char*);
Handle_801F7F10 fn_801B550C(Manager*, const Name&, const Name&);
int fn_801ADB28(Registry*, const Word&);
int fn_801F4F8C(Registry*, Node*);
void fn_8023E994(Node*, Handle_801F7F10*, signed char);
void fn_8023EFAC(Node*, void*);
void* fn_801D1F98(void*, const void*);
void fn_8024B76C(void*, const void*);
void fn_8024B5D8(void*, const void*);
}
inline Name::Name(const char* text) { value = fn_801F948C(this, text); }
inline void* operator new(Word, void* p) { return p; }
struct Zero : Handle_801F7F10 { Zero() { value = 0; } ~Zero() {} };
struct Copy : Zero {
    Copy(const Handle_801F7F10& h)
    {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
struct Value : Zero {
    Value() { value = 0; }
    ~Value() {}
    Value& operator=(const Value& h)
    {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
    Value& operator=(const Handle_801F7F10& h)
    {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct Typed : Value {
    Typed(const Handle_801F7F10& h)
    {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
struct Value3 : Value {
    Value3() { value = 0; }
    ~Value3() {}
};
template<class T> struct Array {
    int count, capacity;
    T* data;
    Array() : count(0), capacity(0), data(0) {}
    ~Array()
    {
        if (data) {
            for (int i = 0; i < count; i++) data[i].~T();
            free();
            data = 0;
        }
    }
    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
    void free()
    {
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }
    void reallocate(int n)
    {
        if (n) {
            if (data) data = (T*)fn_8028FAF4(lbl_8028F698, data, capacity * sizeof(T), n * sizeof(T));
            else data = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else free();
    }
    void reserve(int n) { reallocate(n); capacity = n; }
    void resize(int n, signed char keep)
    {
        int i;
        if (n > count) {
            if (n > capacity || !keep) reserve(n);
            for (i = count; i < n; i++) new (data + i) T;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; i--) data[i].~T();
            if (keep) count = n;
            else { reserve(n); count = n; }
        }
    }
};
extern "C" Value fn_8024BDA0(Owner*, const Name&);
typedef Value Named[6];
template<class T> struct RawArray {
    int count, capacity;
    T* data;
    T& operator[](int i) { return data[i]; }
};
struct Node {
    Name name;
    Word unknown04;
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(Handle_801F7F10*);
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void lookup(Handle_801F7F10*, const Handle_801F7F10*);
};
struct OwnerBase {
    Name name;
    Handle_801F7F10 keyHandle;
    void* vtable;
    char unknown0C[4];
    float f10, f14, f18, f1C;
};
struct Owner : OwnerBase {
    Array<Value> first;
    Handle_801F7F10 relatedHandle;
    Array<Value> second;
    int slotIndex;
    RawArray<Named> named40;
    RawArray<Named> named4C;
    RawArray<Named> named58;
    Array<Value3> third;
    char unknown70[0x10];
    RawArray<Handle_801F7F10> array80;
};
inline Node* resolve(const Handle_801F7F10& h)
{
    Entry* e = lbl_801E9D24.manager->entries + h.bits.index;
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}
inline Word getKey(const Handle_801F7F10& h)
{
    Manager* m = lbl_801E9D24.manager;
    int tag = h.getTag();
    int i = h.getIndex();
    int valid = 0;
    if (i < m->count && tag == m->entries[i].getTag()) valid = 1;
    return valid ? m->entries[i].getKey() : 0;
}
static inline void assign(Handle_801F7F10& target, const Handle_801F7F10& source)
{
    fn_801F86C8(lbl_801E9D24.manager, &target, -1);
    target.value = source.value;
    fn_801F86C8(lbl_801E9D24.manager, &source, 1);
}
inline void cloneNamed(Owner* copy, Owner* self, RawArray<Named>& dst, RawArray<Named>& src)
{
    fn_8024B5D8(&dst, &src);
    for (int i = 0; i < dst.count; i++)
        if (fn_801F7EB8(&dst[i][1]))
            dst[i][1] = fn_8024BDA0(copy, resolve(src.data[i][1])->name);
}
inline Owner* owner(Node* n) { return (Owner*)n; }
extern "C" void fn_8024A934(Owner* self, Handle_801F7F10& target, Handle_801F7F10& other)
{
    int i;
    Name name(lbl_8037B440);
    assign(target, Copy(fn_801B550C(lbl_801E9D24.manager, name, self->name)));
    Owner* copy = (Owner*)resolve(Typed(target));
    OwnerBase* base = (OwnerBase*)resolve(target);
    base->f10 = self->f10;
    base->f14 = self->f14;
    base->f18 = self->f18;
    base->f1C = self->f1C;
    fn_8023E994(resolve(self->relatedHandle), &copy->relatedHandle, 1);
    fn_8023EFAC(resolve(copy->relatedHandle), &copy->first);
    Array<Value> first;
    first.resize(self->first.count, 0);
    for (i = 0; i < copy->first.count; i++) {
        int index = fn_801F4F8C(lbl_801E9D24.registry, resolve(copy->first[i]));
        first[index] = copy->first[i];
    }
    fn_801D1F98(&copy->first, &first);
    Word key = getKey(self->keyHandle);
    copy->slotIndex = fn_801ADB28(lbl_801E9D24.registry, key);
    fn_8024B76C(copy->unknown70, self->unknown70);
    Owner* peer = owner(resolve(Typed(other)));
    copy->third.resize(self->third.count, 0);
    for (i = 0; i < self->third.count; i++)
    {
        Node* node = resolve(self->third[i]);
        node->lookup(&copy->third[i], &peer->array80[i]);
    }
    fn_8024B5D8(&copy->named40, &self->named40);
    for (i = 0; i < copy->named40.count; i++)
        if (fn_801F7EB8(&copy->named40[i][1]))
            copy->named40[i][1] = fn_8024BDA0(copy, resolve(self->named40.data[i][1])->name);
    fn_8024B5D8(&copy->named58, &self->named58);
    for (i = 0; i < copy->named58.count; i++)
        if (fn_801F7EB8(&copy->named58[i][1]))
            copy->named58[i][1] = fn_8024BDA0(copy, resolve(self->named58.data[i][1])->name);
    fn_8024B5D8(&copy->named4C, &self->named4C);
    for (i = 0; i < copy->named4C.count; i++)
        if (fn_801F7EB8(&copy->named4C[i][1]))
            copy->named4C[i][1] = fn_8024BDA0(copy, resolve(self->named4C.data[i][1])->name);
    copy->second.resize(self->second.count, 0);
    for (i = 0; i < self->second.count; i++)
        if (fn_801F7EB8(&self->second[i]))
        {
            Node* node = resolve(self->second[i]);
            node->slot20(&copy->second[i]);
        }
}
