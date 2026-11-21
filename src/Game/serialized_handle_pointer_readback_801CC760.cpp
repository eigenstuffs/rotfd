/* Resolve three serialized handles, then replace each serialized pointer token
 * with the object identified by a temporary retained handle. */
typedef unsigned int u32;

struct HandleIndex {
    int value;
    HandleIndex(int v) : value(v) {}
    operator int() const { return value; }
};
struct ReadbackEntry {
    void* object;
    u32 key;
    char unknown08[4];
    signed char generation;
    char unknown0D[3];
    bool matchesGeneration(signed char tag) const {
        return generation == tag;
    }
};
struct ReadbackManager {
    int count, capacity;
    ReadbackEntry* entries;
};
struct ReadbackGlobals {
    char unknown00[0x118];
    ReadbackManager* manager;
};
extern "C" ReadbackGlobals lbl_801E9D24;

struct ReadbackHandleBits {
    signed int generation : 8;
    signed int index : 24;
    template<class T> T* get() const {
        ReadbackManager* manager = lbl_801E9D24.manager;
        const HandleIndex slot(index);
        signed char tag = generation;
        if (manager->entries[slot].matchesGeneration(tag))
            return (T*)manager->entries[slot].object;
        return 0;
    }
};
struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ReadbackZeroHandle : Handle_801F7F10 {
    ReadbackZeroHandle() { word = 0; }
    ~ReadbackZeroHandle() {}
};
struct ReadbackOwnedHandle : ReadbackZeroHandle {
    ReadbackOwnedHandle() { word = 0; }
    ~ReadbackOwnedHandle() {}
};
extern "C" {
void fn_801B3E54(ReadbackManager*, void*);
void fn_801B3F0C(ReadbackManager*, Handle_801F7F10*, void*);
}
struct ReadbackOwner {
    char unknown00[0x104];
    ReadbackHandleBits first, second, third;
    u32 count, capacity;
    void** data;
};
typedef char ReadbackEntrySize[sizeof(ReadbackEntry) == 16 ? 1 : -1];
typedef char ReadbackHandleSize[sizeof(ReadbackOwnedHandle) == 4 ? 1 : -1];

extern "C" void fn_801CC760(ReadbackOwner* self) {
    fn_801B3E54(lbl_801E9D24.manager, &self->first);
    fn_801B3E54(lbl_801E9D24.manager, &self->second);
    fn_801B3E54(lbl_801E9D24.manager, &self->third);
    ReadbackOwnedHandle temporary;
    for (u32 i = 0; i < self->count; ++i) {
        fn_801B3F0C(lbl_801E9D24.manager, &temporary, self->data[i]);
        void*& destination = self->data[i];
        destination = ((ReadbackHandleBits*)&temporary)->get<void>();
    }
}
