typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802C939C[],lbl_802C967C[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineBase {
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802C967C;
        fn_8009009C(this,0);
    }
};
struct Object_800EFC08:InlineBase {
    ~Object_800EFC08();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800EFC08::~Object_800EFC08() {
    vtable=lbl_802C939C;
}
