typedef unsigned long Word;
struct Prefix{char opaque00[0x4];};
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
virtual long apply();
};
extern "C" long fn_80067034(Control*self){return self->apply();}
