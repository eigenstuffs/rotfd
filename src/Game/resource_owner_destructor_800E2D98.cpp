typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__16CSBPants_BRKMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct ObjectThrow_Z{u32 unknown00[2];const void*primaryTable;char unknown0C[0x1ec];~ObjectThrow_Z();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct CSBPants_BRKMove:ObjectThrow_Z,CFSM{Resource**resources;~CSBPants_BRKMove();};
CSBPants_BRKMove::~CSBPants_BRKMove(){primaryTable=__vt__16CSBPants_BRKMove;secondaryTable=__vt__16CSBPants_BRKMove+0x13c;for(int i=0;i<3;i++)delete resources[i];operator delete(resources);}
