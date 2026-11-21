/* Original native engine flag and member construction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-flag-construct.md. */
typedef unsigned long u32;
extern "C" {void __ct__21CallbackFlag_802ECD68Fv(void*);void __ct__24CallbackControl_802ECC00Fv(void*);void __ct__22CallbackClock_802ECEC0Fv(void*);extern char lbl_802B1884[],lbl_802B29D0[],lbl_802B2B60[],lbl_802B7E38[];}
struct Agent_8003CD88 {u32 unknown00[2];void*vtable;char unknown0C[0x38-0xC];unsigned long long flags;char unknown40[0x70-0x40];unsigned char field70;char unknown71[0x170-0x71];u32 field170,field174,field178;Agent_8003CD88();};
Agent_8003CD88::Agent_8003CD88(){__ct__22CallbackClock_802ECEC0Fv(this);vtable=lbl_802B2B60;field170=0;field174=0;field178=0;flags&=~0x100000ULL;field70=0;}
