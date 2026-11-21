#include "Game/plane_bounds_test_internal.h"
extern "C" signed char fn_8026BED4(const PlaneBounds*self,const BoundsSphere&s,int*flags){
 *flags=0;
 float minimum=self->minimum-s.z;
 float maximum=self->maximum-s.z;
 if(minimum>s.radius||maximum<-s.radius)return 0;
 if(minimum>-s.radius)*flags=1;else if(maximum>-s.radius)*flags|=2;
 float x=s.x,y=s.y,z=s.z;
 float a=self->x[0]*x;
 float b=self->x[1]*x;
 float c=self->x[2]*x;
 float d=self->x[3]*x;
 a+=self->y[0]*y;
 b+=self->y[1]*y;
 c+=self->y[2]*y;
 d+=self->y[3]*y;
 a+=self->z[0]*z;
 b+=self->z[1]*z;
 c+=self->z[2]*z;
 d+=self->z[3]*z;
 float radius=s.radius;
 if(a<-radius||b<-radius||c<-radius||d<-radius)return 0;
 if(a<radius||b<radius||c<radius||d<radius)*flags|=2;
 return 1;
}

extern "C" void fn_80099A00(BoundsSphere*,const void*,const BoundsSphere*);
static inline BoundsSphere transform(const void*matrix,const BoundsSphere*source){BoundsSphere result;fn_80099A00(&result,matrix,source);return result;}
extern "C" signed char fn_8026C028(const PlaneBounds*self,const void*matrix,const BoundsSphere*source,int*flags){BoundsSphere local(transform(matrix,source));return fn_8026BED4(self,local,flags);}
extern "C" signed char fn_8026C094(const PlaneBounds*self,const void*matrix,const BoundsSphere*source,int*flags,BoundsSphere*output){BoundsSphere transformed;fn_80099A00(&transformed,matrix,source);*output=transformed;return fn_8026BED4(self,*output,flags);}
