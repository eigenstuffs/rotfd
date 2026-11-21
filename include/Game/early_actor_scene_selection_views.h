#ifndef GAME_EARLY_ACTOR_SCENE_SELECTION_VIEWS_H
#define GAME_EARLY_ACTOR_SCENE_SELECTION_VIEWS_H
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct SelectionObject{char unknown00[0x130];Handle_801F7F10 related;};struct SelectionEntry{SelectionObject*object;char unknown04[8];signed char tag;char unknown0D[3];};struct SelectionManager{int count,capacity;SelectionEntry*entries;};
struct SelectionNode{char unknown00[8];const Handle_801F7F10*handle;};struct SelectionMode{char unknown00[0xF0];int mode,submode;};struct SelectionScene{char unknown00[0x15058];SelectionMode*mode;};struct SelectionContext{char unknown00[0x118];SelectionManager*manager;SelectionNode*node;char unknown120[4];SelectionScene*scene;};
extern "C" {extern SelectionContext lbl_801E9D24;void fn_801F86C8(SelectionManager*,const Handle_801F7F10*,int);void*fn_801F7EB8(const Handle_801F7F10*);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];extern const char lbl_8029D680[];unsigned long fn_801F948C(void*,const char*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){value=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_80020B90&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){value=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){value=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct SelectionName{unsigned long value;SelectionName(const char*s){value=fn_801F948C(this,s);}};
extern "C" {Handle_80020834 fn_80058778(SelectionMode*,const SelectionName&,signed char);Handle_80020B90 fn_8026A494(SelectionObject*,const SelectionName&);}
inline SelectionObject*resolveSelection(const Handle_801F7F10&h){SelectionEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct SelectionActor{char unknown00[0x30];unsigned long long flags;inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct SelectionOwner{char unknown00[8];SelectionActor*actor;void*controller;char unknown10[0x30];SelectionObject*first,*second;};extern "C" void fn_80089B74(SelectionOwner*);
struct SelectionSecondEntry{SelectionObject*object;char unknown04[8];signed char tag;char unknown0D[3];};struct SelectionSecondManager{int count,capacity;SelectionSecondEntry*entries;};
inline SelectionObject*resolveSelectionSecond(const Handle_801F7F10&h){SelectionSecondEntry*e=&((SelectionSecondManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
#endif
