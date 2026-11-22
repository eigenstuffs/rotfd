typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__13CRedJfishMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct CJellyfishMove{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~CJellyfishMove();};
struct CRedJfishMove:CJellyfishMove{Resource**resources;~CRedJfishMove();};
CRedJfishMove::~CRedJfishMove(){primaryTable=__vt__13CRedJfishMove;secondaryTable=__vt__13CRedJfishMove+0x170;for(int i=0;i<9;i++)delete resources[i];operator delete(resources);}
