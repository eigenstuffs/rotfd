/* Pause-menu resource binding (fn_8002E2F8): creates the nine 2D menu
 * definitions of the owning menu object (handles +0x6C..+0x90), loads each from
 * "DB:>Definitions>menus2D>" + file and binds it to the owner handle, then
 * creates the scene owner's HUD data (+0x60) and no-camera draw (+0x64) objects.
 * Strings stay external in lbl_8029A0C0 (owned by native_readable_pools_8029A0C0.cpp).
 * The scoped member pointer to the offset-0 path keeps the pool base in a
 * register and emits the original per-use addi rX,base,0 (as in
 * engine_scene_startup_registration_8003DE58.cpp). Handle_8002DDAC's destructor
 * is out of line here (called, not inlined) as in the original. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Owner;
struct Scene{char unknown00[0x15058];Owner*owner;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const void*,int);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);Word fn_801F948C(void*,const char*);
char*strcpy(char*,const char*);char*strcat(char*,const char*);extern const char lbl_80378368[4];}
struct Key{Word value;Key(const char*s){value=fn_801F948C(this,s);}};
struct Strings{
 char root[0x1C];char pauseFile[0x14];char pauseName[0xC];char menuType[0xC];
 char worldStatusFile[0x18];char worldStatusName[0x14];char optionsFile[0x14];char optionsName[0x10];
 char settingsFile[0x14];char settingsName[0x10];char optionsType[0x10];char saveFile[0x10];
 char saveName[0xC];char loadFile[0x10];char loadName[0xC];char mainOptionsFile[0x18];
 char mainOptionsName[0x14];char mainLoadFile[0x18];char mainLoadName[0x10];char mainExtrasFile[0x18];
 char mainExtrasName[0x14];char hudType[0xC];char hudFile[0x18];char noCameraName[0xC];
 char noCameraType[0xC];char rest[0x98];
};
extern "C" const Strings lbl_8029A0C0;
extern "C" Handle_801F7F10 fn_801B550C(Manager*,const Key&,const Key&);

struct Layer1_2E2F8:Handle_801F7F10{Layer1_2E2F8(){word=0;}~Layer1_2E2F8(){}};
struct Layer2_2E2F8:Layer1_2E2F8{Layer2_2E2F8(){word=0;}~Layer2_2E2F8(){}};
struct Handle_8002DEA8:Layer2_2E2F8{Handle_8002DEA8(){word=0;}~Handle_8002DEA8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002DE2C:Handle_8002DEA8{
 Handle_8002DE2C(){word=0;}
 Handle_8002DE2C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Handle_8002DE2C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_8002DE2C&operator=(const Handle_8002DE2C&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Handle_8002DDAC:Handle_8002DE2C{
 Handle_8002DDAC(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Handle_8002DDAC();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_8002DDAC&operator=(const Handle_8002DDAC&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct LayerA_2E2F8:Handle_801F7F10{LayerA_2E2F8(){word=0;}~LayerA_2E2F8(){}};
struct LayerB_2E2F8:LayerA_2E2F8{LayerB_2E2F8(){word=0;}~LayerB_2E2F8(){}};
struct Handle_8002F6B0:LayerB_2E2F8{Handle_8002F6B0(){word=0;}~Handle_8002F6B0(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002F634:Handle_8002F6B0{
 Handle_8002F634(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002F634(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_8002F634&operator=(const Handle_8002F634&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Handle_8002F520:Handle_8002F6B0{
 Handle_8002F520(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002F520(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_8002F520&operator=(const Handle_8002F520&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Handle_80020478:Handle_801F7F10{
 Handle_80020478(){word=0;}Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Handle_80020834:Handle_80020478{
 Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
 virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();
 virtual void setName(const char*);virtual void v48();virtual void v4C();virtual char load(const char*,int);
};
struct Owner{char unknown00[4];Handle_801F7F10 self;char unknown08[0x58];Handle_8002F634 hud;Handle_8002F520 camera;};
struct MenuPrefix{char unknown00[4];Handle_801F7F10 self;};
struct Menu:MenuPrefix{
 virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C(int,int);
 char unknown0C[0x2C];unsigned long long flags38;char unknown40[0x2C];
 Handle_8002DE2C pause,worldStatus,options;Handle_8002DDAC settings;Handle_8002DE2C unknown7C,load,save,mainLoad;Handle_8002DDAC mainOptions;Handle_8002DE2C extras;
};
extern "C"{void fn_8002F728(Node*,const Handle_80020834&);void fn_8002F59C(Node*,const Handle_80020478&);void fn_800A7798(Node*);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline void menuPath(char*path,const Strings*s,const char*file){const char(Strings::*root)[0x1C]=&Strings::root;strcpy(path,s->*root);strcat(path,file);}

extern "C" void fn_8002E2F8(Menu*self){
 char path[64];
 const Strings*const s=&lbl_8029A0C0;
 self->flags38|=0x20000ULL;
 menuPath(path,s,s->pauseFile);
 self->pause=Handle_8002DE2C(fn_801B550C(lbl_801E9D24.manager,Key(s->menuType),Key(s->pauseName)));
 if(resolve(self->pause)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->pause),Handle_80020834(original));}
 menuPath(path,s,s->worldStatusFile);
 self->worldStatus=Handle_8002DE2C(fn_801B550C(lbl_801E9D24.manager,Key(s->menuType),Key(s->worldStatusName)));
 if(resolve(self->worldStatus)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->worldStatus),Handle_80020834(original));}
 menuPath(path,s,s->optionsFile);
 self->options=Handle_8002DE2C(fn_801B550C(lbl_801E9D24.manager,Key(s->menuType),Key(s->optionsName)));
 if(resolve(self->options)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->options),Handle_80020834(original));}
 menuPath(path,s,s->settingsFile);
 self->settings=Handle_8002DDAC(fn_801B550C(lbl_801E9D24.manager,Key(s->optionsType),Key(s->settingsName)));
 if(resolve(self->settings)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->settings),Handle_80020834(original));}
 menuPath(path,s,s->saveFile);
 self->save=Handle_8002DE2C(fn_801B550C(lbl_801E9D24.manager,Key(s->menuType),Key(s->saveName)));
 if(resolve(self->save)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->save),Handle_80020834(original));}
 menuPath(path,s,s->loadFile);
 self->load=Handle_8002DE2C(fn_801B550C(lbl_801E9D24.manager,Key(s->menuType),Key(s->loadName)));
 if(resolve(self->load)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->load),Handle_80020834(original));}
 menuPath(path,s,s->mainOptionsFile);
 self->mainOptions=Handle_8002DDAC(fn_801B550C(lbl_801E9D24.manager,Key(s->optionsType),Key(s->mainOptionsName)));
 if(resolve(self->mainOptions)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->mainOptions),Handle_80020834(original));}
 menuPath(path,s,s->mainLoadFile);
 self->mainLoad=Handle_8002DE2C(fn_801B550C(lbl_801E9D24.manager,Key(s->menuType),Key(s->mainLoadName)));
 if(resolve(self->mainLoad)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->mainLoad),Handle_80020834(original));}
 menuPath(path,s,s->mainExtrasFile);
 self->extras=Handle_8002DE2C(fn_801B550C(lbl_801E9D24.manager,Key(s->menuType),Key(s->mainExtrasName)));
 if(resolve(self->extras)->load(path,0)){const Handle_801F7F10&original=self->self;fn_8002F728(resolve(self->extras),Handle_80020834(original));}
 Owner*owner=lbl_801E9D24.scene->owner;
 owner->hud=Handle_8002F634(fn_801B550C(lbl_801E9D24.manager,Key(s->hudType),Key(lbl_80378368)));
 {const Handle_801F7F10&original=owner->self;fn_8002F59C(resolve(owner->hud),Handle_80020478(original));}
 resolve(owner->hud)->setName(s->hudFile);
 {const Handle_801F7F10&original=owner->self;fn_8002F59C(resolve(owner->hud),Handle_80020478(original));}
 fn_800A7798(resolve(owner->hud));
 owner->camera=Handle_8002F520(fn_801B550C(lbl_801E9D24.manager,Key(s->noCameraType),Key(s->noCameraName)));
 self->v8C(0,0);
}
