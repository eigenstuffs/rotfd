#ifndef GAME_RENDER_BUFFER_RESOURCE_H
#define GAME_RENDER_BUFFER_RESOURCE_H
#include "Game/engine_spatial_handle_ctor.h"
/* Partial lifetime view. Full original 88-byte dispatch tables remain borrowed. */
extern "C" {
extern const float lbl_8037A468;
void *fn_801EFA1C(const void *,unsigned long,const char *,const char *,int,int);
void *fn_8028FACC(void *,unsigned long);
void fn_8028F8F0(void *,void *,unsigned long);
void fn_801EF610(const void *,void *);
extern const char lbl_801EF5C8[],lbl_802ACF20[],lbl_802AD0C0[];
extern char lbl_8028F698[];
}
struct SpatialRecord_802EA440:SpatialBase_802EC118 {
 unsigned short poolIndex; unsigned short unknown22;
 /* Native slots 4C/50/54 read, set and release poolIndex. The first
  * non-inline virtual declaration belongs to an existing native slot. */
 SpatialRecord_802EA440(); virtual unsigned short slot4C(); virtual void slot50(unsigned short); virtual void slot54(); virtual ~SpatialRecord_802EA440();
 static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct ArrayResource_802EA330:SpatialRecord_802EA440 {
 char unknown24[0x1C];
 /* slot0C forwards the existing stream-address word to the spatial reader. */
 ArrayResource_802EA330(){} virtual void slot0C(unsigned long); virtual ~ArrayResource_802EA330();
};
struct RenderByteStorage {
 void *data; unsigned long allocatedBytes,usedBytes;
 RenderByteStorage(){data=0;allocatedBytes=0;usedBytes=0;}
 ~RenderByteStorage();
};
struct RenderBuffer_8028245C:ArrayResource_802EA330 {
 RenderByteStorage buffer;
 RenderBuffer_8028245C(){buffer.allocatedBytes=160;buffer.data=fn_8028FACC(lbl_8028F698,buffer.allocatedBytes);}
 /* Native slot34 consumes the render input through its second argument. */
 virtual void slot34(void*); virtual ~RenderBuffer_8028245C();
};
typedef char SpatialRecordSizeCheck[(sizeof(SpatialRecord_802EA440)==0x24)?1:-1];
typedef char ArrayResourceSizeCheck[(sizeof(ArrayResource_802EA330)==0x40)?1:-1];
typedef char RenderBufferSizeCheck[(sizeof(RenderBuffer_8028245C)==0x4C)?1:-1];
#endif
