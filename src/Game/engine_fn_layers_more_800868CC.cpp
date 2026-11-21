/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-layers-more.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B8DE4[],lbl_802B92B0[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineBase {
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802B92B0;
        fn_8009009C(this,0);
    }
};
struct Object_800868CC:InlineBase {
    ~Object_800868CC();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800868CC::~Object_800868CC() {
    vtable=lbl_802B8DE4;
}
