/* Scene state predicate control; see docs/notes/game-scene-state-predicate-control.md. */
struct Handle { signed int generation:8,index:24; };
struct Entry { void* object; char unknown04[8]; signed char generation; char unknown0D[3]; };
struct Manager { int count,capacity; Entry* entries; };
extern "C" struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
struct Actor { char unknown00[0x24]; Handle handle; char unknown28[0x2F8]; int state; };
struct Owner { char unknown00[8]; Actor* actor; char unknown0C[0x4C]; signed char enabled; };
extern "C" { void fn_80255D88(void*,int,int,int,int); void fn_80255CBC(void*,int,int); }
inline void* resolve(const Handle& h) { Entry* entry=lbl_801E9D24.manager->entries+h.index; return entry->generation==h.generation?entry->object:0; }
inline int stateEnabled(Actor* a){int result=1;if(a->state!=0x30&&a->state!=0x11)result=0;return result;}
extern "C" void fn_800E54DC(Owner* self) {
    signed char enabled=stateEnabled(self->actor);
    if (!self->enabled&&enabled) { fn_80255D88(resolve(self->actor->handle),0x7A,15,0,0); self->enabled=1; }
    else if (self->enabled&&!enabled) { fn_80255CBC(resolve(self->actor->handle),0x7A,0); self->enabled=0; }
}
