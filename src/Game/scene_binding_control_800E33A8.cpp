/* Scene binding and callback control; see docs/notes/game-scene-binding-controls.md. */
struct Handle { signed int generation:8,index:24; };
struct Entry { void* object; char unknown04[8]; signed char generation; char unknown0D[3]; };
struct Manager { int count,capacity; Entry* entries; };
extern "C" struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
struct Owner { char unknown00[0x70]; Handle handle; };
extern "C" { void fn_8025A0A4(Owner*); void fn_800E2C3C(void*,Owner*); }
inline void* resolve(const Handle& h) { Entry* entry=lbl_801E9D24.manager->entries+h.index; return entry->generation==h.generation?entry->object:0; }
extern "C" void fn_800E33A8(Owner* self) { fn_8025A0A4(self); fn_800E2C3C(resolve(self->handle),self); }
