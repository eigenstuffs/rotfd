typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__12CSBPantsMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct LodMove_Z{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];~LodMove_Z();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct CSBPantsMove:LodMove_Z,CFSM{Resource**resources;~CSBPantsMove();};
CSBPantsMove::~CSBPantsMove(){primaryTable=__vt__12CSBPantsMove;secondaryTable=__vt__12CSBPantsMove+0x170;for(int i=0;i<2;i++)delete resources[i];operator delete(resources);}
