typedef unsigned long u32;
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Target{};
struct Entry{Target*object;u32 opaque04,opaque08;signed char generation0C;char opaque0D[3];};
struct ManagerPrefix{u32 count,capacity;Entry*entries;char opaque0C[0x18];};
struct Manager:ManagerPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual Handle_801F7F10 find(const char*);};
struct Arguments{char opaque00[0x860];int count860;char opaque864[4];const char*argument868;char opaque86C[0x50];float first8BC,second8C0;};
struct Scene{char opaque00[0x1506C];Handle_801F7F10 handle1506C;};
extern "C" struct Global{char opaque00[0x110];Arguments*args;char opaque114[4];Manager*manager;char opaque11C[8];Scene*scene;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_800C4404(Target*,const Handle_801F7F10*,float,int,int);extern const float lbl_80378510;}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003F47C:Handle_8001FF78{Handle_8003F47C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8003F47C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline Target*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->generation0C==h.bits.tag?e->object:0;}

extern "C" int fn_8003F338(){if(lbl_801E9D24.args->count860<3)return 0;const char*name=lbl_801E9D24.args->argument868;float first=lbl_801E9D24.args->first8BC;float second=lbl_80378510;if(lbl_801E9D24.args->count860>3)second=lbl_801E9D24.args->second8C0;Target*t=resolve(lbl_801E9D24.scene->handle1506C);Handle_8003F47C h(lbl_801E9D24.manager->find(name));fn_800C4404(t,&h,first,0,(int)second);return 1;}
