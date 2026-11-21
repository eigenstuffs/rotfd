#ifndef GAME_EARLY_ACTOR_REFLECTION_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_REFLECTION_CONTROL_VIEWS_H
struct ReflectionControlVector{float x,y,z;ReflectionControlVector&operator=(const ReflectionControlVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct ReflectionControlActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x2E8];void*record;char unknown324[0x30];float speed;char unknown358[0xB4];signed char enabled40C;};
struct ReflectionControlOwner{void*vtable;unsigned char enabled;char unknown05[3];ReflectionControlActor*actor;void*controller;char unknown10[0x30];ReflectionControlVector vector;float speed;};
struct ReflectionControlMonitor{char unknown00[0x130];void*first,*second;};
extern "C"{extern ReflectionControlMonitor*lbl_803776B8;extern const float lbl_80378AD0;extern char lbl_802B92B0[],lbl_802B8EA4[];extern const ReflectionControlVector game_vec3_zero;void fn_80090084(void*);void fn_80068158(ReflectionControlMonitor*,void*);}
#endif
