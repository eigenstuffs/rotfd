struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ReverseHitEntry {
    char* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct ReverseHitManager { char unknown00[8]; ReverseHitEntry* entries; };
extern "C" {
    extern struct { char unknown00[0x118]; ReverseHitManager* manager; } lbl_801E9D24;
    void fn_801F86C8(void*, const void*, int);
}
inline char* resolveReverseHit(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    ReverseHitManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation) return manager->entries[index].object;
    return 0;
}
struct ReverseHitZero1 : Handle_801F7F10 { ReverseHitZero1() { value = 0; } };
struct ReverseHitZero2 : ReverseHitZero1 { ReverseHitZero2() { value = 0; } };
struct ReverseHitZero3 : ReverseHitZero2 { ReverseHitZero3() { value = 0; } };
struct ReverseHitZero4 : ReverseHitZero3 { ReverseHitZero4() { value = 0; } };
struct ReverseHitCopy4 : ReverseHitZero4 {
    ReverseHitCopy4() { value = 0; }
    ReverseHitCopy4(const Handle_801F7F10& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
    ReverseHitCopy4(const ReverseHitCopy4& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
struct ReverseHitOutput { char unknown00[4]; Handle_801F7F10 handle; };
struct ReverseHitSelf {
    char unknown0000[0xC110];
    Handle_801F7F10 items[8];
    int count;
    typedef Handle_801F7F10 ItemArray[8];
    const ItemArray& getItems() const { return items; }
    const Handle_801F7F10& getItem(unsigned int index) const { return getItems()[index]; }
};
extern "C" signed char fn_80242C70(char*, const void*, ReverseHitOutput*);
inline void assignReverseHit(Handle_801F7F10& dest, const Handle_801F7F10& input) {
    fn_801F86C8(lbl_801E9D24.manager, &dest, -1);
    dest.value = input.value;
    fn_801F86C8(lbl_801E9D24.manager, &input, 1);
}
extern "C" signed char fn_80269DE0(ReverseHitSelf* self, const void* input, ReverseHitOutput* output, int selected) {
    for (int index = self->count; --index >= 0;) {
        if (selected >= 0 && selected != index) continue;
        ReverseHitCopy4 handle(self->getItem(index));
        if (!fn_80242C70(resolveReverseHit(handle), input, output)) continue;
        assignReverseHit(output->handle, handle);
        return 1;
    }
    return 0;
}
