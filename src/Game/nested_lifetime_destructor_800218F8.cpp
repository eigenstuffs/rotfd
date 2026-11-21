// Native record and array lifetime views; unobserved fields remain opaque.
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct NestedEHHandle1:Handle_801F7F10{};
struct NestedEHHandle2:NestedEHHandle1{};
struct NestedEHHandle3:NestedEHHandle2{};
struct Record_800218F8 {char unknown[0x8C];NestedEHHandle3 first,second;~Record_800218F8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
Record_800218F8::~Record_800218F8(){}
