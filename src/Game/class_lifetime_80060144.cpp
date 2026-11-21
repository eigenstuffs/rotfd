// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// RedJfishAgent.h factory establishes the 0x98-byte opaque object storage.
extern "C" {
extern unsigned long lbl_803776E8;
void fn_8005BF88();
void fn_80060180(void*);
void fn_800601C4(void*, short);
void fn_80060144()
{
    unsigned long object[0x98 / 4];
    lbl_803776E8 = 0;
    fn_8005BF88();
    fn_80060180(object);
    fn_800601C4(object, -1);
}
}
