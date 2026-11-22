typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802BBCEC[],lbl_802BC8C8[],lbl_802BC04C[];
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
        vtable=lbl_802BC8C8;
    }
};
struct Object_800A2D30:InlineBase {
    ~Object_800A2D30();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800A2D30::~Object_800A2D30() {
    vtable=lbl_802BBCEC;
}
