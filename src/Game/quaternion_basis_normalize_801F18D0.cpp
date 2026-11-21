// Partial text split: fn_801F18D0 (basis matrix from direction/up) and
// fn_801F1AAC (fast quaternion normalization). fn_801F14E0 (99.66%) before
// them and fn_801F1B1C/fn_801F1BB0 (~95.5%) after them remain original code;
// full draft: scratch/claude_match/auto_03_801F14E0_text/final.cpp.
/* Engine quaternion/basis helpers at 0x801F14E0..0x801F1C64 (part of the
   original math translation unit that follows random.cpp).
   - fn_801F14E0: quaternion turning the forward axis (0,0,1) onto direction a
     with up axis b: yaw about b by acos(flat.z) (sign from b . (fwd x flat)),
     then pitch about normalize(h x b) by acos(h . a), result = pitch * yaw.
   - fn_801F18D0: basis matrix (rows right, up, forward) from direction/up.
   - fn_801F1AAC: fast in-place quaternion normalization.
   - fn_801F1B1C: rotates a vector by a quaternion (q * v * conj(q)).
   - fn_801F1BB0: in-place quaternion product (a = a * b).
   Matching notes: the game_math_* labels are the original TU's pooled float
   literals; reads through *(const float*)& / (unsigned long) casts keep a use
   as a separate load as a literal was. Vec3/Quat have user-declared copy
   operations: with compiler-generated struct copies this compiler defers
   fn_801F14E0/fn_801F18D0 and emits them after the leaf functions, and the
   copies also change fn_801F14E0's register allocation. The temporary
   Vec3(0,0,1) receiving a member call is materialized at sp+8 (and the cross
   result at sp+0x14), as in the original. fn_801F18D0 needs expression
   propagation off; fn_801F1BB0 is closest with common subexpressions off.
   The fast sqrt / rsqrt helpers are the established inline asm ones. */
extern "C" { extern const float game_math_zero, game_math_epsilon, game_math_one, game_math_negative_one, game_math_half; }
extern "C" { double __fabs(double); void* memset(void*,int,unsigned long); float fn_80284DD8(float); float fn_8028506C(float); float fn_80284FA8(float); }
struct Vec3{float x,y,z; Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
  Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
  Vec3& operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}
  Vec3 cross(const Vec3&b)const{return Vec3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);}
};
extern "C" const Vec3 game_vec3_zero;
inline float dot(const Vec3&a,const Vec3&b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline Vec3 cross(const Vec3&a,const Vec3&b){return Vec3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
struct Quat{float w,x,y,z; Quat(){} Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}
  Quat(const Quat&o):w(o.w),x(o.x),y(o.y),z(o.z){}
  Quat& operator=(const Quat&o){w=o.w;x=o.x;y=o.y;z=o.z;return *this;}};
extern "C" const Quat game_quat_identity;
struct Matrix4{float m[4][4];};
inline float fastSqrt(register float x){register float r=game_math_zero;if(x!=r){asm{frsqrte f4,x
 fres r,f4}}return r;}
inline float frsqrte(register float x){register float r;asm{frsqrte r,x}return r;}
inline float rsqrt(register float x){register float r=game_math_zero;if(x!=r){asm{frsqrte r,x}}return r;}
inline float clampUnit(float c){if(c>*(const float*)&game_math_one)c=*(const float*)(unsigned long)&game_math_one;if(c<game_math_negative_one)c=game_math_negative_one;return c;}
inline Quat axisAngle(const Vec3&axis,float angle){float half=angle*game_math_half;Quat q;q.w=fn_8028506C(half);float s=fn_80284FA8(half);q.x=axis.x*s;q.y=axis.y*s;q.z=axis.z*s;return q;}
inline Quat mul(const Quat&l,const Quat&r){
    return Quat(
        l.w * r.w - l.x * r.x - l.y * r.y - l.z * r.z,
        l.w * r.x + l.x * r.w + l.y * r.z - l.z * r.y,
        l.w * r.y + l.y * r.w + l.z * r.x - l.x * r.z,
        l.w * r.z + l.z * r.w + l.x * r.y - l.y * r.x);
}
inline int pairEqual(float x,float y){int result=0;if((float)__fabs(x)<game_math_epsilon){if((float)__fabs(y)<game_math_epsilon)result=1;}return result;}
inline signed char vecEqual(float x,float y,float z){signed char result=0;if(pairEqual(x,y)&&(float)__fabs(z)<game_math_epsilon)result=1;return result;}


#pragma opt_propagation off
extern "C" void fn_801F18D0(const Vec3* dir, const Vec3* up, Matrix4* out) {
Vec3 c = cross(*dir, *up); Vec3 r;
  if (vecEqual(c.x-game_vec3_zero.x, c.y-game_vec3_zero.y, c.z-game_vec3_zero.z)) { r = Vec3(game_math_one, game_math_zero, *(const float*)&game_math_zero); }
  else { float s = frsqrte(c.x*c.x + c.y*c.y + c.z*c.z); r.x = c.x*s; r.y = c.y*s; r.z = c.z*s; }
  Vec3 u = cross(r, *dir);
  memset(out, 0, sizeof(Matrix4));
  out->m[0][0] = game_math_one; out->m[1][1] = game_math_one; out->m[2][2] = game_math_one; out->m[3][3] = game_math_one;
  out->m[0][0] = r.x; out->m[0][1] = r.y; out->m[0][2] = r.z;
  out->m[1][0] = u.x; out->m[1][1] = u.y; out->m[1][2] = u.z;
  out->m[2][0] = dir->x; out->m[2][1] = dir->y; out->m[2][2] = dir->z;
}
#pragma opt_propagation reset

extern "C" void fn_801F1AAC(Quat*q){
  float r = rsqrt(q->x*q->x + q->y*q->y + q->z*q->z + q->w*q->w);
  q->x*=r; q->y*=r; q->z*=r; q->w*=r;
}


