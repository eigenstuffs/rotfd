/* MetroTRK target-state ABI, from source references and original accesses. */
#ifndef ROTFD_TRK_TARGIMPL_ABI_H
#define ROTFD_TRK_TARGIMPL_ABI_H
#include "msghndlr_abi.h"
typedef unsigned char u128[16];


/*
 *    Default register block (all registers typically requested by debugger)
 */

typedef u32 DefaultType;
typedef u32 Extended1Type;
typedef u64 FloatType;
typedef FloatType FPType; /* TRK core calls it FPType */

typedef struct Default_PPC {
    /* 0x00 */ DefaultType GPR[32];
    /* 0x80 */ DefaultType PC;
    /* 0x84 */ DefaultType LR;
    /* 0x88 */ DefaultType CR;
    /* 0x8C */ DefaultType CTR;
    /* 0x90 */ DefaultType XER;
} Default_PPC; // size = 0x94

/*
** Register indices
*/
#define TRK_DEFAULT_GPR(x) (x)
#define TRK_DEFAULT_PC 32
#define TRK_DEFAULT_LR 33
#define TRK_DEFAULT_CR 34
#define TRK_DEFAULT_CTR 35
#define TRK_DEFAULT_XER 36

#define TRK_DEFAULT_MIN_REGISTER 0
#define TRK_DEFAULT_MAX_REGISTER                                              \
    (sizeof(Default_PPC) / sizeof(DefaultType) - 1)

#define TRK_DEFAULT_SIZE (sizeof(DefaultType))

typedef struct Float_PPC {
    /* 0x000 */ FloatType FPR[32];
    /* 0x100 */ FloatType FPSCR;
    /* 0x108 */ FloatType FPECR;
} Float_PPC; // size = 0x110

/*
** Register indices
*/
#define TRK_FLOAT_FPR(x) (x)
#define TRK_FLOAT_FPSCR 32
#define TRK_FLOAT_FPECR 33

#define TRK_FLOAT_MIN_REGISTER 0
#define TRK_FLOAT_MAX_REGISTER (sizeof(Float_PPC) / sizeof(FloatType) - 1)

#define TRK_FLOAT_SIZE (sizeof(FloatType))

/*
 * Info stored in NotifyStopped message.
 */

typedef DefaultType PCType;
typedef u32 InstructionType;
typedef u16 ExceptionCauseType;

typedef struct StopInfo_PPC {
    /* 0x00 */ PCType PC;
    /* 0x04 */ InstructionType PCInstruction;
    /* 0x08 */ ExceptionCauseType exceptionID;
} StopInfo_PPC; // size = 0x0C

//
/// Info stored in NotifyException message.
//

typedef StopInfo_PPC ExceptionInfo_PPC;

/*
** Info used by breakpoint code to restore (unset)
** breakpoints.  For software breakpoints it is just
** the saved instruction.
*/

typedef InstructionType BreakpointRestore;

#define TRK_EXTENDED2_SIZE (sizeof(Extended2Type))

/// Special purpose registers
#define SPR_XER 1

#define SPR_LR 8
#define SPR_CTR 9

#define SPR_DSISR 18
#define SPR_DAR 19

#define SPR_DEC 22

#define SPR_SDR1 25
#define SPR_SRR0 26
#define SPR_SRR1 27

#define TBR_TBL_READ 268
#define TBR_TBU_READ 269

#define SPR_SPRG0 272
#define SPR_SPRG1 273
#define SPR_SPRG2 274
#define SPR_SPRG3 275

#define SPR_EAR 282

#define TBR_TBL_WRITE 284
#define TBR_TBU_WRITE 285

#define SPR_PVR 287

#define SPR_IBAT0U 528
#define SPR_IBAT0L 529
#define SPR_IBAT1U 530
#define SPR_IBAT1L 531
#define SPR_IBAT2U 532
#define SPR_IBAT2L 533
#define SPR_IBAT3U 534
#define SPR_IBAT3L 535

#define SPR_DBAT0U 536
#define SPR_DBAT0L 537
#define SPR_DBAT1U 538
#define SPR_DBAT1L 539
#define SPR_DBAT2U 540
#define SPR_DBAT2L 541
#define SPR_DBAT3U 542
#define SPR_DBAT3L 543

#define SPR_IBAT4U 560
#define SPR_IBAT4L 561
#define SPR_IBAT5U 562
#define SPR_IBAT5L 563
#define SPR_IBAT6U 564
#define SPR_IBAT6L 565
#define SPR_IBAT7U 566
#define SPR_IBAT7L 567

#define SPR_DBAT4U 568
#define SPR_DBAT4L 569
#define SPR_DBAT5U 570
#define SPR_DBAT5L 571
#define SPR_DBAT6U 572
#define SPR_DBAT6L 573
#define SPR_DBAT7U 574
#define SPR_DBAT7L 575

#define SPR_GQR0 912
#define SPR_GQR1 913
#define SPR_GQR2 914
#define SPR_GQR3 915
#define SPR_GQR4 916
#define SPR_GQR5 917
#define SPR_GQR6 918
#define SPR_GQR7 919

