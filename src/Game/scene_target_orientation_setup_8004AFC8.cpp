/* Scene target orientation setup: copies the source/target handles, caches both positions and builds a yaw quaternion about lbl_802F4148. */
struct Handle{signed int tag:8;signed int index:24;};
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}};
struct Quat{float w;Vec3 v;Quat(){}Quat(float a,const Vec3&b):w(a),v(b){}Quat&operator=(const Quat&q){w=q.w;v=q.v;return*this;}};
struct Transform{char unknown00[0x30];Vec3 position;Vec3 getPosition()const{return Vec3(position.x,position.y,position.z);}};
struct Entity{char unknown00[0x124];Transform*transform;};
struct Entry{Entity*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Entity*resolve(const Handle&h){Entry*e=lbl_801E9D24.manager->entries+h.index;if(e->tag==h.tag)return e->object;return 0;}
extern "C"{void fn_801F86C8(Manager*,const Handle*,int);}
struct RefHandle:Handle{void assign(const Handle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);*(Handle*)this=h;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Object{char unknown00[0x38];unsigned long long flags38;char unknown40[0x20];unsigned char state60;char unknown61[3];int mode64;char unknown68[0xC];RefHandle target;RefHandle source;Vec3 from;Vec3 to;Quat rotation;};
extern "C"{extern const float lbl_80378588;extern const Vec3 lbl_802F4148;const Handle*fn_8025E1D4(Object*,int);float fn_8025E268(Object*,int);float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);}
extern "C" void fn_8004AFC8(Object*self){
 self->flags38|=0x40000000ULL;
 self->state60=(int)fn_8025E268(self,0);
 self->mode64=(unsigned char)(int)fn_8025E268(self,1);
 self->source.assign(*fn_8025E1D4(self,0));
 self->target.assign(*fn_8025E1D4(self,1));
 self->from=resolve(self->source)->transform->getPosition();
 self->to=resolve(self->target)->transform->getPosition();
 float angle=fn_80285124(self->to.x-self->from.x,self->to.z-self->from.z);angle*=lbl_80378588;
 float c=fn_8028506C(angle);
 self->rotation=Quat(c,lbl_802F4148*fn_80284FA8(angle));
}
