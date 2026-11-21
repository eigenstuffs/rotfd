#ifndef GAME_ENGINE_HIERARCHY_HANDLE_APPEND_H
#define GAME_ENGINE_HIERARCHY_HANDLE_APPEND_H

// Native Handle/Name partial views; existing caller declarations remain unchanged.
typedef unsigned long u32;
struct Handle_801F7F10 {union{u32 value;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct HierarchyCreatedObject;
struct HierarchyCreateEntry {HierarchyCreatedObject*object;char unknown04[8];signed char generation;char pad[3];};
struct HierarchyCreateManager {int count,capacity;HierarchyCreateEntry*entries;};
struct HierarchyCreateGlobals {char unknown00[0x118];HierarchyCreateManager*manager;};
struct HierarchyCreateName {u32 value;HierarchyCreateName(const char*);};
extern "C" {extern HierarchyCreateGlobals lbl_801E9D24;extern const char lbl_802AECDC[];extern char lbl_8028F698[];u32 fn_801F948C(void*,const char*);signed char fn_801B5230(HierarchyCreateManager*,const HierarchyCreateName&,const HierarchyCreateName&);Handle_801F7F10 fn_801B5408(HierarchyCreateManager*,const HierarchyCreateName&);Handle_801F7F10 fn_801B550C(HierarchyCreateManager*,const HierarchyCreateName&,const HierarchyCreateName&);void fn_801F86C8(HierarchyCreateManager*,const void*,short);void*fn_801F7EB8(const void*);void fn_802072D4(HierarchyCreatedObject*,const HierarchyCreateName&,int);void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);}
inline HierarchyCreateName::HierarchyCreateName(const char*s){value=fn_801F948C(this,s);}
struct HierarchyCreatedHandle:Handle_801F7F10 {
 HierarchyCreatedHandle(){value=0;}
 HierarchyCreatedHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 HierarchyCreatedHandle(const HierarchyCreatedHandle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 HierarchyCreatedHandle&operator=(const HierarchyCreatedHandle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
inline void*operator new(unsigned long,void*p){return p;}
struct HierarchyCreatedArray {int count,capacity;HierarchyCreatedHandle*data;
 void storage(int n){if(n){if(data)data=(HierarchyCreatedHandle*)fn_8028FAF4(lbl_8028F698,data,capacity*4,n*4);else data=(HierarchyCreatedHandle*)fn_8028FF24(lbl_8028F698,n*4);}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}}
 void append(const HierarchyCreatedHandle&h){if(count+1>capacity){storage(capacity+100);capacity+=100;}new(data+count++)HierarchyCreatedHandle(h);}
};
struct HierarchyCreateOwner {char unknown00[0x34];HierarchyCreatedArray children;};
inline HierarchyCreatedObject*resolve(const Handle_801F7F10&h){HierarchyCreateEntry*e=lbl_801E9D24.manager->entries+h.bits.index;return e->generation==h.bits.generation?e->object:0;}

extern "C" {
HierarchyCreatedHandle fn_80260868(HierarchyCreateOwner*, const HierarchyCreateName&, const char*);
HierarchyCreatedHandle fn_80260BA4(HierarchyCreateOwner*, const char*);
}

#endif
