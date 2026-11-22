typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BD5C4[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct H1:Handle_801F7F10{~H1(){}};
struct H2:H1{~H2(){}};
struct H3:H2{~H3(){}};
struct Objects_802EB7C0{u32 unknown00[2];const void*primaryTable;char unknown0C[0x1F8-0x0C];~Objects_802EB7C0();};
struct CFSM{const void*secondaryTable;char unknown04[0x2C];~CFSM();};
struct Resource{virtual~Resource();};
struct Record{char unknown00[0x8C];H3 first,second;~Record(){}};
struct Object_800AF348:Objects_802EB7C0,CFSM{
    Record record228;char unknown2BC[0x10];Resource**resources2CC;~Object_800AF348();
};
Object_800AF348::~Object_800AF348(){primaryTable=lbl_802BD5C4;secondaryTable=lbl_802BD5C4+0x13C;for(int i=0;i<3;i++)delete resources2CC[i];operator delete(resources2CC);}
