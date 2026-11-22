typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
extern "C" char lbl_802C8D50[];
struct Object_80021064 {
    u32 unknown00[2];
    void*vtable;
    ~Object_80021064();
};
struct Agent_800E3250:Object_80021064 {
    ~Agent_800E3250();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_800E3250::~Agent_800E3250() {
    vtable=lbl_802C8D50;
}
