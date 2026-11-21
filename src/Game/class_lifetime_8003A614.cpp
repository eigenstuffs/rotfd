// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// ProjectileAgent.h factory establishes the 0x88-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377614;
void fn_8003A650();
void fn_8003A670(void*);
void fn_8003A6FC(void*, short);
void fn_8003A614()
{
    unsigned long object[0x88 / 4];
    lbl_80377614 = 0;
    fn_8003A650();
    fn_8003A670(object);
    fn_8003A6FC(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_8003A650() { fn_8003522C(); }
}
