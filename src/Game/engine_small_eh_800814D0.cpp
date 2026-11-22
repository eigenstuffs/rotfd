typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
struct H4:H3 {
};
extern "C" {
    extern char lbl_802B92B0[];
    void fn_8009009C(void*,int);
    void fn_8009A8AC(void*,int);
}
struct Object_800814D0 {
    void*vtable;
    ~Object_800814D0();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800814D0::~Object_800814D0() {
    vtable=lbl_802B92B0;
    fn_8009009C(this,0);
}
