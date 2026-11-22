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
struct Reset {
    u32 unknown00,unknown04,unknown08,unknown0C,unknown10,unknown14;
    unsigned char unknown18,unknown19,unknown1A,unknown1B;
    unsigned short values1C[50];
    ~Reset() {
        unknown00=0;
        unknown04=0;
        unknown0C=0;
        unknown19=0;
        unknown1A=0;
        unknown1B=0;
        for(int i=0; i<50; i++)values1C[i]=0;
    }
};
struct Record_800E5F90 {
    char unknown00[0x1D0];
    ~Record_800E5F90();
};
struct Object_800E62E4:Reset {
    Record_800E5F90 records80[4];
    ~Object_800E62E4();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800E62E4::~Object_800E62E4() {
}
