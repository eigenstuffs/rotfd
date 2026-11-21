/* Clears the actor's acceleration and vertical velocity, sets its +0x350
 * scale, passes the remaining planar velocity to controller event 0x6E, then
 * requests controller action 0x7B and notifies the python event monitor. */
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator=(const Vec3&p){x=p.x;y=p.y;z=p.z;return *this;}};
struct Actor{char unknown00[0x15C];Vec3 velocity;char unknown168[0x1B8];int key;char unknown324[0x2C];float scale350;char unknown354[4];Vec3 acceleration;};
struct Owner{char unknown00[8];Actor*actor;void*controller;};
struct Monitor{char unknown00[0x130];void*first;void*second;};
extern "C"{extern Monitor*lbl_803776B8;extern const Vec3 game_vec3_zero;extern const float lbl_80378B38,lbl_80378D58,lbl_80378AD0;
void fn_8006803C(Monitor*,int);void fn_8025795C(void*,int,int,float,float);void fn_80255D88(void*,int,int,int,int);}
extern "C" void fn_8008761C(Owner*self){
 self->actor->acceleration=game_vec3_zero;
 self->actor->scale350=lbl_80378B38*lbl_80378D58;
 Actor*actor=self->actor;
 float z=actor->velocity.z;
 float x=actor->velocity.x;
 actor->velocity.y=lbl_80378AD0;
 fn_8025795C(self->controller,0x6E,0,x,z);
 fn_80255D88(self->controller,0x7B,0xF,0,0);
 if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->key);
}
