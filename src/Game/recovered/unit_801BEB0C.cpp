/* auto_03_801BEB0C_text: character collision move (fn_801BEB0C, vtable slot
   0x164 of the mover: ground ray, sphere push-out, floor/wall flags, final
   ground ray) and fn_801BF5A4 (the stepped mover that builds the sphere list
   and calls slot 0x164 per step, with carrier/rider attachment).
   GC/1.3.2, -O4,p, -fp_contract on (same flags as
   related_flag_transfer_801BE6F4 / physics_node_swept_sphere_move_801C109C).
   Status: full drafts, not exact (see results w9_801BEB0C.json).
   The original used float/double literals; the compiled .sdata2 pool is in
   the same order as the target 0x8037A310..0x8037A350, so this unit owns
   that range.  Literals matter: Vec3(x,0.0f,z).length() folds 0*0.
   The Ray origin temporary is materialised via get() (the original stores
   the from+offset sum to a stack temporary before copying it into the ray);
   the sphere loop indexes through a char* offset so the base+offset add
   stays in the loop as in the original. */
typedef unsigned long Word;
typedef unsigned long long Wide;
extern "C" {
extern const float lbl_8037A310; /* 0.1 */
extern const float lbl_8037A314; /* 0.0 */
extern const float lbl_8037A318; /* 1e-6 */
extern const float lbl_8037A31C; /* -1 */
extern const float lbl_8037A320; /* 1 */
extern const float lbl_8037A324; /* 0.707 */
extern const float lbl_8037A328; /* -0.707 */
extern const float lbl_8037A32C; /* 0.0001 */
extern const float lbl_8037A330; /* 0.5 */
extern const float lbl_8037A334; /* 0.999999 */
extern const float lbl_8037A338; /* 0.05 */
}
#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float sqrtOrZeroK(float sq,float zero){float r=zero;if(sq!=r)r=fastSqrt(sq);return r;}
/* single-temp variant (asm writes r directly): one coalesced name fewer than
   sqrtOrZeroK, which the first ground-ray block needs for its colouring */
