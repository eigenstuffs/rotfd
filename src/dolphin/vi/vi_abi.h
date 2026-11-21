/* Local VI, GX render-mode and SRAM ABI declarations from public Dolphin references. */
#ifndef ROTFD_VI_ABI_H
#define ROTFD_VI_ABI_H
#include "../os/OSContext_abi.h"
typedef signed short s16;
typedef signed long s32;
typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
#define TRUE 1
#define FALSE 0
#define nullptr NULL
#define OSPhysicalToCached(p) ((void *)((u32)(p) + 0x80000000))
typedef struct OSThreadQueue { void *head, *tail; } OSThreadQueue;
typedef struct OSSram { u16 checkSum, checkSumInv; u32 ead0, ead1, counterBias; signed char displayOffsetH; u8 ntd, language, flags; } OSSram;
typedef s16 __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext *);
extern void OSClearContext(OSContext *), OSInitThreadQueue(OSThreadQueue *), OSWakeupThread(OSThreadQueue *), OSSleepThread(OSThreadQueue *);
extern void OSRegisterVersion(const char *), SIRefreshSamplingRate(void);
extern __OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt, __OSInterruptHandler);
extern u32 __OSUnmaskInterrupts(u32);
extern OSSram *__OSLockSram(void);
extern BOOL __OSUnlockSram(BOOL);
extern void OSPanic(const char *, int, const char *, ...);
extern vu16 __VIRegs[59] : 0xCC002000;
// Display pixel size.
#define VI_DISPLAY_PIX_SZ (2)

// Interlacing types
#define VI_INTERLACE     (0)
#define VI_NON_INTERLACE (1)
#define VI_PROGRESSIVE   (2)
#define VI_3D            (3)

// Video output formats
#define VI_NTSC      (0)
#define VI_PAL       (1)
#define VI_MPAL      (2)
#define VI_DEBUG     (3)
#define VI_DEBUG_PAL (4)
#define VI_EURGB60   (5)
#define VI_GCA       (6)

// Conversion to TVMode used in enums
#define VI_TVMODE(FMT, INT) (((FMT) << 2) + (INT))

// Fields
#define VI_FIELD_ABOVE (1)
#define VI_FIELD_BELOW (0)

// Max screen dimensions
// NTSC
#define VI_MAX_WIDTH_NTSC  (720)
#define VI_MAX_HEIGHT_NTSC (480)

// PAL
#define VI_MAX_WIDTH_PAL  (720)
#define VI_MAX_HEIGHT_PAL (574)

// MPAL
#define VI_MAX_WIDTH_MPAL  (720)
#define VI_MAX_HEIGHT_MPAL (480)

// EU RGB60 (same as NTSC)
#define VI_MAX_WIDTH_EURGB60  VI_MAX_WIDTH_NTSC
#define VI_MAX_HEIGHT_EURGB60 VI_MAX_HEIGHT_NTSC

// Conversion to padded FB width from screen width
#define VIPadFrameBufferWidth(width) ((u16)(((u16)(width) + 15) & ~15))

////////////////////////////////////

/////// VIDEO INTERFACE TYPES //////
// Retrace callback function type.
typedef void (*VIRetraceCallback)(u32 retraceCount);

// Position callback function type.
typedef void (*VIPositionCallback)(s16 x, s16 y);

