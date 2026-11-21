#ifndef GAME_EARLY_RANDOM_RECORD_GRID_VIEWS_H
#define GAME_EARLY_RANDOM_RECORD_GRID_VIEWS_H
typedef unsigned long u32;
struct GridEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct GridManager{char unknown00[8];GridEntry*entries;};
struct GridContext{char unknown00[0x118];GridManager*manager;char unknown11C[0x30];void*scope;};
extern "C" {extern GridContext lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(GridManager*,const void*,int);u32 fn_801F948C(void*,const char*);float fn_801F1200();extern const float lbl_80378FD4,lbl_80378FD8,lbl_80378FDC,lbl_80378FE0,lbl_80378FE4,lbl_80378FE8,lbl_80378FEC,lbl_80378FF0;extern const char lbl_8029EDF0[];void fn_80239A7C(void*);void fn_802397E0(void*);}
struct GridBits{signed long tag:8,index:24;};
struct Handle_801F7F10{union{u32 word;GridBits bits;};Handle_801F7F10();~Handle_801F7F10();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct GridZero154:Handle_801F7F10{GridZero154(){word=0;}~GridZero154(){}};
struct Handle_80020834:GridZero154{Handle_80020834(){word=0;}~Handle_80020834(){}};
struct Handle_800723F4:GridZero154{~Handle_800723F4(){}};
struct GridName{u32 word;GridName(const char*s){word=fn_801F948C(this,s);}};
extern "C" Handle_800723F4 fn_802631B0(void*,const GridName&);
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager,&d,-1);d.word=s.word;fn_801F86C8(lbl_801E9D24.manager,&s,1);}
inline void*resolveGrid(const Handle_801F7F10&h){int index=h.bits.index;GridManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct GridRecord{float x,y,z,w;};
struct RandomGrid{char unknown00[0x34];Handle_801F7F10 handle34;char unknown38[0x3C];float value;GridRecord records[400];unsigned char flag1978,flag1979;char unknown197A[2];int index;Handle_801F7F10 handle1980;};
extern "C" void fn_800A85AC(RandomGrid*);
#endif
