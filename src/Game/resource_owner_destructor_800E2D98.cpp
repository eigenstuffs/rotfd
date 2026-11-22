typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802C872C[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct Objects_802EB7C0{u32 unknown00[2];const void*primaryTable;char unknown0C[0x1ec];~Objects_802EB7C0();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct Object_800E2D98:Objects_802EB7C0,CFSM{Resource**resources;~Object_800E2D98();};
Object_800E2D98::~Object_800E2D98(){primaryTable=lbl_802C872C;secondaryTable=lbl_802C872C+0x13c;for(int i=0;i<3;i++)delete resources[i];operator delete(resources);}
