extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" {
    extern char lbl_802EC810[];
    void fn_80020FE8(void*,int);
}
struct Handle_801F7F10 {
    unsigned int word;
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
struct H5:H4 {
};
struct H6:H5 {
};
struct Object_80020F2C {
    char unknown00[8];
    void*vtable;
    char unknown0C[0x74];
    char handle80[4];
    ~Object_80020F2C();
    static void operator delete(void*p)throw() {
        dispose(p);
    }
};
Object_80020F2C::~Object_80020F2C() {
    vtable=lbl_802EC810;
    reinterpret_cast<H6*>(handle80)->~H6();
    fn_80020FE8(this,0);
}
