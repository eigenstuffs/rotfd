/* Original record resource lifecycle; see docs/notes/game-engine-record-lifecycle.md. */
typedef unsigned long u32;
struct Service{char opaque00[0x15058];void*field15058;};
extern "C" {extern struct{char opaque00[0x124];Service*service124;}lbl_801E9D24;float fn_8025E268(void*,int);}
struct View{char opaque00[0x60];signed char flag60;char opaque61[3];u32 field64;char opaque68[8];void*field70;};
extern "C" void fn_800E770C(View*self){self->flag60=(signed char)fn_8025E268(self,1);self->field64=(unsigned char)fn_8025E268(self,2);self->field70=lbl_801E9D24.service124->field15058;}