inline float sqrtOrZeroA(register float sq,float zero){register float r=zero;if(sq!=r){asm{frsqrte f4,sq
fres r,f4}}return r;}
struct Vec3{float x,y,z;
Vec3(){}
Vec3(float a,float b,float c):x(a),y(b),z(c){}
Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}
Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
Vec3 operator-(const Vec3&o)const{return Vec3(x-o.x,y-o.y,z-o.z);}
Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
Vec3&operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;return *this;}
Vec3&operator-=(const Vec3&o){x-=o.x;y-=o.y;z-=o.z;return *this;}
const Vec3&get()const{return *this;}
Vec3 addZYX(const Vec3&o)const{Vec3 r;r.z=z+o.z;r.y=y+o.y;r.x=x+o.x;return r;}
Vec3 subXYZ(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
float dot(const Vec3&o)const{return x*o.x+y*o.y+z*o.z;}
float length()const{float sq=x*x+y*y+z*z;float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
float lengthS()const{float xx=x*x;float yy=y*y;float zz=z*z;float sq=xx+yy+zz;float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r){center.x=c.x;center.y=c.y;center.z=c.z;radius=r;}
Sphere(const Sphere&s){center.x=s.center.x;center.y=s.center.y;center.z=s.center.z;radius=s.radius;}};
struct Matrix;
extern "C" void fn_801F1080(const Matrix*,const Matrix*,Matrix*);
struct Quat{float w,x,y,z;Quat(){}Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}Quat conj()const{float d=-z,c=-y,b=-x;return Quat(w,b,c,d);}};
struct Attach{Vec3 offset;Quat rotation;Attach(){}Attach(const Vec3&o,const Quat&r):offset(o),rotation(r){}void set(const Vec3&o,const Quat&r){offset=o;rotation=r;}};
struct Raw{float m[4][4];};struct Matrix:Raw{Matrix(){}Matrix(const Matrix&o){*(Raw*)this=o;}Matrix preMul(const Matrix*a){Matrix r;fn_801F1080(a,this,&r);*this=r;return *this;}};
struct Handle{signed char tag;signed int index:24;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char is(signed char t)const{return tag==t;}};
struct Manager{char unknown00[8];Entry*entries;Entry*at(int i){return &entries[i];}
void*get(const Handle&h){const Handle*p=&h;int i=p->index;if(at(i)->is(p->tag))return at(i)->object;return 0;}
/* getK: resolve that also copies a one-member box (out.v=in.v) in both arms; the copies are coalesced at RA (no code) and give the params the permanent neighbours the target colouring needs (w34) */
template<class B>void*getK(const Handle&h,B&out,const B&in){const Handle*p=&h;int i=p->index;void*r;if(at(i)->is(p->tag)){r=at(i)->object;out.v=in.v;}else{r=0;out.v=in.v;}return r;}};
struct PBox{Matrix*v;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
#define resolve(h) (lbl_801E9D24.manager->get(h))
struct Body{char unknown00[0x74];Sphere*bound;Sphere*bound2;};
struct Node{char unknown00[0x124];Matrix*matrix;};
struct Collider{char unknown00[4];Handle owner;char unknown08[4];Handle parent;char unknown10[0xB8];Quat rotation;char unknownD8[0x48];Word flags;Matrix*matrix;};
struct Ray{Vec3 origin;float length;Vec3 direction;float unknown1C;
Ray(const Vec3&o,const Vec3&d,float l):origin(o),direction(d){length=l;}};
struct Result{Vec3 point;float distance;Vec3 normal;char unknown1C[0xC];Wide flags;struct Collider*object;Word other,extra;signed char hit;char unknown3D[3];Word end;
Result(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct Hit{Vec3 point;float distance;Vec3 normal;char unknown1C[0xC];~Hit(){}};
struct Hits{Word storage[0xA00];int count;Hits():count(0){}~Hits(){for(int i=0;i<count;++i)reinterpret_cast<Hit*>(storage)[i].~Hit();}
Hit*begin(){return reinterpret_cast<Hit*>(storage);}};
struct Shape{Word storage[0x28];int count;Shape():count(0){}~Shape(){for(int i=0;i<count;++i)reinterpret_cast<Sphere*>(storage)[i].~Sphere();}
const Sphere&first()const{return *reinterpret_cast<const Sphere*>(storage);}};
struct Prefix{char unknown00[8];};
struct Owner:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual signed char slot5C(Result*,Vec3*,int);virtual void slot60(Hit*,Vec3*,int);virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
virtual void slot98();virtual const Handle*slot9C(int);virtual void slotA0();virtual void slotA4();
virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();
virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();
virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();
virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();
virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();
virtual void slotF8();virtual void slotFC();
virtual void place(void*,const Vec3*,const Vec3*,Vec3*,int,float);
virtual void slot104();virtual void slot108();
virtual Vec3 move(void*,const Vec3*,Sphere*,const Vec3*,Vec3*,int,int);
virtual void slot110();
virtual void contact(Result*,const Vec3*,int);
virtual void settle(int,int);
virtual void slot11C();virtual void slot120();virtual void slot124();virtual void slot128();
virtual void slot12C();virtual void slot130();virtual void slot134();
virtual void adjust(Vec3*,int,float);
virtual void slot13C();virtual void slot140();virtual void slot144();virtual void slot148();
virtual void slot14C();virtual void slot150();virtual void slot154();virtual void slot158();
virtual void slot15C();virtual void slot160();
virtual signed char sweep(void*,Vec3*,Vec3*,Shape*,Result*,Vec3*);
virtual void slot168();
virtual signed char slide(void*,const Vec3*,Vec3*,const Vec3*,Vec3*,float);
char unknown0C[0x24];Wide flags;char unknown38[0x40];void*support;char unknown7C[0xEC];Handle body;char unknown16C[0x40];Handle carrier;char unknown1B0[8];
Vec3 contactNormal;char unknown1C4[0x34];Handle rider;char unknown1FC[0x38];Attach attach;signed char attached;char unknown251[3];Collider*attachedTo;signed char keepStep;signed char trackGround;char unknown25A[2];float groundY;signed char grounded;
signed char test(Wide mask)const{signed char r=0;if(flags&mask)r=1;return r;}
};
extern "C"{
extern const Vec3 game_vec3_zero;
extern signed char lbl_80377FA0;
signed char fn_8021F23C(Owner*);
void fn_801BE4D0(Owner*,void*,const Vec3*,Vec3*,Vec3*,const Vec3*,int,float);
void fn_801C1CB4(Owner*,void*,const Vec3*,Vec3*,Vec3*,const Vec3*,int,float);
int fn_801C0B48(Shape*,const Sphere&);
Sphere fn_80099A00(const Matrix*,const Sphere*);
void fn_801F250C(const Matrix*,Matrix*);
void fn_801F1080(const Matrix*,const Matrix*,Matrix*);
Quat fn_801F1C64(const Quat*,const Quat*);
void fn_801F1B1C(Vec3*,const Quat*,const Vec3*);
signed char fn_801C0AB0(const Handle*,const Handle*);
signed char fn_80269230(void*,const Ray&,Result*,Wide,Wide);
signed char fn_80268918(void*,const Sphere*,Hits*,Wide,Wide);
float fn_800AA52C(float,float); /* max */
}

/* FBox (w40): fb.v is a copy of the floor.x temporary made in both arms of the
   pen<eps test and read back by the floor update.  The two definitions stop
   copy propagation; at RA the box temp is coalesced with the floor.x temp (no
   code) and stays in the interference graph across the inner loop: the one
   extra coalesced node the target colouring needs (with floor.x=px). */
struct FBox{float v;};
inline float spdA(float sq){return sqrtOrZeroA(sq,0.0f);}
extern "C" signed char fn_801BEB0C(Owner*self,void*world,const Vec3*from,const Vec3*move,Shape*shape,Result*res,Vec3*to){
    self->slot9C(0);
    Hits hits;
    int n;const Sphere*s;
    Wide sphereA=0x000201E000000002ULL,sphereB=8;
    Wide rayA=0x000001E000000002ULL,rayB=0x0000000400000008ULL;
    float mx=move->x,my=move->y,mz=move->z;
    float extra;
    float fy,fz;float nfl;
    float top;
    if(self->flags&0x1000000000ULL)extra=0.1f;else extra=0.0f;
    if(self->flags&0x800)sphereA|=0x0000000400000002ULL;
    if(self->flags&0x200){sphereA|=0x00008E0000000000ULL;rayA|=0x00008E0000000000ULL;}
    else{sphereB|=0x0000F00000000000ULL;rayB|=0x0000F00000000000ULL;}
    Vec3 offset=shape->first().center;
    top=offset.y;
    if(top<shape->first().radius)top=shape->first().radius;
    if(my<=0.000001f){
        Ray ray((*from+offset).get(),Vec3(0.0f,-1.0f,0.0f),top+extra-my);
        if(fn_80269230(world,ray,res,rayA,rayB)){
            float vx,vy,vz;float speed=spdA(mx*mx+mz*mz);
            Vec3 p;p.y=res->point.y;p.x=res->point.x;p.z=res->point.z;
            Vec3 n;n.y=res->normal.y;n.x=res->normal.x;n.z=res->normal.z;
            Vec3 mv(mx,0.0f,mz);float qz=p.z+mv.z,qy=p.y+mv.y,qx=p.x+mv.x;Vec3 q(qx,qy,qz);
            float dq=res->normal.dot(q);
            float plane=-n.dot(p);
            float t=-((plane+dq)/n.y);
            Vec3 onPlane=Vec3(0.0f,1.0f,0.0f)*t+q;
            Vec3 d=onPlane.subXYZ(p);
            float len=sqrtOrZeroA(d.x*d.x+d.y*d.y+d.z*d.z,0.0f);
            if(len<0.000001f){vx=game_vec3_zero.x;vy=game_vec3_zero.y;vz=game_vec3_zero.z;}
            else{Vec3 w=d*(1.0f/len)*speed;vx=w.x;vy=w.y;vz=w.z;}
            res->point.x-=offset.x;res->point.z-=offset.z;
            Vec3 e=*from-res->point;vx-=e.x;vy-=e.y;vz-=e.z;*to=*from+Vec3(vx,vy,vz);
            if(self->flags&0x1000000000ULL)self->flags|=0x4000000000ULL;
            if(self->slot5C(res,to,0)){self->flags|=0x40000000000ULL;self->flags|=0x8000000000ULL;}
            goto moved;
        }
    }
    *to=*from+*move;
moved:
    float px=game_vec3_zero.x,py=game_vec3_zero.y,pz=game_vec3_zero.z;Vec3 floor;floor.x=px;fy=py;fz=pz;
    float scale=0.0f;
    signed char hit=0;
    float floorLimit=0.707f;nfl=-floorLimit;
    for(int i=0;i<shape->count;i++){
        s=(const Sphere*)((const char*)shape+i*sizeof(Sphere));
        Sphere sphere(s->center+*to,s->radius);
        if(fn_80268918(world,&sphere,&hits,sphereA,sphereB)){
            n=hits.count;
            hit=1;
            float eps=0.000001f;
            Hit*h=hits.begin();
            for(int j=0;j<n;j++,h++){
                self->slot60(h,to,0);
                float l=h->normal.lengthS();
                if(l>eps){
                    float inv=1.0f/l;
                    h->normal.x*=inv;h->normal.y*=inv;h->normal.z*=inv;
                    FBox fb;float pen=s->radius-h->distance;
                    float p2;
                    if(pen<eps){p2=eps;fb.v=floor.x;}else{p2=pen;p2+=eps;fb.v=floor.x;}
                    scale=fn_800AA52C(scale,p2);
                    Vec3 t=h->normal*scale;px+=t.x;py+=t.y;pz+=t.z;
                    if(h->normal.y<nfl)self->flags|=0x10000000000ULL;
                    else{self->flags|=0x100000000000ULL;Vec3 t2=h->normal*(s->radius-h->distance);floor.x=fb.v+t2.x;fy+=t2.y;fz+=t2.z;}
                }
            }
        }
    }
    if(hit){
        float l=sqrtOrZeroK(px*px+py*py+pz*pz,0.0f);
        if(l>0.000001f){
            float inv=1.0f/l;
            px*=inv;py*=inv;pz*=inv;
            *to+=Vec3(px*scale,py*scale,pz*scale);
        }
        if(self->flags&0x100000000000ULL){
            float l2=Vec3(floor.x,fy,fz).length();
            if(l2>0.000001f){
                float inv=1.0f/l2;
                floor.x*=inv;fz*=inv;
                float ia,ib;
                float ax=floor.x,ay=0.0f,az=fz;
                float bx=move->x,by=0.0f,bz=move->z;
                float la=sqrtOrZeroK(ax*ax+ay*ay+az*az,0.0f);
                float lb=sqrtOrZeroK(bx*bx+by*by+bz*bz,0.0f);
                if(la>0.000001f&&lb>0.000001f){
                    ia=1.0f/la;ib=1.0f/lb;
                    ax*=ia;ay*=ia;az*=ia;
                    bx*=ib;by*=ib;bz*=ib;
                    if(ax*bx+ay*by+az*bz<-0.707f)self->flags|=0x20000000000ULL;
                }
            }
        }
    }
    Ray ray((*to+offset).get(),Vec3(0.0f,-1.0f,0.0f),0.0001f+(top+extra));
    if(fn_80269230(world,ray,res,rayA,rayB)){
        res->point.x-=offset.x;res->point.z-=offset.z;
        *to=res->point;
        if(self->flags&0x1000000000ULL)self->flags|=0x4000000000ULL;
        if(self->trackGround){self->grounded=1;self->groundY=to->y;}
        if(self->slot5C(res,to,0)){self->flags|=0x40000000000ULL;self->flags|=0x8000000000ULL;self->contactNormal=res->normal;}
    }else{
        self->contactNormal.x=0.0f;self->contactNormal.y=0.0f;self->contactNormal.z=0.0f;
    }
    return hit;
}

inline void contactResponse(Owner*self,Result&res,const Vec3*velocity,int which){
    Collider*hit=res.object;
    if((signed char)((hit->flags>>9)&1)){
        const Handle*own=&hit->owner;
        if(!fn_801C0AB0(own,&((Collider*)resolve(*self->slot9C(which)))->parent)){
            self->contact(&res,velocity,which);
            return;
        }
    }
    if(res.object->flags&0x800)self->contact(&res,velocity,which);
}
inline Vec3 rotate(const Quat&q,const Vec3&o){Vec3 r;fn_801F1B1C(&r,&q,&o);return r;}
#define addSphere(list,m,s,cur) {Sphere local=fn_80099A00(m,s);local.center-=cur;fn_801C0B48(&list,local);}

extern "C" void fn_801BF5A4(Owner*self,void*world,const Vec3*from,Vec3*to,Vec3*out,Vec3*velocity,int which,float dt){
    lbl_80377FA0=0;
    if(fn_8021F23C(self)||self->test(0x40000ULL)){
        fn_801BE4D0(self,world,from,to,out,velocity,which,dt);
        return;
    }
    if(self->flags&0x800000000ULL){
        fn_801C1CB4(self,world,from,to,out,velocity,which,dt);
        return;
    }
    Vec3 start=*from;
    if(self->flags&0x400ULL){
        if(!((Body*)resolve(self->body))->bound)return;
        Vec3 delta=*to-*from;
        if(delta.x*delta.x+delta.z*delta.z<0.000001f)self->flags|=0x80000000000ULL;
        else self->attached=0;
        if(to->y-from->y>0.000001f)self->attached=0;
        if(self->slide(world,from,&delta,velocity,out,dt)){
            *to=*from+delta;
        }else{
            Sphere bound=*((Body*)resolve(self->body))->bound;
            Vec3 v=self->move(world,from,&bound,velocity,out,which,1);
            self->adjust(&v,0,dt);
            start+=v;
            Vec3 cur=start;
            float len=delta.lengthS();
            float n=len/(0.5f*bound.radius);
            int steps;
            if(n>0.0f)steps=(int)(0.999999f+n);else steps=(int)n;
            Owner*carrier=(Owner*)resolve(self->carrier);
            Owner*rider=(Owner*)resolve(self->rider);
            if(self->keepStep||carrier||rider||!self->support||!self->attached){
                if(steps==0)steps++;
            }
            Shape list;
            fn_801C0B48(&list,bound);
            if(self->flags&0x800000ULL){
                if(((Body*)resolve(self->body))->bound2)fn_801C0B48(&list,*((Body*)resolve(self->body))->bound2);
            }
            if(rider){
                Node*node=(Node*)resolve(*rider->slot9C(0));
                if(((Body*)resolve(rider->body))->bound)addSphere(list,node->matrix,((Body*)resolve(rider->body))->bound,cur);
                if(rider->flags&0x800000ULL){
                    if(((Body*)resolve(rider->body))->bound2){Matrix*mm=node->matrix;addSphere(list,mm,((Body*)resolve(rider->body))->bound2,cur);}
                }
            }
            if(carrier&&(self->flags&0x1000000ULL)&&((Body*)resolve(carrier->body))->bound){
                Node*node=(Node*)resolve(*carrier->slot9C(0));
                lbl_80377FA0=1;
                {Matrix*mm=node->matrix;addSphere(list,mm,((Body*)resolve(carrier->body))->bound,cur);}
                if(((Body*)resolve(carrier->body))->bound2){Matrix*mm=node->matrix;addSphere(list,mm,((Body*)resolve(carrier->body))->bound2,cur);}
            }
            if(!(self->flags&0x1000000000ULL)){
                fn_801C0B48(&list,Sphere(Vec3(bound.center.x,0.05f+bound.radius,bound.center.z).get(),bound.radius));
            }
            Result res;
            if(steps>0){
                float inv=1.0f/steps;Vec3 step=delta*inv;
                for(int i=0;i<steps;i++){
                    self->sweep(world,&cur,&step,&list,&res,to);
                    cur=*to;
                }
                {Vec3 d=*to-*from;if(d.length()<0.001)*to=*from;}
                self->settle(1,which);
                if(res.hit){
                    contactResponse(self,res,velocity,which);
                    if(self->support){
                        Collider*hit=res.object;
                        PBox A;A.v=hit->matrix;PBox B;
                        Matrix m;fn_801F250C(((Collider*)lbl_801E9D24.manager->getK(hit->parent,B,A))->matrix,&m);
                        Matrix*node=B.v;
                        m.preMul(node);
                        self->attachedTo=res.object;
                        self->attach.offset=*to-*(Vec3*)node->m[3];
                        self->attach.set(self->attach.offset,res.object->rotation.conj());
                        self->attached=1;
                    }else self->attached=0;
                }else self->attached=0;
            }else{
                Vec3 vel=delta;
                Vec3 saved=*to;
                cur=start;
                signed char moved=self->sweep(world,&cur,&vel,&list,&res,&saved);
                if(res.hit){
                    if(self->attachedTo!=res.object)self->attached=0;
                    if(moved)self->attached=0;
                    if(!self->attached){
                        self->attachedTo=res.object;
                        Collider*hit=res.object;
                        PBox A;A.v=hit->matrix;PBox B;
                        Matrix m;fn_801F250C(((Collider*)lbl_801E9D24.manager->getK(hit->parent,B,A))->matrix,&m);
                        Matrix*node=B.v;
                        m.preMul(node);
                        self->attach.offset=*to-*(Vec3*)node->m[3];
                        self->attach.rotation=res.object->rotation.conj();
                        if(self->support)self->attached=1;
                    }else{
                        Collider*hit=res.object;
                        PBox A;A.v=hit->matrix;PBox B;
                        Matrix m;fn_801F250C(((Collider*)lbl_801E9D24.manager->getK(hit->parent,B,A))->matrix,&m);
                        Matrix*node=B.v;
                        m.preMul(node);
                        Quat q=res.object->rotation;
                        q=fn_801F1C64(&q,&self->attach.rotation);
                        *to=*(Vec3*)node->m[3]+rotate(q,self->attach.offset);
                        to->y=saved.y;
                    }
                }else self->attached=0;
                if(!self->attached)*to=saved;
                self->settle(1,which);
                if(res.hit)contactResponse(self,res,velocity,which);
            }
            if(!(self->flags&0x40ULL)){
                if(delta.x*delta.x+delta.z*delta.z<0.000001f)delta=*velocity;
                *out=*to+delta;
            }
        }
    }else{
        *out=start+*velocity;
    }
    lbl_80377FA0=0;
    self->place(world,from,&start,to,which,dt);
}
