typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],__vt__14CSpongeBobMove[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct CActorMove{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~CActorMove();};
struct CSpongeBobMove:CActorMove{Resource**resources;char unknown348[0xE0];u32 reset428,reset42C;~CSpongeBobMove();};
CSpongeBobMove::~CSpongeBobMove(){primaryTable=__vt__14CSpongeBobMove;secondaryTable=__vt__14CSpongeBobMove+0x170;for(int i=0;i<58;i++)delete resources[i];operator delete(resources);reset428=0;reset42C=0;}
