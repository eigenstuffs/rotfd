extern "C" const float lbl_80378D68;

struct Vec3{
    float x,y,z;
    Vec3(){}
    Vec3(float xx,float yy,float zz):x(xx),y(yy),z(zz){}
    Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}
    Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
    Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
    // Scale by the pooled rate constant lbl_80378D68; each component reads the
    // shared label in its own form (emulates the original's uncombined literal uses).
    Vec3 scaledByRate()const{return Vec3(x*lbl_80378D68,y*(*(const float*)&lbl_80378D68),z*(*(const float*)(unsigned long)&lbl_80378D68));}
};

struct PendingFlagsResource{char unknown00[0x38];unsigned long long flags;};
struct PendingHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct PendingEntry{PendingFlagsResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct PendingManager{int count,capacity;PendingEntry*entries;};
struct PendingContext{char unknown00[0x118];PendingManager*manager;};
extern "C" PendingContext lbl_801E9D24;
inline PendingFlagsResource*resolvePending(const PendingHandle&h){PendingEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}

struct PendingHandleView{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct PendingEntryView{PendingFlagsResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct PendingManagerView{int count,capacity;PendingEntryView*entries;};
inline PendingFlagsResource*resolvePendingView(const PendingHandleView&h){PendingEntryView*e=&((PendingManagerView*)lbl_801E9D24.manager)->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}

struct PendingImpulseOwner{char unknown00[0x24];PendingHandle handle;char unknown28[0x358-0x28];Vec3 velocity;char unknown364[0x384-0x364];Vec3 impulse;};
struct PendingImpulseOwnerView{char unknown00[0x24];PendingHandleView handle;};

extern "C" void fn_8009AB94(PendingImpulseOwner*self,float delta){
    if(resolvePending(self->handle)->flags&0x40000000000ULL){
        resolvePendingView(((PendingImpulseOwnerView*)self)->handle)->flags&=~0x40000000000ULL;
        self->velocity+=(self->impulse*delta).scaledByRate();
    }
}
