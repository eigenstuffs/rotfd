typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802BB230[],lbl_802BB2CC[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineBase {
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802BB2CC;
        fn_8009009C(this,0);
    }
};
struct Object_8009CE40:InlineBase {
    ~Object_8009CE40();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8009CE40::~Object_8009CE40() {
    vtable=lbl_802BB230;
}
