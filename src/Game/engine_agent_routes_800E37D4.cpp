typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
extern "C" char lbl_802C8C80[];
struct Object_80020F2C {
    u32 unknown00[2];
    void*vtable;
    ~Object_80020F2C();
};
struct Agent_800E3798:Object_80020F2C {
    ~Agent_800E3798();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_800E3798::~Agent_800E3798() {
    vtable=lbl_802C8C80;
}
