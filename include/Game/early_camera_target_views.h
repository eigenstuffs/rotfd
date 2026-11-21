#ifndef GAME_EARLY_CAMERA_TARGET_VIEWS_H
#define GAME_EARLY_CAMERA_TARGET_VIEWS_H

struct TargetVector{float x,y,z;TargetVector(){} TargetVector(float a,float b,float c):x(a),y(b),z(c){} TargetVector&operator=(const TargetVector&v){x=v.x;y=v.y;z=v.z;return *this;} bool operator!=(const TargetVector&v)const{return x!=v.x||y!=v.y||z!=v.z;}};
struct TargetCamera{char unknown00[0xD0];int state;char unknownD4[4];TargetVector up;char unknownE4[0x10];TargetVector current,direction;char unknown10C[0xC];TargetVector desired;char unknown124[0x28];TargetVector target;char unknown158[0x1D];signed char enabled;};
extern "C"{signed char fn_8007ACAC(TargetCamera*);signed char fn_8007AA9C(TargetCamera*,float);signed char fn_80079D3C(TargetCamera*);signed char fn_8007AB68(TargetCamera*,float);void fn_8007D4B4(TargetVector*,const TargetVector*,TargetVector*,float,float);extern const float lbl_8037899C,lbl_803789A4,lbl_80378A28;}

#endif
