// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// SpellBookAgent.h factory establishes the 0x98-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377800;
void fn_8002AD5C();
void fn_800C4F7C(void*);
void fn_800C4FB8(void*, short);
void fn_800C4F40()
{
    unsigned long object[0x98 / 4];
    lbl_80377800 = 0;
    fn_8002AD5C();
    fn_800C4F7C(object);
    fn_800C4FB8(object, -1);
}
}
