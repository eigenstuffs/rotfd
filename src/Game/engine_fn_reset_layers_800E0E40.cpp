typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802C8290[],lbl_802C82AC[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineResetBase {
    void*vtable;
    u32 unknown04,word08,word0C;
    ~InlineResetBase() {
        vtable=lbl_802C82AC;
        word08=0;
        word0C=0;
        fn_8009009C(this,0);
    }
};
struct Object_800E0E40:InlineResetBase {
    ~Object_800E0E40();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800E0E40::~Object_800E0E40() {
    vtable=lbl_802C8290;
}
