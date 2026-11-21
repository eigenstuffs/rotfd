#ifndef GAME_EARLY_ACTOR_SCOPED_HANDLE_VIEWS_H
#define GAME_EARLY_ACTOR_SCOPED_HANDLE_VIEWS_H

extern "C" void fn_801F7CB4(void*,const void*);
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();Handle_801F7F10(const Handle_801F7F10&h){fn_801F7CB4(this,&h);}~Handle_801F7F10();};
struct ScopedComponent{char unknown00[0xC];float value;};
struct ScopedResource{char unknown00[0x70];Handle_801F7F10 handle;ScopedComponent*first,*second;};
struct ScopedEntry{ScopedResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ScopedManager{int count,capacity;ScopedEntry*entries;};struct ScopedContext{char unknown00[0x118];ScopedManager*manager;};extern "C" ScopedContext lbl_801E9D24;
inline ScopedResource*resolveScoped(const Handle_801F7F10&h){ScopedEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct ScopedRecord{char unknown00[8];int key;};
struct ScopedActor{char unknown00[0x168];Handle_801F7F10 resource;char unknown16C[0x1AC];ScopedRecord record;char unknown324[0xE8];signed char enabled40C;};
struct ScopedControllerNode{char unknown00[4];Handle_801F7F10 handle;};
struct ScopedControllerObject{char unknown00[0x2C];ScopedControllerNode*node;};
struct ScopedOwner{char unknown00[8];ScopedActor*actor;void*controller;char unknown10[0x34];float first,second;};
struct ScopedMonitor{char unknown00[0x130];void*first,*second;};
extern "C" {extern ScopedMonitor*lbl_803776B8;int fn_80092844(ScopedActor*);void fn_8007D6A0(ScopedRecord*,int);signed char fn_8025E9FC(void*,int);ScopedControllerObject*fn_8025E50C(void*);void fn_80224038(ScopedActor*,const Handle_801F7F10*);void fn_80092DAC(ScopedActor*,double);void fn_80068158(ScopedMonitor*,int);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}

#endif
