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
    extern char __vt__14CJellyfishMove[];
    void fn_8009009C(void*,int);

}
struct CNPCMove {
    u32 unknown00[2];
    void*vtable;
    char unknown0C[0x318-0xC];
    void*secondaryVtable;
    ~CNPCMove();
};
struct CJellyfishMove : CNPCMove {
    ~CJellyfishMove();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
CJellyfishMove::~CJellyfishMove() {
    vtable=__vt__14CJellyfishMove;
    secondaryVtable=__vt__14CJellyfishMove+0x170;
}
