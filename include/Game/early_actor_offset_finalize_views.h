#ifndef GAME_EARLY_ACTOR_OFFSET_FINALIZE_VIEWS_H
#define GAME_EARLY_ACTOR_OFFSET_FINALIZE_VIEWS_H
struct OffsetVector{float x,y,z;OffsetVector(float a,float b,float c):x(a),y(b),z(c){}OffsetVector operator+(const OffsetVector&v)const{return OffsetVector(x+v.x,y+v.y,z+v.z);}void set(float a,float b,float c){x=a;y=b;z=c;}void add(float a,float b,float c){x+=a;y+=b;z+=c;}OffsetVector&operator+=(const OffsetVector&v){*this=*this+v;return*this;}};
struct OffsetRecord{int word;};
struct OffsetActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x10C];OffsetVector position;char unknown150[0x1C8];OffsetRecord record;char unknown31C[8];int state;char unknown328[0x30];OffsetVector offset;char unknown364[0x64];float height;int previousState;signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}void clearFlags(unsigned long long mask){flags&=~mask;}};
struct OffsetOwner{char unknown00[8];OffsetActor*actor;};
extern "C"{extern const float lbl_80378E40;signed char fn_8009FABC(OffsetActor*,int);void fn_800A4E30(OffsetOwner*);void fn_800A4DF0(OffsetOwner*,float);void fn_8007D6A0(OffsetRecord*,int);}
#endif
