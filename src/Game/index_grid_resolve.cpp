#include "Game/handle_array_clear_internal.h"
#include "Game/index_grid_records_internal.h"
extern "C" void fn_801B3F0C(Manager*,Handle*,void*);
struct GridResolveArray {int count,capacity;IndexGridRecord*data;IndexGridRecord&operator[](int i){return data[i];}};
struct GridResolveView {char unknown00[0x34];GridResolveArray records;};
static inline void*getContext(const IndexGridRecord&r){return r.context;}
extern "C" void fn_802667F0(GridResolveView*self){
 ArrayClearTypedHandle local;
 for(int i=0;i<self->records.count;++i){
  if(getContext(self->records[i])){fn_801B3F0C(lbl_801E9D24.manager,&local,getContext(self->records[i]));IndexGridRecord*record=&self->records[i];record->context=resolved(local);}
 }
}
