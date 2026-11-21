#ifndef ROTFD_MENU3D_LIFECYCLE_INTERNAL_H
#define ROTFD_MENU3D_LIFECYCLE_INTERNAL_H

// Observed Menu3D storage, native handles, and trivial-element list layout.
#include "menu_base_internal.h"
extern "C" {
extern char lbl_801EF5C8[],lbl_8028F698[],__vt__15Menu3D_802193C0[];
void fn_801EF610(void*,void*);
void fn_8028FD50(void*,void*,u32);
}
struct HandleLayer1:Handle_801F7F10 {HandleLayer1(){value=0;}~HandleLayer1(){}};
struct HandleLayer2:HandleLayer1 {HandleLayer2(){value=0;}~HandleLayer2(){}};
struct Element {char unknown[0xBC];~Element(){}};
struct Elements {
 int count,capacity;Element*data;
 void releaseStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Element));data=0;}}
 ~Elements(){if(data){for(int i=0;i<count;i++)data[i].~Element();releaseStorage();data=0;}}
};
struct Menu3D_802193C0:MenuBase_8021D7E4 {
 HandleLayer2 handle4C;char unknown50[0x18];Elements elements;HandleLayer2 handle74;float pulse;char unknown7C[0x44];
 ~Menu3D_802193C0();
 static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct Manager;
struct RenderSlot { char unknown[0x4C]; };
struct Globals { char unknown[0x114]; RenderSlot* renderSlots; Manager* manager; };
extern "C" Globals lbl_801E9D24;
extern "C" void fn_801F86C8(Manager*,const void*,short);
struct Menu3DHandle : HandleLayer2 {
 Menu3DHandle(const Handle_801F7F10& h) {value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Menu3DHandle(){}
};
typedef char CheckMenuBaseSize[sizeof(MenuBase_8021D7E4)==0x4C?1:-1];
typedef char CheckMenuSize[sizeof(Menu3D_802193C0)==0xC0?1:-1];
typedef char CheckElementSize[sizeof(Element)==0xBC?1:-1];

#endif
