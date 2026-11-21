/* Original Handle member assignment and service application; strict retained EH plus strong-owner backup audit.
 * See docs/notes/game-engine-handle-member-assign.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Context {char unknown00[0x114];char*slots114;Manager*manager;};
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_802139D8(void*);void fn_801E1F3C(void*,const Handle_801F7F10*);}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner {char unknown00[0x1F4];Handle_801F7F10 handle;};
extern "C" void fn_80062B20(Owner*self,const Handle_801F7F10&value){Handle_80021BCC h(value);fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
