// Partial views of the native Handle manager and callback owner.
struct ReadyActionObject {
    char unknown00[0x18];
    signed char ready;
};
struct ReadyActionEntry {
    ReadyActionObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct ReadyActionManager {
    char unknown00[8];
    ReadyActionEntry* entries;
};
struct ReadyActionContext {
    char unknown00[0x118];
    ReadyActionManager* manager;
};
struct ReadyActionHandle {
    signed int generation : 8;
    signed int index : 24;
    signed char getGeneration() const { return generation; }
};
struct ReadyActionCallback {
    char unknown00[0x6C];
    ReadyActionHandle handle;
};
extern "C" {
    extern ReadyActionContext lbl_801E9D24;
    void fn_801C4F7C(void*);
    void fn_801C6C94(void*);
    void fn_801C4BC4(void*);
}
static inline ReadyActionObject* resolve(const ReadyActionHandle& handle) {
    ReadyActionManager* manager = lbl_801E9D24.manager;
    int index = handle.index;
    signed char generation = manager->entries[index].getGeneration();
    return generation == handle.getGeneration() ? manager->entries[index].object : 0;
}
extern "C" void fn_8025D4D0(ReadyActionCallback* self) {
    if (resolve(self->handle)->ready) {
        ReadyActionObject* object = resolve(self->handle);
        fn_801C4F7C(object);
        fn_801C6C94(object);
        fn_801C4BC4(object);
    }
}
