#pragma fp_contract on
/* fn_801EDD8C: sample the AnimFrame curves at the current time and apply them to the owner or its typed target. */
typedef unsigned long Word;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Quat{float w,x,y,z;Quat(){}Quat(const Quat&q):w(q.w),x(q.x),y(q.y),z(q.z){}Quat&operator=(const Quat&q){w=q.w;x=q.x;y=q.y;z=q.z;return *this;}};
struct Matrix{float m[16];};
struct Basis{float v[9];};
struct Handle{signed int tag:8;signed int index:24;};
struct NodeStorage{char unknown00[8];};
struct Node:NodeStorage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
 virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34(const Vec3*);
};
struct Transform{char unknown00[0x30];Basis rotation,basis;char unknown78[0xA8];Word flags;Matrix*matrix,*inverse;short unknown12C,index;};
struct Owner{char unknown00[0xC];Handle transform;char unknown10[0xC];Handle target;char unknown20[0x98];Vec3 position;float unknownC4;Quat rotation;Vec3 scale;char unknownE4[0x3C];Word flags;};
struct TargetC:Node{char unknown0C[0x60];unsigned short type;char unknown6E[6];Quat rotation;char unknown84[0x18];Vec3 offset;char unknownA8[4];Vec3 position;};
struct TargetD:Node{char unknown0C[0x60];unsigned short type;char unknown6E[0x16];Vec3 position;Vec3 scale;Quat rotation;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Pool{Matrix*pages[6];unsigned char active;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x18];Pool*pool;} lbl_801E9D24;
inline void*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Curve{unsigned short flags,unknown02;int count,capacity;void*items;};
struct AnimFrame{char unknown00[0x20];Handle owner;float period;Curve position,rotation,scale,progress,path,events,offset,extra,action;char unknownB8[4];unsigned short flags;char unknownBE[2];float time;Owner*getOwner();};
extern "C"{
extern const float lbl_8037A648,lbl_8037A650,lbl_8037A660;
extern const Vec3 game_vec3_zero;
float fn_8028506C(float);float fn_80284FA8(float);
short fn_801B0C3C(Curve*,float*,bool*,short,float);
short fn_801AFFE4(Curve*,Vec3*,short,float);
short fn_801AF484(Curve*,Quat*,short,float);
short fn_801AFA0C(Curve*,Vec3*,short,float);
signed char fn_801ED050(Curve*,float,float,Vec3*,Quat*,bool);
void fn_801F230C(const Matrix*,Matrix*);
void fn_801F2124(const Basis*,Basis*);
void fn_801F1E78(Quat*,const Basis*);
void fn_801F1BB0(Quat*,const Quat*);
void fn_8023D400(Owner*,Word);
void fn_8023D648(Owner*);
void fn_801EDD8C(AnimFrame*);
}
inline Owner*AnimFrame::getOwner(){return (Owner*)resolve(owner);}
inline void refreshInverse(Transform*t){if(t->flags&0x20){t->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][t->index];fn_801F230C(t->matrix,t->inverse);t->flags&=~0x20;}}
inline void refreshBasis(Transform*t){if(t->flags&0x40){fn_801F2124(&t->rotation,&t->basis);t->flags&=~0x40;}}
inline Vec3 transformPoint(const Matrix&m,const Vec3&v){float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];return Vec3(X,Y,Z);}

extern "C" void fn_801EDD8C(AnimFrame*self){
 self->flags&=~0x80;
 Transform*t;Owner*owner=self->getOwner();
 if(owner&&!(owner->flags&0x100000)){
  TargetC*c=0;TargetD*d=0;Node*e=0;
  Node*target=(Node*)resolve(owner->target);
  if(target){
   int type=((TargetC*)target)->type;
   if(type==0xC)c=(TargetC*)target;
   else if(type==0xD)d=(TargetD*)target;
   else if(type==0x10)e=target;
  }
  if((self->flags&3)==3){
   if(self->flags&0x20)self->flags&=~2;
   float progress=lbl_8037A660;
   Vec3 position=game_vec3_zero;
   Quat rotation;
   {float cs=fn_8028506C(lbl_8037A648);float sn=fn_80284FA8(lbl_8037A648);rotation.w=cs;float y=lbl_8037A648*sn;rotation.x=lbl_8037A660*sn;rotation.y=y;rotation.z=y;}
   bool flag=1;
   Vec3 scale=game_vec3_zero;
   if(self->progress.count){
    fn_801B0C3C(&self->progress,&progress,&flag,1,self->time);
    if(progress>lbl_8037A660)progress=*(const float*)&lbl_8037A660;
    if(progress<lbl_8037A650)progress=lbl_8037A648;
   }
   if(c||d){
    signed char changed=0;
    if(self->position.count){
     fn_801AFFE4(&self->position,&position,1,self->time);
     if(c)c->position=position;else d->position=position;
     changed=1;
    }
    if(self->rotation.count){
     fn_801AF484(&self->rotation,&rotation,1,self->time);
     if(c)c->rotation=rotation;else d->rotation=rotation;
     changed=1;
    }
    if(d&&self->scale.count){
     fn_801AFFE4(&self->scale,&scale,1,self->time);
     d->scale=scale;
     changed=1;
    }
    if(self->path.count){
     Vec3 point;Quat turn;
     signed char turned=fn_801ED050(&self->path,progress*self->period,self->period,&point,&turn,flag);
     t=(Transform*)resolve(owner->transform);
     refreshInverse(t);
     position+=transformPoint(*t->inverse,point);
     if(c)c->position=position;else d->position=position;
     if(turned){
      t=(Transform*)resolve(owner->transform);
      refreshBasis(t);
      Quat q;fn_801F1E78(&q,&t->basis);fn_801F1BB0(&q,&turn);turn=q;
      if(self->rotation.count)fn_801F1BB0(&turn,&rotation);
      if(c)c->rotation=turn;else d->rotation=turn;
     }
     changed=1;
    }
    if(changed)fn_8023D400(owner,0x10);
   }else{
    signed char changed=0;
    if(self->position.count){
     fn_801AFFE4(&self->position,&position,1,self->time);
     owner->position=position;
     changed=1;
    }
    if(self->rotation.count){
     fn_801AF484(&self->rotation,&rotation,1,self->time);
     owner->rotation=rotation;
     changed=1;
    }
    if(self->scale.count){
     fn_801AFFE4(&self->scale,&scale,1,self->time);
     owner->scale=scale;
     changed=1;
    }
    if(self->path.count){
     Vec3 point;Quat turn;
     signed char turned=fn_801ED050(&self->path,progress*self->period,self->period,&point,&turn,flag);
     t=(Transform*)resolve(owner->transform);
     refreshInverse(t);
     position+=transformPoint(*t->inverse,point);
     owner->position=position;
     if(turned){
      t=(Transform*)resolve(owner->transform);
      refreshBasis(t);
      Quat q;fn_801F1E78(&q,&t->basis);fn_801F1BB0(&q,&turn);turn=q;
      if(self->rotation.count)fn_801F1BB0(&turn,&rotation);
      owner->rotation=turn;
     }
     changed=1;
    }
    if(changed)fn_8023D648(owner);
   }
   if(self->offset.count&&(c||d||e)){
    Vec3 offset;
    fn_801AFA0C(&self->offset,&offset,1,self->time);
    if(c)c->slot34(&offset);
    if(d)((Node*)d)->slot34(&offset);
    if(e)e->slot34(&offset);
   }
   if(self->extra.count&&c){
    Vec3 extra;
    fn_801AFA0C(&self->extra,&extra,1,self->time);
    if(c)c->offset=extra;
   }
  }
 }
}
