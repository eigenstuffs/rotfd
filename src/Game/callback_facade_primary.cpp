#include "Game/callback_facade_internal.h"

extern "C" void fn_8025E064(void*a,void*b) {fn_8025ED38(a,b,lbl_80378078);fn_8025ED38(a,b,lbl_80378028);}

extern "C" int fn_8025E0B0(void*a,void*b) {
 int value=fn_8025E70C(a,b,lbl_80378078);
 if(value!=-1)return value;
 value=fn_8025E70C(a,b,lbl_80378028);
 if(value!=-1)return value;
 return -1;
}
