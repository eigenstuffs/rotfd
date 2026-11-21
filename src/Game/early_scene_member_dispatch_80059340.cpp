/* Scene member event dispatch and scoped native handles.
 * See docs/notes/game-early-scene-member-dispatch.md. */
typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct DispatchZero_59340:Handle_801F7F10{DispatchZero_59340(){word=0;}~DispatchZero_59340(){}};
struct Handle_80020B90:DispatchZero_59340{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ServicePrefix{char opaque00[0x7C];};
struct Service:ServicePrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void dispatch(const void*,int,const Handle_80020B90&,const Handle_80020B90&);};
extern "C" struct Globals{char opaque00[0x158];Service*service;}lbl_801E9D24;
struct Owner{char opaque00[0x2F8];Word entries[7];};
extern "C"void fn_80059340(Owner*self,int kind){
 switch(kind){
 case 0x26:lbl_801E9D24.service->dispatch(&self->entries[0],0,Handle_80020B90(),Handle_80020B90());break;
 case 0x27:lbl_801E9D24.service->dispatch(&self->entries[1],0,Handle_80020B90(),Handle_80020B90());break;
 case 0x28:lbl_801E9D24.service->dispatch(&self->entries[2],0,Handle_80020B90(),Handle_80020B90());break;
 case 0x29:lbl_801E9D24.service->dispatch(&self->entries[3],0,Handle_80020B90(),Handle_80020B90());break;
 case 0x2A:lbl_801E9D24.service->dispatch(&self->entries[4],0,Handle_80020B90(),Handle_80020B90());break;
 case 0x2B:lbl_801E9D24.service->dispatch(&self->entries[5],0,Handle_80020B90(),Handle_80020B90());break;
 case 0x99:lbl_801E9D24.service->dispatch(&self->entries[6],0,Handle_80020B90(),Handle_80020B90());break;
 }
}
