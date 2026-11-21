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
struct H1_80021064:Handle_801F7F10 {
};
struct H2_80021064:H1_80021064 {
};
struct H3_80021064:H2_80021064 {
};
struct H4_80021064:H3_80021064 {
};
struct H5_80021064:H4_80021064 {
};
struct H6_80021064:H5_80021064 {
};
struct Object_80021108 {
    u32 unknown00[2];
    void*vtable;
    char unknownC[0x70-0xC];
    ~Object_80021108();
};
struct Object_80021064:Object_80021108 {
    H3_80021064 handle70;
    char unknown74[0x80-0x74];
    ~Object_80021064();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_80021064::~Object_80021064() {
    vtable=lbl_802ECA18;
}
