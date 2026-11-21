/* Dolphin SDK OS.c C reconstruction, GSQE78.
 * Adapted from pinned PrimeDecomp/prime SDK source; see reference/prime-sdk/PROVENANCE.md.
 * Native exception and CPU instruction routines remain original fallback.
 */
#include "OS_abi.h"
extern OSTime __OSGetSystemTime();
static const char* __OSVersion =
    "<< Dolphin SDK - OS\trelease build: Nov  5 2002 12:52:29 (0x2301) >>";

extern char _stack_addr[];

#define OS_BI2_DEBUG_ADDRESS 0x800000F4
#define DEBUGFLAG_ADDR 0x800030E8
#define OS_DEBUG_ADDRESS_2 0x800030E9

extern void __OSResetSWInterruptHandler(int, OSContext*);

vu16 __OSDeviceCode : (OS_BASE_CACHED | 0x30E6);
static DVDDriveInfo DriveInfo ATTRIBUTE_ALIGN(32);
static DVDCommandBlock DriveBlock;

static OSBootInfo* BootInfo;
static u32* BI2DebugFlag;
static u32* BI2DebugFlagHolder;
__declspec(weak) BOOL __OSIsGcam = FALSE;
static BOOL AreWeInitialized = FALSE;
extern __OSExceptionHandler* OSExceptionTable;
OSTime __OSStartTime;
BOOL __OSInIPL;

extern u8 __ArenaHi[];
extern u8 __ArenaLo[];
extern u32 __DVDLongFileNameFlag;
extern u32 __PADSpec;

#define OS_EXCEPTIONTABLE_ADDR 0x3000
#define OS_DBJUMPPOINT_ADDR 0x60


void OSDefaultExceptionHandler(__OSException exception, OSContext* context);
extern BOOL __DBIsExceptionMarked(__OSException);
static void OSExceptionInit(void);

u32 OSGetConsoleType() {
  if (BootInfo == NULL || BootInfo->consoleType == 0) {
    return OS_CONSOLE_ARTHUR;
  }
  return BootInfo->consoleType;
}

void* __OSSavedRegionStart;
void* __OSSavedRegionEnd;
/* Originally static; exported only to the separate handler C fragment. */
__OSExceptionHandler* OSExceptionTable;

extern u32 BOOT_REGION_START : 0x812FDFF0; 
extern u32 BOOT_REGION_END : 0x812FDFEC;   

