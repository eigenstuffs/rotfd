#ifndef GAME_EARLY_RELATED_HANDLE_APPEND_VIEWS_H
#define GAME_EARLY_RELATED_HANDLE_APPEND_VIEWS_H
struct RelatedAppendObject;struct RelatedAppendEntry{RelatedAppendObject*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct RelatedAppendManager{int count,capacity;RelatedAppendEntry*entries;};
extern "C"{extern struct RelatedAppendContext{char unknown00[0x118];RelatedAppendManager*manager;}lbl_801E9D24;void fn_801F86C8(RelatedAppendManager*,const void*,short);extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);}
struct Handle_801F7F10{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478();};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834();};
struct RelatedAppendHandle:Handle_80020834{RelatedAppendHandle(const RelatedAppendHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~RelatedAppendHandle();RelatedAppendHandle&operator=(const RelatedAppendHandle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct RelatedAppendObject{char unknown00[0x60];RelatedAppendHandle parent;void setParent(const RelatedAppendHandle&h){fn_801F86C8(lbl_801E9D24.manager,&parent,-1);parent.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
inline RelatedAppendObject*resolveRelatedAppend(const Handle_801F7F10&h){RelatedAppendEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline void*operator new(unsigned long,void*p){return p;}
struct RelatedAppendOwner{char unknown00[0x1504C];int count,capacity;RelatedAppendHandle*data;void grow(int size){if(size){if(data)data=(RelatedAppendHandle*)fn_8028FAF4(lbl_8028F698,data,capacity*4,size*4);else data=(RelatedAppendHandle*)fn_8028FF24(lbl_8028F698,size*4);}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}}};
#endif
