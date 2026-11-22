typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__15WaterHelmetMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct ObjectMove_Z{u32 unknown00[2];const void*primaryTable;char unknown0C[0x15c];~ObjectMove_Z();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct WaterHelmetMove:ObjectMove_Z,CFSM{Resource**resources;~WaterHelmetMove();};
WaterHelmetMove::~WaterHelmetMove(){primaryTable=__vt__15WaterHelmetMove;secondaryTable=__vt__15WaterHelmetMove+0x120;for(int i=0;i<2;i++)delete resources[i];operator delete(resources);}
