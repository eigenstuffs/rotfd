#include "Game/early_actor_index_control_views.h"
extern "C"void fn_800B6374(IndexArrayOwner*self,const IndexHandle*value,int column,int row){IndexHandle*dest=&self->arrays[row]->handles[column];fn_801F86C8(lbl_801E9D24.manager,dest,-1);*dest=*value;fn_801F86C8(lbl_801E9D24.manager,value,1);}
