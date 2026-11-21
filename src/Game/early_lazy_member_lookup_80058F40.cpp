/* Lazy scene member lookup and retained native handles.
 * See docs/notes/game-early-lazy-member-lookup.md. */
typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;extern "C"{extern char lbl_801EF5C8[];extern const char lbl_8029ACA8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);void*fn_801F7EB8(const Handle_801F7F10*);}
extern "C" struct Globals{char opaque00[0x118];Manager*manager;}lbl_801E9D24;
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8005287C:Handle_8001FF78{Handle_8005287C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8005287C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_8005287C&operator=(const Handle_8005287C&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct ManagerPrefix{char opaque00[0x24];};struct Manager:ManagerPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual Handle_801F7F10 lookup(const char*);};
struct Owner{char opaque00[0x2F8];Handle_8005287C entries[7];};
extern "C"void fn_80058F40(Owner*self){const Word strings=(Word)lbl_8029ACA8;if(!fn_801F7EB8(&self->entries[0])){
self->entries[0]=Handle_8005287C(lbl_801E9D24.manager->lookup((const char*)(strings+0x6a0)));
self->entries[1]=Handle_8005287C(lbl_801E9D24.manager->lookup((const char*)(strings+0x6bc)));
self->entries[2]=Handle_8005287C(lbl_801E9D24.manager->lookup((const char*)(strings+0x6d8)));
self->entries[3]=Handle_8005287C(lbl_801E9D24.manager->lookup((const char*)(strings+0x6f4)));
self->entries[4]=Handle_8005287C(lbl_801E9D24.manager->lookup((const char*)(strings+0x710)));
self->entries[5]=Handle_8005287C(lbl_801E9D24.manager->lookup((const char*)(strings+0x72c)));
self->entries[6]=Handle_8005287C(lbl_801E9D24.manager->lookup((const char*)(strings+0x748)));
}}
