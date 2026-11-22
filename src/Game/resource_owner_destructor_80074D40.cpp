typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__16CCollectableMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct ObjectMove_Z{u32 unknown00[2];const void*primaryTable;char unknown0C[0x15c];~ObjectMove_Z();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct CCollectableMove:ObjectMove_Z,CFSM{char unknownAfterSecondary[0x1c];Resource**resources;~CCollectableMove();};
CCollectableMove::~CCollectableMove(){primaryTable=__vt__16CCollectableMove;secondaryTable=__vt__16CCollectableMove+0x120;for(int i=0;i<3;i++)delete resources[i];operator delete(resources);}
