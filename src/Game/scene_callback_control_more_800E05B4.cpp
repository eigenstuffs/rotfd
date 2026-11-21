/* Scene callback setup and nested Handle control; see docs/notes/game-scene-native-callback-controls-more.md. */
typedef unsigned long Word;struct Handle{signed int generation:8,index:24;};struct Entry{void*object;char unknown04[8];signed char generation;char unknown0D[3];};struct Manager{int count,capacity;Entry*entries;};struct Scene{char unknown00[0x15058];void*mode;};
struct Selection{char unknown00[0x1C];Handle*handle;};struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Selection*selection;};extern "C" Context lbl_801E9D24;
template<class T>inline T*resolve(const Handle&h){Entry*entry=lbl_801E9D24.manager->entries+h.index;return entry->generation==h.generation?(T*)entry->object:0;}
struct ByteManager{int count,capacity;char*entries;};template<class T>inline T*resolveAlternate(const Handle&h){Entry*entry=(Entry*)(((ByteManager*)lbl_801E9D24.manager)->entries+h.index*16);return entry->generation==h.generation?(T*)entry->object:0;}
struct Actor{char unknown00[0x70];Handle handle;char unknown74[0x3C];Handle*child;char unknownB4[0xB4];char component168[0x1B0];char component318[1];};struct Owner{char unknown00[8];Actor*actor;};
extern "C"{unsigned long fn_801F7EB8(const Handle*);signed char fn_8007D604(void*,int);void fn_8007D6A0(void*,int);}
inline Actor*checked(const Handle&h){return fn_801F7EB8(&h)?resolve<Actor>(h):0;}
extern "C" void fn_800E05B4(Owner*self){Actor*actor=checked(resolve<Actor>(*resolveAlternate<Actor>(*lbl_801E9D24.selection->handle)->child)->handle);if(actor&&fn_8007D604(actor->component318,0x37))fn_8007D6A0(self->actor->component168,1);}
