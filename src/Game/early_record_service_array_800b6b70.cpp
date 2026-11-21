#include "Game/early_record_service_array_views.h"
extern "C" int fn_800B6B70(ServiceArrayOwner*self){ServiceArrayRecord*record=(ServiceArrayRecord*)fn_801EFA1C(lbl_801EF5C8,0x40,lbl_802A0590,lbl_802A05A0,0x231,4);if(record)record=__ct__22ControllerListDefaultsFv(record);if(self->count+1>self->capacity)growRecords(self,8);new(&self->data[self->count++])ServiceArrayRecord*(record);return self->count-1;}

