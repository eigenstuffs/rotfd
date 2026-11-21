/* Scene startup registration: font pairs, menu/message text tables and the global and memory-card agents.
 * The string pool stays external (owned by native_readonly_pools_8029A7A8.cpp); the const pool pointer
 * keeps its base in a register and the offset-0 string is reached through a member pointer (addi rX,rY,0). */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Target;
struct Scene{char opaque00[0x15058];Target*first15058;Target*second1505C;void*third15060;void*fourth15064;};
struct Input{char opaque00[0x4C];void*object4C;};
struct Entry{Target*object;Word opaque04,opaque08;signed char generation0C;char opaque0D[3];};
struct Manager{char opaque00[8];Entry*entries;};
extern "C" struct Global{char opaque00[0x118];Manager*manager;char opaque11C[8];Scene*scene;char opaque128[0x24];void*fonts14C;char opaque150[0x14];Input*input164;}lbl_801E9D24;
extern "C"{Word fn_801F948C(void*,const char*);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Name{Word word;Name(const char*s){word=fn_801F948C(this,s);}};
struct NameArgument{Word word;NameArgument(const Name&n):word(n.word){}};
inline Target*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->generation0C==h.bits.tag?e->object:0;}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{unsigned char fn_8026248C(void*,const NameArgument&,const NameArgument&);void fn_800AFCF4(const char*);void fn_800B026C(const char*);void fn_800C2474(void*,const char*);Handle_80020478 fn_80260868(Scene*,const Name&,int);}
struct Strings{char bigFontMask[0x10];char bigFont[0xC];char smallFontMask[0x10];char smallFont[0xC];char taskList[0x18];char credits[0x24];char boxText[0x18];char dvdText[0x18];char inputText[0x1C];char globalAgent[0x10];char memCardAgent[0x10];};
extern "C" const Strings lbl_8029A7A8;
extern "C" int fn_8003DE58(){
 const Strings*const s=&lbl_8029A7A8;
 const char(Strings::*mask)[0x10]=&Strings::bigFontMask;
 fn_8026248C(lbl_801E9D24.fonts14C,Name(s->bigFont),Name(s->*mask));
 fn_8026248C(lbl_801E9D24.fonts14C,Name(s->smallFont),Name(s->smallFontMask));
 fn_800AFCF4(s->taskList);
 fn_800B026C(s->credits);
 fn_800C2474(lbl_801E9D24.scene->third15060,s->boxText);
 fn_800C2474(lbl_801E9D24.scene->fourth15064,s->dvdText);
 fn_800C2474(lbl_801E9D24.input164->object4C,s->inputText);
 Target*first=resolve(fn_80260868(lbl_801E9D24.scene,Name(s->globalAgent),0));
 lbl_801E9D24.scene->first15058=first;
 Target*second=resolve(fn_80260868(lbl_801E9D24.scene,Name(s->memCardAgent),0));
 lbl_801E9D24.scene->second1505C=second;
 return 1;
}
