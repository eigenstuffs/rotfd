typedef unsigned long ActorCurve_801AEE70_Word;
struct ActorCurve_801AEE70_Curve{int unknown00,count;void*items;int unknown0C;};
struct ActorCurve_801AEE70_Owner{char unknown00[0xC];ActorCurve_801AEE70_Curve position,rotation,scale,actions;};
struct ActorCurve_801AEE70_Vector{float x,y,z;ActorCurve_801AEE70_Vector&operator=(const ActorCurve_801AEE70_Vector&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct ActorCurve_801AEE70_Quaternion{float x,y,z,w;ActorCurve_801AEE70_Quaternion&operator=(const ActorCurve_801AEE70_Quaternion&q){x=q.x;y=q.y;z=q.z;w=q.w;return *this;}};
struct ActorCurve_801AEE70_Actor{char unknown00[0xB8];ActorCurve_801AEE70_Vector position;float unknownC4;ActorCurve_801AEE70_Quaternion rotation;ActorCurve_801AEE70_Vector scale;};
extern "C"{short fn_801AFFE4(ActorCurve_801AEE70_Curve*,ActorCurve_801AEE70_Vector*,short,float);short fn_801AF484(ActorCurve_801AEE70_Curve*,ActorCurve_801AEE70_Quaternion*,short,float);short fn_801F72E4(ActorCurve_801AEE70_Curve*,void*,void*,short,float,float,float);void fn_8023D648(ActorCurve_801AEE70_Actor*);}
extern "C"void fn_801AEE70(ActorCurve_801AEE70_Owner*self,short*indices,ActorCurve_801AEE70_Actor*actor,void*first,void*second,float time0,float time1,float time2){ActorCurve_801AEE70_Vector vector;ActorCurve_801AEE70_Quaternion quaternion;
 if(self->position.count>1){indices[0]=fn_801AFFE4(&self->position,&vector,indices[0],time1);actor->position=vector;}
 if(self->rotation.count>1){indices[1]=fn_801AF484(&self->rotation,&quaternion,indices[1],time1);actor->rotation=quaternion;}
 if(self->scale.count>1){indices[2]=fn_801AFFE4(&self->scale,&vector,indices[2],time1);actor->scale=vector;}
 if(self->actions.count)indices[3]=fn_801F72E4(&self->actions,first,second,indices[3],time0,time1,time2);
}
