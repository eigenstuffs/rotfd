typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__11CSimpleMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct CScriptMove{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0xdc];~CScriptMove();};
struct CSimpleMove:CScriptMove{Resource**resources;~CSimpleMove();};
CSimpleMove::~CSimpleMove(){primaryTable=__vt__11CSimpleMove;secondaryTable=__vt__11CSimpleMove+0x170;for(int i=0;i<22;i++)delete resources[i];operator delete(resources);}
