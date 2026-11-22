#ifndef GAME_MOTION_FORWARDING_H
#define GAME_MOTION_FORWARDING_H
struct ForwardVector{float x,y,z;};
struct ForwardActor{char unknown00[0x318];char component[1];};
struct ForwardAction;
extern "C"{
void slot18__10CActorMoveFv(ForwardActor* self);
void slot38__10CActorMoveFf(ForwardActor* self,float delta);
void slot40__10CActorMoveFPC4Vec3PC4Vec3PC4Vec3if(void);
void slot34__9LodMove_ZFv(ForwardActor* self);
void fn_800A4DF0(ForwardAction* self,float delta);
void fn_800A4E50(ForwardAction* self);
void slot40__11CScriptMoveFPC4Vec3PC4Vec3PC4Vec3if(ForwardActor* self,const ForwardVector* first,const ForwardVector* second,float delta);
void slot38__11CScriptMoveFf(ForwardActor* self,float delta);
void fn_800A3798(void);
void fn_800A379C(ForwardAction* self,void* value);
void fn_800A37D0(ForwardAction* self);
void fn_800A386C(ForwardAction* self);
void slot34__10CActorMoveFv(ForwardActor*);void fn_8007DCDC(void*);
}
#endif