static void ClearArena(void) {
  if ((u32)(OSGetResetCode() + 0x80000000) != 0U) {
    __OSSavedRegionStart = 0U;
    __OSSavedRegionEnd = 0U;
    memset(OSGetArenaLo(), 0U, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
    return;
  }
  __OSSavedRegionStart = (void*)BOOT_REGION_START;
  __OSSavedRegionEnd = (void*)BOOT_REGION_END;
  if (BOOT_REGION_START == 0U) {
    memset(OSGetArenaLo(), 0U, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
    return;
  }

  if ((u32)OSGetArenaLo() < (u32)__OSSavedRegionStart) {
    if ((u32)OSGetArenaHi() <= (u32)__OSSavedRegionStart) {
      memset(OSGetArenaLo(), 0U, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
      return;
    }
    memset(OSGetArenaLo(), 0U, (u32)__OSSavedRegionStart - (u32)OSGetArenaLo());
    if ((u32)OSGetArenaHi() > (u32)__OSSavedRegionEnd) {
      memset(__OSSavedRegionEnd, 0, (u32)OSGetArenaHi() - (u32)__OSSavedRegionEnd);
    }
  }
}

static void InquiryCallback(s32 result, DVDCommandBlock* block) {
  switch (block->state) {
  case 0:
    __OSDeviceCode = (u16)(0x8000 | DriveInfo.deviceCode);
    break;
  default:
    __OSDeviceCode = 1;
    break;
  }
}

void OSInit(void) {

  BI2Debug* DebugInfo;
  void* debugArenaLo;
  u32 inputConsoleType;
  u32 tdev;

  if ((BOOL)AreWeInitialized == FALSE) { 
    AreWeInitialized = TRUE;             

    __OSStartTime = __OSGetSystemTime();
    OSDisableInterrupts();

    PPCDisableSpeculation();
    PPCSetFpNonIEEEMode();

    BI2DebugFlag = 0;                       
    BootInfo = (OSBootInfo*)OS_BASE_CACHED; 

    __DVDLongFileNameFlag = (u32)0; 

    DebugInfo = (BI2Debug*)*((u32*)OS_BI2_DEBUG_ADDRESS);

    if (DebugInfo != NULL) {
      BI2DebugFlag = &DebugInfo->debugFlag;              
      __PADSpec = (u32)DebugInfo->padSpec;               
      *((u8*)DEBUGFLAG_ADDR) = (u8)*BI2DebugFlag;        
      *((u8*)OS_DEBUG_ADDRESS_2) = (u8)__PADSpec;        
    } else if (BootInfo->arenaHi) {                      
      BI2DebugFlagHolder = (u32*)*((u8*)DEBUGFLAG_ADDR); 
      BI2DebugFlag = (u32*)&BI2DebugFlagHolder;          
      __PADSpec = (u32) * ((u8*)OS_DEBUG_ADDRESS_2);     
    }

    __DVDLongFileNameFlag = 1; 

    OSSetArenaLo((BootInfo->arenaLo == NULL) ? __ArenaLo : BootInfo->arenaLo);

    if ((BootInfo->arenaLo == NULL) && (BI2DebugFlag != 0) && (*BI2DebugFlag < 2)) {
      debugArenaLo = (char*)(((u32)_stack_addr + 0x1f) & ~0x1f);
      OSSetArenaLo(debugArenaLo);
    }

    OSSetArenaHi((BootInfo->arenaHi == NULL) ? __ArenaHi : BootInfo->arenaHi);

    OSExceptionInit();
    __OSInitSystemCall();
    OSInitAlarm();
    __OSModuleInit();
    __OSInterruptInit();
    __OSSetInterruptHandler(__OS_INTERRUPT_PI_RSW, (void*)__OSResetSWInterruptHandler);
    __OSContextInit();
    __OSCacheInit();
    EXIInit();
    SIInit();
    __OSInitSram();
    __OSThreadInit();
    __OSInitAudioSystem();
    PPCMthid2(PPCMfhid2() & 0xBFFFFFFF);
    if ((BOOL)__OSInIPL == FALSE) {
      __OSInitMemoryProtection();
    }

    OSReport("\nDolphin OS $Revision: 60 $.\n");
    OSReport("Kernel built : %s %s\n", "Nov  5 2002", "12:52:29");

    OSReport("Console Type : ");

    if (BootInfo == NULL || (inputConsoleType = BootInfo->consoleType) == 0) {
      inputConsoleType = OS_CONSOLE_ARTHUR; 
    } else {
      inputConsoleType = BootInfo->consoleType;
    }

    switch (inputConsoleType & 0xffff0000) { 
    case OS_CONSOLE_RETAIL:
      OSReport("Retail %d\n", inputConsoleType);
      break;
    default:
      switch (inputConsoleType & 0x0000ffff) { 
      case OS_CONSOLE_EMULATOR:
        OSReport("Mac Emulator\n");
        break;
      case OS_CONSOLE_PC_EMULATOR:
        OSReport("PC Emulator\n");
        break;
      case OS_CONSOLE_ARTHUR:
        OSReport("EPPC Arthur\n");
        break;
      case OS_CONSOLE_MINNOW:
        OSReport("EPPC Minnow\n");
        break;
      default:
        tdev = ((u32)inputConsoleType & 0x0000ffff);
        OSReport("Development HW%d (%08x)\n", tdev - 3, inputConsoleType);
        break;
      }
      break;
    }

    OSReport("Memory %d MB\n", (u32)BootInfo->memorySize >> 0x14U);
    
    OSReport("Arena : 0x%x - 0x%x\n", OSGetArenaLo(), OSGetArenaHi());
    
    OSRegisterVersion(__OSVersion);

    if (BI2DebugFlag && ((*BI2DebugFlag) >= 2)) {
      EnableMetroTRKInterrupts();
    }

    ClearArena();
    OSEnableInterrupts();

    if ((BOOL)__OSInIPL == FALSE) {
      DVDInit();
      if ((BOOL)__OSIsGcam) {
        __OSDeviceCode = 0x9000;
        return;
      }
      DCInvalidateRange(&DriveInfo, sizeof(DriveInfo));
      DVDInquiryAsync((char*)&DriveBlock, &DriveInfo, InquiryCallback);
    }
  }
}
static u32 __OSExceptionLocations[] = {
    0x00000100, 0x00000200, 0x00000300, 0x00000400, 0x00000500, 0x00000600, 0x00000700, 0x00000800,
    0x00000900, 0x00000C00, 0x00000D00, 0x00000F00, 0x00001300, 0x00001400, 0x00001700,
};

void __OSEVStart(void);
void __OSEVEnd(void);
void __OSEVSetNumber(void);
void __OSExceptionVector(void);

void __DBVECTOR(void);
void __OSDBINTSTART(void);
void __OSDBINTEND(void);
void __OSDBJUMPSTART(void);
void __OSDBJUMPEND(void);

#define NOP 0x60000000

__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler);

static void OSExceptionInit(void) {
  __OSException exception;
  void* destAddr;

  u32* opCodeAddr;
  u32 oldOpCode;

  u8* handlerStart;
  u32 handlerSize;

  opCodeAddr = (u32*)__OSEVSetNumber;
  oldOpCode = *opCodeAddr;
  handlerStart = (u8*)__OSEVStart;
  handlerSize = (u32)((u8*)__OSEVEnd - (u8*)__OSEVStart);

  destAddr = (void*)OSPhysicalToCached(OS_DBJUMPPOINT_ADDR);
  if (*(u32*)destAddr == 0) 
  {
    DBPrintf("Installing OSDBIntegrator\n");
    memcpy(destAddr, (void*)__OSDBINTSTART, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
    DCFlushRangeNoSync(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
    __sync();
    ICInvalidateRange(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
  }

  for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
    if (BI2DebugFlag && (*BI2DebugFlag >= 2) && __DBIsExceptionMarked(exception)) {
      
      DBPrintf(">>> OSINIT: exception %d commandeered by TRK\n", exception);
      continue;
    }

    *opCodeAddr = oldOpCode | exception;

    if (__DBIsExceptionMarked(exception)) {
      DBPrintf(">>> OSINIT: exception %d vectored to debugger\n", exception);
      memcpy((void*)__DBVECTOR, (void*)__OSDBJUMPSTART, (u32)__OSDBJUMPEND - (u32)__OSDBJUMPSTART);
    } else {
      
      u32* ops = (u32*)__DBVECTOR;
      int cb;

      for (cb = 0; cb < (u32)__OSDBJUMPEND - (u32)__OSDBJUMPSTART; cb += sizeof(u32)) {
        *ops++ = NOP;
      }
    }

    destAddr = (void*)OSPhysicalToCached(__OSExceptionLocations[(u32)exception]);
    memcpy(destAddr, handlerStart, handlerSize);
    DCFlushRangeNoSync(destAddr, handlerSize);
    __sync();
    ICInvalidateRange(destAddr, handlerSize);
  }

  OSExceptionTable = OSPhysicalToCached(OS_EXCEPTIONTABLE_ADDR);

  for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
    __OSSetExceptionHandler(exception, OSDefaultExceptionHandler);
  }

  *opCodeAddr = oldOpCode;

  DBPrintf("Exceptions initialized...\n");
}

/* Shared with the trailing OSRegisterVersion C fragment. */
__declspec(section ".sdata") char OSVersionFormat[] = "%s\n";
