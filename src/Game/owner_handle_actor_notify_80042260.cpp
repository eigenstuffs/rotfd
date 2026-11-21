/* fn_80042260: resolve the owner's Handle at +0x70, then, when the scene
 * settings hold an actor at +0x314, pass a retained copy of that actor's
 * Handle to fn_80229098 and set the resolved node's counter at +0x318 to 0x18.
 *
 * Matching notes: the manager pointer must be a local read through an inline
 * accessor (it is register-allocated after the expression temporaries), and the
 * settings expression must be passed directly as the helper's argument (inline
 * arguments are evaluated right to left, so it is loaded before the resolve). */
typedef unsigned long u32;
struct Handle_801F7F10{union{u32 word;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char unknown00[0x318];};
struct Entry{Node*object;u32 key,unknown08;signed char generation;char unknown0D[3];};
struct Manager{char unknown00[8];Entry*entries;};
struct Actor{u32 unknown00;Handle_801F7F10 handle04;};
struct Settings{char unknown00[0x314];Actor*actor314;};
struct Scene{char unknown00[0x15058];Settings*settings;};
struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;};
struct Owner{char unknown00[0x70];Handle_801F7F10 handle70;};
extern "C"{
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
void fn_801F86C8(Manager*,const Handle_801F7F10*,short);
void fn_8007D6A0(void*,int);
}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(){word=0;}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025BF4:Handle_80021B54{Handle_80025BF4(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" void fn_80229098(Node*,Handle_80025BF4);
inline Manager*GetManager(){return lbl_801E9D24.manager;}
inline Node*resolve(const Handle_801F7F10&h){Manager*m=GetManager();Entry*entry=m->entries+h.bits.index;if(entry->generation==h.bits.generation)return entry->object;return 0;}
inline void notify(Node*node,Settings*settings){Actor*actor=settings->actor314;if(actor){const Handle_801F7F10&original=actor->handle04;fn_80229098(node,Handle_80025BF4(original));fn_8007D6A0((char*)node+0x318,0x18);}}
extern "C" void fn_80042260(Owner*self){notify(resolve(self->handle70),lbl_801E9D24.scene->settings);}
