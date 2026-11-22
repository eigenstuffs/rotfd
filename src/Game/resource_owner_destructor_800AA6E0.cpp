typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__9CTileMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct ObjectMove_Z{u32 unknown00[2];const void*primaryTable;char unknown0C[0x15c];~ObjectMove_Z();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct CTileMove:ObjectMove_Z,CFSM{char unknownAfterSecondary[0x4];Resource**resources;~CTileMove();};
CTileMove::~CTileMove(){primaryTable=__vt__9CTileMove;secondaryTable=__vt__9CTileMove+0x120;for(int i=0;i<6;i++)delete resources[i];operator delete(resources);}
