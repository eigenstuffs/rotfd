typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__12CComplexMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct CScriptMove{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0xdc];~CScriptMove();};
struct CComplexMove:CScriptMove{Resource**resources;~CComplexMove();};
CComplexMove::~CComplexMove(){primaryTable=__vt__12CComplexMove;secondaryTable=__vt__12CComplexMove+0x170;for(int i=0;i<4;i++)delete resources[i];operator delete(resources);}
