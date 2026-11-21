// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// ProjectileAgent.h factory establishes the 0xa0-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377600;
void fn_80038130();
void fn_80038150(void*);
void fn_800381F8(void*, short);
void fn_800380F4()
{
    unsigned long object[0xa0 / 4];
    lbl_80377600 = 0;
    fn_80038130();
    fn_80038150(object);
    fn_800381F8(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_80036BC0();
void fn_80038130() { fn_80036BC0(); }
}
