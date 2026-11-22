typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802B860C[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct H1:Handle_801F7F10{~H1(){}};
struct H2:H1{~H2(){}};
struct H3:H2{~H3(){}};
struct Objects_802EB518{u32 unknown00[2];const void*primaryTable;char unknown0C[0x318-0x0C];~Objects_802EB518();};
struct CFSM{const void*secondaryTable;char unknown04[0x2C];~CFSM();};
struct Resource{virtual~Resource();};
struct Record{char unknown00[0x8C];H3 first,second;~Record(){}};
struct Object_8007F578:Objects_802EB518,CFSM{
    Record record348;char unknown3DC[0x0C];Resource**resources3E8;~Object_8007F578();
};
Object_8007F578::~Object_8007F578(){primaryTable=lbl_802B860C;secondaryTable=lbl_802B860C+0x170;for(int i=0;i<4;i++)delete resources3E8[i];operator delete(resources3E8);}
