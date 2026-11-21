/* fn_800AAD5C: per-frame View update (virtual method of the View built by fn_800AAC0C).
   While control 0x85 is held, compares the controller's level with the related
   actor's resource level and may fire fn_8007350C; then steers `value` toward
   `goal` (20 while held, else 10) at 11 units/s, clamping, and stores
   (-up * goal + up * value) * dt as the body velocity (0x144).

   Matching notes: the original TU used pooled float literals (lbl_80379048 = 0.0f,
   lbl_8037904C = 10.0f, lbl_80379050 = 20.0f, lbl_80379054 = 11.0f,
   lbl_80379058 = 1.0f). Literal reads are emulated with distinct read forms:
   the clamp compare and store use different forms, and the six reads of the two
   up-vector temporaries use the forms below (axisA.y/z plain, the rest distinct).
   The two products are named locals (not stored); the four stored stack temps
   are the two up vectors, the negated vector and the sum (object of *dt). */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{
    float x,y,z;
    Vec3(){}
    Vec3(float a,float b,float c):x(a),y(b),z(c){}
    Vec3 operator-()const{return Vec3(-x,-y,-z);}
    Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
    Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
};
struct Stats{char unknown00[0x34];float level;};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
    virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
    virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
    virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
    virtual const Handle*getResource(int);
    char unknown0C[0x4C];Handle related58;char unknown5C[0x14];Handle actor;char unknown74[0x3C];Handle*child;char unknownB4[0x70];Stats*stats;char unknown128[0x1F0];char actions[4];
};
struct Body{char unknown00[0x144];Vec3 velocity;};
struct Controller{char unknown00[0x58];Handle related;};
struct View{void*vtable;char unknown04[4];Body*body;Controller*controller;float field10;float goal;float value;};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{Word unknown00,unknown04;Entry*entries;};
struct Related{char unknown00[0x1C];Handle*handle;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C"{
    extern const float lbl_80379048,lbl_8037904C,lbl_80379050,lbl_80379054,lbl_80379058;
    Word fn_801F7EB8(const Handle*);
    signed char fn_8025E9FC(Controller*,int);
    signed char fn_8007D604(void*,int);
    void fn_8007350C(Controller*);
}
inline Node*resolve(const Handle&h){int i=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[i].getTag();return tag==h.bits.tag?m->entries[i].object:0;}
inline Node*actor(){const Handle&h=resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(&h))return resolve(h);return 0;}
inline Vec3 axisA(){return Vec3(*(const float*)&lbl_80379048,lbl_80379058,lbl_80379048);}
inline Vec3 axisB(){return Vec3(*(const float*)(unsigned long)&lbl_80379048,*(const float*)&lbl_80379058,*(const float*)(long)&lbl_80379048);}
inline float actorLevel(){return resolve(*actor()->getResource(0))->stats->level;}
extern "C" void fn_800AAD5C(View*self,float dt){
    if(fn_8025E9FC(self->controller,0x85)){
        float level=resolve(self->controller->related)->stats->level;
        if(level<actorLevel()){
            if(fn_8007D604(actor()->actions,0x14))fn_8007350C(self->controller);
        }
    }
    if(fn_8025E9FC(self->controller,0x85))self->goal=lbl_80379050;else self->goal=lbl_8037904C;
    if(lbl_80379050==self->goal&&self->value<lbl_80379050)self->value+=lbl_80379054*dt;
    else if(self->value>*(const float*)&lbl_80379050)self->value=*(const float*)(unsigned long)&lbl_80379050;
    if(!fn_8025E9FC(self->controller,0x85)){
        if(lbl_8037904C==self->goal&&self->value>lbl_8037904C)self->value-=lbl_80379054*dt;
        else if(self->value<*(const float*)&lbl_8037904C)self->value=*(const float*)(unsigned long)&lbl_8037904C;
    }
    Vec3 a=-axisA()*self->goal;
    Vec3 b=axisB()*self->value;
    self->body->velocity=(a+b)*dt;
}
