#ifndef GAME_OWNER_CONTROL_STATE_VIEWS_H
#define GAME_OWNER_CONTROL_STATE_VIEWS_H
struct ControlStateHandle {
    union { unsigned long value; struct { signed int tag:8; signed int index:24; } bits; };
};
struct ControlStateEntry { char* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct ControlStateManager { int count, capacity; ControlStateEntry* entries; };
struct ControlStateScreen { char unknown00[0x2CC]; unsigned int active; };
struct ControlStateWorld { char unknown00[0x15058]; ControlStateScreen* screen; };
struct ControlStateContext {
    char unknown00[0x118]; ControlStateManager* manager;
    char unknown11C[8]; ControlStateWorld* world;
};
extern "C" ControlStateContext lbl_801E9D24;
inline char* resolveControlState(const ControlStateHandle& handle)
{
    ControlStateEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag) return entry->object;
    return 0;
}
struct ControlStateObject { char unknown00[0x84]; int state; char unknown88[0x14]; signed char active; };
struct ControlStateAgent {
    char unknown00[0x24]; ControlStateHandle owner;
    char unknown28[0x120]; float velocityY;
    char unknown14C[0x14]; float angularY;
    char unknown164[0x48]; ControlStateHandle related;
    char unknown1B0[0x168]; char controls;
    char unknown319[0x43]; float movementY;
    char unknown360[0x84]; float limit;
    char unknown3E8[0x1D]; signed char enabled;
};
extern "C" {
signed char fn_8007D604(void*, int);
void fn_8007D6A0(void*, int);
void fn_8007D7F4(void*, int);
void fn_80094600(ControlStateAgent*);
unsigned long fn_801F7EB8(const void*);
extern const float lbl_80378BAC, lbl_80378BEC;
}
#endif