#define SPR_HID2 920
#define SPR_WPAR 921
#define SPR_DMAU 922
#define SPR_DMAL 923

#define SPR_UMMCR0 936
#define SPR_UPMC1 937
#define SPR_UPMC2 938
#define SPR_USIA 939
#define SPR_UMMCR1 940
#define SPR_UPMC3 941
#define SPR_UPMC4 942
#define SPR_USDA 943

#define SPR_MMCR2 944
#define SPR_BAMR 951

#define SPR_MMCR0 952
#define SPR_PMC1 953
#define SPR_PMC2 954
#define SPR_SIA 955
#define SPR_MMCR1 956
#define SPR_PMC3 957
#define SPR_PMC4 958
#define SPR_SDA 959

#define SPR_DMISS 976
#define SPR_DCMP 977
#define SPR_HASH1 978
#define SPR_HASH2 979
#define SPR_IMISS 980
#define SPR_ICMP 981
#define SPR_RPA 982

#define SPR_HID0 1008
#define SPR_HID1 1009
#define SPR_IABR 1010
#define SPR_HID4 1011
#define SPR_TDCL 1012
#define SPR_DABR 1013

#define SPR_MSSCR0 1014
#define SPR_MSSCR1 1015

#define SPR_L2CR 1017
#define SPR_TDCH 1018
#define SPR_ICTC 1019

#define SPR_THRM1 1020
#define SPR_THRM2 1021
#define SPR_THRM3 1022

#define SPR_FPECR 1022

#define SPR_PIR 1023

/// MSR Register bits
#define COND_EQ 2
#define MSR_SE 0x0400 /* SE bit of MSR (bit 21) */
#define MSR_EE 0x8000 /* EE bit of MSR (bit 16) */
#define MSR_RI 0x0002 /* RI bit of MSR (bit 30) */
#define MSR_DR 0x0010 /* DR bit of MSR (bit 27) */
#define MSR_IR 0x0020 /* IR bit of MSR (bit 26) */
#define MSR_FP 0x2000 /* FP bit of MSR (bit 18) */
#define MSR_VEC 0x02000000 /* VEC bit of MSR (bit 6) */ /* AltiVec support */





typedef struct Extended1_PPC_6xx_7xx {
    /* 0x000 */ u32 SR[16];
    /* 0x040 */ u32 TBL;
    /* 0x044 */ u32 TBU;
    /* 0x048 */ u32 HID0;
    /* 0x04C */ u32 HID1;
    /* 0x050 */ u32 MSR;
    /* 0x054 */ u32 PVR;
    /* 0x058 */ u32 IBAT0U;
    /* 0x05C */ u32 IBAT0L;
    /* 0x060 */ u32 IBAT1U;
    /* 0x064 */ u32 IBAT1L;
    /* 0x068 */ u32 IBAT2U;
    /* 0x06C */ u32 IBAT2L;
    /* 0x070 */ u32 IBAT3U;
    /* 0x074 */ u32 IBAT3L;
    /* 0x078 */ u32 DBAT0U;
    /* 0x07C */ u32 DBAT0L;
    /* 0x080 */ u32 DBAT1U;
    /* 0x084 */ u32 DBAT1L;
    /* 0x088 */ u32 DBAT2U;
    /* 0x08C */ u32 DBAT2L;
    /* 0x090 */ u32 DBAT3U;
    /* 0x094 */ u32 DBAT3L;
    /* 0x098 */ u32 DMISS;
    /* 0x09C */ u32 DCMP;
    /* 0x0A0 */ u32 HASH1;
    /* 0x0A4 */ u32 HASH2;
    /* 0x0A8 */ u32 IMISS;
    /* 0x0AC */ u32 ICMP;
    /* 0x0B0 */ u32 RPA;
    /* 0x0B4 */ u32 SDR1;
    /* 0x0B8 */ u32 DAR;
    /* 0x0BC */ u32 DSISR;
    /* 0x0C0 */ u32 SPRG0;
    /* 0x0C4 */ u32 SPRG1;
    /* 0x0C8 */ u32 SPRG2;
    /* 0x0CC */ u32 SPRG3;
    /* 0x0D0 */ u32 DEC;
    /* 0x0D4 */ u32 IABR;
    /* 0x0D8 */ u32 EAR;
    /* 0x0DC */ u32 DABR;
    /* 0x0E0 */ u32 PMC1;
    /* 0x0E4 */ u32 PMC2;
    /* 0x0E8 */ u32 PMC3;
    /* 0x0EC */ u32 PMC4;
    /* 0x0F0 */ u32 SIA;
    /* 0x0F4 */ u32 MMCR0;
    /* 0x0F8 */ u32 MMCR1;
    /* 0x0FC */ u32 THRM1;
    /* 0x100 */ u32 THRM2;
    /* 0x104 */ u32 THRM3;
    /* 0x108 */ u32 ICTC;
    /* 0x10C */ u32 L2CR;
    /* 0x110 */ u32 UMMCR2;
    /* 0x114 */ u32 UBAMR;
    /* 0x118 */ u32 UMMCR0;
    /* 0x11C */ u32 UPMC1;
    /* 0x120 */ u32 UPMC2;
    /* 0x124 */ u32 USIA;
    /* 0x128 */ u32 UMMCR1;
    /* 0x12C */ u32 UPMC3;
    /* 0x130 */ u32 UPMC4;
    /* 0x134 */ u32 USDA;
    /* 0x138 */ u32 MMCR2;
    /* 0x13C */ u32 BAMR;
    /* 0x140 */ u32 SDA;
    /* 0x144 */ u32 MSSCR0;
    /* 0x148 */ u32 MSSCR1;
    /* 0x14C */ u32 PIR;
    /* 0x150 */ u32 exceptionID;
    /* 0x154 */ u32 GQR[8];
    /* 0x174 */ u32 HID_G;
    /* 0x178 */ u32 WPAR;
    /* 0x17C */ u32 DMA_U;
    /* 0x180 */ u32 DMA_L;
} Extended1_PPC_6xx_7xx; // size = 0x184

