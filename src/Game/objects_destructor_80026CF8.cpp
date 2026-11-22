// Private native destruction view; original data and complete class layouts stay external.
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[],lbl_802EB7C0[],lbl_802EB518[],lbl_802EB940[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct ObjectsEHHandle1:Handle_801F7F10{};
struct ObjectsEHHandle2:ObjectsEHHandle1{};
struct ObjectsEHHandle3:ObjectsEHHandle2{};
struct ObjectsEHHandle4:ObjectsEHHandle3{};
struct ObjectThrow_Z {u32 unknown00[2];void*vtable;char unknown0C[0x1B4-0xC];~ObjectThrow_Z();};
struct LodMove_Z:ObjectThrow_Z {
char unknown1B4[0x1F8-0x1B4];
ObjectsEHHandle3 handle1F8;
char unknown1FC[0x230-0x1FC];
ObjectsEHHandle2 handle230;
~LodMove_Z();
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
LodMove_Z::~LodMove_Z(){vtable=lbl_802EB518;}
