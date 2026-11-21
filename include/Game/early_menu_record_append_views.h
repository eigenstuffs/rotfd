#ifndef GAME_EARLY_MENU_RECORD_APPEND_VIEWS_H
#define GAME_EARLY_MENU_RECORD_APPEND_VIEWS_H
struct MenuAppendManager;
extern "C"{extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);void fn_801F86C8(MenuAppendManager*,const void*,short);extern struct MenuAppendContext{char unknown00[0x118];MenuAppendManager*manager;}lbl_801E9D24;}
struct Handle_801F7F10{unsigned long word;Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78();};
struct MenuAppendHandle:Handle_8001FF78{MenuAppendHandle(const MenuAppendHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~MenuAppendHandle();};
struct MenuAppendName{unsigned long word;MenuAppendName(const MenuAppendName&h){word=h.word;}};
struct MenuAppendValue{struct Text{unsigned long words[32];}text;unsigned long a80,a84,a88;unsigned short a8C;MenuAppendName values90[8];unsigned char aB0,aB1,aB2,aB3;float aB4,aB8,aBC;MenuAppendHandle handle;};
template<class T>struct MenuAppendArray{int count,capacity;T*data;void grow(int size){if(size){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),size*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,size*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}int append(const T&value){if(count+1>capacity){grow(capacity+32);capacity+=32;}new(&data[count++])T(value);return count-1;}};
inline void*operator new(unsigned long,void*p){return p;}
struct MenuAppendOwner{char unknown00[0x38];MenuAppendArray<MenuAppendValue*> index;char unknown44[0x24];MenuAppendArray<MenuAppendValue> records;};
typedef char MenuAppendValueSize[sizeof(MenuAppendValue)==0xC4?1:-1];
#endif
