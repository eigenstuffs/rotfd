#ifndef GAME_CONTROL_POSE_APPLY_800E466C_H
#define GAME_CONTROL_POSE_APPLY_800E466C_H

// Partial offset views for the original actor pose routine.
#pragma fp_contract on
struct PoseApplyVector {
 float x,y,z;
 PoseApplyVector(){}
 PoseApplyVector(float a,float b,float c):x(a),y(b),z(c){}
 PoseApplyVector(const PoseApplyVector&v):x(v.x),y(v.y),z(v.z){}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 PoseApplyVector operator+(const PoseApplyVector&v)const{return PoseApplyVector(x+v.x,y+v.y,z+v.z);}
};
struct PoseApplyBasis {
 float xx,xy,xz,yx,yy,yz,zx,zy,zz;
 PoseApplyVector operator*(const PoseApplyVector&v)const{return PoseApplyVector(xx*v.x+yx*v.y+zx*v.z,xy*v.x+yy*v.y+zy*v.z,xz*v.x+yz*v.y+zz*v.z);}
};
struct PoseApplyMatrix {
 float xx,xy,xz,xw,yx,yy,yz,yw,zx,zy,zz,zw,tx,ty,tz,tw;
 PoseApplyVector operator*(const PoseApplyVector&v)const{float x=tx+(xx*v.x+yx*v.y+zx*v.z),y=ty+(xy*v.x+yy*v.y+zy*v.z),z=tz+(xz*v.x+yz*v.y+zz*v.z);PoseApplyVector out;out.set(x,y,z);return out;}
};
struct PoseApplyQuaternion {float x,y,z,w;};
struct PoseApplyHandle {union{unsigned long value;struct{signed int tag:8,index:24;}bits;};};
struct PoseApplyPrefix{unsigned long unknown00;PoseApplyHandle identity;};
struct PoseApplyNode:PoseApplyPrefix {
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2C();
 virtual void slot30();
 virtual void slot34();
 virtual void reset38();
 virtual void slot3C();
 virtual void slot40();
 virtual void slot44();
 virtual void slot48();
 virtual void slot4C();
 virtual void slot50();
 virtual void slot54();
 virtual void slot58();
 virtual void slot5C();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6C();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual const PoseApplyHandle&matrixHandle(int);
 virtual void slotA0();
 virtual void slotA4();
 virtual void slotA8();
 virtual void slotAC();
 virtual PoseApplyVector position(int);
 char unknown0C[0x24];PoseApplyBasis basis;char unknown54[0xD0];PoseApplyMatrix*transform;
};
struct PoseApplyModel {char unknown00[0x20];PoseApplyHandle transform;};
struct PoseApplyTransform {char unknown00[0x2C];PoseApplyVector position;};
template<class T>struct PoseApplyEntry{T*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
template<class T>struct PoseApplyManager{int count,capacity;PoseApplyEntry<T>*entries;T*resolve(const PoseApplyHandle&h){int index=h.bits.index;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}};
struct PoseApplyContext{char unknown00[0x118];union{PoseApplyManager<PoseApplyNode>*nodes;PoseApplyManager<PoseApplyModel>*models;PoseApplyManager<PoseApplyTransform>*transforms;};};
extern "C" PoseApplyContext lbl_801E9D24;
inline PoseApplyNode*resolve(const PoseApplyHandle&h){return lbl_801E9D24.nodes->resolve(h);}
inline PoseApplyTransform*resolveTransform(const PoseApplyHandle&h){return lbl_801E9D24.transforms->resolve(h);}
inline PoseApplyModel*resolveModel(const PoseApplyHandle&h){return lbl_801E9D24.models->resolve(h);}
struct PoseApplyTargets {char unknown00[0x14];PoseApplyHandle first;unsigned long unknown18;PoseApplyHandle second;};
struct PoseApplyControl{char unknown00[8];PoseApplyNode*actor;char unknown0C[0x3C];PoseApplyTargets*targets;PoseApplyNode*unknown4C;PoseApplyNode*unknown50;PoseApplyNode*second;};
extern "C" {
 signed char fn_8007D604(void*,int);
 signed char fn_80255618(PoseApplyNode*);
 void fn_802554F4(PoseApplyNode*);
 void fn_80255678(PoseApplyNode*);
 void fn_80254BB4(PoseApplyNode*,const PoseApplyVector&);
 void fn_80254AF4(PoseApplyNode*,const PoseApplyVector&,const PoseApplyQuaternion&);
 float fn_8028506C(float);
 float fn_80284FA8(float);
 void fn_801F1AAC(PoseApplyQuaternion*);
 extern const float lbl_803797C8,lbl_803797CC,lbl_803797D4;
}
extern "C" void fn_800E466C(PoseApplyControl*);

#endif
