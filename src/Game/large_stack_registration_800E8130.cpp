/* Partial text reconstruction. The original action-17 exception record and
 * exception index remain original-owned and receive no source credit. */
typedef unsigned long RegistrationWord;
struct RegistrationMemberPointer {
    RegistrationWord delta, vslot, tableOffset;
};
extern "C" {
    extern RegistrationWord lbl_803778BC;
    extern RegistrationMemberPointer lbl_802C90C0;
    void fn_80256448();
    void fn_8025E714(void*, RegistrationMemberPointer);
}
struct Object_800E81C8 {
    char storage[0xB310];
    Object_800E81C8();
};
/* Native constructor and destructor identities are borrowed independently.
 * This first-member lifetime view preserves the observed common address. */
struct Object_800E82C4 {
    Object_800E81C8 first;
    ~Object_800E82C4();
};
typedef char RegistrationObjectSize[sizeof(Object_800E82C4) == 0xB310 ? 1 : -1];
extern "C" void fn_800E8130() {
    lbl_803778BC = 0;
    fn_80256448();
    Object_800E82C4 local;
    fn_8025E714(&local, lbl_802C90C0);
}
