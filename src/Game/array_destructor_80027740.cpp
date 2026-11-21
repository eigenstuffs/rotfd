// Native array destruction; element fields outside lifetime behavior remain opaque.
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct ArrayEHHandle1:Handle_801F7F10{};
struct ArrayEHHandle2:ArrayEHHandle1{};
template<int N>struct ArrayEHElement{char unknown[N];~ArrayEHElement(){}};
struct Array_80027740 {
int count,capacity;ArrayEHHandle2*data;
~Array_80027740();
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
Array_80027740::~Array_80027740(){if(data){for(int i=0;i<count;++i)data[i].~ArrayEHHandle2();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ArrayEHHandle2));data=0;}data=0;}}
