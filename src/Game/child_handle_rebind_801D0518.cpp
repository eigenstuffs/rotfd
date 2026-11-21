// Replace each handle with the handle stored in its resolved child. These are
// bounded views of the native four-byte handles and the observed owner fields.
typedef unsigned long RebindWord;
struct RebindHandle {
    union {
        RebindWord word;
        struct { signed int tag : 8, index : 24; } bits;
    };
    void operator=(const RebindHandle&);
};
struct RebindChild { char unknown[0xB8]; RebindHandle replacement; };
struct RebindEntry {
    void* object;
    RebindWord key;
    char unknown8[4];
    signed char tag;
    char unknownD[3];
    bool matchesTag(signed char expected) const { return tag == expected; }
};
struct RebindEntries {
    RebindEntry* data;
    RebindEntry& operator[](int index) const { return data[index]; }
};
struct RebindManager { int count, capacity; RebindEntries entries; };
struct RebindGlobals { char unknown[0x118]; RebindManager* manager; };
extern "C" {
extern RebindGlobals lbl_801E9D24;
void fn_801F86C8(RebindManager*, const RebindHandle&, short);
}
inline void RebindHandle::operator=(const RebindHandle& source) {
    fn_801F86C8(lbl_801E9D24.manager, *this, -1);
    word = source.word;
    fn_801F86C8(lbl_801E9D24.manager, source, 1);
}
struct HandleRebindOwner_801D0518 {
    char unknown[0xB0];
    int count, capacity;
    RebindHandle* handles;
};
struct RebindIndex {
    int value;
    RebindIndex(int index) : value(index) {}
    operator const int&() const { return value; }
};
inline RebindChild* resolveRebindChild(RebindHandle& handle) {
    RebindManager* manager = lbl_801E9D24.manager;
    const RebindIndex index(handle.bits.index);
    signed char tag = handle.bits.tag;
    if (manager->entries[index].matchesTag(tag))
        return static_cast<RebindChild*>(manager->entries[index].object);
    return 0;
}
extern "C" void fn_801D0518(HandleRebindOwner_801D0518* owner) {
    for (int i = 0; i < owner->count; ++i)
        owner->handles[i] = resolveRebindChild(owner->handles[i])->replacement;
}
typedef char RebindHandleSize[sizeof(RebindHandle) == 4 ? 1 : -1];
typedef char RebindEntrySize[sizeof(RebindEntry) == 16 ? 1 : -1];
