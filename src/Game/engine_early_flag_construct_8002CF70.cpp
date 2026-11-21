/* Original native engine flag and member construction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-flag-construct.md. */
typedef unsigned long u32;
extern "C" {void __ct__21CallbackFlag_802ECD68Fv(void*);void __ct__24CallbackControl_802ECC00Fv(void*);void __ct__22CallbackClock_802ECEC0Fv(void*);extern char lbl_802B1884[],lbl_802B29D0[],lbl_802B2B60[],lbl_802B7E38[];}
struct Agent_8002CF70 {u32 unknown00[2];void*vtable;char unknown0C[0x38-0xC];unsigned long long flags;Agent_8002CF70();};
Agent_8002CF70::Agent_8002CF70(){__ct__21CallbackFlag_802ECD68Fv(this);vtable=lbl_802B1884;flags&=~0x400ULL;}
