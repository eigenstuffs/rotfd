/* Typed resource and multiple-base cleanup with original exception metadata.
 * See docs/notes/game-complex-owner-destructors.md. */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[],lbl_802BF6B0[],__vt__24ManipulatorDraw_802BC9D0[],__vt__13Manipulator_Z[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct H1:Handle_801F7F10{~H1(){}};
struct H2:H1{~H2(){}};
struct Activable_Z{u32 unknown00[2];const void*vtable;char unknown0C[0x10];~Activable_Z();};
struct Root:Activable_Z{float unknown1C;~Root(){vtable=__vt__13Manipulator_Z;}};
struct Draw:Root{~Draw(){vtable=__vt__24ManipulatorDraw_802BC9D0;}};
struct ResourcePrefix{u32 unknown00[2];};
struct Resource:ResourcePrefix{virtual~Resource();};
struct Object_800C224C:Draw{
    H1 handle20;char unknown24[0x604-0x24];H2 handle604,handle608,handle60C;char unknown610[0x14];Resource*resource624;
    ~Object_800C224C();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
Object_800C224C::~Object_800C224C(){vtable=lbl_802BF6B0;delete resource624;}
