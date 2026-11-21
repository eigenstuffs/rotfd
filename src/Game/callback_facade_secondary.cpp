#include "Game/callback_facade_internal.h"

extern "C" void fn_8025E428(void*a,void*b) {fn_8025ED38(a,b,lbl_80378080);fn_8025ED38(a,b,lbl_80378028);}

extern "C" int fn_8025E474(void*a,void*b) {
 int value=fn_8025E70C(a,b,lbl_80378080);
 if(value!=-1)return value;
 value=fn_8025E70C(a,b,lbl_80378028);
 if(value!=-1)return value;
 return -1;
}

extern "C" void fn_8025E4E0(void*,int value) {fn_80287B8C(((Global*)lbl_801E9D24)->target,value);}

extern "C" void fn_8025E50C(Parameter*self) {fn_80287B8C(((Global*)lbl_801E9D24)->target,(int)self->value);}

extern "C" void fn_8025E548(Parameter*self) {fn_80287B9C(((Global*)lbl_801E9D24)->target,(unsigned char)(int)self->value);}

extern "C" void fn_8025E588(VirtualView*self) {fn_80256370(self);self->slot28(0);}

extern "C" void fn_8025E5CC(VirtualView*self) {self->slot28(0);}
