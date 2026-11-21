/* Scene callback and native Handle control; see docs/notes/game-scene-native-callback-controls.md. */
typedef unsigned long Word;
struct Handle_801F7F10{signed int generation:8,index:24;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
extern "C" struct{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;}lbl_801E9D24;
struct Prefix{Word unknown00,unknown04;};
struct Owner:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C(int,int);char unknown0C[0x2C];unsigned long long flags;};
extern "C"{Handle_801F7F10 fn_801B52EC(Manager*,const char*);void fn_8025A3C8(Owner*,const Handle_801F7F10&);void fn_8025A48C(Owner*);extern const char lbl_802AB048[];}
extern "C" void fn_800E3308(Owner*self){self->flags&=~1ULL;fn_8025A3C8(self,fn_801B52EC(lbl_801E9D24.manager,lbl_802AB048));fn_8025A48C(self);self->slot7C(0,0);}
