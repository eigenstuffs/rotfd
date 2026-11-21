/* fn_801F27BC: quaternion rotating direction u onto direction v.
   The axis is cross(u, v); its fast length (frsqrte/fres) is sin of the angle,
   and asin is taken on the far branch when dot(u, v) <= 0. Degenerate (near
   parallel) inputs give the identity rotation. The game_math_* labels are the
   original translation unit's pooled float literals: the second zero use is
   read through a cast so it stays a separate load, as a literal was. The
   (c * s) temporary is materialized on the stack because the member operator
   is called on it. */
extern "C" { extern const float game_math_zero, game_math_epsilon, game_math_one, game_math_half; extern const float lbl_8037A728; }
extern "C" { double asin(double); double cos(double); double sin(double); }
struct Vec3{float x,y,z; Vec3(){} Vec3(float a,float b,float c):x(a),y(b),z(c){}
  Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
  Vec3 operator/(float d)const{float r=game_math_one/d;return Vec3(x*r,y*r,z*r);}
};
extern "C" const Vec3 game_vec3_zero;
inline float dot(const Vec3&a,const Vec3&b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline Vec3 cross(const Vec3&a,const Vec3&b){return Vec3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
inline float fastSqrt(register float x){register float r=game_math_zero;if(x!=r){asm{frsqrte f4,x
 fres r,f4}}return r;}
struct Quat{float w; Vec3 v;};
extern "C" Quat* fn_801F27BC(Quat* q, const Vec3* u, const Vec3* v) {
  Vec3 c = cross(*u, *v);
  float len = fastSqrt(dot(c, c));
  if (len < game_math_epsilon) {
    q->w = game_math_one; q->v = game_vec3_zero;
  } else {
    float half;
    if (dot(*u, *v) > *(const float*)&game_math_zero) { float angle = (float)asin(len); half = angle * game_math_half; }
    else { float angle = lbl_8037A728 - (float)asin(len); half = angle * game_math_half; }
    q->w = (float)cos(half);
    q->v = (c * (float)sin(half)) / len;
  }
  return q;
}
