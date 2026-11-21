/* Early actor vertical-direction step (fn_80082570). Below the 0.9 threshold
 * on the actor direction's y component, the velocity at +0x144 becomes the
 * flattened unit direction (y cleared) scaled by 15 and the scene vector
 * lbl_802F4198 records the actor position. Above it, while the accumulated
 * motion time lbl_80377768 is under 0.5, the time advances by the frame
 * delta and the velocity becomes the stored scene vector damped by
 * lbl_80374A18 (0.99), which is then copied back; once the time has run out
 * the actor record receives command 0x14. The actor motion update
 * fn_80092DAC always follows.
 *
 * Matching notes: the original multiplied by a pooled 15.0f literal, which
 * the IR does not CSE (the backend merges the three loads into one lfs that
 * colors before the dot-product temporary). Reading the shared label through
 * three distinct but equivalent lvalue forms reproduces that (see
 * owner_launch_direction_setup_800487C4.cpp). The fast normalize uses a bare
 * frsqrte, written as the usual minimal inline asm helper. */
inline float rsqrt(register float x){register float r;asm{frsqrte r,x}return r;}
struct Vec3{float x,y,z;
Vec3(){}
Vec3(float xx,float yy,float zz):x(xx),y(yy),z(zz){}
void set(float xx,float yy,float zz){x=xx;y=yy;z=zz;}
Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
};
struct Record{char unknown00[8];int key;};
struct Actor{char unknown00[0x144];Vec3 velocity;char unknown150[0xC];Vec3 position;char unknown168[0x1B8-0x168];Vec3 direction;char unknown1C4[0x318-0x1C4];Record record;};
struct Owner{char unknown00[8];Actor*actor;};
extern "C"{
extern const float lbl_80378BA8; /* 0.9f */
extern const float lbl_80378AE8; /* 15.0f */
extern const float lbl_80378AD0; /* 0.0f */
extern const float lbl_80378AEC; /* 0.5f */
extern float lbl_80374A18; /* 0.99f */
extern float lbl_80377768;
extern Vec3 lbl_802F4198;
void fn_8007D6A0(Record*,int);
void fn_80092DAC(Actor*,float);
}

extern "C" void fn_80082570(Owner*self,float delta){
    if(self->actor->direction.y<lbl_80378BA8){
        float y=self->actor->direction.y;
        float x=self->actor->direction.x;
        float z=self->actor->direction.z;
        float inv=rsqrt(x*x+y*y+z*z);
        x*=inv;z*=inv;
        float ny=lbl_80378AD0;
        x*=lbl_80378AE8;ny*=*(const float*)&lbl_80378AE8;z*=*(float*)&lbl_80378AE8;
        self->actor->velocity.set(x,ny,z);
        lbl_802F4198=self->actor->position;
    }else if(self->actor->direction.y>lbl_80378BA8&&lbl_80377768<lbl_80378AEC){
        lbl_80377768+=delta;
        self->actor->velocity=lbl_802F4198*lbl_80374A18;
        lbl_802F4198=self->actor->velocity;
    }else if(self->actor->direction.y>lbl_80378BA8){
        fn_8007D6A0(&self->actor->record,0x14);
    }
    fn_80092DAC(self->actor,delta);
}
