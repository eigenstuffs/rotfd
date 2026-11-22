typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Context {char unknown00[0x114];char*slots114;Manager*manager;};
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_802139D8(void*);void fn_801E1F3C(void*,const Handle_801F7F10*);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner {char unknown00[0x30];Handle_801F7F10 handle;};
extern "C" void fn_8002F59C(Owner*self,const Handle_801F7F10&value){Handle_80020834 h(value);fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
