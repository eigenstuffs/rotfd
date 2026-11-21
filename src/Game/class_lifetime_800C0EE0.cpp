// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// ExtraHealthAgent.h factory establishes the 0x98-byte opaque object storage.
extern "C" {
extern unsigned long lbl_803777E8;
void fn_8002AD5C();
void fn_800C0F1C(void*);
void fn_800C0F58(void*, short);
void fn_800C0EE0()
{
    unsigned long object[0x98 / 4];
    lbl_803777E8 = 0;
    fn_8002AD5C();
    fn_800C0F1C(object);
    fn_800C0F58(object, -1);
}
}
