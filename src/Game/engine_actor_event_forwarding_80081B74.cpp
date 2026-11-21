/* Original actor event forwarding; see docs/notes/game-engine-actor-event-forwarding.md. */
struct Actor{char opaque00[0x318];char component318[0x40C-0x318];signed char enabled40C;};
struct Owner{char opaque00[8];Actor*actor08;void*control0C;char opaque10[0x30];float time40;};
extern "C" {signed char fn_8025E9FC(void*,int);signed char fn_8007D6A0(void*,int);int fn_80092844(Actor*);void fn_80092DAC(Actor*,double);void fn_8008CE2C(Owner*);void fn_8008D86C(Owner*);void fn_8025795C(void*,int,int);extern const float lbl_80378AD4,lbl_80378AD0;struct Service{char opaque00[0x2E];signed char enabled2E;};extern struct Global{char opaque00[0x164];Service*service164;}lbl_801E9D24;}
extern "C" {void fn_80092BF4(Actor*,int,double);void fn_80257828(void*,int,int,int);}
extern "C" signed char fn_8007D604(void*,int);
extern "C" void fn_80081B74(Owner*self,float delta){fn_80092BF4(self->actor08,3,delta);fn_80092DAC(self->actor08,delta);self->time40+=delta;int index=-1;fn_8007D604(self->actor08->component318,3);if(index!=7)index=fn_80092844(self->actor08);if(index!=3)fn_8007D6A0(self->actor08->component318,index);}
