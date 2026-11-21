/* fn_801D0CBC: re-register an owner's two Handle arrays with the global
 * resource registry (lbl_801E9D24+0x144), remap them into registry-indexed
 * order through temporary arrays, seed the selected registry slot's default
 * handles when it has none, trim trailing invalid handles (never below the
 * registry index-table sizes) and shrink both arrays.
 * Registry layout follows src/Game/indexed_registry.cpp: first table +0x80,
 * first index table +0x8C, second table +0x98, second index table +0xA4,
 * slot array data +0xB8 (0x14-byte slots).
 * Register-allocation notes: the getKey statement order (tag before index),
 * the indexed resolve form used only by the first registration loop, and
 * routing the slot resize count through the shared loop index i are what
 * reproduce the original register assignment.
 * Compile: GC/1.3.2, -O4,p -inline auto -Cpp_exceptions off -RTTI off
 * -use_lmw_stmw on. */
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
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, Word, Word);
void* fn_8028FF24(void*, Word);
void fn_8028FD50(void*, void*, Word);
void fn_801F86C8(Manager*, const void*, short);
Node* fn_801F7EB8(const Handle_801F7F10*);
void fn_8023E1B4(Node*);
void fn_801F4E7C(Registry*, Node*);
int fn_801ADB28(Registry*, const Word&);
int fn_801F4F8C(Registry*, Node*);
void fn_801F49B8(Registry*, Node*);
int fn_801F4AC8(Registry*, Node*);
void fn_8023E994(Node*, void*, int);
void* fn_801D1F98(void*, const void*);
void* fn_801D1B60(void*, const void*);
}
inline void* operator new(Word, void* p) { return p; }
struct Zero : Handle_801F7F10 { Zero() { value = 0; } ~Zero() {} };
struct Value : Zero {
    Value() { value = 0; }
    ~Value() {}
    Value& operator=(const Value& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
template<class T> struct Array {
    int count, capacity;
    T* data;
    Array() : count(0), capacity(0), data(0) {}
    ~Array() {
        if (data) {
            for (int i = 0; i < count; i++) data[i].~T();
            free();
            data = 0;
        }
    }
    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
    void free() {
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }
    void reallocate(int n) {
        if (n) {
            if (data) data = (T*)fn_8028FAF4(lbl_8028F698, data, capacity * sizeof(T), n * sizeof(T));
            else data = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else free();
    }
    void reserve(int n) { reallocate(n); capacity = n; }
    void resize(int n, signed char keep) {
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
    void shrink() {
        if (capacity > count) {
            if (count == 0) { free(); data = 0; }
            else reallocate(count);
            capacity = count;
        }
    }
};
struct Slot { Array<Value> handles; Word unknown[2]; };
struct Registry {
    char unknown00[0x80];
    int firstCount;
    char unknown84[8];
    int firstIndexCount;
    char unknown90[8];
    int secondCount;
    char unknown9C[8];
    int secondIndexCount;
    char unknownA8[16];
    Slot* slots;
};
struct Owner {
    char unknown00[4];
    Handle_801F7F10 keyHandle;
    char unknown08[0x18];
    Array<Value> first;
    Handle_801F7F10 relatedHandle;
    Array<Value> second;
    int slotIndex;
};
inline Word resolve(const Handle_801F7F10& h) {
    Entry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->tag == h.bits.tag ? (Word)e->object : 0;
}
inline Word resolveIndexed(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? (Word)m->entries[index].object : 0;
}
inline Word getKey(const Handle_801F7F10& h) {
    Manager* m = lbl_801E9D24.manager;
    int tag = h.getTag();
    int i = h.getIndex();
    int valid = 0;
    if (i < m->count && tag == m->entries[i].getTag()) valid = 1;
    return valid ? m->entries[i].getKey() : 0;
}
extern "C" void fn_801D0CBC(Owner* self) {
    int i;
    fn_8023E1B4((Node*)resolve(self->relatedHandle));
    for (i = 0; i < self->first.count; i++)
        fn_801F4E7C(lbl_801E9D24.registry, (Node*)resolveIndexed(self->first[i]));
    Word key = getKey(self->keyHandle);
    self->slotIndex = fn_801ADB28(lbl_801E9D24.registry, key);
    Slot& slot = lbl_801E9D24.registry->slots[self->slotIndex];
    int n = lbl_801E9D24.registry->firstCount;
    if (slot.handles.count) n = slot.handles.count;
    Array<Value> first;
    first.resize(n, 0);
    for (i = 0; i < self->first.count; i++) {
        int index = fn_801F4F8C(lbl_801E9D24.registry, (Node*)resolve(self->first[i]));
        first[index] = self->first[i];
    }
    fn_801D1F98(&self->first, &first);
    if (!slot.handles.count) {
        i = self->first.count;
        slot.handles.resize(i, 0);
        for (int i = 0; i < self->first.count; i++)
            if (fn_801F7EB8(&self->first[i])) {
                Node* node = (Node*)resolve(self->first[i]);
                fn_8023E994(node, &slot.handles[i], 0);
            }
    }
    for (i = 0; i < self->second.count; i++)
        if (fn_801F7EB8(&self->second[i]))
            fn_801F49B8(lbl_801E9D24.registry, (Node*)resolve(self->second[i]));
    Array<Value> second;
    second.resize(lbl_801E9D24.registry->secondCount, 0);
    for (i = 0; i < self->second.count; i++)
        if (fn_801F7EB8(&self->second[i])) {
            int index = fn_801F4AC8(lbl_801E9D24.registry, (Node*)resolve(self->second[i]));
            second[index] = self->second[i];
        }
    fn_801D1B60(&self->second, &second);
    int end = self->first.count - 1;
    for (; end >= 0; --end) {
        if (fn_801F7EB8(&self->first[end])) break;
    }
    ++end;
    if (end < lbl_801E9D24.registry->firstIndexCount) end = lbl_801E9D24.registry->firstIndexCount;
    self->first.resize(end, 0);
    self->first.shrink();
    end = self->second.count - 1;
    for (; end >= 0; --end) {
        if (fn_801F7EB8(&self->second[end])) break;
    }
    ++end;
    if (end < lbl_801E9D24.registry->secondIndexCount) end = lbl_801E9D24.registry->secondIndexCount;
    self->second.resize(end, 0);
    self->second.shrink();
}
