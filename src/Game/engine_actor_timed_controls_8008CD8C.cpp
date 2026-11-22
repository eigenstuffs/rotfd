struct Actor{char opaque00[0x318];char component318[1];};
struct Owner{char opaque00[8];Actor*actor08;void*control0C;char opaque10[0x30];float time40;};
extern "C" {signed char fn_8025E9FC(void*,int);signed char fn_8007D6A0(void*,int);int fn_80092844(Actor*);void fn_80092DAC(Actor*,double);void fn_8008CE2C(Owner*);void fn_8008D86C(Owner*);void fn_8025795C(void*,int,int);extern const float lbl_80378AD4,lbl_80378AD0;struct Service{char opaque00[0x2E];signed char enabled2E;};extern struct Global{char opaque00[0x164];Service*service164;}lbl_801E9D24;}
extern "C" void fn_8008CD8C(Owner*self,double delta){if(fn_8025E9FC(self->control0C,0x8D))fn_8008CE2C(self);fn_80092DAC(self->actor08,delta);}
