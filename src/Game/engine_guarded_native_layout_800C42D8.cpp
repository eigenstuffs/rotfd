typedef unsigned long u32;
extern "C" char lbl_802BF7DC[];
struct Manipulator_Z {u32 unknown00[2];void*vtable;char unknown0C[0x20-0xC];Manipulator_Z();~Manipulator_Z();};
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct H1:Handle_801F7F10 {H1(){word=0;}~H1();};
struct H2:H1 {H2(int){word=0;}~H2();};
struct Object_800C42D8:Manipulator_Z {char unknown20[0xC];H2 handle2C;unsigned char field30,field31;Object_800C42D8();};
Object_800C42D8::Object_800C42D8():handle2C((vtable=lbl_802BF7DC,0)){field30=0;field31=0;}
