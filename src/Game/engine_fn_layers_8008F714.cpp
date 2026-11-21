/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-layers.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B8F94[],lbl_802B92B0[];
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
struct Object_8008F714:InlineBase {
    ~Object_8008F714();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8008F714::~Object_8008F714() {
    vtable=lbl_802B8F94;
}
