// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// SandDollarAgent.h factory establishes the 0x98-byte opaque object storage.
extern "C" {
extern unsigned long lbl_803777F0;
void fn_8002AD5C();
void fn_800C4710(void*);
void fn_800C474C(void*, short);
void fn_800C46D4()
{
    unsigned long object[0x98 / 4];
    lbl_803777F0 = 0;
    fn_8002AD5C();
    fn_800C4710(object);
    fn_800C474C(object, -1);
}
}
