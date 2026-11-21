/* Actor approach/idle control transitions (fn_800987AC): elapsed timer,
   height and distance limits and random idle choice; same shape as
   early_actor_approach_control_800961E0.cpp without the recharge timer and
   selected-target checks. */
typedef unsigned long Word;
extern "C" const float lbl_80378D00;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Vec3 {
    float x, y, z;
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378D00;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Node{char unknown0[0x15C];Vec3 velocity;char unknown168[0x318-0x168];char control;char unknown319[0x394-0x319];float threshold;char unknown398[0x3B0-0x398];float elapsed;float range;char unknown3B8[0x3D0-0x3B8];float interval;char unknown3D4[4];float limit;};
extern "C"{void fn_80098CB0(Node*);signed char fn_8007D604(void*,int);void fn_80099F74(Node*,float*);void fn_8009A270(Node*,float*);void fn_8007D6A0(void*,int);int fn_801F1224(int,int);void fn_80099E40(Node*);}
extern "C" void fn_800987AC(Node*self,float delta){
 fn_80098CB0(self);
 if(fn_8007D604(&self->control,3)||fn_8007D604(&self->control,4))return;
 self->elapsed+=delta;
 float distance,height;
 fn_80099F74(self,&distance);
 fn_8009A270(self,&height);
 if(height>self->limit&&!fn_8007D604(&self->control,8))fn_8007D6A0(&self->control,8);
 else if(distance<=self->threshold&&!fn_8007D604(&self->control,7)&&!fn_8007D604(&self->control,8))fn_8007D6A0(&self->control,7);
 else if(self->elapsed>=self->interval&&(fn_8007D604(&self->control,6)||fn_8007D604(&self->control,5))){
  self->elapsed=lbl_80378D00;
  if(fn_801F1224(0,1)){fn_80099E40(self);fn_8007D6A0(&self->control,6);}
  else if(self->velocity.length()<self->range)fn_8007D6A0(&self->control,5);
 }
}
