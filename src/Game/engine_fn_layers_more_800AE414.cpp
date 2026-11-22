typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802BD500[],lbl_802BD518[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineBase {
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802BD518;
        fn_8009009C(this,0);
    }
};
struct Object_800AE414:InlineBase {
    ~Object_800AE414();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800AE414::~Object_800AE414() {
    vtable=lbl_802BD500;
}
