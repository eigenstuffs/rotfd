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
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void apply(unsigned char);
};
extern "C" signed char fn_80068CF8(Control*self,unsigned char value){self->apply(value);return 1;}
