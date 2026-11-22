typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B29D0[];
    void fn_801EF610(void*,void*);
}
extern "C" void fn_80020FE8(void*,int);
struct Agent_80035294 {
    u32 unknown00[2];
    void*vtable;
    ~Agent_80035294();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_80035294::~Agent_80035294() {
    vtable=lbl_802B29D0;
    fn_80020FE8(this,0);
}
