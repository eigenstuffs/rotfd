// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// ProjectileAgent.h factory establishes the 0x88-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377610;
void fn_8003A214();
void fn_8003A234(void*);
void fn_8003A2C0(void*, short);
void fn_8003A1D8()
{
    unsigned long object[0x88 / 4];
    lbl_80377610 = 0;
    fn_8003A214();
    fn_8003A234(object);
    fn_8003A2C0(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_8003A214() { fn_8003522C(); }
}
