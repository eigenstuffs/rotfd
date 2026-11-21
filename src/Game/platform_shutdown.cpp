#include "Game/platform_cache_internal.h"
struct PlatformResource {virtual ~PlatformResource();};
#include "Game/platform_pool_internal.h"
#include "Game/platform_item_internal.h"
inline Globals& globals(){return lbl_801E9D24;}
extern "C" {
void VISetBlack(int);void VIFlush();void VIWaitForRetrace();void GXDrawDone();void GXAbortFrame();
void fn_801EA0FC(){
 delete globals().cache900;globals().cache900=0;
 delete globals().cache10;globals().cache10=0;
 delete globals().resource;globals().resource=0;
 delete globals().pool;globals().pool=0;
 VISetBlack(1);VIFlush();VIWaitForRetrace();GXDrawDone();GXAbortFrame();
 if(globals().allocation)fn_801EF610(lbl_801EF5C8,globals().allocation);
 globals().allocation=0;
 if(globals().item)delete globals().item;
 globals().item=0;
}
}
