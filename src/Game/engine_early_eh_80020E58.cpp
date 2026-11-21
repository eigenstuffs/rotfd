/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802B0330[],lbl_802EC810[],lbl_802ECA18[],lbl_802EC798[],lbl_802ED000[],lbl_802EC720[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
    void fn_80020FE8(void*,int);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1_80020E58:Handle_801F7F10 {
};
struct H2_80020E58:H1_80020E58 {
};
struct H3_80020E58:H2_80020E58 {
};
struct H4_80020E58:H3_80020E58 {
};
struct H5_80020E58:H4_80020E58 {
};
struct H6_80020E58:H5_80020E58 {
};
struct Object_80020F2C {
    u32 unknown00[2];
    void*vtable;
    char unknownC[0x88-0xC];
    ~Object_80020F2C();
};
struct Agent_80021260:Object_80020F2C {
    H2_80020E58 handle88,handle8C;
    char unknown90[0xBC-0x90];
    H2_80020E58 handleBC;
    ~Agent_80021260();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_80021260::~Agent_80021260() {
    vtable=lbl_802B0330;
}
