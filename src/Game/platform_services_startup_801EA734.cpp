/* Platform service allocation and startup; see docs/notes/game-platform-services-startup.md. */
#include "Game/service_interface_tables.h"
typedef unsigned long Word;
struct EmptyService {void* unknown;};
struct WindowPrefix {char unknown00[0x278];};
struct Window:WindowPrefix {virtual void slot08();virtual void open(int,int);};
struct RenderPrefix {char unknown00[0x1C];};
struct Render:RenderPrefix {virtual void start();};
struct AudioPrefix {char unknown00[0x7C];};
struct Audio:AudioPrefix {virtual void slot08();virtual void slot0C();virtual void slot10();virtual void start();};
struct CardPrefix {char unknown00[0x30];};
struct Card:CardPrefix {virtual void start();};
struct CachePrefix{char unknown00[8];};struct CacheDispatch:CachePrefix{virtual void slot08();virtual void start();};
struct Cache {unsigned char state;char unknown01[7];void*table;char unknown0C[0x3C];Word zero48;char unknown4C[0x10];unsigned char flag5C;void start(){((CacheDispatch*)this)->start();}};
struct Arrays {void**table;};
struct Context {char unknown00[0x110];void*logger;Window*window;char unknown118[0x3C];Render*render;Audio*audio;Cache*cache;char unknown160[8];Card*card;char unknown16C[0xC];void*service178;void*service17C;Arrays*arrays;void*pool;char unknown188[4];void*service18C;};
extern "C" {
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[],platform_type_registry_End_Frame_required_a_SoftReset[];
extern void* __vt__23PlatformArrays_802EA874[],*lbl_802F16D0[];
void*fn_801EFA1C(void*,Word,const char*,const char*,int,int);
void*fn_802859F0(void*);void fn_8028581C(void*);Window*fn_80275A44(void*);
void*fn_801EAEBC(void*);void*fn_801EAA94(void*);
void __ct__23PlatformArrays_802EA884Fi(void*,const char*);
void*__ct__21PlatformPool_80281EA4Fv(void*);void fn_80281EA0(void*);
Render*__ct__20InputDevice_8027696CFv(void*);Audio*fn_80287AE0(void*);Card*fn_80279044(void*);
void fn_801FA014(void*,const char*,...);
}
inline void* allocate(const char*pool,Word bytes,int line){return fn_801EFA1C(lbl_801EF5C8,bytes,pool+0x20,pool+0x30,line,4);}
extern "C" void fn_801EA734(){const char*pool=platform_type_registry_End_Frame_required_a_SoftReset;
 void*p=allocate(pool,0xC,0x266);if(p)p=fn_802859F0(p);lbl_801E9D24.service18C=p;fn_8028581C(p);
 p=allocate(pool,0xA20,0x269);if(p)p=fn_80275A44(p);lbl_801E9D24.window=(Window*)p;((Window*)p)->open(640,448);
 p=allocate(pool,0x18,0x26C);if(p)p=fn_801EAEBC(p);lbl_801E9D24.service178=p;
 p=allocate(pool,0x18,0x26D);if(p)p=fn_801EAA94(p);lbl_801E9D24.service17C=p;
 Arrays*arrays=(Arrays*)allocate(pool,0x34,0x26F);if(arrays){__ct__23PlatformArrays_802EA884Fi(arrays,pool+0x40);arrays->table=__vt__23PlatformArrays_802EA874;}lbl_801E9D24.arrays=arrays;
 p=allocate(pool,0x24,0x271);if(p)p=__ct__21PlatformPool_80281EA4Fv(p);lbl_801E9D24.pool=p;fn_80281EA0(p);
 p=allocate(pool,0xEC,0x273);if(p)p=__ct__20InputDevice_8027696CFv(p);lbl_801E9D24.render=(Render*)p;((Render*)p)->start();
 p=allocate(pool,0x5308,0x275);if(p)p=fn_80287AE0(p);lbl_801E9D24.audio=(Audio*)p;((Audio*)p)->start();
 Cache*cache=(Cache*)allocate(pool,0x60,0x277);if(cache){cache->table=&lbl_802EA0F8;cache->state=0;cache->table=lbl_802F16D0;cache->zero48=0;cache->flag5C=0;}lbl_801E9D24.cache=cache;cache->start();
 p=allocate(pool,0x4D8,0x27A);if(p)p=fn_80279044(p);lbl_801E9D24.card=(Card*)p;((Card*)p)->start();
 fn_801FA014(lbl_801E9D24.logger,pool+0x54);
}
