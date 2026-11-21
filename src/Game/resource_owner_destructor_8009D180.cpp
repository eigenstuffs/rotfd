/* Typed resource and multiple-base cleanup with original exception metadata.
 * See docs/notes/game-resource-owner-destructors.md. */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BB3F4[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct Object_8009AA98{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~Object_8009AA98();};
struct Object_8009D180:Object_8009AA98{Resource**resources;~Object_8009D180();};
Object_8009D180::~Object_8009D180(){primaryTable=lbl_802BB3F4;secondaryTable=lbl_802BB3F4+0x170;for(int i=0;i<4;i++)delete resources[i];operator delete(resources);}
