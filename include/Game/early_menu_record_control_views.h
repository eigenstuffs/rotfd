#ifndef GAME_EARLY_MENU_RECORD_CONTROL_VIEWS_H
#define GAME_EARLY_MENU_RECORD_CONTROL_VIEWS_H
typedef unsigned long MenuRecordWord;
struct MenuRecordVec3{float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}void scale(float s){set(x*s,y*s,z*s);}};
struct MenuRecordOwner{char unknown00[0x80];MenuRecordVec3 corners[4];};
extern "C"{void fn_800B3344(void*);void fn_8021D51C(void*,int);extern const float lbl_803792F8;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);}
struct MenuRecordManager;extern "C" struct MenuRecordContext{char unknown00[0x118];MenuRecordManager*manager;}lbl_801E9D24;
extern "C" void fn_801F86C8(MenuRecordManager*,const void*,short);
struct Handle_801F7F10{MenuRecordWord word;Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct MenuRecordPair{MenuRecordWord first,second;};
struct MenuRecordHandle:Handle_8001FF78{~MenuRecordHandle();MenuRecordHandle(const MenuRecordHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct MenuRecordValue{MenuRecordHandle handle;MenuRecordWord key;struct Text{MenuRecordWord words[32];}text;MenuRecordWord a88,a8C,a90,a94;MenuRecordPair a98,aA0;unsigned char aA8,aA9;float aAC,aB0;unsigned char aB4,aB5,aB6;float aB8,aBC,aC0,aC4,aC8,aCC,aD0;
};
struct MenuRecordArray{int count,capacity;MenuRecordValue*data;void grow(int size){if(size){if(data)data=(MenuRecordValue*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(MenuRecordValue),size*sizeof(MenuRecordValue));else data=(MenuRecordValue*)fn_8028FF24(lbl_8028F698,size*sizeof(MenuRecordValue));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(MenuRecordValue));data=0;}}};
inline void*operator new(unsigned long,void*p){return p;}
typedef char CheckMenuRecordSize[sizeof(MenuRecordValue)==0xD4?1:-1];
#endif
