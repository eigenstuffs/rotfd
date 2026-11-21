/* Original callback setup/notification lifetime; see docs/notes/game-engine-callback-handle-followup.md. */
typedef unsigned long u32;
struct Handle_801F7F10{u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Context{char unknown00[0x118];void*manager;char unknown11C[0x164-0x11C];void*service;};
extern "C"{extern Context lbl_801E9D24;void fn_801F86C8(void*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_8002BA94(void*);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Prefix{u32 unknown00;Handle_801F7F10 handle04;};
struct Owner:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void*query();};
extern "C" void fn_800B70AC(void*,Handle_80020478,void*);
extern "C" void fn_80040758(Owner*self){fn_8002BA94(self);const Handle_801F7F10&original=self->handle04;Handle_80020478 h(static_cast<const Handle_801F7F10&>(Handle_80020478(original)));fn_800B70AC(lbl_801E9D24.service,Handle_80020478(static_cast<const Handle_801F7F10&>(h)),self->query());}
