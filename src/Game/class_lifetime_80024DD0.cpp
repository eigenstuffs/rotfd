// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// HookAgent.h factory establishes the 0x88-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377580;
void fn_802598F4();
void fn_80024E0C(void*);
void fn_80024ECC(void*, short);
void fn_80024DD0()
{
    unsigned long object[0x88 / 4];
    lbl_80377580 = 0;
    fn_802598F4();
    fn_80024E0C(object);
    fn_80024ECC(object, -1);
}
}
