/* Typed resource and multiple-base cleanup with original exception metadata.
 * See docs/notes/game-resource-owner-destructors.md. */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802C96DC[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Resource{virtual~Resource();};
extern "C" char __vt__20ObjectsRoot_80213EBC[];
struct ObjectsOwner_80213D44{u32 unknown00[2];const void*primaryTable;char unknown0C[0x10];~ObjectsOwner_80213D44();};
struct Root:ObjectsOwner_80213D44{float unknown1C;~Root(){primaryTable=__vt__20ObjectsRoot_80213EBC;}};
struct Object_8007D594{const void*secondaryTable;char unknown04[0x28];~Object_8007D594();};
struct Object_800F0560:Root,Object_8007D594{Resource**resources;~Object_800F0560();};
Object_800F0560::~Object_800F0560(){primaryTable=lbl_802C96DC;secondaryTable=lbl_802C96DC+0x40;for(int i=0;i<24;i++)delete resources[i];operator delete(resources);}
