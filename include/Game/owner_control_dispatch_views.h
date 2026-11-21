#ifndef GAME_OWNER_CONTROL_DISPATCH_VIEWS_H
#define GAME_OWNER_CONTROL_DISPATCH_VIEWS_H
struct StateDispatchHandle { union {unsigned long value; struct {signed int tag:8; signed int index:24;} bits;}; };
struct StateDispatchEntry { char* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct StateDispatchManager { int count, capacity; StateDispatchEntry* entries; };
struct StateDispatchContext { char unknown00[0x118]; StateDispatchManager* manager; };
extern "C" StateDispatchContext lbl_801E9D24;
inline char* resolveStateDispatch(const StateDispatchHandle& handle)
{
    StateDispatchEntry* entry=&lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag) return entry->object;
    return 0;
}
struct StateDispatchRecord { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void dispatch(); };
struct StateDispatchObject { char unknown00[0x84]; int count; };
struct StateDispatchAgent {
    char unknown00[0x24]; StateDispatchHandle owner;
    char unknown28[8]; unsigned long long flags;
    char unknown38[0x2E0]; char controls;
    char unknown319[0xB]; int previous;
    signed char hasFlag(unsigned long long mask) const { return (flags & mask) != 0; }
};
extern "C" {
signed char fn_8007D604(void*, int);
void fn_8007D6A0(void*, int);
void fn_8007D7F4(void*, int);
StateDispatchRecord* fn_8007DD0C(void*, int);
}
#endif
