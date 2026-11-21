/* Control 8A follow-up (called from fn_80048BAC): when the owner carries flag 0x2000000 it resets the current child's
 * actor launch vector to (0,12,0) and marks it; otherwise, for flag 0x20000000, it takes the forward (z) axis of the
 * first group record whose node has flag 0x2000000, flattens and normalizes it, and sets the owner target's velocity to
 * (2x, 10, 2z). The original pooled 0/1/2/10/12 literals now live in shared labels; IR CSE of a repeated extern read
 * creates a temporary that colors differently from the original literal loads, so each repeated label read in one
 * block uses a distinct but equivalent lvalue form (the backend still merges them into one lfs). */
typedef unsigned long Word;
union Handle{Word word;struct{signed int tag:8,index:24;}bits;};
struct Node;
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
struct Related{char unknown00[0x1C];Handle*handle;};
struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;};
extern "C"{extern Context lbl_801E9D24;Node*fn_801F7EB8(const Handle*);extern const float lbl_80378570,lbl_80378574,lbl_80378578,lbl_8037857C,lbl_80378580;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct Matrix{float m[3][3];};
struct Node{char unknown00[0x1C];Handle handle1C;Handle handle20;char unknown24[0xC];Matrix rotation;char unknown54[0x1C];Handle handle70;char unknown74[0x3C];Handle*child;char unknownB4[0x24];int countD8;char unknownDC[4];Handle*recordsE0;char unknownE4[0x3C];Word flags120;};
struct Actor{char unknown00[0x144];Vec3 velocity;char unknown150[0x2C4];Vec3 impulse;unsigned char flag420;};
struct Flagged{char unknown00[0x38];unsigned long long flags38;char unknown40[0x30];Handle handle70;};
struct Owner{char unknown00[0x28];Handle handle28;char unknown2C[0x2C];Handle handle58;};
inline Node*resolve(const Handle&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline Node*resolveOrNull(const Handle&h){Node*r=0;Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))r=m->entries[index].object;return r;}
inline signed char flagSet(unsigned long long flags,unsigned long long mask){if(flags&mask)return 1;return 0;}
inline Node*currentChild(){return resolve(*resolve(*lbl_801E9D24.related->handle)->child);}
extern "C" void fn_800487C4(Owner*self){
 Flagged*owner=(Flagged*)resolve(self->handle28);
 if(flagSet(owner->flags38,0x2000000ULL)){
  const Handle*h=&currentChild()->handle70;Actor*actor=fn_801F7EB8(h)?(Actor*)resolve(*h):0;
  actor->impulse=Vec3(lbl_80378570,lbl_80378574,lbl_80378570);
  actor->flag420=1;
 }else if(owner->flags38&0x20000000ULL){
  Actor*target=(Actor*)resolveOrNull(owner->handle70);
  Node*const group=resolve(resolve(self->handle58)->handle1C);
  Vec3 dir;
  for(int i=0;i<group->countD8;i++){
   if(resolve(resolve(group->recordsE0[i])->handle20)->flags120&0x2000000){
    const Matrix&m=resolve(resolve(group->recordsE0[i])->handle20)->rotation;
    dir.x=m.m[0][0]*lbl_80378570+m.m[1][0]**(const float*)&lbl_80378570+m.m[2][0]*lbl_80378578;
    dir.z=m.m[0][2]**(float*)&lbl_80378570+m.m[1][2]*((const float*)&lbl_80378570)[0]+m.m[2][2]**(const float*)&lbl_80378578;
    break;
   }
  }
  float inverse=reciprocalSqrt(dir.x*dir.x+lbl_80378570+dir.z*dir.z);
  dir.x*=inverse;dir.z*=inverse;
  dir.x*=lbl_8037857C;dir.z*=*(const float*)&lbl_8037857C;
  target->velocity.x=dir.x;target->velocity.y=lbl_80378580;target->velocity.z=dir.z;
 }
}