// TV Modes
typedef enum {
	// NTSC
	VI_TVMODE_NTSC_INT  = VI_TVMODE(VI_NTSC, VI_INTERLACE),     // 0
	VI_TVMODE_NTSC_DS   = VI_TVMODE(VI_NTSC, VI_NON_INTERLACE), // 1
	VI_TVMODE_NTSC_PROG = VI_TVMODE(VI_NTSC, VI_PROGRESSIVE),   // 2
	VI_TVMODE_NTSC_3D   = VI_TVMODE(VI_NTSC, VI_3D),            // 3

	// PAL
	VI_TVMODE_PAL_INT = VI_TVMODE(VI_PAL, VI_INTERLACE),     // 4
	VI_TVMODE_PAL_DS  = VI_TVMODE(VI_PAL, VI_NON_INTERLACE), // 5

	// MPAL
	VI_TVMODE_MPAL_INT = VI_TVMODE(VI_MPAL, VI_INTERLACE),     // 8
	VI_TVMODE_MPAL_DS  = VI_TVMODE(VI_MPAL, VI_NON_INTERLACE), // 9

	// Debug
	VI_TVMODE_DEBUG_INT = VI_TVMODE(VI_DEBUG, VI_INTERLACE), // 12

	// Debug PAL
	VI_TVMODE_DEBUG_PAL_INT = VI_TVMODE(VI_DEBUG_PAL, VI_INTERLACE),     // 16
	VI_TVMODE_DEBUG_PAL_DS  = VI_TVMODE(VI_DEBUG_PAL, VI_NON_INTERLACE), // 17

	// EU RGB60
	VI_TVMODE_EURGB60_INT = VI_TVMODE(VI_EURGB60, VI_INTERLACE),     // 20
	VI_TVMODE_EURGB60_DS  = VI_TVMODE(VI_EURGB60, VI_NON_INTERLACE), // 21

	// GCA
	VI_TVMODE_GCA_INT  = VI_TVMODE(VI_GCA, VI_INTERLACE),     // 24
	VI_TVMODE_GCA_DS   = VI_TVMODE(VI_GCA, VI_NON_INTERLACE), // 25
	VI_TVMODE_GCA_PROG = VI_TVMODE(VI_GCA, VI_PROGRESSIVE),   // 26
} VITVMode;

// External frame buffer modes (single and double?)
typedef enum {
	VI_XFBMODE_SF = 0,
	VI_XFBMODE_DF = 1,
} VIXFBMode;

// Structure to use with timing in vi.c (size 0x26).
typedef struct VITimingInfo {
	u8 equ;           // _00
	u16 acv;          // _02
	u16 prbOdd;       // _04
	u16 prbEven;      // _06
	u16 psbOdd;       // _08
	u16 psbEven;      // _0A
	u8 bs1;           // _0C
	u8 bs2;           // _0D
	u8 bs3;           // _0E
	u8 bs4;           // _0F
	u16 be1;          // _10
	u16 be2;          // _12
	u16 be3;          // _14
	u16 be4;          // _16
	u16 numHalfLines; // _18
	u16 hlw;          // _1A
	u8 hsy;           // _1C
	u8 hcs;           // _1D
	u8 hce;           // _1E
	u8 hbe640;        // _1F
	u16 hbs640;       // _20
	u8 hbeCCIR656;    // _22
	u16 hbsCCIR656;   // _24
} VITimingInfo;

// Structure to use with HorVer in vi.c (size 0x58).
typedef struct VIPositionInfo {
	u16 dispPosX;         // _00
	u16 dispPosY;         // _02
	u16 dispSizeX;        // _04
	u16 dispSizeY;        // _06
	u16 adjDispPosX;      // _08
	u16 adjDispPosY;      // _0A
	u16 adjDispSizeY;     // _0C
	u16 adjPanPosY;       // _0E
	u16 adjPanSizeY;      // _10
	u16 fbSizeX;          // _12
	u16 fbSizeY;          // _14
	u16 panPosX;          // _16
	u16 panPosY;          // _18
	u16 panSizeX;         // _1A
	u16 panSizeY;         // _1C
	VIXFBMode xfbMode;    // _20
	u32 nonInter;         // _24
	u32 tv;               // _28
	u8 wordPerLine;       // _2C
	u8 std;               // _2D
	u8 wpl;               // _2E
	u32 bufAddr;          // _30
	u32 tfbb;             // _34
	u32 bfbb;             // _38
	u8 xof;               // _3C
	BOOL isBlack;         // _40
	BOOL is3D;            // _44
	u32 rbufAddr;         // _48
	u32 rtfbb;            // _4C
	u32 rbfbb;            // _50
	VITimingInfo* timing; // _54
} VIPositionInfo;


