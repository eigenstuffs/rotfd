/* Target GX ABI based on the public Melee SDK reconstruction. */
#ifndef ROTFD_GX_ABI_H
#define ROTFD_GX_ABI_H
#include "gx.h"
#include "vitypes.h"
#define ASSERTMSGLINE(line, condition, message) ((void)0)
#define ASSERTLINE(line, condition) ((void)0)
#define OSPhysicalToUncached(p) ((void *)((u32)(p) + 0xC0000000))
#define OSUncachedToPhysical(p) ((u32)(p) - 0xC0000000)
extern u32 __OSBusClock : 0x800000F8;
extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32), PPCMtwpar(u32);
extern u32 VIGetTvFormat(void);
extern void OSRegisterVersion(const char *);
#include "__gx.h"
#endif
