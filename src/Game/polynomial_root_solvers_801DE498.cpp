// Quartic and cubic real-root solvers share the natural Newton square-root literal pool.
extern "C" const double lbl_8037A500;
extern "C" {
extern int __float_nan[],__float_huge[];
double __frsqrte(double); double pow(double,double); double acos(double); double cos(double);
}
inline double squareRoot(double x){
 if(x>0.0){double guess=__frsqrte(x);
 guess=0.5*guess*(3.0-guess*guess*x);
 guess=0.5*guess*(3.0-guess*guess*x);
 guess=0.5*guess*(3.0-guess*guess*x);
 guess=0.5*guess*(3.0-guess*guess*x);
 return x*guess;
 }else if(x==0.0)return 0.0;
 else if(x)return *(float*)__float_nan;
 return *(float*)__float_huge;
}
inline double cubeRoot(double x){double result=0.0;if(x>0.0)result=pow((float)x,(1.0/3.0));else if(x<0.0)result=-pow((float)-x,(1.0/3.0));return result;}
inline int solveQuadratic(const double*c,double*s){
 double p=c[1]/(2.0*c[2]),q=c[0]/c[2],D=p*p-q;
 if(D>(-1e-9f)&&D<1e-9f){s[0]=-p;return 1;}
 else if(D<0.0)return 0;
 else{double root=squareRoot(D);s[0]=root-p;s[1]=-root-p;return 2;}
}
extern "C" int fn_801DEA88(const double*,double*);
extern "C" int fn_801DE498(const double*c,double*s){
 double coeffs[4];int num;
 double A=c[3]/c[4],B=c[2]/c[4],C=c[1]/c[4],D=c[0]/c[4];
 double sqA=A*A;
 double p=(-3.0/8.0)*sqA+B;
 double q=(1.0/8.0)*sqA*A-0.5*A*B+C;
 double r=(-3.0/256.0)*sqA*sqA+(1.0/16.0)*sqA*B-0.25*A*C+D;
 double sub=0.25*A;
 if(r>(-1e-9f)&&r<1e-9f){
  coeffs[0]=q;coeffs[1]=p;coeffs[2]=0.0;coeffs[3]=lbl_8037A500;
  num=fn_801DEA88(coeffs,s);s[num++]=0.0;
 }else{
  coeffs[0]=0.5*r*p-(1.0/8.0)*q*q;
  coeffs[1]=-r;coeffs[2]=-0.5*p;coeffs[3]=lbl_8037A500;
  fn_801DEA88(coeffs,s);
  double z=s[0],u=z*z-r,v=2.0*z-p;
  if(u>(-1e-9f)&&u<1e-9f)u=0.0;
  else if(u>0.0)u=squareRoot(u);else return 0;
  if(v>(-1e-9f)&&v<1e-9f)v=0.0;
  else if(v>0.0)v=squareRoot(v);else return 0;
  coeffs[0]=z-u;coeffs[1]=q<0.0?-v:v;coeffs[2]=lbl_8037A500;
  num=solveQuadratic(coeffs,s);
  coeffs[0]=z+u;coeffs[1]=q<0.0?v:-v;coeffs[2]=lbl_8037A500;
  num+=solveQuadratic(coeffs,s+num);
 }
 for(int i=0;i<num;++i)s[i]-=sub;
 return num;
}
extern "C" int fn_801DEA88(const double*c,double*s){
 double A=c[2]/c[3],B=c[1]/c[3],C=c[0]/c[3];
 double sqA=A*A;double sub=(1.0/3.0)*A;
 double p=(1.0/3.0)*((-1.0/3.0)*sqA+B);
 double q=0.5*((2.0/27.0)*A*sqA-sub*B+C);
 double cbp=p*p*p,D=q*q+cbp;
 int num;
 if(D>(-1.0e-9f) && D<1.0e-9f){
  if(q>(-1.0e-9f) && q<1.0e-9f){s[0]=0.0;num=1;}
  else{double u=cubeRoot(-q);s[0]=2.0*u;s[1]=-u;num=2;}
 }else if(D<0.0){
  double phi=(1.0/3.0)*acos(-q/squareRoot(-cbp));
  double t=2.0*squareRoot(-p);
  s[0]=t*cos(phi);s[1]=-t*cos(phi+1.0471975803375244);s[2]=-t*cos(phi-1.0471975803375244);num=3;
 }else{
  double sqrtD=squareRoot(D);
  double u=cubeRoot(sqrtD-q),v=-cubeRoot(sqrtD+q);
  s[0]=u+v;num=1;
 }
 for(int i=0;i<num;++i)s[i]-=sub;
 return num;
}
