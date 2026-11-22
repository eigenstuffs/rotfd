typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BC2C0[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct Object_8009DAB0{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0xdc];~Object_8009DAB0();};
struct Object_800A402C:Object_8009DAB0{Resource**resources;~Object_800A402C();};
Object_800A402C::~Object_800A402C(){primaryTable=lbl_802BC2C0;secondaryTable=lbl_802BC2C0+0x170;for(int i=0;i<4;i++)delete resources[i];operator delete(resources);}
