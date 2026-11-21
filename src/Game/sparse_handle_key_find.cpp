#include "Game/sparse_handle_key_find_internal.h"
extern "C" int fn_8026BC50(SparseHandleKeyPool*self,void*const&key){for(int i=self->first();i>=0;i=self->next(i)){if(*(void**)resolved((*self)[i])==key)return i;}return -1;}
