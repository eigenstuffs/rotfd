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

// Preserve a signed-byte snapshot while combining the two negative flag tests.
struct ControlFlagResult{signed char value;ControlFlagResult(unsigned long long flags,unsigned long long mask):value(0){if((flags&mask)!=0)value=1;}operator signed char()const{return value;}};
extern "C" void fn_800936D0(StateDispatchAgent* self)
{
    if (self->hasFlag(0x100000000000000ULL) && !fn_8007D604(&self->controls, 0x21))
        fn_8007D6A0(&self->controls, 0x21);
    else if (!self->hasFlag(0x100000000000000ULL) && fn_8007D604(&self->controls, 0x21))
        fn_8007D7F4(&self->controls, 0x21);
    if (self->hasFlag(0x200000000000000ULL) && !fn_8007D604(&self->controls, 0x21))
        fn_8007D6A0(&self->controls, 0x21);
    else if (!ControlFlagResult(self->flags,0x200000000000000ULL) && !self->hasFlag(0x100000000000000ULL)
            && fn_8007D604(&self->controls, 0x21))
        fn_8007D7F4(&self->controls, 0x21);
    if (self->hasFlag(0x4000000000000ULL) && !fn_8007D604(&self->controls, 0x15)
        && !fn_8007D604(&self->controls, 0x2F) && !fn_8007D604(&self->controls, 9)
        && !fn_8007D604(&self->controls, 0x36) && self->previous != 0x2F) {
        StateDispatchObject* object=(StateDispatchObject*)resolveStateDispatch(self->owner);
        --object->count;
        if (object->count <= 0)
            fn_8007D6A0(&self->controls, 0x2F);
        else {
            fn_8007D6A0(&self->controls, 0x15);
            fn_8007D6A0(&self->controls, 0x36);
        }
    }
}
