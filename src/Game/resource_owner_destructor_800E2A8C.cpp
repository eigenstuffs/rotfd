/* Typed resource and multiple-base cleanup with original exception metadata.
 * See docs/notes/game-resource-owner-destructors.md. */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802C88EC[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct Objects_802EB518{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];~Objects_802EB518();};
struct CFSM{const void*secondaryTable;char unknown04[0x28];~CFSM();};
struct Object_800E2A8C:Objects_802EB518,CFSM{Resource**resources;~Object_800E2A8C();};
Object_800E2A8C::~Object_800E2A8C(){primaryTable=lbl_802C88EC;secondaryTable=lbl_802C88EC+0x170;for(int i=0;i<2;i++)delete resources[i];operator delete(resources);}
