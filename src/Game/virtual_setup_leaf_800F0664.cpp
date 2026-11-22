typedef unsigned long Word;
typedef unsigned long long Flags;
struct Prefix{char opaque00[8];};
struct Control:Prefix{
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void apply();
};
extern "C" void fn_80213920(Control*,int);
extern "C" void fn_80213A18(Control*);
extern "C" void fn_800F0664(Control*self){fn_80213920(self,8);fn_80213A18(self);self->apply();}
