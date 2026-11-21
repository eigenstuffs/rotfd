/* Vertical bob oscillator update: offset = amplitude * sin(phase), pushes the
 * actor's position raised by that offset through virtual slot 0xBC, then
 * advances phase by delta * (pi * speed) and wraps it to zero past 2*pi.
 * Constructor fn_800AB9E4 sets amplitude 0.15 and speed 2.0.
 *
 * The original source used literal 0.0f components (pooled into the shared
 * lbl_80379048).  Referencing the shared label normally lets the front end
 * common the two label loads into an early temporary, which swaps f3/f4;
 * disabling common-subexpression elimination for this function keeps the
 * literal's evaluation order and the original register allocation. */
struct Vec3{
    float x,y,z;
    Vec3(){}
    Vec3(float xx,float yy,float zz):x(xx),y(yy),z(zz){}
    Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
};
struct Prefix{char unknown00[8];};
struct Actor:Prefix{
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
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void setPosition(const Vec3&,int); /* slot 0xBC */
    char unknown0C[0x1A0];
    Vec3 position; /* 0x1AC */
};
struct BobOscillator{
    char unknown00[8];
    Actor*actor;      /* 0x08 */
    char unknown0C[8];
    float offset;     /* 0x14 */
    float phase;      /* 0x18 */
    float amplitude;  /* 0x1C */
    float speed;      /* 0x20 */
};
extern "C"{
    float fn_80284FA8(float);              /* sinf */
    extern const float lbl_80379048;       /* 0.0f */
    extern const float lbl_8037907C;       /* pi */
    extern const float lbl_80379088;       /* 2*pi */
}

#pragma opt_common_subs off
extern "C" void fn_800ABB3C(BobOscillator*self,float delta){
    self->offset=self->amplitude*fn_80284FA8(self->phase);
    Vec3 position=self->actor->position+Vec3(lbl_80379048,self->offset,lbl_80379048);
    self->actor->setPosition(position,0);
    self->phase+=delta*(lbl_8037907C*self->speed);
    if(self->phase>lbl_80379088)self->phase=lbl_80379048;
}
#pragma opt_common_subs reset
