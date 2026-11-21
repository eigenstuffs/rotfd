/* fn_8027F994 / fn_8027FC80: GX hardware light setup (point light and
   directional light + ambient).  fn_8027F994 flips the view matrix's z
   column, builds a point light (direction toward the viewer, position,
   distance attenuation, colour) and loads it into GX_LIGHT1..3 by slot;
   fn_8027FC80 sets the ambient channel colour and a directional light
   placed 10000 units along the light direction from the node position.
   fn_8027FF4C / fn_802800A8 transform skinned vertex positions (and normals)
   by a 3x4 matrix with per-vertex weights; they were written as paired-single
   assembly (psq_l/ps_madd/ps_sum), which this compiler only emits from asm
   function bodies, the form the SDK's own matrix routines use.
   Matching notes: the 255/10000 float literals were pooled per use in the
   original, emulated with distinct read forms of the shared labels; the
   memory-resident Vec3 comes from binding normalize()'s returned *this; the
   user-declared Vec3::operator= keeps the functions in address order (an
   implicit copy assignment defers and reverses emission). */
#pragma fp_contract on
typedef unsigned char u8;
struct GXColor{u8 r,g,b,a;};
struct GXLightObj{unsigned long data[16];};
extern "C"{
void GXInitLightDir(GXLightObj*,float,float,float);
void GXInitLightPos(GXLightObj*,float,float,float);
void GXInitLightAttn(GXLightObj*,float,float,float,float,float,float);
void GXInitLightColor(GXLightObj*,GXColor);
void GXLoadLightObjImm(GXLightObj*,int);
void GXSetChanAmbColor(int,GXColor);
extern const float lbl_8037B7D0;
extern const float lbl_8037B7D4;
extern const float lbl_8037B7D8;
extern const float lbl_8037B7DC;
}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
fres r,f4}return r;}
inline float sqrtLength(float sq){float r=lbl_8037B7D0;if(sq!=r)r=fastSqrt(sq);return r;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return*this;}
 Vec3&normalize();
 Vec3 operator-(const Vec3&o)const{return Vec3(x-o.x,y-o.y,z-o.z);}
 Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
};
struct Mtx44{float m[4][4];
 Vec3 apply(const Vec3&p)const{Vec3 r;r.x=m[0][0]*p.x+m[1][0]*p.y+m[2][0]*p.z+m[3][0];r.y=m[0][1]*p.x+m[1][1]*p.y+m[2][1]*p.z+m[3][1];r.z=m[0][2]*p.x+m[1][2]*p.y+m[2][2]*p.z+m[3][2];return r;}
 void flipZ(){m[0][2]=-m[0][2];m[1][2]=-m[1][2];m[2][2]=-m[2][2];m[3][2]=-m[3][2];}
};
struct PointLight{Vec3 position;float intensity;Vec3 color;float rangeSq;};
struct LightView{char unknown00[0xB8];Vec3 position;};
struct LightEnv{char unknown00[0x84];Vec3 color;Vec3 direction;Vec3 ambient;};
struct LightFrame{float m[3][4];Vec3 position;};
struct LightNode{char unknown00[0x124];LightFrame*frame;Vec3 position()const{return Vec3(frame->position.x,frame->position.y,frame->position.z);}};
#pragma fp_contract off
inline float lengthSq(const Vec3&v){return v.x*v.x+v.y*v.y+v.z*v.z;}
#pragma fp_contract on
inline Vec3&Vec3::normalize(){float r=reciprocalSqrt(lengthSq(*this));x*=r;y*=r;z*=r;return*this;}

