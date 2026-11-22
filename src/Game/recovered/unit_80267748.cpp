// fn_80267748: quad-vs-frustum cull for one face of the six-face (skybox) owner.
// Returns 0 when the face's four corners are all outside one clip plane or all behind the near plane.
typedef unsigned char u8;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 operator+(const Vec3&b)const{return Vec3(x+b.x,y+b.y,z+b.z);}};
struct Vec4{float x,y,z,w;Vec4(){}Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}};
inline Vec4 scale(const Vec4&a,const float&s){return Vec4(a.x*s,a.y*s,a.z*s,a.w*s);}
inline void accumulate(Vec4&a,const Vec4&o){a.x+=o.x;a.y+=o.y;a.z+=o.z;a.w+=o.w;}
struct Matrix{float m[4][4];const Vec3&translation()const{return *(const Vec3*)m[3];}};
struct Frustum:Matrix{float near40;};
struct SixFaceRenderOwner{char unknown00[0x28];Vec3 corners28[8];};
extern "C"{
extern const u8 lbl_802ED130[6][4];
}
inline Vec3 offsetCorner(const Vec3&c,const Vec3&o){return c+o;}
inline void transformPoint(Vec3&r,const Matrix*m,const Vec3&c,const Vec3&o){
 Vec3 p=offsetCorner(c,o);
 r.x=m->m[3][0]+(m->m[0][0]*p.x+m->m[1][0]*p.y+m->m[2][0]*p.z);
 r.y=m->m[3][1]+(m->m[0][1]*p.x+m->m[1][1]*p.y+m->m[2][1]*p.z);
 r.z=m->m[3][2]+(m->m[0][2]*p.x+m->m[1][2]*p.y+m->m[2][2]*p.z);}
inline Vec4 project(const Matrix*f,const Vec3&p){
 Vec4 r;
 r=scale(*(const Vec4*)f->m[0],p.x);
 accumulate(r,scale(*(const Vec4*)f->m[1],p.y));
 accumulate(r,scale(*(const Vec4*)f->m[2],p.z));
 return r;}
extern "C" signed char fn_80267748(SixFaceRenderOwner*self,const Frustum*frustum,const Matrix*local,const Matrix*transform,u8 face){
    Vec3 pos=local->translation();
    Vec4 c0,c1,c2,c3; Vec3 t0,t1,t2,t3;
    transformPoint(t0,transform,self->corners28[lbl_802ED130[face][0]],pos);
    c0=project(frustum,t0);
    transformPoint(t1,transform,self->corners28[lbl_802ED130[face][1]],pos);
    c1=project(frustum,t1);
    transformPoint(t2,transform,self->corners28[lbl_802ED130[face][2]],pos);
    c2=project(frustum,t2);
    transformPoint(t3,transform,self->corners28[lbl_802ED130[face][3]],pos);
    c3=project(frustum,t3);
    if((c0.x<1e-6f&&c1.x<1e-6f&&c2.x<1e-6f&&c3.x<1e-6f)||
       (c0.y<1e-6f&&c1.y<1e-6f&&c2.y<1e-6f&&c3.y<1e-6f)||
       (c0.z<1e-6f&&c1.z<1e-6f&&c2.z<1e-6f&&c3.z<1e-6f)||
       (c0.w<1e-6f&&c1.w<1e-6f&&c2.w<1e-6f&&c3.w<1e-6f)||
       (t0.z<frustum->near40&&t1.z<frustum->near40&&t2.z<frustum->near40&&t3.z<frustum->near40))return 0;
    return 1;
}
