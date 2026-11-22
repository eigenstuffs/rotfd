typedef unsigned long Word;
struct Handle_801F7F10{signed int generation:8,index:24;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
extern "C" struct{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;}lbl_801E9D24;
struct Prefix{Word unknown00,unknown04;};
struct Owner:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94(int,int);char unknown0C[0x2C];unsigned long long flags;};
extern "C"{Handle_801F7F10 fn_801B52EC(Manager*,const char*);void fn_8025A3C8(Owner*,const Handle_801F7F10&);void fn_80259258(Owner*);extern const char lbl_802AB058[];}
extern "C" void fn_800E3850(Owner*self){self->flags&=~4ULL;fn_8025A3C8(self,fn_801B52EC(lbl_801E9D24.manager,lbl_802AB058));fn_80259258(self);self->slot94(0,0);}
