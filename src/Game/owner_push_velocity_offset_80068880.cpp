/* Owner push: offsets the queried owner's velocity by the scaled planar push
   returned from fn_8009F278, clears actor flag bit39 and byte 3E9, then
   moves the resource owner to its position plus a fixed offset. Handle
   layers follow actor_handle_pair_dispatch_8006ECE8.cpp. */
typedef unsigned long u32;
typedef unsigned long long u64;
struct Node;
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;u32 unknown04,unknown08;signed char tag;char opaque0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{char opaque00[8];EntryArray entries;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager;}lbl_801E9D24;void fn_801F86C8(Manager*,const void*,int);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct Vec3{
    float x,y,z;
    Vec3(){}
    Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
    Vec3 translated(float ox,float oy,float oz)const{return Vec3(x+ox,y+oy,z+oz);}
    Vec3 operator*(float k)const{return Vec3(x*k,y*k,z*k);}
    Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
    Vec3&operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;return*this;}
    Vec3&operator*=(float k){x*=k;y*=k;z*=k;return*this;}
};
struct Vec2{float x,y;};
struct Matrix{float m[16];Vec3 getPos()const{return Vec3(m[12],m[13],m[14]);}};
struct Node{char opaque00[0x30];u64 flags30;char opaque38[0x124-0x38];Matrix*matrix;char opaque128[0x358-0x128];Vec3 velocity;char opaque364[0x3E9-0x364];signed char byte3E9;
    Vec3 getPos()const{return matrix->getPos();}};
struct Resource{char opaque00[0x58];Handle_801F7F10 owner;};
extern "C"{void fn_8009F278(Node*,void*,Vec2*);void fn_8023D100(Node*,const Vec3*);void fn_8023DE28(Node*);
extern const float lbl_803787D0,lbl_803787D4,lbl_803787D8;}
struct QueryPrefix{u32 unknown00;};
struct Query:QueryPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual Resource*getResource();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual const Handle_801F7F10*getHandle();
};
extern "C" void fn_80068880(Query*self,void*arg,float scale)
{
    Vec2 out;
    fn_8009F278(resolve(*self->getHandle()),arg,&out);
    Vec3 delta(out.x,lbl_803787D0,out.y);
    delta*=scale;
    resolve(*self->getHandle())->velocity+=delta;
    resolve(*self->getHandle())->flags30&=~0x8000000000ULL;
    resolve(*self->getHandle())->byte3E9=0;
    Handle_80020B90 handle(self->getResource()->owner);
    Vec3 target=resolve(handle)->getPos().translated(lbl_803787D4,lbl_803787D8,lbl_803787D4);
    fn_8023D100(resolve(handle),&target);
    fn_8023DE28(resolve(handle));
}
