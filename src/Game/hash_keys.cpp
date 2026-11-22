#include "Game/hash_key_tables.h"
typedef unsigned long u32;
typedef signed long s32;
struct PointerKey { s32 tag; const void*vt; u32 value; };
struct IntegerKey { s32 tag; const void*vt; s32 value; };
extern "C" {
extern const char lbl_802ADD00[],lbl_802ADD10[];
extern const char lbl_802EAFA0[];
extern char lbl_801EF5C8[];
void*fn_801EFA1C(void*,u32,const char*,const char*,int,int);
void fn_801EF610(void*,void*);
}
static inline void pointerBase(PointerKey*p){p->vt=lbl_802EAFA0;}
static inline void pointerInit(PointerKey*p){pointerBase(p);p->vt=&lbl_802EAF80;p->value=0;}
static inline void integerBase(IntegerKey*p){p->vt=lbl_802EAFA0;}
static inline void integerInit(IntegerKey*p,s32 value,s32 tag){integerBase(p);p->vt=&lbl_802EAFC0;p->value=value;p->tag=tag;}
extern "C" {
PointerKey*fn_802088D0(PointerKey*t){
 PointerKey*p=(PointerKey*)fn_801EFA1C(lbl_801EF5C8,12,lbl_802ADD10,lbl_802ADD00,0xE7,4);
 if(p){s32 tag=t->tag;pointerInit(p);p->value=t->value;p->tag=tag;}
 return p;
}
signed char fn_80208958(PointerKey*a,PointerKey*b){return a->value!=b->value;}
signed char fn_80208978(PointerKey*a,PointerKey*b){return a->value==b->value;}
u32 fn_80208994(PointerKey*p){u32 x=p->value;u32 a=x>>20;u32 b=(x-(a<<20))>>10;u32 c=x-((x>>10)<<10);return a^(c^b);}
u32 fn_802089BC(PointerKey*p){u32 x=p->value;u32 a=x>>20;u32 b=(x-(a<<20))>>10;u32 c=x-((x>>10)<<10);return a+(c+b);}
void fn_802089E4(PointerKey*p){if(p){p->vt=&lbl_802EAF80;fn_801EF610(lbl_801EF5C8,p);}}
PointerKey*fn_80208A28(PointerKey*p,short flag){if(p){p->vt=&lbl_802EAF80;if(flag>0)fn_801EF610(lbl_801EF5C8,p);}return p;}
void fn_80208A7C(PointerKey*p,const u32*v){p->value=*v;p->tag=-888;}
void fn_80208A90(PointerKey*p,const u32*v){pointerInit(p);p->value=*v;p->tag=-888;}
IntegerKey*fn_80208AC4(IntegerKey*t){
 IntegerKey*p=(IntegerKey*)fn_801EFA1C(lbl_801EF5C8,12,lbl_802ADD10,lbl_802ADD00,0x8D,4);
 if(p){integerInit(p,t->value,t->tag);}
 return p;
}
signed char fn_80208B44(IntegerKey*a,IntegerKey*b){return a->value!=b->value;}
signed char fn_80208B64(IntegerKey*a,IntegerKey*b){return a->value==b->value;}
s32 fn_80208B80(IntegerKey*p){s32 x=p->value;s32 a=x>>20;s32 b=(x-(a<<20))>>10;s32 c=x-((x>>10)<<10);return a^(c^b);}
s32 fn_80208BA8(IntegerKey*p){s32 x=p->value;s32 a=x>>20;s32 b=(x-(a<<20))>>10;s32 c=x-((x>>10)<<10);return a+(c+b);}
void fn_80208BD0(IntegerKey*p){fn_801EF610(lbl_801EF5C8,p);}
void fn_80208BFC(IntegerKey*p,s32 v){integerInit(p,v,-888);}
}
