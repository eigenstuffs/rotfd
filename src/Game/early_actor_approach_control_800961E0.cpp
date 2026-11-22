/* Actor approach/idle control transitions: recharge timer at 0x3E8, height
   and distance limits, selected-target check and random idle choice. The
   engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, no frsp), written as a minimal inline
   asm statement in the math helper; see early_actor_height_control_80096C98.cpp
   for the shared resolve/selected idioms. */
typedef unsigned long Word;
extern "C" const float lbl_80378C48;
extern "C" const float lbl_80378C60;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Vec3 {
    float x, y, z;
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378C48;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Node{char unknown0[0x70];Handle actor;char unknown74[0xB0-0x74];Handle*related;char unknownB4[0x15C-0xB4];Vec3 velocity;char unknown168[0x318-0x168];char control;char unknown319[0x398-0x319];float threshold;char unknown39C[0x3B0-0x39C];float elapsed;float range;char unknown3B8[0x3D0-0x3B8];float interval;char unknown3D4[4];float limit;char unknown3DC[0x3E8-0x3DC];float timer;signed char ready;};
struct RootNode:Node{};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct RootEntry{RootNode*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};struct RootManager{int count,capacity;RootEntry*entries;};
struct Registry{char unknown0[0x1C];Handle*handle;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x20];Registry*registry;}lbl_801E9D24;
extern "C"{void slot38__14CJellyfishMoveFf(Node*);signed char fn_8007D604(void*,int);Node*fn_801F7EB8(const Handle*);void fn_80099F74(Node*,float*);void fn_8009A270(Node*,float*);void fn_8007D6A0(void*,int);int fn_801F1224(int,int);void fn_80099E40(Node*);}
inline Node*resolve(const Handle&h){const Entry*entries=lbl_801E9D24.manager->entries;int index=h.bits.index;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}
inline RootNode*resolveRoot(const Handle&h){RootEntry*e=&((RootManager*)lbl_801E9D24.manager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
inline Node*selected(){const Handle&h=resolve(*resolveRoot(*lbl_801E9D24.registry->handle)->related)->actor;if(fn_801F7EB8(&h))return resolve(h);return 0;}
extern "C" void slot38__16CYellowJfishMoveFf(Node*self,float delta){
 slot38__14CJellyfishMoveFf(self);
 if(fn_8007D604(&self->control,3)||fn_8007D604(&self->control,4))return;
 if(!self->ready){
  self->timer-=delta;
  if(self->timer<=lbl_80378C48){self->timer=lbl_80378C60;self->ready=1;}
 }
 float distance,height;
 fn_80099F74(self,&distance);
 fn_8009A270(self,&height);
 if(height>self->limit&&!fn_8007D604(&self->control,8))fn_8007D6A0(&self->control,8);
 else if(distance<=self->threshold&&self->ready&&!fn_8007D604(&self->control,7)&&!fn_8007D604(&self->control,8)&&!fn_8007D604(&selected()->control,0x2F))fn_8007D6A0(&self->control,7);
 else{
  self->elapsed+=delta;
  if(self->elapsed>=self->interval&&(fn_8007D604(&self->control,6)||fn_8007D604(&self->control,5))){
   self->elapsed=lbl_80378C48;
   if(fn_801F1224(0,1)){fn_80099E40(self);fn_8007D6A0(&self->control,6);}
   else if(self->velocity.length()<self->range)fn_8007D6A0(&self->control,5);
  }
 }
}
