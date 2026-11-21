/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-layers-more.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B7F28[],lbl_802B7F74[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineBase {
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802B7F74;
        fn_8009009C(this,0);
    }
};
struct Object_80074A8C:InlineBase {
    ~Object_80074A8C();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_80074A8C::~Object_80074A8C() {
    vtable=lbl_802B7F28;
}