typedef struct _GXRenderModeObj {
	VITVMode viTVmode;        // _00
	u16 fbWidth;              // _04, frame buffer width (same for emb. and ext.)
	u16 efbHeight;            // _06, embedded frame buffer height
	u16 xfbHeight;            // _08, external frame buffer height (may scale emb.)
	u16 viXOrigin;            // _0A
	u16 viYOrigin;            // _0C
	u16 viWidth;              // _0E
	u16 viHeight;             // _10
	VIXFBMode xFBmode;        // _14, single or double field for external frame buffer
	u8 field_rendering;       // _18, rendering fields/frames
	u8 aa;                    // _19, is anti-aliasing on
	u8 sample_pattern[12][2]; // _1C, anti-aliasing sample pattern
	u8 vfilter[7];            // _34, vertical filter coeffs
} GXRenderModeObj;
#define VI_VERT_TIMING        (0)
#define VI_DISP_CONFIG        (1)
#define VI_HORIZ_TIMING_0L    (2)
#define VI_HORIZ_TIMING_0U    (3)
#define VI_HORIZ_TIMING_1L    (4)
#define VI_HORIZ_TIMING_1U    (5)
#define VI_VERT_TIMING_ODD    (6)
#define VI_VERT_TIMING_ODD_U  (7)
#define VI_VERT_TIMING_EVEN   (8)
#define VI_VERT_TIMING_EVEN_U (9)
#define VI_BBI_ODD    (10) // burst blanking interval
#define VI_BBI_ODD_U  (11) // burst blanking interval
#define VI_BBI_EVEN   (12) // burst blanking interval
#define VI_BBI_EVEN_U (13) // burst blanking interval
#define VI_TOP_FIELD_BASE_LEFT   (14) // top in 2d, top of left pic in 3d
#define VI_TOP_FIELD_BASE_LEFT_U (15) // top in 2d, top of left pic in 3d
#define VI_TOP_FIELD_BASE_RIGHT   (16) // top of right pic in 3d
#define VI_TOP_FIELD_BASE_RIGHT_U (17) // top of right pic in 3d
#define VI_BTTM_FIELD_BASE_LEFT   (18) // bottom in 2d, bottom of left pic in 3d
#define VI_BTTM_FIELD_BASE_LEFT_U (19) // bottom in 2d, bottom of left pic in 3d
#define VI_BTTM_FIELD_BASE_RIGHT   (20) // bottom of right pic in 3d
#define VI_BTTM_FIELD_BASE_RIGHT_U (21) // bottom of right pic in 3d
#define VI_VERT_COUNT  (22) // vertical display position
#define VI_HORIZ_COUNT (23) // horizontal display position
#define VI_DISP_INT_0  (24) // display interrupt 0L
#define VI_DISP_INT_0U (25) // display interrupt 0U
#define VI_DISP_INT_1  (26) // display interrupt 1L
#define VI_DISP_INT_1U (27) // display interrupt 1U
#define VI_DISP_INT_2  (28) // display interrupt 2L
#define VI_DISP_INT_2U (29) // display interrupt 2U
#define VI_DISP_INT_3  (30) // display interrupt 3L
#define VI_DISP_INT_3U (31) // display interrupt 3U
#define VI_HSW (36) // horizontal scaling width
#define VI_HSR (37) // horizontal scaling register
#define VI_FCT_0  (38) // filter coefficient table 0L
#define VI_FCT_0U (39) // filter coefficient table 0U
#define VI_FCT_1  (40) // filter coefficient table 1L
#define VI_FCT_1U (41) // filter coefficient table 1U
#define VI_FCT_2  (42) // filter coefficient table 2L
#define VI_FCT_2U (43) // filter coefficient table 2U
#define VI_FCT_3  (44) // filter coefficient table 3L
#define VI_FCT_3U (45) // filter coefficient table 3U
#define VI_FCT_4  (46) // filter coefficient table 4L
#define VI_FCT_4U (47) // filter coefficient table 4U
#define VI_FCT_5  (48) // filter coefficient table 5L
#define VI_FCT_5U (49) // filter coefficient table 5U
#define VI_FCT_6  (50) // filter coefficient table 6L
#define VI_FCT_6U (51) // filter coefficient table 6U
#define VI_CLOCK_SEL (54) // clock select
#define VI_DTV_STAT  (55) // DTV status
#define VI_WIDTH (56)
#endif
