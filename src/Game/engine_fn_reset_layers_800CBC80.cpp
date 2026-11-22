typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802C191C[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct Object_800CBC80 {
    void*vtable;
    u32 unknown04,word08,word0C;
    ~Object_800CBC80();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800CBC80::~Object_800CBC80() {
    vtable=lbl_802C191C;
    word08=0;
    word0C=0;
    fn_8009009C(this,0);
}
