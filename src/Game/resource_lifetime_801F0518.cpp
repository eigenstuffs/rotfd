// Recovered resource cleanup and cursor serialization; see unit note.
#include "Game/resource_lifetime_801F0518_internal.h"
extern "C" {
ResourceLifetimeView *fn_801F0518(ResourceLifetimeView *self,short flag){
 if(self){self->vtable=lbl_802EA958;fn_80243E90(self,0);if(flag>0)fn_801EF610(lbl_801EF5C8,self);}return self;
}
void fn_801F0580(ResourceLifetimeView*self,void**cursor){
 fn_80243E44(self,cursor);
 char *start=self->stored;char *end=self->extension;
 *cursor=fn_801E9F40(start,*cursor,end-start+64);
}
}
