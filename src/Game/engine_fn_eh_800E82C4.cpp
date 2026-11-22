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
extern "C" char lbl_802C9160[],lbl_802C8E18[],lbl_802EC720[];
struct Service {
    char unknown00[0x1505C];
    void*owner1505C;
};
struct Context {
    char unknown00[0x124];
    Service*service124;
};
extern "C" Context lbl_801E9D24;
struct Element {
    u32 word;
    ~Element() {
    }
};
struct Pool {
    int size,capacity;
    Element*data;
    ~Pool() {
        if(data) {
            for(int i=0; i<size; i++)data[i].~Element();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
struct Object_8025F0D8 {
    u32 unknown00;
    Handle_801F7F10 owner;
    void*vtable;
    char unknown0C[0x48-0xC];
    ~Object_8025F0D8();
};
struct ContainerPrefix:Object_8025F0D8 {
    Pool pool48;
    u32 unknown54;
    H2 handle58;
    u32 unknown5C;
    ~ContainerPrefix() {
        vtable=lbl_802EC720;
    }
};
struct Record_800E6A58 {
    char unknown00[0x3B5C];
    ~Record_800E6A58();
};
struct FixedRecords {
    void*vtable;
    u32 unknown04,unknown08;
    Record_800E6A58 records0C[3];
    ~FixedRecords() {
        vtable=lbl_802C8E18;
    }
};
struct Object_800E82C4:ContainerPrefix {
    char unknown60[0xC8-0x60];
    FixedRecords recordsC8;
    ~Object_800E82C4();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800E82C4::~Object_800E82C4() {
    vtable=lbl_802C9160;
    if(lbl_801E9D24.service124)lbl_801E9D24.service124->owner1505C=0;
}
