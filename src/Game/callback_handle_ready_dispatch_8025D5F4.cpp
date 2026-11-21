// Clock-action callback slot 0x38 (vtable lbl_802ECEC0): runs the shared
// callback step, then dispatches on the ready flag of the object named by the
// callback's handle. Partial views of the native Handle manager and the
// callback owner; the resolver shape matches fn_8025D4D0.
struct ReadyDispatchTarget {
    char unknown00[8];
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    char unknown0C[0xC];
    signed char ready;
};
struct ReadyDispatchEntry {
    ReadyDispatchTarget* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct ReadyDispatchManager {
    char unknown00[8];
    ReadyDispatchEntry* entries;
};
struct ReadyDispatchContext {
    char unknown00[0x118];
    ReadyDispatchManager* manager;
};
struct ReadyDispatchHandle {
    signed int generation : 8;
    signed int index : 24;
    signed char getGeneration() const { return generation; }
};
struct ReadyDispatchPrefix {
    char unknown00[8];
};
struct ReadyDispatchCallback : ReadyDispatchPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    char unknown0C[0x6C - 0x0C];
    ReadyDispatchHandle handle;
};
extern "C" {
    extern ReadyDispatchContext lbl_801E9D24;
    void fn_8025E588(void*);
}
static inline ReadyDispatchTarget* resolve(const ReadyDispatchHandle& handle) {
    ReadyDispatchManager* manager = lbl_801E9D24.manager;
    int index = handle.index;
    signed char generation = manager->entries[index].getGeneration();
    return generation == handle.getGeneration() ? manager->entries[index].object : 0;
}
extern "C" void fn_8025D5F4(ReadyDispatchCallback* self) {
    fn_8025E588(self);
    if (resolve(self->handle)->ready) {
        self->slot80();
    } else {
        resolve(self->handle)->slot34();
    }
}
