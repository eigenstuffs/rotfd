// The accepted destructor801E1870 destroys seven0x4Cviewport records.
#include "Game/owner_viewport_interface_tables.h"
struct ViewportUpdateHandle { union { unsigned long word; struct { signed int tag:8,index:24; } bits; }; void*resolve()const; };
struct ViewportUpdateEntry {void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ViewportUpdateManager {char unknown00[8];ViewportUpdateEntry*entries;};
struct ViewportUpdateContext {char unknown00[0x118];ViewportUpdateManager*manager;};
extern "C"ViewportUpdateContext lbl_801E9D24;
inline void*ViewportUpdateHandle::resolve()const{int index=bits.index;ViewportUpdateManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==bits.tag?m->entries[index].object:0;}
struct ViewportUpdateView {char unknown00[0x10];ViewportUpdateHandle handle;char unknown14[0x38];};
struct Viewports_801E1378 {ViewportUpdateView views[7];signed char count;ViewportUpdateView&get(int i){return views[i];}};
extern "C"void fn_801E81AC(void*);
extern "C"void fn_801E1378(Viewports_801E1378*self){for(int i=0;i<self->count;++i){ViewportUpdateHandle&handle=self->views[i].handle;void*object=handle.resolve();if(object)fn_801E81AC(object);}}