extern "C" void fn_8027F994(void*self,int slot,PointLight*light,Mtx44*m,LightView*view){
 GXLightObj obj;
 Vec3 v;
 m->flipZ();
 v=m->apply(view->position-light->position);
 Vec3&n=v.normalize();
 GXInitLightDir(&obj,n.x,n.y,n.z);
 v=m->apply(light->position);
 GXInitLightPos(&obj,v.x,v.y,v.z);
 float s=sqrtLength(light->rangeSq);
 float s2=s*s;
 float k=light->intensity;
 GXInitLightAttn(&obj,k*s2+k*(s*s2),*(const float*)&lbl_8037B7D0,*(const float*)&lbl_8037B7D0,*(const float*)&lbl_8037B7D0,s*k,s*k);
 v=Vec3(light->color.x*lbl_8037B7D4,light->color.y**(const float*)&lbl_8037B7D4,light->color.z**(const float*)(unsigned long)&lbl_8037B7D4);
 GXColor c;
 c.r=v.x;c.g=v.y;c.b=v.z;
 GXInitLightColor(&obj,c);
 switch(slot){
 case 0:GXLoadLightObjImm(&obj,2);break;
 case 1:GXLoadLightObjImm(&obj,4);break;
 case 2:GXLoadLightObjImm(&obj,8);break;
 }
 m->flipZ();
}

extern "C" void fn_8027FC80(void*self,LightEnv*env,Mtx44*m,LightNode*node){
 GXLightObj obj;
 Vec3 v;
 GXColor c;
 v=Vec3(env->ambient.x*lbl_8037B7D4,env->ambient.y**(const float*)&lbl_8037B7D4,env->ambient.z**(const float*)(unsigned long)&lbl_8037B7D4);
 c.r=v.x;c.g=v.y;c.b=v.z;c.a=0xFF;
 GXSetChanAmbColor(5,c);
 v=m->apply(env->direction);
 Vec3&n=v.normalize();
 GXInitLightDir(&obj,n.x,n.y,n.z);
 v=m->apply(node->position()+env->direction**(const float*)&lbl_8037B7D8);
 GXInitLightPos(&obj,v.x,v.y,v.z);
 GXInitLightAttn(&obj,lbl_8037B7DC,lbl_8037B7D0,lbl_8037B7D0,lbl_8037B7DC,lbl_8037B7D0,lbl_8037B7D0);
 v=Vec3(env->color.x*lbl_8037B7D4,env->color.y**(const float*)&lbl_8037B7D4,env->color.z**(const float*)(long)&lbl_8037B7D4);
 c.r=v.x;c.g=v.y;c.b=v.z;c.a=0xFF;
 GXInitLightColor(&obj,c);
 GXLoadLightObjImm(&obj,1);
}

