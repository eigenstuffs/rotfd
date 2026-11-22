typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802AFEE0[];
    void fn_801EF610(void*,void*);
}
struct Agent_80021260 {
    u32 unknown00[2];
    void*vtable;
    ~Agent_80021260();
};
struct Object_8002340C:Agent_80021260 {
    ~Object_8002340C();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8002340C::~Object_8002340C() {
    vtable=lbl_802AFEE0;
}
