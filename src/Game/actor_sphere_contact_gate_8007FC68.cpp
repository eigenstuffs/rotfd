/* Bounded contact gate on the related actor (fn_8007FC68, a virtual override
 * that forwards its six arguments to the base method fn_801BEB0C).
 *
 * Captures whether neither controller slot 0 nor 1 of the counter at 0x318 is
 * busy, resolves the related actor (service +0x13C -> handle -> child ->
 * actor handle 0x70), and compares the squared distance between the related
 * actor's matrix position and this object's world sphere centre (local sphere
 * 0x168->0x74 plus own matrix position, radius times scale slot 0xB4) with the
 * squared sum of both radii. Inside clears actor flag 0x200 and resource flag
 * 0x40000; outside sets actor flag 0x200. When this object's resource flag
 * 0x10000 is clear it forwards to the base method (only if allowed) and sets
 * the related resource flag 0x40000.
 *
 * Allocation notes: the two sphere pointers are separate locals (other first);
 * operator+= adds z, x, y; the related position is a named Vec3 local built by
 * value (this keeps its loads as named locals and gives the original FPRs);
 * the difference is bound to a const reference (dead stores to the stack). */
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{
    float x,y,z;
    Vec3(){}
    Vec3(float a,float b,float c):x(a),y(b),z(c){}
    Vec3&operator+=(const Vec3&v){z+=v.z;x+=v.x;y+=v.y;return*this;}
    Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
    float squared()const{return x*x+y*y+z*z;}
};
struct Sphere{Vec3 center;float radius;};
struct Matrix{char unknown0[0x30];Vec3 position;Vec3 getPosition()const{return Vec3(position.x,position.y,position.z);}};
struct Prefix{char unknown0[8];};
struct Node:Prefix{
    virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
    virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
    virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
    virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
    virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();
    virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
    virtual void slot98();
    virtual const Handle&query(int);
    virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();
    virtual float scale(int);
    char unknownC[0x30-0xC];unsigned long long flags;char unknown38[0x38];Handle actor;Sphere*sphere;
    char unknown78[0xB0-0x78];Handle*child;char unknownB4[0x120-0xB4];Word state;Matrix*matrix;
    char unknown128[0x168-0x128];Handle sphereHandle;char unknown16C[0x318-0x16C];char controller;
};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown0[0x1C];Handle*handle;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"{Word fn_801F7EB8(const Handle*);signed char fn_8007D604(void*,int);Word fn_801BEB0C(Node*,void*,void*,void*,void*,void*,void*);}
inline Node*relatedActor(){const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(h))return resolve(*h);return 0;}
inline signed char canRun(Node*self){signed char result=0;if(!fn_8007D604(&self->controller,0)&&!fn_8007D604(&self->controller,1))result=1;return result;}

extern "C"Word fn_8007FC68(Node*self,void*a,void*b,void*c,void*d,void*e,void*f){
    Word result=0;
    int allowed=canRun(self);
    Node*other=relatedActor();
    Sphere*otherSphere=resolve(other->sphereHandle)->sphere;
    Sphere*ownSphere=resolve(self->sphereHandle)->sphere;
    Sphere sphere=*ownSphere;
    float otherRadius=otherSphere->radius;
    sphere.center+=resolve(self->query(0))->matrix->position;
    sphere.radius*=self->scale(0);
    Vec3 position=resolve(other->query(0))->matrix->getPosition();
    const Vec3&difference=position-sphere.center;
    float radius=otherRadius+sphere.radius;
    if(difference.squared()<radius*radius){
        other->flags&=~0x200ULL;
        resolve(other->query(0))->state&=~0x40000UL;
    }else other->flags|=0x200ULL;
    if(!(resolve(self->query(0))->state&0x10000)){
        if((signed char)allowed)result=fn_801BEB0C(self,a,b,c,d,e,f);
        resolve(other->query(0))->state|=0x40000UL;
    }
    return result;
}
