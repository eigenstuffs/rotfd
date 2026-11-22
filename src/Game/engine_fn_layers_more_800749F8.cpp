typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B7EF8[],lbl_802B7F74[];
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
struct Object_800749F8:InlineBase {
    ~Object_800749F8();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800749F8::~Object_800749F8() {
    vtable=lbl_802B7EF8;
}
