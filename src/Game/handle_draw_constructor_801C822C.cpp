/* Constructor-only ABI views. Original vtables and virtual slots retain their owners. */
typedef unsigned long Word;
struct Handle_801F7F10 { Word value; Handle_801F7F10(); ~Handle_801F7F10(); };
struct HandleDrawZero:Handle_801F7F10 { HandleDrawZero(){value=0;} ~HandleDrawZero(){} };
struct HandleDrawTwoZero:HandleDrawZero { HandleDrawTwoZero(){value=0;} ~HandleDrawTwoZero(){} };
struct HandleDrawThreeZero:HandleDrawTwoZero { HandleDrawThreeZero(){value=0;} ~HandleDrawThreeZero(){} };
struct HandleDrawFourZero:HandleDrawThreeZero { HandleDrawFourZero(){value=0;} ~HandleDrawFourZero(){} };
struct Manager;
struct Context {char pad[0x118];Manager*manager;};
extern "C" {
 void __ct__13Manipulator_ZFv(void*);
 extern char __vt__24ManipulatorDraw_802BC9D0[],lbl_802E9FF8[];
 extern Context lbl_801E9D24;
 void fn_801F86C8(Manager*,const Handle_801F7F10*,short);
}
struct RootPrefix {Word words[2];};
struct Manipulator_Z:RootPrefix {Manipulator_Z();virtual ~Manipulator_Z();virtual void slot0C(Word);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C(float);virtual void slot30();virtual void slot34();virtual void slot38(float);virtual void slot3C();char tail[0x14];};
struct ManipulatorDraw_802BC9D0:Manipulator_Z {ManipulatorDraw_802BC9D0(){}virtual ~ManipulatorDraw_802BC9D0();virtual void slot40();};
struct RootView {Word words[2];void*table;};
struct Array {int count,capacity;void*data;Array(int n=0){count=n;capacity=0;data=0;}};
struct HandleDraw_801C426C {
 ManipulatorDraw_802BC9D0 head;
 Array first,second,third;
 HandleDrawTwoZero a,b;HandleDrawFourZero c;HandleDrawTwoZero d;
 Word untouched54,untouched58;int selected;char unknown60[0x20];
 HandleDraw_801C426C();
};
HandleDraw_801C426C::HandleDraw_801C426C():first((((RootView*)&head)->table=lbl_802E9FF8,0)){
 selected=-1;
 HandleDrawTwoZero empty;
 fn_801F86C8(lbl_801E9D24.manager,&d,-1);
 d.value=empty.value;
 fn_801F86C8(lbl_801E9D24.manager,&empty,1);
}

typedef char HandleDrawSizeCheck[sizeof(HandleDraw_801C426C)==0x80 ? 1 : -1];
