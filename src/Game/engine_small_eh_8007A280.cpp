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
struct Object_8007A280 {
    char unknown00[0x2800];
    int count;
    ~Object_8007A280();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8007A280::~Object_8007A280() {
    for(int i=0; i<count; i++) {
    }
}
