typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BB3F4[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct CActorMove{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~CActorMove();};
struct CWildSnailMove:CActorMove{Resource**resources;~CWildSnailMove();};
CWildSnailMove::~CWildSnailMove(){primaryTable=lbl_802BB3F4;secondaryTable=lbl_802BB3F4+0x170;for(int i=0;i<4;i++)delete resources[i];operator delete(resources);}
