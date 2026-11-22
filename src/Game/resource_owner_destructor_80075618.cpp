typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__18CTreasureChestMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct ObjectMove_Z{u32 unknown00[2];const void*primaryTable;char unknown0C[0x15c];~ObjectMove_Z();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct CTreasureChestMove:ObjectMove_Z,CFSM{char unknownAfterSecondary[0x4];Resource**resources;~CTreasureChestMove();};
CTreasureChestMove::~CTreasureChestMove(){primaryTable=__vt__18CTreasureChestMove;secondaryTable=__vt__18CTreasureChestMove+0x120;for(int i=0;i<2;i++)delete resources[i];operator delete(resources);}
