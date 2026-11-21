/* fn_800E8130: startup registration using a large local record object.
 * The local is built by the native constructor at 800E81C8 and destroyed by
 * the native destructor at 800E82C4 (separate units).
 * Code is byte-identical. The single extab action (type 0x11, a large-frame
 * DESTROYLOCAL) carries two uninitialized padding bytes at record+0x12: the
 * original has 37 01 (the same garbage as fn_800D00E8's DESTROYLOCALCOND
 * records, handled there by extab_padding=[0x37, 0x01]); this compiler build
 * leaves environment-dependent bytes (3a 6c under fdiff, 3b 6c elsewhere).
 * `dtk extab clean` rejects action 17, so integration needs those two bytes
 * patched. */
typedef unsigned long u32;

struct MemberPointer {
    u32 a, b, c;
};

extern "C" {
extern u32 lbl_803778BC;
extern MemberPointer lbl_802C90C0;
void fn_80256448();
void fn_8025E714(void* object, MemberPointer callback);
}

struct Object_800E81C8 {
    char opaque[0xB310];
    Object_800E81C8();
};

struct Object_800E82C4 : Object_800E81C8 {
    ~Object_800E82C4();
};

extern "C" void fn_800E8130() {
    lbl_803778BC = 0;
    fn_80256448();
    Object_800E82C4 local;
    fn_8025E714(&local, lbl_802C90C0);
}
