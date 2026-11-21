/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-small-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
struct H4:H3 {
};
extern "C" char lbl_802BB070[];
struct Objects_802EB518 {
    u32 unknown00[2];
    void*vtable;
    char unknown0C[0x318-0xC];
    ~Objects_802EB518();
};
struct CFSM {
    void*secondaryVtable;
    char unknown04[0x2C];
    ~CFSM();
};
struct Object_8009AA98:Objects_802EB518,CFSM {
    H4 handle348;
    ~Object_8009AA98();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8009AA98::~Object_8009AA98() {
    vtable=lbl_802BB070;
    secondaryVtable=lbl_802BB070+0x170;
}
