typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802BC908[],lbl_802BC04C[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineBase {
    void*vtable;
    ~InlineBase() {
        vtable=lbl_802BC04C;
        fn_8009009C(this,0);
    }
};
struct Object_800A39BC:InlineBase {
    ~Object_800A39BC();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800A39BC::~Object_800A39BC() {
    vtable=lbl_802BC908;
}
