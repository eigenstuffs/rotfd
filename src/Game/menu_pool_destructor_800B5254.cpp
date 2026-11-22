typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[],lbl_8028F698[],__vt__15Object_800B4F28[],lbl_802BD800[];
void fn_801EF610(void*,void*);
void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct H1:Handle_801F7F10{~H1(){}};
struct H2:H1{~H2(){}};
struct MenuBase_8021D7E4{u32 unknown00[2];const void*vtable;char unknown0C[0x40];~MenuBase_8021D7E4();};
struct Record{char unknown00[0xC0];H2 handleC0;~Record(){}};
struct Pool{int size,capacity;Record*data;~Pool(){if(data){for(int i=0;i<size;i++)data[i].~Record();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Record));data=0;}data=0;}}};
struct MenuLayer:MenuBase_8021D7E4 {
    H2 handle4C;
    char unknown50[0x18];
    Pool records68;
    H2 handle74;
    ~MenuLayer(){vtable=__vt__15Object_800B4F28;}
    static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Object_800B5254:MenuLayer{~Object_800B5254();};
Object_800B5254::~Object_800B5254(){vtable=lbl_802BD800;}
