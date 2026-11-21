// Native record and array lifetime views; unobserved fields remain opaque.
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct NestedEHHandle1:Handle_801F7F10{};
struct NestedEHHandle2:NestedEHHandle1{};
struct NestedEHHandle3:NestedEHHandle2{};
struct RecordBase_80025634 {u32 unknown0;NestedEHHandle2 handle4;char unknown8[16];~RecordBase_80025634(){}};struct RecordDerived_80025634:RecordBase_80025634 {~RecordDerived_80025634(){}};
struct Array_80025634 {int count,capacity;RecordDerived_80025634*data;~Array_80025634();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
Array_80025634::~Array_80025634(){if(data){for(int i=0;i<count;++i)data[i].~RecordDerived_80025634();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(RecordDerived_80025634));data=0;}data=0;}}
