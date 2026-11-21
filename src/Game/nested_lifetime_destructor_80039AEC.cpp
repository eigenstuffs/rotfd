// Native record and array lifetime views; unobserved fields remain opaque.
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct NestedEHHandle1:Handle_801F7F10{};
struct NestedEHHandle2:NestedEHHandle1{};
struct NestedEHHandle3:NestedEHHandle2{};
struct Array_80039AEC {int count,capacity;NestedEHHandle2*data;~Array_80039AEC();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
Array_80039AEC::~Array_80039AEC(){if(data){for(int i=0;i<count;++i)data[i].~NestedEHHandle2();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(NestedEHHandle2));data=0;}data=0;}}
