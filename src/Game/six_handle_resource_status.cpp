#include "six_handle_resource_internal.h"
static inline Activable_Z* resolved(const Handle_801F7F10& handle){
    int index=handle.bits.index;
    Manager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==handle.bits.generation?m->entries[index].object:0;
}
signed char SixHandleResource_802EA840::slot1C(){
    if(!BaseObject_Z::slot1C())return 0;
    for(int i=0;i<6;++i){
        if(fn_801F7EB8(&handles[i]))resolved(handles[i])->slot1C();
    }
    return 1;
}
