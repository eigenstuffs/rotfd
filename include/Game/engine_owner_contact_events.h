#ifndef GAME_ENGINE_OWNER_CONTACT_EVENTS_H
#define GAME_ENGINE_OWNER_CONTACT_EVENTS_H

typedef unsigned long ContactWord;
typedef unsigned long long ContactFlags;

struct Handle_801F7F10 {
    union {
        ContactWord word;
        struct { signed int generation : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ContactPrefix { ContactWord unknown00; Handle_801F7F10 self; };
struct ContactObject : ContactPrefix {
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
    virtual signed char queryFirst(int*);
    virtual signed char querySecond(int*);
    char unknown0C[0x30 - 0xC];
    ContactFlags state;
    ContactFlags flags;
    char unknown40[0x70 - 0x40];
    Handle_801F7F10 active;
    char unknown74[0x120 - 0x74];
    ContactWord nodeFlags;
    char unknown124[12];
    Handle_801F7F10 related;
};
struct ContactEntry {
    ContactObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct ContactManager { int count, capacity; ContactEntry* entries; };
struct ContactGlobals { char unknown00[0x118]; ContactManager* manager; };
struct ContactOwner {
    char unknown00[0x24];
    Handle_801F7F10 resource;
    char unknown28[8];
    ContactFlags state;
};

extern "C" {
    extern ContactGlobals lbl_801E9D24;
    extern const float lbl_8037B074;
    void fn_801F86C8(ContactManager*, const Handle_801F7F10*, short);
    void fn_802073E8(ContactObject*, int, ContactObject*, float);
    void slot64__12ObjectMove_ZFv(ContactOwner*, ContactObject*, const void*, const void*, ContactFlags);
}
struct ContactCopy : Handle_801F7F10 {
    ContactCopy(const Handle_801F7F10& handle) {
        word = handle.word;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};

#endif
