#ifndef GAME_ACTOR_MATRIX_OFFSET_801BCD74_H
#define GAME_ACTOR_MATRIX_OFFSET_801BCD74_H
#pragma fp_contract on
struct ActorOffsetVec3 {
 float x,y,z;
 ActorOffsetVec3(){}
 ActorOffsetVec3(float a,float b,float c):x(a),y(b),z(c){}
 ActorOffsetVec3(const ActorOffsetVec3&a):x(a.x),y(a.y),z(a.z){}
 ActorOffsetVec3&operator=(const ActorOffsetVec3&a){x=a.x;y=a.y;z=a.z;return *this;}
 ActorOffsetVec3 operator+(const ActorOffsetVec3&a)const{return ActorOffsetVec3(x+a.x,y+a.y,z+a.z);}
 ActorOffsetVec3 operator-(const ActorOffsetVec3&a)const{return ActorOffsetVec3(x-a.x,y-a.y,z-a.z);}
 ActorOffsetVec3&operator-=(const ActorOffsetVec3&a){x-=a.x;y-=a.y;z-=a.z;return *this;}
};
extern "C" const ActorOffsetVec3 game_vec3_zero;
struct ActorOffsetMatrix {float m[4][4];ActorOffsetVec3 point(const ActorOffsetVec3&v)const{ActorOffsetVec3 r;r.x=m[0][0]*v.x+m[1][0]*v.y+m[2][0]*v.z+m[3][0];r.y=m[0][1]*v.x+m[1][1]*v.y+m[2][1]*v.z+m[3][1];r.z=m[0][2]*v.x+m[1][2]*v.y+m[2][2]*v.z+m[3][2];return r;}};
struct ActorOffsetResource {char unknown00[0x124];ActorOffsetMatrix*matrix;};
struct ActorOffsetStorage {char unknown00[8];};
struct ActorOffsetOwner:ActorOffsetStorage {
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void clearFlags(unsigned long long,int);virtual void slotE0();virtual void slotE4();virtual unsigned long long getFlags(int);virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();virtual void slot108();virtual void slot10C();virtual void slot110();virtual void slot114();virtual void slot118();virtual ActorOffsetResource*getVectors(ActorOffsetVec3*,ActorOffsetVec3*,ActorOffsetVec3*,int);
};

extern "C" ActorOffsetVec3 slot110__12ObjectMove_ZFv(ActorOffsetOwner*,const ActorOffsetVec3&,ActorOffsetVec3*,ActorOffsetVec3*,int);
#endif