#define DS_EXTENDED1_MIN_REGISTER_6xx_7xx 0
#define DS_EXTENDED1_MAX_REGISTER_6xx_7xx                                     \
    (sizeof(Extended1_PPC_6xx_7xx) / sizeof(Extended1Type) - 1)

typedef struct Extended2_PPC_6xx_7xx {
    /* 0x00 */ u32 PSR[32][2];
} Extended2_PPC_6xx_7xx; // size = 0x100

typedef struct ProcessorState_PPC_6xx_7xx {
    /* 0x000 */ Default_PPC Default;
    /* 0x098 */ Float_PPC Float;
    /* 0x1A8 */ Extended1_PPC_6xx_7xx Extended1;
    /* 0x32C */ Extended2_PPC_6xx_7xx Extended2;
    /* 0x42C */ DefaultType transport_handler_saved_ra;
} ProcessorState_PPC_6xx_7xx; // size = 0x430

typedef ProcessorState_PPC_6xx_7xx ProcessorState_PPC;


typedef struct TRKState_PPC {
    /* 0x00 */ DefaultType GPR[32];
    /* 0x80 */ DefaultType LR;
    /* 0x84 */ DefaultType CTR;
    /* 0x88 */ DefaultType XER;
    /* 0x8C */ Extended1Type MSR;
    /* 0x90 */ Extended1Type DAR;
    /* 0x94 */ Extended1Type DSISR;
    /* 0x98 */ bool stopped;
    /* 0x9C */ bool inputActivated;
    /* 0xA0 */ u8* inputPendingPtr;
} TRKState_PPC;
typedef struct ProcessorRestoreFlags_PPC { u8 TBR; u8 DEC; u8 reserved[7]; } ProcessorRestoreFlags_PPC;
typedef struct TRKExceptionStatus { StopInfo_PPC exceptionInfo; u8 inTRK; u8 exceptionDetected; } TRKExceptionStatus;
typedef struct TRKStepStatus { bool active; u8 type; u32 count; u32 rangeStart; u32 rangeEnd; } TRKStepStatus;
extern ProcessorState_PPC gTRKCPUState;
extern ProcessorRestoreFlags_PPC gTRKRestoreFlags;
extern TRKState_PPC gTRKState;
extern TRKExceptionStatus gTRKExceptionStatus;
extern TRKStepStatus gTRKStepStatus;
extern u128 TRKvalue128_temp;
extern Default_PPC gTRKSaveState;
extern u16 TRK_saved_exceptionID;
typedef void (*RegAccessFunc)(void*, u128);
extern u32 __TRK_get_MSR(void);
extern void __TRK_set_MSR(u32);
extern void TRK_ppc_memcpy(void*, const void*, int, u32, u32);
extern void TRK_flush_cache(u32, u32);
extern u32 TRKTargetTranslate(u32);
extern u8 TRKTargetCPUMinorType(void);
extern DSError TRKAppendBuffer_ui32(MessageBuffer*, const u32*, int);
extern DSError TRKReadBuffer_ui32(MessageBuffer*, u32*, int);
extern DSError TRKAppendBuffer1_ui64(MessageBuffer*, u64);
extern DSError TRKReadBuffer1_ui64(MessageBuffer*, u64*);
extern DSError TRKDoNotifyStopped(u8);
extern void TRKTargetSetStopped(bool);
extern DSError TRKSuppAccessFile(u32, u8*, size_t*, u8*, bool, bool);
extern DSError HandleOpenFileSupportRequest(const char*, u8, u32*, u8*);
extern DSError HandleCloseFileSupportRequest(u32, u8*);
extern DSError HandlePositionFileSupportRequest(u32, u32, u8, u8*);
enum { kDSIONoError=0, kDSIOError=1, kValidMemoryReadable=0, kValidMemoryWriteable=1 };
#define PPC_PROGRAMERROR 0x700
#define PPC_TRACE 0xD00
#define SUPPORT_TRAP 0x0FE00000
#define DSFetch_u64(p) (*(u64*)(p))
#define DSFetch_u32(p) (*(u32*)(p))
#endif
