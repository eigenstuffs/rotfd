#include "Game/early_actor_record_dispatch_views.h"
extern "C"void fn_800B3B94(RecordDispatchQuery*self,int index,void*output){unsigned long values[10];RecordDispatchRecord*record;for(int i=0;i<(record=&self->records[index])->count;++i)values[i]=resolveActor(self->handle)->query(record->key,record->handles[i]);fn_801F44DC(output,record,values);}
