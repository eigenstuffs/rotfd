typedef unsigned long Word;
struct Handle_801F7F10{signed int generation:8,index:24;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
extern "C" struct{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;}lbl_801E9D24;
struct Prefix{Word unknown00,unknown04;};
struct Controller{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18(void*,void*,void*,void*,float);};
struct Owner{char unknown00[0x168];char component[1];};
extern "C"{signed char fn_8007D604(void*,int);Controller*fn_8007DCF8(void*);void fn_8021F568(Owner*,void*,void*,void*,void*,float);}
extern "C" void fn_800E1248(Owner*self,void*a,void*b,void*c,void*d,float t){if(fn_8007D604(self->component,1))fn_8007DCF8(self->component)->slot18(a,b,c,d,t);else fn_8021F568(self,a,b,c,d,t);}
