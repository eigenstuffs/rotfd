typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802BC4DC[],lbl_802BC888[],lbl_802BC04C[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineRoot {
    void*vtable;
    ~InlineRoot() {
        vtable=lbl_802BC04C;
        fn_8009009C(this,0);
    }
};
struct InlineBase:InlineRoot {
    ~InlineBase() {
        vtable=lbl_802BC888;
    }
};
struct Object_800A479C:InlineBase {
    ~Object_800A479C();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800A479C::~Object_800A479C() {
    vtable=lbl_802BC4DC;
}
