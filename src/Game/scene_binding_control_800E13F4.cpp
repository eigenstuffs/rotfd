/* Scene binding and callback control; see docs/notes/game-scene-binding-controls.md. */
typedef unsigned long Word;
struct Handle_801F7F10 { signed int generation:8,index:24; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Manager;
extern "C" struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
struct Owner { char unknown00[0x38]; unsigned long long flags; };
extern "C" { Handle_801F7F10 fn_801B52EC(Manager*,const char*); void fn_8025A3C8(Owner*,const Handle_801F7F10&); void fn_8025A48C(Owner*); extern const char lbl_802AAED0[]; }
extern "C" void fn_800E13F4(Owner* self) { fn_8025A3C8(self,fn_801B52EC(lbl_801E9D24.manager,lbl_802AAED0)); self->flags&=~1ULL; fn_8025A48C(self); }
