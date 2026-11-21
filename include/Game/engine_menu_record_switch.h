#ifndef GAME_ENGINE_MENU_RECORD_SWITCH_H
#define GAME_ENGINE_MENU_RECORD_SWITCH_H

struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct MenuRecordSwitchObject {
    char unknown00[0x1C];
    Handle_801F7F10 first, second;
    char unknown24[12];
    Handle_801F7F10 child;
    char unknown34[0xFC];
    Handle_801F7F10 parent;
};
struct MenuRecordSwitchEntry {
    MenuRecordSwitchObject *object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
    signed char getTag()const{return tag;}
};
struct MenuRecordSwitchManager { int count, capacity; MenuRecordSwitchEntry *entries; };
struct MenuRecordSwitchContext {
    char unknown00[0x118];
    MenuRecordSwitchManager *manager;
    char unknown11C[0x150 - 0x11C];
    void *recordManager;
};
struct MenuRecordSwitchOwner;
extern "C" {
extern MenuRecordSwitchContext lbl_801E9D24;
extern const float lbl_8037AF90;
void fn_802073E8(MenuRecordSwitchOwner*,int,MenuRecordSwitchObject*,float);
void fn_801E5C1C(void*,unsigned long,const Handle_801F7F10*);
void fn_801F86C8(MenuRecordSwitchManager *, const Handle_801F7F10 *, short);
unsigned long fn_801F7EB8(const Handle_801F7F10 *);


signed char fn_801E5D78(void *, unsigned long, Handle_801F7F10 *);
void fn_8023D648(MenuRecordSwitchObject *);
void fn_8023DE28(MenuRecordSwitchObject *);
}
struct MenuRecordSwitchZero : Handle_801F7F10 {
    MenuRecordSwitchZero() { value = 0; }
};
struct MenuRecordSwitchHandle : MenuRecordSwitchZero {
    MenuRecordSwitchHandle() { value = 0; }
};
struct MenuRecordSwitchRecord {
    char unknown00[0x80];
    unsigned long value80, value84, value88;
    unsigned short value8C;
    Handle_801F7F10 handle90;
    unsigned long value94;
    Handle_801F7F10 handle98;
};
struct MenuRecordSwitchArray { int count, capacity; MenuRecordSwitchRecord *data; };
struct MenuRecordSwitchOwner {
    char unknown00[0x20];
    Handle_801F7F10 first;
    char unknown24[4];
    short selected;
    short previous;
    char unknown2C[0x4C - 0x2C];
    MenuRecordSwitchArray records;
    Handle_801F7F10 second;
};

typedef char CheckMenuRecordSwitchRecordSize[sizeof(MenuRecordSwitchRecord) == 0x9C ? 1 : -1];
extern "C" void fn_8021ACD8(MenuRecordSwitchOwner*);

static inline unsigned long menuRecordResolveMessage(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    MenuRecordSwitchManager* manager = lbl_801E9D24.manager;
    int tag = manager->entries[index].getTag();
    if (tag == handle.bits.tag) return (unsigned long)manager->entries[index].object;
    return 0;
}
#endif
