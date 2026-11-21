/* Dolphin SDK SI sampling-rate C unit, GSQE78.
 * Adapted from projectPiki/pikmin2; see reference/pikmin2-sdk/PROVENANCE.md.
 */
#include "../os/OSContext_abi.h"
extern u32 SISetXY(u32, u32), VIGetTvFormat(void);
#define VI_NTSC 0
#define VI_PAL 1
#define VI_MPAL 2
#define VI_EURGB60 5

struct tvformat {
	u16 mTvShort;
	u8 mTvByte;
};

u16 _viRegList : 0xCC00206C;

static u32 SamplingRate;
static struct tvformat XYNTSC[12] = { 0x00F6, 0x02, 0x000F, 0x12, 0x001E, 0x09, 0x002C, 0x06, 0x0034, 0x05, 0x0041, 0x04,
	                                  0x0057, 0x03, 0x0057, 0x03, 0x0057, 0x03, 0x0083, 0x02, 0x0083, 0x02, 0x0083, 0x02 };
static struct tvformat XYPAL[12]  = { 0x0128, 0x02, 0x000F, 0x15, 0x001D, 0x0B, 0x002D, 0x07, 0x0034, 0x06, 0x003F, 0x05,
	                                  0x004E, 0x04, 0x0068, 0x03, 0x0068, 0x03, 0x0068, 0x03, 0x0068, 0x03, 0x009C, 0x02 };


void SISetSamplingRate(u32 msec)
{
	BOOL interruptState;
	u16 viRegList;
	int xScale;
	struct tvformat* format; 

	if (msec > 11) {
		msec = 11;
	}

	interruptState = OSDisableInterrupts();
	SamplingRate   = msec;

	switch (VIGetTvFormat()) {
	case VI_NTSC:
	case VI_MPAL:
	case VI_EURGB60:
		format = XYNTSC;
		break;
	case VI_PAL:
		format = XYPAL;
		break;
	default:
		OSReport("SISetSamplingRate: unknown TV format. Use default.");
		msec   = 0;
		format = XYNTSC;
		break;
	}

	viRegList = (_viRegList);
	if ((viRegList & 1) != 0) {
		xScale = 2;
	} else {
		xScale = 1;
	}

	SISetXY(xScale * format[msec].mTvShort, format[msec].mTvByte);
	OSRestoreInterrupts(interruptState);
}


void SIRefreshSamplingRate(void)
{
	SISetSamplingRate(SamplingRate);
}
