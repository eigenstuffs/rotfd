/* Adds the actor's planar velocity (x/z of +0x15C, zero y) into its
 * acceleration (+0x358), advances the actor, then requests action 0x14 when
 * flag bit 0x8000000000 is set. */
struct Vec3{float x,y,z;Vec3(){}Vec3(float xx,float yy,float zz):x(xx),y(yy),z(zz){}};
struct Record{char unknown00[8];int key;};
struct Actor{char unknown00[0x30];unsigned long long flags;char unknown38[0x124];Vec3 velocity;char unknown168[0x1B0];Record record;char unknown324[0x34];Vec3 acceleration;
 inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct Owner{char unknown00[8];Actor*actor;};
extern "C"{extern const float lbl_80378AD0;void fn_8007D6A0(Record*,int);void fn_80092DAC(Actor*,double);}
extern "C" void fn_80085A04(Owner*self,double delta){
 Actor*actor=self->actor;
 Vec3 velocity=actor->velocity;
 actor->acceleration.x+=velocity.x;
 actor->acceleration.y+=lbl_80378AD0;
 actor->acceleration.z+=velocity.z;
 fn_80092DAC(self->actor,delta);
 if(self->actor->hasFlags(0x8000000000ULL))fn_8007D6A0(&self->actor->record,0x14);
}
