// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// WildSnailAgent.h factory establishes the 0x98-byte opaque object storage.
extern "C" {
extern unsigned long lbl_803776F8;
void fn_8002B58C();
void fn_80060EC4(void*);
void fn_80060F08(void*, short);
void fn_80060E88()
{
    unsigned long object[0x98 / 4];
    lbl_803776F8 = 0;
    fn_8002B58C();
    fn_80060EC4(object);
    fn_80060F08(object, -1);
}
}
