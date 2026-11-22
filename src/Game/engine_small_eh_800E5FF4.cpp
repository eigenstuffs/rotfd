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
struct Object_800E5FF4 {
    u32 unknown00,unknown04,unknown08,unknown0C,unknown10,unknown14;
    unsigned char unknown18,unknown19,unknown1A,unknown1B;
    unsigned short values1C[50];
    ~Object_800E5FF4();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800E5FF4::~Object_800E5FF4() {
    unknown00=0;
    unknown04=0;
    unknown0C=0;
    unknown19=0;
    unknown1A=0;
    unknown1B=0;
    for(int i=0; i<50; i++)values1C[i]=0;
}
