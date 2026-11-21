typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Console{
 char unknown000[0x860];int argc;int unknown864;const char*arg868;
 char unknown86C[0x39];signed char valid8A5,valid8A6;char unknown8A7[0x11];
 float value8B8,index8BC;
};
struct Viewports{char records[0x214];signed char count;char unknown215[0x13];unsigned int lod;};
struct Pool{char invalidParameter[0x14];char splitMissing[0x1C];char parameter1[0x18];char invalidLod[0x14];
 char parameter2[0x18];char worldMissing[0x1C];};
extern "C" const Pool lbl_802ACD70;
extern "C" struct Context{char unknown00[0x110];Console*console;Viewports*viewports;Manager*manager;}lbl_801E9D24;
inline const char*invalidText(const Pool*p){const char(Pool::*m)[0x1C]=&Pool::splitMissing;const char*s=p->*m;return s-sizeof(p->invalidParameter);}
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F948C(void*,const char*);void fn_801FA014(Console*,const char*,...);Word fn_801F7EB8(const Handle_801F7F10*);}
struct NameHash{Word word;NameHash(const char*s){word=fn_801F948C(this,s);}NameHash(){word=0;}};
struct NameType{Word word;NameType(const NameHash&n):word(n.word){}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(const Handle_801F7F10&h,Context*c){word=h.word;fn_801F86C8(c->manager,&h,1);}Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80020C04(const Handle_80020C04&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}};
extern "C"{Handle_801F7F10 fn_801B5054(Manager*,const NameHash&,NameType);void fn_8003125C(Viewports*,int,Handle_80020C04);}


extern "C" int fn_801E1108(){
 const Pool*const pool=&lbl_802ACD70;
 Console*console=lbl_801E9D24.console;
 if(console->argc!=3){fn_801FA014(console,invalidText(pool));return 1;}
 if(!console->valid8A6){fn_801FA014(console,pool->parameter2);return 1;}
 Handle_80020C04 world(fn_801B5054(lbl_801E9D24.manager,NameHash(console->arg868),NameType(NameHash())));
 int index=(int)lbl_801E9D24.console->index8BC;
 if(!fn_801F7EB8(&world)){fn_801FA014(*(Console**)&lbl_801E9D24.console,pool->worldMissing,lbl_801E9D24.console->arg868);return 1;}
 if(index<0||index>=lbl_801E9D24.viewports->count){fn_801FA014(lbl_801E9D24.console,pool->splitMissing,index);return 1;}
 fn_8003125C(lbl_801E9D24.viewports,index,world);
 return 1;
}
