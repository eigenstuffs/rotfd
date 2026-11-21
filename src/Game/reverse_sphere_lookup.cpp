struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ReverseSphereEntry {
    char* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct ReverseSphereManager { char unknown00[8]; ReverseSphereEntry* entries; };
extern "C" {
    extern struct { char unknown00[0x118]; ReverseSphereManager* manager; } lbl_801E9D24;
    void fn_801F86C8(void*, const void*, int);
}
inline char* resolveReverseSphere(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    ReverseSphereManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation) return manager->entries[index].object;
    return 0;
}
struct ReverseSphereZero1 : Handle_801F7F10 { ReverseSphereZero1() { value = 0; } };
struct ReverseSphereZero2 : ReverseSphereZero1 { ReverseSphereZero2() { value = 0; } };
struct ReverseSphereZero3 : ReverseSphereZero2 { ReverseSphereZero3() { value = 0; } };
struct ReverseSphereZero4 : ReverseSphereZero3 { ReverseSphereZero4() { value = 0; } };
struct ReverseSphereCopy4 : ReverseSphereZero4 {
    ReverseSphereCopy4() { value = 0; }
    ReverseSphereCopy4(const Handle_801F7F10& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
    ReverseSphereCopy4(const ReverseSphereCopy4& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
struct ReverseSphere { float x, y, z, radius; };
struct ReverseSphereSelf {
    char unknown0000[0xC110];
    Handle_801F7F10 items[8];
    int count;
    typedef Handle_801F7F10 ItemArray[8];
    const ItemArray& getItems() const { return items; }
};
extern "C" ReverseSphereCopy4 fn_80269C94(ReverseSphereSelf* self, ReverseSphere* output) {
    for (int index = self->count; --index >= 0;) {
        ReverseSphereCopy4 handle(self->getItems()[index]);
        *output = *reinterpret_cast<ReverseSphere*>(resolveReverseSphere(handle) + 0xC);
        return ReverseSphereCopy4(handle);
    }
    return ReverseSphereCopy4();
}