struct Matrix34;
extern "C" asm void fn_8027FF4C(Matrix34*, void*, void*, void*, int, unsigned long, void*, void*, unsigned long) {
    nofralloc
    stwu r1, -0x30(r1)
    stw r3, 0x8(r1)
    stw r4, 0xc(r1)
    stw r5, 0x10(r1)
    stw r6, 0x14(r1)
    stw r7, 0x18(r1)
    stw r8, 0x1c(r1)
    stw r9, 0x20(r1)
    stw r10, 0x24(r1)
    psq_l f2, 0x0(r3), 0, 0
    cmpwi r7, 0x0
    psq_l f3, 0x8(r3), 0, 0
    ble L_802800A0
    psq_l f4, 0x10(r3), 0, 0
    psq_l f5, 0x18(r3), 0, 0
    lwz r11, 0x0(r4)
    psq_l f6, 0x20(r3), 0, 0
    psq_l f7, 0x28(r3), 0, 0
    mulli r11, r11, 0xc
L_8027FF98:
    psq_l f13, 0x4(r4), 1, 0
    addi r4, r4, 0x8
    psq_lx f8, r11, r5, 0, 0
    addi r11, r11, 0x8
    psq_lx f9, r11, r5, 1, 0
    subi r11, r11, 0x8
    ps_mul f10, f2, f8
    lwz r12, 0x0(r4)
    ps_mul f11, f4, f8
    mulli r12, r12, 0xc
    ps_mul f12, f6, f8
    psq_lx f8, r11, r6, 0, 0
    addi r11, r11, 0x8
    ps_madd f10, f3, f9, f10
    subi r7, r7, 0x1
    ps_madd f11, f5, f9, f11
    ps_madd f12, f7, f9, f12
    psq_lx f9, r11, r6, 1, 0
    subi r11, r11, 0x8
    ps_sum0 f10, f10, f10, f10
    ps_sum1 f10, f11, f10, f11
    ps_sum0 f11, f12, f11, f12
    ps_madds0 f8, f10, f13, f8
    ps_madds0 f9, f11, f13, f9
    cmpwi r7, 0x0
    psq_stx f8, r11, r6, 0, 0
    addi r11, r11, 0x8
    psq_stx f9, r11, r6, 1, 0
    mr r11, r12
    bgt L_8027FF98
    lwz r7, 0x38(r1)
    ps_sub f8, f8, f8
    cmpwi r7, 0x0
    ps_merge00 f3, f3, f8
    ble L_802800A0
    ps_merge00 f5, f5, f8
    lwz r12, 0x0(r8)
    ps_merge00 f7, f7, f8
    mulli r12, r12, 0xc
    addc r11, r9, r12
L_80280038:
    psq_l f13, 0x4(r8), 1, 0
    addi r8, r8, 0x8
    psq_l f8, 0x0(r11), 0, 0
    psq_l f9, 0x8(r11), 1, 0
    addc r11, r10, r12
    lwz r12, 0x0(r8)
    ps_mul f10, f2, f8
    mulli r12, r12, 0xc
    ps_mul f11, f4, f8
    ps_mul f12, f6, f8
    ps_madd f10, f3, f9, f10
    ps_madd f11, f5, f9, f11
    ps_madd f12, f7, f9, f12
    psq_l f8, 0x0(r11), 0, 0
    ps_sum0 f10, f10, f10, f10
    psq_l f9, 0x8(r11), 1, 0
    ps_sum1 f10, f11, f10, f11
    ps_sum0 f11, f12, f11, f12
    ps_madds0 f8, f10, f13, f8
    subi r7, r7, 0x1
    ps_madds0 f9, f11, f13, f9
    psq_st f8, 0x0(r11), 0, 0
    cmpwi r7, 0x0
    psq_st f9, 0x8(r11), 1, 0
    addc r11, r9, r12
    bgt L_80280038
L_802800A0:
    addi r1, r1, 0x30
    blr
}

extern "C" asm void fn_802800A8(Matrix34*, void*, void*, void*, int) {
    nofralloc
    stwu r1, -0x20(r1)
    stw r3, 0x8(r1)
    stw r4, 0xc(r1)
    stw r5, 0x10(r1)
    stw r6, 0x14(r1)
    stw r7, 0x18(r1)
    lwz r8, 0x0(r4)
    psq_l f2, 0x0(r3), 0, 0
    psq_l f3, 0x8(r3), 0, 0
    mulli r8, r8, 0xc
    psq_l f4, 0x10(r3), 0, 0
    psq_l f5, 0x18(r3), 0, 0
    add r9, r5, r8
    psq_l f6, 0x20(r3), 0, 0
    psq_l f7, 0x28(r3), 0, 0
    add r10, r6, r8
L_802800E8:
    psq_l f13, 0x4(r4), 1, 0
    psq_l f8, 0x0(r9), 0, 0
    psq_l f9, 0x8(r9), 1, 0
    ps_mul f10, f2, f8
    ps_mul f11, f4, f8
    ps_mul f12, f6, f8
    ps_madd f10, f3, f9, f10
    ps_madd f11, f5, f9, f11
    ps_madd f12, f7, f9, f12
    psq_l f8, 0x0(r10), 0, 0
    psq_l f9, 0x8(r10), 1, 0
    ps_sum0 f10, f10, f10, f10
    ps_sum1 f10, f11, f10, f11
    ps_sum0 f11, f12, f11, f12
    addi r4, r4, 0x8
    ps_madds0 f8, f10, f13, f8
    ps_madds0 f9, f11, f13, f9
    lwz r8, 0x0(r4)
    subi r7, r7, 0x1
    psq_st f14, 0x0(r10), 0, 0
    mulli r8, r8, 0xc
    psq_st f15, 0x8(r10), 1, 0
    cmpwi r7, 0x0
    add r9, r5, r8
    add r10, r6, r8
    bgt L_802800E8
    addi r1, r1, 0x20
    blr
}

