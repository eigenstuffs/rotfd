typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B00B8[];
    void fn_801EF610(void*,void*);
}
struct Agent_80021260 {
    u32 unknown00[2];
    void*vtable;
    ~Agent_80021260();
};
struct Object_80022FCC:Agent_80021260 {
    ~Object_80022FCC();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_80022FCC::~Object_80022FCC() {
    vtable=lbl_802B00B8;
}
