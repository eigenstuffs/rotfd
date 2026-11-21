/* Owner action step: distance from the actor's point at 0x3C4 to the matrix
   position of its query target; when the controller reports event 0x3A or
   the distance reaches the actor's range, action 6 is pushed. The difference
   is bound to a const reference, which keeps both temporaries on the stack
   as in the original. The engine square root is the bare reciprocal of a
   reciprocal-square-root estimate (frsqrte into f4, then fres, no frsp),
   written as a minimal inline asm statement in the math helper. */
typedef unsigned long Word;
extern "C" const float lbl_80378C38;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378C38;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Matrix { float m[16]; Vec3 getPos() const { return Vec3(m[12], m[13], m[14]); } };
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entity{char unknown00[0x124];Matrix*matrix;};
struct Entry{Entity*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Globals{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Entity*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
struct ActionStack{char unknown00[1];};
struct ActorPrefix{char unknown00[8];};
struct Actor:ActorPrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual Handle_801F7F10*query(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();
 virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();
 virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();
 virtual void slot100();virtual void slot104();virtual void slot108();virtual void slot10C();virtual void slot110();virtual void slot114();virtual void slot118();virtual void slot11C();
 virtual void slot120();virtual void slot124();virtual void slot128();virtual void slot12C();virtual void slot130();virtual void slot134();virtual void slot138();virtual void slot13C();
 virtual void slot140();virtual void slot144();virtual void slot148();virtual void slot14C();virtual void slot150();virtual void slot154();virtual void slot158();virtual void slot15C();
 virtual void slot160();virtual void slot164();virtual void slot168();virtual void slot16C();virtual void slot170();virtual void slot174();virtual void slot178();virtual void slot17C();
 virtual void slot180();virtual void slot184();virtual void slot188();virtual void update();
 char unknown0C[0x30C];ActionStack actions;char unknown319[0x3C4-0x319];Vec3 point;char unknown3D0[8];float range;
};
struct Controller;
struct Owner{char unknown00[8];Actor*actor;Controller*controller;};
extern "C"{signed char fn_8025E9FC(Controller*,int);void fn_8007D6A0(ActionStack*,int);}
extern "C" void fn_80095A60(Owner*self){
 Actor*actor=self->actor;
 const Vec3&delta=resolve(*actor->query(0))->matrix->getPos()-actor->point;
 float distance=delta.length();
 if(fn_8025E9FC(self->controller,0x3a)||distance>=self->actor->range)fn_8007D6A0(&self->actor->actions,6);
 self->actor->update();
}
