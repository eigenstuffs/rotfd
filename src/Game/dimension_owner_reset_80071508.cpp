// Positive dimensions use the compiler reciprocal-square-root estimate and four Newton refinements.
extern "C"{double __frsqrte(double);}
inline double squareRoot(double x){double estimate=__frsqrte(x);
 estimate=0.5*estimate*(3.0-estimate*estimate*x);
 estimate=0.5*estimate*(3.0-estimate*estimate*x);
 estimate=0.5*estimate*(3.0-estimate*estimate*x);
 estimate=0.5*estimate*(3.0-estimate*estimate*x);
 return x*estimate;}
struct DimensionPrefix{char unknown00[8];};
struct DimensionOwner:DimensionPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28(int,int);
virtual void slot29();
virtual void slot30(int,int);
char unknown0C[0x54];short width,height;short unknown64,mode,unknown68,unknown6A;int flags;char active;};
extern "C"void fn_800717D4(DimensionOwner*);
extern "C"void fn_80071508(DimensionOwner*self){short a=(short)squareRoot(9.0),b=(short)squareRoot(9.0);self->width=a;self->height=b;self->mode=9;self->flags=0;self->active=0;self->unknown6A=0;fn_800717D4(self);self->slot28(0,0);self->slot30(0,0);}
