/* Typed resource and multiple-base cleanup with original exception metadata.
 * See docs/notes/game-resource-owner-destructors.md. */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BA0BC[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
struct Object_80098A70{u32 unknown00[2];const void*primaryTable;char unknown0C[0x30c];const void*secondaryTable;char unknownSecondary[0x28];~Object_80098A70();};
struct Object_8009731C:Object_80098A70{Resource**resources;~Object_8009731C();};
Object_8009731C::~Object_8009731C(){primaryTable=lbl_802BA0BC;secondaryTable=lbl_802BA0BC+0x170;for(int i=0;i<6;i++)delete resources[i];operator delete(resources);}
