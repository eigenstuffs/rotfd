/* Planar-distance hysteresis toggle. The engine square root is the bare reciprocal of a
   reciprocal-square-root estimate (frsqrte into f4, then fres, no frsp), which no compiler
   built-in produces; it is written as a minimal inline asm statement in the vector helper. */
extern "C" const float lbl_803788A8;
struct Vec3{
 float x,y,z;
 float planarLength()const{
  register float sq=x*x+z*z;
  register float result=lbl_803788A8;
  if(sq!=result){
   asm{frsqrte f4,sq}
   asm{fres result,f4}
  }
  return result;
 }
};
struct Self{char unknown00[0x38];unsigned long long flags38;char unknown40[0x50];signed char active90;char unknown91[3];float enter94;float exit98;};
extern "C"{void fn_80255D88(Self*,int,int,int,int);void fn_80255CBC(Self*,int,int);}
extern "C" void fn_8006F5B8(Self*self,const Vec3*v){
 if(!self->active90&&v->planarLength()>self->enter94){
  fn_80255D88(self,0x79,0xF,0,0);
  self->active90=1;
  self->flags38|=0x20000ULL;
 }else if(self->active90&&v->planarLength()<self->exit98){
  fn_80255CBC(self,0x79,0);
  self->active90=0;
  self->flags38&=~0x20000ULL;
 }
}
