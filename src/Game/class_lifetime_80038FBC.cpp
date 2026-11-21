// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// ProjectileAgent.h factory establishes the 0x88-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377604;
void fn_80038FF8();
void fn_80039018(void*);
void fn_800390A4(void*, short);
void fn_80038FBC()
{
    unsigned long object[0x88 / 4];
    lbl_80377604 = 0;
    fn_80038FF8();
    fn_80039018(object);
    fn_800390A4(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_80038FF8() { fn_8003522C(); }
}
