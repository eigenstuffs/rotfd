#ifndef GAME_ANIMATION_EVENT_CURSOR_RESET_802340F4_H
#define GAME_ANIMATION_EVENT_CURSOR_RESET_802340F4_H

// Partial observed event and cursor views; borrowed runtime/provider identities retain their owners.
typedef unsigned short AnimationHalf;typedef unsigned long AnimationWord;
struct AnimationEventRecord { int command;AnimationWord value;AnimationWord unknown08;float time;char unknown10[0x1c]; };
struct AnimationCursor4 { AnimationHalf a,b,c,flags;void reset(){a=b=c=1;flags=0;} };
struct AnimationCursor8 { AnimationHalf a,b,c,d,e,f,g,h;void reset(){a=b=c=d=e=f=g=h=1;} };
template<class T>struct AnimationCursorArray { int count,capacity;T*items;const int&size()const{return count;} T&operator[](int i){return items[i];} void reset(){int n=size();for(int i=0;i<n;++i)items[i].reset();} };
struct AnimationIndex { AnimationHalf value;void reset(){value=1;} };
struct AnimationEventState { void*active;float age,weight,loopTime;AnimationHalf loopCount,flags;char unknown14[0x4c-0x14];AnimationCursorArray<AnimationCursor4> four;AnimationCursorArray<AnimationCursor8> eight;AnimationCursorArray<AnimationIndex> one;AnimationWord end;void resetAll(){int i;int n=four.size();for(i=0;i<n;++i)four[i].reset();n=eight.size();for(i=0;i<n;++i)eight[i].reset();n=one.size();for(i=0;i<n;++i)one[i].reset();} };
extern "C" {void fn_801C6968(void*);void __construct_array(void*,void(*)(void*),void(*)(void*),AnimationWord,AnimationWord);char fn_801F694C(void*,int,float,float,float,AnimationEventRecord*,int*);void fn_80233944(void*,AnimationEventState*,void*,float,float,float);extern const float lbl_8037B1E0;}

typedef char AnimationEventSize[(sizeof(AnimationEventRecord)==44)?1:-1];
typedef char AnimationCursor4Size[(sizeof(AnimationCursor4)==8)?1:-1];
typedef char AnimationCursor8Size[(sizeof(AnimationCursor8)==16)?1:-1];
typedef char AnimationIndexSize[(sizeof(AnimationIndex)==2)?1:-1];
typedef char AnimationEventStateSize[(sizeof(AnimationEventState)==0x74)?1:-1];
extern "C" void fn_802340F4(void*,AnimationEventState*,void*,float,float);

#endif
