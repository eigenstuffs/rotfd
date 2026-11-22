typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
extern "C" char lbl_802B7E38[];
extern "C" void fn_80020FE8(void*,int);
struct Agent_800737D8 {
    u32 unknown00[2];
    void*vtable;
    ~Agent_800737D8();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_800737D8::~Agent_800737D8() {
    vtable=lbl_802B7E38;
    fn_80020FE8(this,0);
}
