#ifndef GAME_MOTION_FORWARDING_H
#define GAME_MOTION_FORWARDING_H
struct ForwardVector{float x,y,z;};
struct ForwardActor{char unknown00[0x318];char component[1];};
struct ForwardAction;
extern "C"{
void fn_8009AB58(ForwardActor* self);
void fn_8009ACBC(ForwardActor* self,float delta);
void fn_8009AEA4(void);
void fn_80224888(ForwardActor* self);
void fn_800A4DF0(ForwardAction* self,float delta);
void fn_800A4E50(ForwardAction* self);
void fn_8009E640(ForwardActor* self,const ForwardVector* first,const ForwardVector* second,float delta);
void fn_8009DF78(ForwardActor* self,float delta);
void fn_800A3798(void);
void fn_800A379C(ForwardAction* self,void* value);
void fn_800A37D0(ForwardAction* self);
void fn_800A386C(ForwardAction* self);
void fn_8009BEE8(ForwardActor*);void fn_8007DCDC(void*);
}
#endif
