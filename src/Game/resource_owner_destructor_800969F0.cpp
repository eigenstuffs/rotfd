typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__15CGreenJfishMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct CJellyfishMove{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~CJellyfishMove();};
struct CGreenJfishMove:CJellyfishMove{Resource**resources;~CGreenJfishMove();};
CGreenJfishMove::~CGreenJfishMove(){primaryTable=__vt__15CGreenJfishMove;secondaryTable=__vt__15CGreenJfishMove+0x170;for(int i=0;i<9;i++)delete resources[i];operator delete(resources);}
