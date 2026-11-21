/* Original virtual control forwarding; see docs/notes/game-virtual-control-leafs.md. */
typedef unsigned long Word;
struct Prefix{char opaque00[0x1C];};
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
virtual void apply(unsigned long,unsigned char,unsigned char);
};
struct Context{char opaque00[0x154];Control*service;};
extern "C" Context lbl_801E9D24;
extern "C" void fn_80068CB4(void*ignoredSelf,unsigned char ignoredValue){lbl_801E9D24.service->apply(0,0,0);}
