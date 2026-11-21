// Lifetime-only class registration; see docs/notes/game-class-registry.md.
// WaterHelmetAgent.h factory establishes the 0x78-byte opaque object storage.
extern "C" {
extern unsigned long lbl_803778A0;
void fn_8025A930();
void fn_800E133C(void*);
void fn_800E1378(void*, short);
void fn_800E1300()
{
    unsigned long object[0x78 / 4];
    lbl_803778A0 = 0;
    fn_8025A930();
    fn_800E133C(object);
    fn_800E1378(object, -1);
}
}
