typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__11CMediumMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct CScriptMove{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0xdc];~CScriptMove();};
struct CMediumMove:CScriptMove{Resource**resources;~CMediumMove();};
CMediumMove::~CMediumMove(){primaryTable=__vt__11CMediumMove;secondaryTable=__vt__11CMediumMove+0x170;for(int i=0;i<4;i++)delete resources[i];operator delete(resources);}
