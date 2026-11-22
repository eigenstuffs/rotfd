typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Context {char unknown00[0x114];char*slots114;Manager*manager;};
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_802139D8(void*);void fn_801E1F3C(void*,const Handle_801F7F10*);}
struct ZeroHandle_800B4E48:Handle_801F7F10{ZeroHandle_800B4E48(){word=0;}~ZeroHandle_800B4E48(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:ZeroHandle_800B4E48{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002F6B0:Handle_80021BCC{Handle_8002F6B0(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_8002F6B0(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner {char unknown00[0x4];Handle_801F7F10 handle;char unknown08[0x34-8];unsigned char slot34;};
extern "C" void fn_800B4E48(Owner*self){fn_802139D8(self);const Handle_801F7F10&original=self->handle;Handle_8002F6B0 h(original);fn_801E1F3C(lbl_801E9D24.slots114+self->slot34*0x4C,&h);}
