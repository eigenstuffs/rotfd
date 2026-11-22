#include "OSContext_abi.h"
typedef signed long s32;
typedef signed long long OSTime;
#define TRUE 1
#define FALSE 0
#define nullptr NULL
#define AT_ADDRESS(address) : address
#define ATTRIBUTE_ALIGN(n) __attribute__((aligned(n)))
#define OS_BOOTROM_ADDR 0x81300000
#define OSRoundUp32B(n) (((u32)(n) + 31) & ~31)
u32 __OSBusClock : 0x800000F8;
#define OS_TIMER_CLOCK (__OSBusClock / 4)
extern BOOL __OSIsGcam;
extern void OSRebootRun(u32);
extern void __OSDoHotReset(s32);
extern void OSClearContext(OSContext *);
extern void DVDInit(void), DVDResume(void), ICFlashInvalidate(void);
extern BOOL DVDSetAutoInvalidation(BOOL), DVDCheckDisk(void);
extern BOOL OSEnableInterrupts(void);
extern u32 __OSMaskInterrupts(u32), __OSUnmaskInterrupts(u32);
extern OSTime OSGetTime(void);
extern void AISetStreamVolLeft(u8), AISetStreamVolRight(u8), AISetStreamPlayState(u32);
extern void ICInvalidateRange(void *, u32);
typedef struct DVDCommandBlock DVDCommandBlock;
typedef void (*DVDCBCallback)(s32, DVDCommandBlock *);
typedef struct DVDDiskID {
	char gameName[4]; // _00
	char company[2];  // _04
	u8 diskNumber;    // _06
	u8 gameVersion;   // _07
	u8 streaming;     // _08
	u8 streamBufSize; // _09, default = 0
	u8 padding[22];   // _0A, all 0s
} DVDDiskID;

// Struct for command information (size 0x30).
struct DVDCommandBlock {
	DVDCommandBlock* next;  // _00
	DVDCommandBlock* prev;  // _04
	u32 command;            // _08
	s32 state;              // _0C
	u32 offset;             // _10
	u32 length;             // _14
	void* addr;             // _18
	u32 currTransferSize;   // _1C
	u32 transferredSize;    // _20
	DVDDiskID* id;          // _24
	DVDCBCallback callback; // _28
	void* userData;         // _2C
};

extern DVDDiskID *DVDGetCurrentDiskID(void);
extern BOOL DVDCancelStreamAsync(DVDCommandBlock *, DVDCBCallback);
extern s32 DVDGetCommandBlockStatus(const DVDCommandBlock *);
extern BOOL DVDReadAbsAsyncPrio(DVDCommandBlock *, void *, s32, s32, DVDCBCallback, s32);
extern void __DVDPrepareResetAsync(void (*)(void));
extern u32 UNK_817FFFF8 : 0x817FFFF8;
extern u32 UNK_817FFFFC : 0x817FFFFC;

static void* SaveStart = nullptr;
static void* SaveEnd   = nullptr;
static BOOL Prepared;

extern u32 BOOT_REGION_START AT_ADDRESS(0x812FDFF0); //(*(u32 *)0x812fdff0)
extern u32 BOOT_REGION_END AT_ADDRESS(0x812FDFEC);   //(*(u32 *)0x812fdfec)
extern u8 OS_REBOOT_BOOL AT_ADDRESS(0x800030E2); // unknown function, set to true by __OSReboot


// Struct for Apploader header (size 0x20).
typedef struct _ApploaderHeader {
	char date[16];  // _00
	u32 entry;      // _10
	u32 size;       // _14
	u32 rebootSize; // _18
	u32 reserved2;  // _1C
} ApploaderHeader;

static ApploaderHeader Header ATTRIBUTE_ALIGN(32);


static inline BOOL IsStreamEnabled(void)
{
	if (DVDGetCurrentDiskID()->streaming) {
		return TRUE;
	}
	return FALSE;
}


static inline void ReadApploader(OSTime time1)
{
	if (!DVDCheckDisk() || OSGetTime() - time1 > OS_TIMER_CLOCK) {
		__OSDoHotReset(UNK_817FFFFC);
	}
}


static void Callback(void)
{
	Prepared = TRUE;
}


void __OSReboot(u32 resetCode, u32 bootDol)
{
	OSContext exceptionContext;
	OSTime time1;
	DVDCommandBlock dvdCmd;
	DVDCommandBlock dvdCmd2;
	DVDCommandBlock dvdCmd3;
	u32 numBytes;
	u32 offset;
	OSDisableInterrupts();
	UNK_817FFFFC = 0;
	UNK_817FFFF8 = 0;
	OS_REBOOT_BOOL    = TRUE;
	BOOT_REGION_START = (u32)SaveStart;
	BOOT_REGION_END   = (u32)SaveEnd;
	OSClearContext(&exceptionContext);
	OSSetCurrentContext(&exceptionContext);
	DVDInit();
	DVDSetAutoInvalidation(TRUE);
	DVDResume();

	Prepared = FALSE;
	__DVDPrepareResetAsync(Callback);

	__OSMaskInterrupts(0xffffffe0);
	__OSUnmaskInterrupts(0x400);
	OSEnableInterrupts();

	time1 = OSGetTime();
	while (Prepared != TRUE) {
		ReadApploader(time1);
	};

	if (!__OSIsGcam) {
		if (IsStreamEnabled()) {
			AISetStreamVolLeft(0);
			AISetStreamVolRight(0);
			DVDCancelStreamAsync(&dvdCmd, nullptr);
			time1 = OSGetTime();
			while (DVDGetCommandBlockStatus(&dvdCmd)) {
				ReadApploader(time1);
			}

			AISetStreamPlayState(0);
		}
	}

	DVDReadAbsAsyncPrio(&dvdCmd2, Header.date, 32, 0x2440, nullptr, 0);

	time1 = OSGetTime();
	while (DVDGetCommandBlockStatus(&dvdCmd2)) {
		ReadApploader(time1);
	}

	offset   = Header.size + 0x20;
	numBytes = OSRoundUp32B(Header.rebootSize);
	DVDReadAbsAsyncPrio(&dvdCmd3, (void*)(OS_BOOTROM_ADDR), numBytes, offset + 0x2440, nullptr, 0);

	time1 = OSGetTime();
	while (DVDGetCommandBlockStatus(&dvdCmd3)) {
		ReadApploader(time1);
	}

	ICInvalidateRange((void*)(OS_BOOTROM_ADDR), numBytes);
	OSDisableInterrupts();
	ICFlashInvalidate();
	OSRebootRun(OS_BOOTROM_ADDR);
}


void OSSetSaveRegion(void* start, void* end)
{
	SaveStart = start;
	SaveEnd   = end;
}


