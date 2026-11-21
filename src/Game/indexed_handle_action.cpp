#include "Game/handle_array_clear_internal.h"
extern "C" void fn_801F86C8(Manager*,const Handle*,short);
struct IndexedActionHandle:ArrayClearNativeHandle {IndexedActionHandle(){value=0;}IndexedActionHandle(const IndexedActionHandle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct IndexedActionObject {char unknown00[0x134];int index;};
struct IndexedActionArray {int count,capacity;IndexedActionHandle*data;IndexedActionHandle&operator[](int i){return data[i];}};
extern "C" signed char fn_80268194(Object*,const Handle&);
extern "C" signed char fn_8026B440(IndexedActionArray*self,const IndexedActionHandle&target){IndexedActionHandle local=(*self)[((IndexedActionObject*)resolved(target))->index];return fn_80268194(resolved(local),target);}
typedef char CheckIndexedActionHandle[sizeof(IndexedActionHandle)==4?1:-1];
