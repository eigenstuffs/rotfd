#include "Game/early_menu_record_append_views.h"
extern "C" int fn_800B2F48(MenuAppendOwner*self,const MenuAppendValue*value){int index=self->records.append(*value);return self->index.append(&self->records.data[index]);}
