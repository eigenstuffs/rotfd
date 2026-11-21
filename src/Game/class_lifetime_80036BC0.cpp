// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// ProjectileAgent.h factory establishes the 0x98-byte opaque object storage.
extern "C" {
extern unsigned long lbl_803775FC;
void fn_80036BFC();
void fn_80036C1C(void*);
void fn_80036D98(void*, short);
void fn_80036BC0()
{
    unsigned long object[0x98 / 4];
    lbl_803775FC = 0;
    fn_80036BFC();
    fn_80036C1C(object);
    fn_80036D98(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_80036BFC() { fn_8003522C(); }
}
