/* Scene callback and native Handle control; see docs/notes/game-scene-native-callback-controls.md. */
typedef unsigned long Word;
struct Handle_801F7F10{signed int generation:8,index:24;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
extern "C" struct{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;}lbl_801E9D24;
struct Prefix{Word unknown00,unknown04;};
struct Actor{char unknown00[0x168];char component[0x40];float y,z;};struct Entry{Actor*object;char unknown04[8];signed char generation;char unknown0D[3];};struct Manager{int count,capacity;Entry*entries;};struct Owner{char unknown00[0x70];Handle_801F7F10 handle;char unknown74[8];int state;};
inline Actor*resolve(const Handle_801F7F10&h){Entry*e=lbl_801E9D24.manager->entries+h.index;return e->generation==h.generation?e->object:0;}
extern "C"{void fn_801FA014(void*,const char*,...);void fn_8002AF3C(void*,void*);void fn_8007D6A0(void*,int);extern const char lbl_802A18A8[];extern const float lbl_803794D8,lbl_803794DC;}
extern "C" void fn_800C0FF8(Owner*self,void*arg){fn_801FA014(lbl_801E9D24.logger,lbl_802A18A8);fn_8002AF3C(self,arg);Actor*a=resolve(self->handle);a->y=lbl_803794D8;a->z=lbl_803794DC;fn_8007D6A0(a->component,1);self->state=2;}
