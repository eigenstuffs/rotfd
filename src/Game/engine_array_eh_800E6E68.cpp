typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
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
extern "C" char lbl_802C8E18[];
struct Record_800E6A58 {
    char unknown00[0x3B5C];
    ~Record_800E6A58();
};
struct Object_800E6E68 {
    void*vtable;
    u32 unknown04,unknown08;
    Record_800E6A58 records0C[3];
    ~Object_800E6E68();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800E6E68::~Object_800E6E68() {
    vtable=lbl_802C8E18;
}
