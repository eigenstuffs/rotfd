typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BA84C[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct Object_80098A70{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~Object_80098A70();};
struct Object_80098518:Object_80098A70{Resource**resources;~Object_80098518();};
Object_80098518::~Object_80098518(){primaryTable=lbl_802BA84C;secondaryTable=lbl_802BA84C+0x170;for(int i=0;i<9;i++)delete resources[i];operator delete(resources);}
