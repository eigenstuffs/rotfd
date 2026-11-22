// Private native destruction view; original data and complete class layouts stay external.
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[],lbl_802EB7C0[],lbl_802EB518[],lbl_802EB940[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct ObjectsEHHandle1:Handle_801F7F10{};
struct ObjectsEHHandle2:ObjectsEHHandle1{};
struct ObjectsEHHandle3:ObjectsEHHandle2{};
struct ObjectsEHHandle4:ObjectsEHHandle3{};
struct ObjectMove_Z {u32 unknown00[2];void*vtable;char unknown0C[0x168-0xC];~ObjectMove_Z();};
struct ObjectThrow_Z:ObjectMove_Z {
ObjectsEHHandle3 handle168,handle16C;
char unknown170[0x180-0x170];
ObjectsEHHandle3 handle180;
ObjectsEHHandle4 handle184;
char unknown188[0x1AC-0x188];
ObjectsEHHandle4 handle1AC,handle1B0;
~ObjectThrow_Z();
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
ObjectThrow_Z::~ObjectThrow_Z(){vtable=lbl_802EB7C0;}
