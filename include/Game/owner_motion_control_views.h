#ifndef GAME_OWNER_MOTION_CONTROL_VIEWS_H
#define GAME_OWNER_MOTION_CONTROL_VIEWS_H
struct MotionControlVec2{float x,y;};
struct MotionControlVec3{float x,y,z;MotionControlVec3(){}MotionControlVec3(float a,float b,float c):x(a),y(b),z(c){}MotionControlVec3(const MotionControlVec3&v):x(v.x),y(v.y),z(v.z){}MotionControlVec3&operator=(const MotionControlVec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct MotionControlAgent{char unknown00[0x318];char controls[8];int state,selector;char unknown328[0x6C];float timer;MotionControlVec3 anchor,direction;float distance,nearDistance,threshold;char unknown3BC[0x10];int previous;char unknown3D0;signed char forward;};
struct MotionControlAction{char unknown00[8];MotionControlAgent*agent;};
struct MotionControlContext{char unknown00[0x110];void*diagnostics;};
extern "C"{extern MotionControlContext lbl_801E9D24;extern const char lbl_8029E588[];extern const float lbl_80378E40,lbl_80378E44;void*fn_8009F170(MotionControlAgent*);float fn_8009F3E8(MotionControlAgent*,void*,MotionControlVec2*);float fn_8009F684(MotionControlAgent*);float fn_8009F558(MotionControlAgent*,MotionControlVec2*);void fn_8009EEC4(MotionControlAgent*);void fn_8009ED90(MotionControlAgent*,const MotionControlVec3&,float);void fn_800A4DF0(MotionControlAction*,float);void fn_800A4E30(MotionControlAction*);void fn_8007D6A0(void*,int);signed char fn_8009C12C(MotionControlAgent*,int);signed char fn_8009FABC(MotionControlAgent*,int);void fn_801F9D68(void*,const char*,...);}
inline void applyMotionControl(MotionControlAction*self,float delta,const MotionControlVec3&v){self->agent->direction=v;fn_8009ED90(self->agent,v,delta);fn_800A4DF0(self,delta);}
#endif
