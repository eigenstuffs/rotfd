typedef unsigned long u32;extern "C"{void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_801F7F10;
struct Context{char unknown00[0x118];void*manager;char unknown11C[0x164-0x11C];void*service;};
extern "C"{extern Context lbl_801E9D24;extern u32 lbl_803777B8;void*__ct__15Handle_801F7F10Fv(void*);void fn_801F86C8(void*,const Handle_801F7F10*,short);void fn_800B6C84(void*,int,u32);void fn_800B6DA8(void*,u32,int,struct Handle_80020478);float fn_8025E268(void*,int);}
struct Handle_801F7F10{u32 word;Handle_801F7F10();~Handle_801F7F10();inline Handle_801F7F10&operator=(const Handle_801F7F10&v){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);return*this;}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner{u32 unknown00;Handle_801F7F10 handle04;char unknown08[0x60-8];Handle_801F7F10 handle60;int mode64;};
extern "C" void fn_8004FD30(Owner*self,const Handle_801F7F10&input){self->handle60=input;self->mode64=(int)fn_8025E268(self,0);if(self->mode64==1){fn_800B6C84(lbl_801E9D24.service,0,lbl_803777B8);const Handle_801F7F10&original=self->handle04;fn_800B6DA8(lbl_801E9D24.service,lbl_803777B8,0,Handle_80020478(original));}}
