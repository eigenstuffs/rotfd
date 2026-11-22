typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802B93F4[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct Object_8009AA98{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~Object_8009AA98();};
struct Object_80090360:Object_8009AA98{Resource**resources;char unknown348[0xE0];u32 reset428,reset42C;~Object_80090360();};
Object_80090360::~Object_80090360(){primaryTable=lbl_802B93F4;secondaryTable=lbl_802B93F4+0x170;for(int i=0;i<58;i++)delete resources[i];operator delete(resources);reset428=0;reset42C=0;}
