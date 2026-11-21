typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;struct Groups{char unknown00[0x1C];Handle_801F7F10*items;};struct Console{char unknown00[0x860];int argc;int unknown864;const char*arg1;};struct Scene{char unknown00[0x15058];void*owner;};
extern "C" struct Context{char unknown00[0x110];Console*console;Word unknown114;Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Groups*groups;}lbl_801E9D24;
extern "C"{void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F948C(void*,const char*);void fn_801FA014(Console*,const char*,...);Word fn_801F7EB8(const Handle_801F7F10*);int fn_801FE99C(Groups*,const Handle_801F7F10*);void fn_80058F40(void*);extern const char lbl_8029A7A8[];extern const char lbl_803784F8[6];}
struct NameHash{Word word;NameHash(const char*s){word=fn_801F948C(this,s);}};
struct NameType{Word word;NameType(const NameHash&n):word(n.word){}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct InitZero_E258:Handle_801F7F10{InitZero_E258(){word=0;}~InitZero_E258(){}};
struct Handle_80020834:InitZero_E258{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003E120:Handle_80020834{Handle_8003E120(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8003E120(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{Handle_801F7F10 fn_801B5054(Manager*,const NameHash&,const NameType&);Handle_80020478 fn_80260BA4(Scene*,const char*);void fn_800BCCBC(Scene*,const Handle_8003E120*,const Handle_801F7F10*);}
extern "C" int fn_8003E258(){
 const char*pool=lbl_8029A7A8;
 if(lbl_801E9D24.console->argc!=2){fn_801FA014(lbl_801E9D24.console,pool+0xE0);return 0;}
 Handle_80020C04 group(fn_801B5054(lbl_801E9D24.manager,NameHash(lbl_801E9D24.console->arg1),NameType(NameHash(lbl_803784F8))));
 if(!fn_801F7EB8(&group)){fn_801FA014(lbl_801E9D24.console,pool+0xF4,lbl_801E9D24.console->arg1);return 0;}
 int index=fn_801FE99C(lbl_801E9D24.groups,&group);
 if(index<0){fn_801FA014(lbl_801E9D24.console,pool+0x110,lbl_801E9D24.console->arg1);return 0;}
 Handle_8003E120 target(fn_80260BA4(lbl_801E9D24.scene,pool+0x124));
 fn_800BCCBC(lbl_801E9D24.scene,&target,&lbl_801E9D24.groups->items[index]);
 fn_80058F40(lbl_801E9D24.scene->owner);return 1;
}
