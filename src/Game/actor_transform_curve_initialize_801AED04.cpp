/* Actor transform curve application reconstruction; see docs/notes/game-actor-transform-curve-apply.md. */
typedef unsigned long ActorCurve_801AED04_Word;
struct ActorCurve_801AED04_Curve{int unknown00,count;void*items;int unknown0C;};
struct ActorCurve_801AED04_Owner{char unknown00[0xC];ActorCurve_801AED04_Curve position,rotation,scale,actions;};
struct ActorCurve_801AED04_Vector{float x,y,z;ActorCurve_801AED04_Vector&operator=(const ActorCurve_801AED04_Vector&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct ActorCurve_801AED04_Quaternion{float x,y,z,w;ActorCurve_801AED04_Quaternion&operator=(const ActorCurve_801AED04_Quaternion&q){x=q.x;y=q.y;z=q.z;w=q.w;return *this;}};
struct ActorCurve_801AED04_Actor{char unknown00[0xB8];ActorCurve_801AED04_Vector position;float unknownC4;ActorCurve_801AED04_Quaternion rotation;ActorCurve_801AED04_Vector scale;};
extern "C"{short fn_801AFFE4(ActorCurve_801AED04_Curve*,ActorCurve_801AED04_Vector*,short,float);short fn_801AF484(ActorCurve_801AED04_Curve*,ActorCurve_801AED04_Quaternion*,short,float);short fn_801F72E4(ActorCurve_801AED04_Curve*,void*,void*,short,float,float,float);void fn_8023D648(ActorCurve_801AED04_Actor*);}
extern "C"void fn_801AED04(ActorCurve_801AED04_Owner*self,ActorCurve_801AED04_Actor*actor,void*first,void*second,float time0,float time1,float time2){ActorCurve_801AED04_Vector vector;ActorCurve_801AED04_Quaternion quaternion;
 if(self->position.count){fn_801AFFE4(&self->position,&vector,1,time1);actor->position=vector;}
 if(self->rotation.count){fn_801AF484(&self->rotation,&quaternion,1,time1);actor->rotation=quaternion;}
 if(self->scale.count){fn_801AFFE4(&self->scale,&vector,1,time1);actor->scale=vector;}
 if(self->actions.count)fn_801F72E4(&self->actions,first,second,0,time0,time1,time2);
 fn_8023D648(actor);
}
