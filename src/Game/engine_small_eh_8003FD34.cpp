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
extern "C" char lbl_802B3168[];
struct Agent_8002B5F4 {
    u32 unknown00[2];
    void*vtable;
    ~Agent_8002B5F4();
};
struct Object_8003FD34:Agent_8002B5F4 {
    ~Object_8003FD34();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8003FD34::~Object_8003FD34() {
    vtable=lbl_802B3168;
}
