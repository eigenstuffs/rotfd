#ifndef GAME_EARLY_RESOURCE_CONTROL_VIEWS_H
#define GAME_EARLY_RESOURCE_CONTROL_VIEWS_H
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ControlObject;
struct ControlEntry{ControlObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ControlManager{int count,capacity;ControlEntry*entries;};
struct ControlContext{char unknown00[0x118];ControlManager*manager;};
extern "C" ControlContext lbl_801E9D24;
extern "C" {void fn_801F86C8(ControlManager*,const Handle_801F7F10*,int);unsigned long fn_801F7EB8(const Handle_801F7F10*);void fn_802139D8(ControlObject*);void fn_80213A18(ControlObject*);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){value=0;}~Handle_80021C40(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(){value=0;}~Handle_80021BCC(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80021B54(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline signed char validControl(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
inline ControlObject*resolveControl(const Handle_801F7F10&h){ControlEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct ControlObject{char unknown00[0x38];unsigned long long flags;char unknown40[0x1B4];Handle_801F7F10 resource;};
#endif
