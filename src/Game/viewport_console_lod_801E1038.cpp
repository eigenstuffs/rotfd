// Partial text split: fn_801E1038 (SetLodRender). The following
// SetWorldToSplit fn_801E1108 (99.3%, saved-register rotation) remains
// original code; full draft: scratch/claude_match/auto_03_801E1038_text/final.cpp.
/* Viewport console commands: fn_801E1038 is SetLodRender (lod 1..3 stored in
 * the viewport set at +0x228), fn_801E1108 is SetWorldToSplit (looks up a
 * world by name and binds it to split index argument 2 via fn_8003125C).
 * The strings stay external: lbl_802ACD70.. is owned by
 * engine_game_strings_802ACD08.cpp and viewed here as one const pool. */
typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Console{
 char unknown000[0x860];int argc;int unknown864;const char*arg868;
 char unknown86C[0x39];signed char valid8A5,valid8A6;char unknown8A7[0x11];
 float value8B8,index8BC;
};
struct Viewports{char records[0x214];signed char count;char unknown215[0x13];unsigned int lod;};
extern "C" struct Context{char unknown00[0x110];Console*console;Viewports*viewports;Manager*manager;}lbl_801E9D24;
struct Pool{char invalidParameter[0x14];char splitMissing[0x1C];char parameter1[0x18];char invalidLod[0x14];
 char parameter2[0x18];char worldMissing[0x1C];};
extern "C" const Pool lbl_802ACD70;
inline const char*invalidText(const Pool*p){const char(Pool::*m)[0x1C]=&Pool::splitMissing;const char*s=p->*m;return s-sizeof(p->invalidParameter);}
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F948C(void*,const char*);void fn_801FA014(Console*,const char*,...);Word fn_801F7EB8(const Handle_801F7F10*);}
struct NameHash{Word word;NameHash(const char*s){word=fn_801F948C(this,s);}NameHash(){word=0;}};
struct NameType{Word word;NameType(const NameHash&n):word(n.word){}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80020C04(const Handle_80020C04&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}};
extern "C"{Handle_801F7F10 fn_801B5054(Manager*,const NameHash&,NameType);void fn_8003125C(Viewports*,int,Handle_80020C04);}
extern "C" int fn_801E1038(){
 const Pool*const pool=&lbl_802ACD70;
 Console*console=lbl_801E9D24.console;
 if(console->argc!=2){fn_801FA014(console,invalidText(pool));return 1;}
 if(!console->valid8A5){fn_801FA014(console,pool->parameter1);return 1;}
 unsigned int lod=(unsigned int)console->value8B8;
 if(lod>3||lod<1){fn_801FA014(console,pool->invalidLod,3);return 1;}
 lbl_801E9D24.viewports->lod=lod;return 1;
}
