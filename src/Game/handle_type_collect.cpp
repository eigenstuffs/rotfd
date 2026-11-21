extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
void fn_801F86C8(void*, const void*, int);
unsigned long fn_801F7EB8(const void*);
}
inline void* operator new(unsigned long, void* address) { return address; }
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct TypeCollectObject { char unknown00[0x1C]; Handle_801F7F10 resource; char unknown20[0x4C]; unsigned short type; };
struct TypeCollectEntry {
    TypeCollectObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct TypeCollectManager { char unknown00[8]; TypeCollectEntry* entries; };
extern "C" { extern struct { char unknown00[0x118]; TypeCollectManager* manager; } lbl_801E9D24; }
inline TypeCollectObject* resolveTypeCollect(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    TypeCollectManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation) return manager->entries[index].object;
    return 0;
}
struct TypeCollectZero1 : Handle_801F7F10 { TypeCollectZero1() { value = 0; } };
struct TypeCollectHandle : TypeCollectZero1 {
    TypeCollectHandle() { value = 0; }
    TypeCollectHandle(const Handle_801F7F10& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
    TypeCollectHandle(const TypeCollectHandle& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
struct TypeCollectArray {
    int count, capacity;
    TypeCollectHandle* items;
    TypeCollectHandle& operator[](int i) { return items[i]; }
    void storage(int n) {
        if (n) {
            if (items) items = (TypeCollectHandle*)fn_8028FAF4(lbl_8028F698, items, capacity * 4, n * 4);
            else items = (TypeCollectHandle*)fn_8028FF24(lbl_8028F698, n * 4);
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * 4);
            items = 0;
        }
    }
    void resize(int n) {
        if (n > count) {
            storage(n);
            capacity = n;
            for (int i = count; i < n; ++i) new (&(*this)[i]) TypeCollectHandle;
            count = n;
        } else if (n < count) {
            for (int i = count - 1; i >= n; --i) (*this)[i].~TypeCollectHandle();
            storage(n);
            capacity = n;
            count = n;
        }
    }
    void append(const TypeCollectHandle& input) {
        if (count + 1 > capacity) {
            storage(capacity + 32);
            capacity += 32;
        }
        new (&items[count++]) TypeCollectHandle(input);
    }
};
struct TypeCollectSelf { char unknown00[0xC]; TypeCollectArray children; };
extern "C" int fn_8026A128(TypeCollectSelf* self, TypeCollectArray* output, int type) {
    output->resize(0);
    for (int i = 0; i < self->children.count; ++i) {
        TypeCollectHandle handle(self->children[i]);
        TypeCollectHandle resource(resolveTypeCollect(handle)->resource);
        if (!fn_801F7EB8(&resource)) continue;
        if (type != resolveTypeCollect(resource)->type) continue;
        output->append(handle);
    }
    return output->count;
}
