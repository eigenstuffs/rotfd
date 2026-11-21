typedef unsigned long TailWord;
extern "C" {
extern const char lbl_802EC720[],lbl_802ED000[],lbl_802EC798[],lbl_802ECAF8[];
extern char lbl_801EF5C8[],lbl_8028F698[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {TailWord word;Handle_801F7F10();~Handle_801F7F10();};
struct TailZero:Handle_801F7F10 {TailZero(){word=0;}~TailZero(){}};
struct TailZero2:TailZero {TailZero2(){word=0;}~TailZero2(){}};
struct TailZero3:TailZero2 {TailZero3(){word=0;}~TailZero3(){}};
struct TailElement {TailWord value;~TailElement(){}};
struct TailPool {
    int count,capacity;TailElement*data;
    ~TailPool(){if(data){for(int i=0;i<count;++i)data[i].~TailElement();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}
};
struct Object_8025F0D8 {
    TailWord unknown0[2];const void*vtable;char unknownC[0x3C];
    ~Object_8025F0D8();
    static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct TailContainerBase:Object_8025F0D8 {
    TailPool pool;TailWord unknown54;TailZero2 handle58;char unknown5C[4];
    ~TailContainerBase(){vtable=lbl_802EC720;}
};
struct TailContainerLayer:TailContainerBase {~TailContainerLayer(){vtable=lbl_802ED000;}};
struct TailHandleOwner:TailContainerLayer {
    TailZero2 handle60;TailZero3 handle64;
    ~TailHandleOwner(){vtable=lbl_802EC798;}
};
struct CallbackTailOwnerSecond:TailHandleOwner {~CallbackTailOwnerSecond();};
CallbackTailOwnerSecond::~CallbackTailOwnerSecond(){vtable=lbl_802ECAF8;}
