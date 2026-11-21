#ifndef _DOLPHIN_GX_H_
#define _DOLPHIN_GX_H_

// IWYU pragma: begin_exports
#include "GXBump.h"
#include "GXCommandList.h"
#include "GXCpu2Efb.h"
#include "GXCull.h"
#include "GXDispList.h"
#include "GXDraw.h"
#include "GXFifo.h"
#include "GXFrameBuffer.h"
#include "GXGeometry.h"
#include "GXGet.h"
#include "GXLighting.h"
#include "GXManage.h"
#include "GXPerf.h"
#include "GXPixel.h"
#include "GXStruct.h"
#include "GXTev.h"
#include "GXTexture.h"
#include "GXTransform.h"
#include "GXVerify.h"
#include "GXVert.h"
// IWYU pragma: end_exports

// unsorted GX externs

#ifdef __cplusplus
extern "C" {
#endif

// GXMisc
void (*GXSetDrawSyncCallback(void (*cb)(unsigned short)))(unsigned short);
void GXSetDrawSync(unsigned short token);

#ifdef __cplusplus
}
#endif

#endif
