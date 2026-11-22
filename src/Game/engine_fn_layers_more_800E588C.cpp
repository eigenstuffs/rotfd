typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802C8DF8[],lbl_802B92B0[];
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
struct Object_800E588C:InlineBase {
    ~Object_800E588C();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800E588C::~Object_800E588C() {
    vtable=lbl_802C8DF8;
}
