/* Original native engine flag and member construction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-flag-construct.md. */
typedef unsigned long u32;
extern "C" {void __ct__21CallbackFlag_802ECD68Fv(void*);void __ct__24CallbackControl_802ECC00Fv(void*);void __ct__22CallbackClock_802ECEC0Fv(void*);extern char lbl_802B1884[],lbl_802B29D0[],lbl_802B2B60[],lbl_802B7E38[];}
struct Agent_800737D8 {u32 unknown00[2];void*vtable;char unknown0C[0x38-0xC];unsigned long long flags;char unknown40[0x80-0x40];u32 field80;unsigned char field84;char unknown85;unsigned short field86;u32 field88;Agent_800737D8();};
Agent_800737D8::Agent_800737D8(){__ct__24CallbackControl_802ECC00Fv(this);vtable=lbl_802B7E38;field80=0;field84=0;field86=0;field88=0;flags&=~4ULL;flags|=0x400000000000ULL;}
