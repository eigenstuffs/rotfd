// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// ProjectileAgent.h factory establishes the 0x88-byte opaque object storage.
extern "C" {
extern unsigned long lbl_803775F8;
void fn_800367C0();
void fn_800367E0(void*);
void fn_8003686C(void*, short);
void fn_80036784()
{
    unsigned long object[0x88 / 4];
    lbl_803775F8 = 0;
    fn_800367C0();
    fn_800367E0(object);
    fn_8003686C(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_800367C0() { fn_8003522C(); }
}
