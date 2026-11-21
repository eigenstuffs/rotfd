#include "Game/handle_key_find_internal.h"
extern "C" KeyFindTypedHandle fn_8026A494(KeyFindView*self,void*const&key){
 int i;for(i=0;i<self->first.count;++i){if(*(void**)resolved(self->first[i])==key)return self->first[i];}
 for(i=0;i<self->second.count;++i){if(*(void**)resolved(self->second[i])==key)return self->second[i];}
 return KeyFindTypedHandle();
}
