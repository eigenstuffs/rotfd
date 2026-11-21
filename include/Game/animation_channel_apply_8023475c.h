#ifndef GAME_ANIMATION_CHANNEL_APPLY_8023475C_H
#define GAME_ANIMATION_CHANNEL_APPLY_8023475C_H

// Partial observed animation/channel views. Original native providers retain ownership.
typedef unsigned long AnimationChannelWord;
typedef unsigned short AnimationChannelHalf;
struct AnimationChannelHandle {union{AnimationChannelWord value;struct{signed int tag:8,index:24;}bits;};};
struct AnimationChannelCursor4{AnimationChannelHalf a,b,c,flags;void reset(){a=b=c=1;flags=0;}};
struct AnimationChannelCursor8{AnimationChannelHalf a,b,c,d,e,f,g,h;void reset(){a=b=c=d=e=f=g=h=1;}};
struct AnimationChannelCursor1{AnimationChannelHalf value;void reset(){value=1;}};
template<class T>struct AnimationChannelArray{int count,capacity;T*items;const int&size()const{return count;}T&operator[](int i){return items[i];}};
struct AnimationChannelActive{char unknown00[0xC];int count;char unknown10[0x20];float duration;AnimationChannelHalf flags;};
struct AnimationChannelRecord{AnimationChannelWord unknown00;short index;char unknown06[0x4A];};
struct AnimationChannelState{AnimationChannelActive*active;float age,weight,loopTime;AnimationChannelHalf loopCount,flags;char unknown14[0x14];AnimationChannelRecord*records;char unknown2C[0x18];float end;char unknown48[4];AnimationChannelArray<AnimationChannelCursor4>four;AnimationChannelArray<AnimationChannelCursor8>eight;AnimationChannelArray<AnimationChannelCursor1>one;AnimationChannelWord tail;void resetAll(){int i;int n=four.size();for(i=0;i<n;++i)four[i].reset();n=eight.size();for(i=0;i<n;++i)eight[i].reset();n=one.size();for(i=0;i<n;++i)one[i].reset();}};
struct AnimationChannelTarget{char unknown00[0x20];int count,capacity;AnimationChannelHandle*items;};
struct AnimationChannelStorage{AnimationChannelWord unknown00,unknown04;};
struct AnimationChannelCallback:AnimationChannelStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual signed char slot24(int);virtual void slot28(int);};
struct AnimationChannelEntry{AnimationChannelTarget*object;AnimationChannelWord unknown04,unknown08;signed char tag;char unknown0D[3];};
struct AnimationChannelManager{int count,capacity;AnimationChannelEntry*entries;};
struct AnimationChannelGlobal{char unknown00[0x118];AnimationChannelManager*manager;};
struct AnimationChannelOwner{char unknown00[0x20];AnimationChannelState states[4];AnimationChannelHandle target,second,third,callback;};
extern "C"{extern AnimationChannelGlobal lbl_801E9D24;extern const float lbl_8037B1E0,lbl_8037B200;void fn_801AED04(AnimationChannelRecord*,AnimationChannelTarget*,void*,int*,float,float,float);void fn_802340F4(AnimationChannelOwner*,AnimationChannelState*,AnimationChannelTarget*,float,float);void fn_8023297C(AnimationChannelOwner*,const void*,int,unsigned char);void __ct__15Handle_801F7F10Fv(void*);void __dt__15Handle_801F7F10Fv(void*,int);double __fabs(double);}
struct AnimationChannelNativeHandle{AnimationChannelWord value;AnimationChannelNativeHandle(){__ct__15Handle_801F7F10Fv(this);}~AnimationChannelNativeHandle(){__dt__15Handle_801F7F10Fv(this,0);}};
struct AnimationChannelZeroHandle:AnimationChannelNativeHandle{AnimationChannelZeroHandle(){value=0;}};
struct AnimationChannelTwiceZeroHandle:AnimationChannelZeroHandle{AnimationChannelTwiceZeroHandle(){value=0;}};
static inline AnimationChannelTarget*resolve(const AnimationChannelHandle&h){AnimationChannelEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
static inline AnimationChannelCallback*getCallback(AnimationChannelOwner*self){return(AnimationChannelCallback*)resolve(self->callback);}
typedef char StateSize[sizeof(AnimationChannelState)==0x74?1:-1];
typedef char RecordSize[sizeof(AnimationChannelRecord)==0x50?1:-1];
typedef char OwnerSize[sizeof(AnimationChannelOwner)==0x200?1:-1];

extern "C" void fn_8023475C(AnimationChannelOwner*,int,float);
#endif
