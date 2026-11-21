struct TransformOwnerVector {float x,y,z;TransformOwnerVector(){}TransformOwnerVector(float a,float b,float c):x(a),y(b),z(c){}};
struct TransformOwnerQuaternion {float x,y,z,w;};
struct TransformOwnerInput {char unknown00[0x30];float basis[9];};
struct TransformOwnerUpdateView {char unknown00[0xC];TransformOwnerVector position;float positionW;char unknown1C[0x58];TransformOwnerQuaternion rotation;TransformOwnerVector scale,direction;char unknown9C[0x10];TransformOwnerVector offset;};
extern "C" {
void fn_801F20F4(TransformOwnerQuaternion*,const float*);
void fn_801F1BB0(TransformOwnerQuaternion*,const TransformOwnerQuaternion*);
void fn_801F1B1C(TransformOwnerVector*,const TransformOwnerQuaternion*,const TransformOwnerVector*);
extern const float lbl_8037B3A8,lbl_8037B3AC;
}
extern "C" void fn_80243FA8(TransformOwnerUpdateView*self,const TransformOwnerInput*input) {
 TransformOwnerQuaternion rotation;
 fn_801F20F4(&rotation,input->basis);
 fn_801F1BB0(&rotation,&self->rotation);
 self->direction.x=lbl_8037B3A8;
 self->direction.y=lbl_8037B3A8;
 self->direction.z=lbl_8037B3AC;
 TransformOwnerVector direction;
 fn_801F1B1C(&direction,&rotation,&self->direction);
 self->direction=direction;
 self->position=TransformOwnerVector(self->offset.x+self->direction.x,self->offset.y+self->direction.y,self->offset.z+self->direction.z);
 self->positionW=lbl_8037B3AC;
}
