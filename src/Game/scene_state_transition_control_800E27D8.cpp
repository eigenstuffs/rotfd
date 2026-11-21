/* Scene timed state transition; see docs/notes/game-scene-timed-state-transition.md. */
typedef unsigned long Word;
struct Vector { float x,y,z; Vector(float a,float b,float c):x(a),y(b),z(c){} void operator=(Vector v){x=v.x;y=v.y;z=v.z;} void operator+=(Vector v){x+=v.x;y+=v.y;z+=v.z;} };
struct Actor { char unknown00[0x30];unsigned long long flags;char unknown38[0x10C];Vector value;char unknown150[0xA8];char component[1]; };
struct Owner { char unknown00[8];Actor* source;void* service;Actor* actor;float time,phase,rate;Vector reset; };
extern "C" { extern const float lbl_80379788,lbl_80379798,lbl_8037979C;void fn_8007D6A0(void*,int);void fn_80255D88(void*,int,int,int,int); }
inline signed char enabled(Actor*a){signed char result=0;if((a->flags&0x8000000000ULL)!=0)result=1;return result;}
extern "C" void fn_800E27D8(Owner*self,float t){self->time-=t;signed char below=self->source->value.y<lbl_80379788;if(self->time<lbl_80379788||below){fn_8007D6A0(self->actor->component,2);}else{if(enabled(self->actor)){if(self->actor->value.y<lbl_8037979C)fn_80255D88(self->service,0x79,15,0,0);self->actor->value=self->reset;}Actor*actor=self->actor;actor->value+=Vector(lbl_80379788,lbl_80379798*t,lbl_80379788);}}
