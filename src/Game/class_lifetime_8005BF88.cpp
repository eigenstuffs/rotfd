// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// JellyfishAgent.h factory establishes the 0x98-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377690;
void fn_8002B58C();
void fn_8005BFC4(void*);
void fn_8005C01C(void*, short);
void fn_8005BF88()
{
    unsigned long object[0x98 / 4];
    lbl_80377690 = 0;
    fn_8002B58C();
    fn_8005BFC4(object);
    fn_8005C01C(object, -1);
}
}
