#include "Game/early_menu_record_control_views.h"
extern "C"int fn_800A5774(MenuRecordArray*self,const MenuRecordValue*v){if(self->count+1>self->capacity){self->grow(self->capacity+8);self->capacity+=8;}new(&self->data[self->count++])MenuRecordValue(*v);return self->count-1;}
