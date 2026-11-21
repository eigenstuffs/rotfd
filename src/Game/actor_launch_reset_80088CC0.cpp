/* Original actor launch/reset control; see docs/notes/game-actor-launch-reset.md. */
struct Vec3 {float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator=(const Vec3&b){x=b.x;y=b.y;z=b.z;return*this;}Vec3&operator+=(const Vec3&b){x+=b.x;y+=b.y;z+=b.z;return*this;}};
struct Actor {char unknown0[0x30];unsigned long long flags;char unknown38[0x110];float field148;char unknown14C[0x14];float field160;char unknown164[0x318-0x164];char controller;char unknown319[7];int record;char unknown324[0x34];Vec3 acceleration;char unknown364[0x88];volatile float speed; signed char hasFlags(unsigned long long mask)const {if(flags&mask)return 1;return 0;}};
struct Controller {char unknown0[0x84];int mode;char unknown88[0x14];signed char flag;};
struct Self {char unknown0[8];Actor*actor;Controller*controller;char unknown10[0x40];Vec3 launch;};
struct FeedbackPrefix {char unknown0[0x1C];};struct Feedback:FeedbackPrefix {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void feedback(int,unsigned char,unsigned char);};
struct SceneMode;struct Scene {char unknown0[0x15058];SceneMode*mode;};struct Context {char unknown0[0x124];Scene*scene;char unknown128[0x2C];Feedback*feedback;};struct Monitor {char unknown0[0x130];void*first;};
extern "C" {extern Context lbl_801E9D24;extern Monitor*lbl_803776B8;extern const float lbl_80378B38,lbl_80378AD0,lbl_80378AE0;extern const Vec3 game_vec3_zero;void fn_80057E40(SceneMode*);void fn_80257828(void*,int,int,int);void fn_8007D6A0(void*,int);void*fn_800BE2B0(Scene*);void fn_802073E8(void*,int,void*,float);void fn_8006803C(Monitor*,int);}
extern "C" void fn_80088CC0(Self*self) {
 if(!self->actor->hasFlags(0x8000000000ULL)) {
  float speed=self->actor->speed;self->launch=Vec3(lbl_80378AD0,lbl_80378B38*speed,lbl_80378AD0);
  self->actor->field160=lbl_80378AD0;self->actor->field148=lbl_80378AD0;
  self->actor->acceleration=game_vec3_zero;
  self->actor->acceleration+=self->launch;
 }
 lbl_801E9D24.feedback->feedback(0,0,0);lbl_801E9D24.feedback->feedback(0,0,0xFF);
 fn_80057E40(lbl_801E9D24.scene->mode);
 fn_80257828(self->controller,0x47,0x7E,0);
 if(self->controller->mode==1)fn_8007D6A0(&self->actor->controller,0x22);
 if(!self->controller->flag)if(fn_800BE2B0(lbl_801E9D24.scene))fn_802073E8(self->controller,0x8F,fn_800BE2B0(lbl_801E9D24.scene),lbl_80378AE0);
 if(lbl_803776B8)if(lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->record);
}
