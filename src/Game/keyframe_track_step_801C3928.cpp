/* Keyframe track playback step (fn_801C3928): advances the current key index
 * while the playback time is past the key time, interpolates position
 * (extrapolated from the key pair) and slerps rotation (fn_8008D420), applies
 * them to the bound object (fn_8023D120), then logs an ahead/late transition
 * when the virtual time-state query (slot 0x48) changes. */
struct Entry{void*object;char unknown04[8];signed char tag;char pad[3];
    signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Globals{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;}lbl_801E9D24;
struct Handle{signed int tag:8;signed int index:24;
    void*get()const{int i=index;Manager*m=lbl_801E9D24.manager;int t=m->entries[i].getTag();return t==tag?m->entries[i].object:0;}};
struct Vec3{float x,y,z;
    Vec3(){}
    Vec3(float a,float b,float c):x(a),y(b),z(c){}
    const Vec3&get()const{return *this;}
    Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
    Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
    Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
};
struct Quat{float x,y,z,w;};
struct Record{float time;Vec3 position;Quat rotation;};
template<class T>struct Array{int count;int capacity;T*data;};
struct ObjectBase{char unknown00[8];};
struct Object:ObjectBase{
    virtual void s08();virtual void s0C();virtual void s10();virtual void s14();
    virtual void s18();virtual void s1C();virtual void s20();virtual void s24();
    virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
    virtual void s38();virtual void s3C();virtual void s40();virtual void s44();
    virtual unsigned char s48(float);
    char unknown0C[0x10];
    float time;
    long index;
    char unknown24[4];
    Handle handle;
    char unknown2C;
    unsigned char state;
    char unknown2E[0x12];
    Array<Record>records;
};
extern "C"{
    Quat fn_8008D420(const Quat&,const Quat&,float);
    void fn_8023D120(void*,const Vec3*,const Quat*);
    void fn_801FA014(void*,const char*,...);
    extern const char lbl_802ACA98[];
    extern const char lbl_802ACAA8[];
}
extern "C" void fn_801C3928(Object*self){
    while(self->index<self->records.count&&self->time>self->records.data[self->index].time)
        self->index++;
    if(self->index==self->records.count)
        self->index--;
    if(self->index<self->records.count){
        Record&a=self->records.data[self->index-1];
        Record&b=self->records.data[self->index];
        float t=(self->time-a.time)/(b.time-a.time);
        Vec3 pos;
        Quat rot;
        Vec3 d=b.position-a.position;
        pos=b.position.get()+d.get()*t;
        rot=fn_8008D420(self->records.data[self->index-1].rotation,b.rotation,t);
        fn_8023D120(self->handle.get(),&pos,&rot);
    }
    unsigned char s=self->s48(self->time);
    if(self->state!=s){
        self->state=s;
        if(self->state==1)
            fn_801FA014(lbl_801E9D24.logger,lbl_802ACA98);
        else
            fn_801FA014(lbl_801E9D24.logger,lbl_802ACAA8);
    }
}
