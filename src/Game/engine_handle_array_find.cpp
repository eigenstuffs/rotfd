#include "Game/engine_handle_array_find.h"

static inline void assign(Handle_801F7F10 &destination,const Handle_801F7F10 &source) {
    fn_801F86C8(lbl_801E9D24.manager,&destination,-1);
    destination.value=source.value;
    fn_801F86C8(lbl_801E9D24.manager,&source,1);
}
static inline ArrayFindObject *resolve(const Handle_801F7F10 &handle) {
    ArrayFindEntry *entry=&lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->tag==handle.bits.tag ? entry->object : 0;
}
extern "C" void fn_8023A8C0(ArrayFind*self,const unsigned long*key,Handle_801F7F10*out) {
    assign(*out,ArrayFindZero2());
    int count=self->count;
    int offset;
    int i=0;
    offset=0;
    for(;i<count;offset+=4,++i) {
        if(fn_801F7EB8((Handle_801F7F10*)((char*)self->handles+offset))) {
            ArrayFindObject *object=resolve(*(Handle_801F7F10*)((char*)self->handles+offset));
            if(object->key==*key) {
                assign(*out,self->handles[i]);
                break;
            }
        }
    }
}
