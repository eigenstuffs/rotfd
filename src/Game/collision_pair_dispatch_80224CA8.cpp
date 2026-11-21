// Collision event dispatch, handle ownership and event value construction.

typedef unsigned long Word;
struct Handle_801F7F10{
    union{
        Word value;
        struct{
            signed int generation:8,index:24;
        } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct CollisionNode;
struct CollisionEntry{
    CollisionNode*object;
    Word unused04,unused08;
    signed char generation;
    char unused0D[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct CollisionManager{
    Word count,capacity;
    CollisionEntry*entries;
};
struct CollisionContext{
    char unused00[0x118];
    CollisionManager*manager;
};
extern "C"{
    extern CollisionContext lbl_801E9D24;
    void fn_801F86C8(void*,const void*,int);
    void fn_802073E8(void*,int,void*,float);
}
struct CollisionCopy:Handle_801F7F10{
    CollisionCopy(const Handle_801F7F10&h){
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
};
struct CollisionZero:Handle_801F7F10{
    CollisionZero(){
        value=0;
    }
};
struct CollisionZeroCopy:CollisionZero{
    CollisionZeroCopy(const Handle_801F7F10&h){
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
};
struct CollisionVec3{
    float x,y,z;
    CollisionVec3(){
    }
    CollisionVec3&operator=(const CollisionVec3&v){
        x=v.x;
        y=v.y;
        z=v.z;
        return*this;
    }
    CollisionVec3(const CollisionVec3&v):x(v.x),y(v.y),z(v.z){
    }
};
struct CollisionEvent{
    CollisionVec3 point;
    Word unused0C;
    unsigned long long flags;
    CollisionVec3 direction;
    CollisionEvent(const CollisionVec3&p,unsigned long long f,const CollisionVec3&d){
        flags=f;
        point=p;
        direction=d;
    }
};
struct CollisionRecord{
    CollisionVec3 direction;
    char unused0C[0x38];
    Handle_801F7F10 first;
    Word unused48;
    Handle_801F7F10 second;
    char unused50[0x58];
};
struct CollisionPrefix{
    Word unused00;
    Handle_801F7F10 identity;
};
struct CollisionNode:CollisionPrefix{
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual int respond(CollisionZeroCopy,const CollisionEvent&);
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual const Handle_801F7F10*getHandle(int);
    const Handle_801F7F10&identityHandle()const{
        return identity;
    }
    char unused0C[0x18];
    Handle_801F7F10 linked;
    char unused28[0x10];
    unsigned long long flags;
    char unused40[0x30];
    Handle_801F7F10 delegate;
    char unused74[0xBC];
    Handle_801F7F10 owner;
    char unused134[0x44];
    int beginEvent,endEvent;
    Word unused180,unused184;
    CollisionRecord*records;
};
// Raw handle resolution leaves the object type to the caller.
static inline void*resolveRaw(const Handle_801F7F10&h){
    int index=h.bits.index;
    CollisionManager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==h.bits.generation?m->entries[index].object:0;
}
static inline CollisionNode*resolve(const Handle_801F7F10&h){
    return (CollisionNode*)resolveRaw(h);
}
extern "C" void fn_8021F518(CollisionNode*,const CollisionEvent&,int);
// Each full-expression Copy retains the sender handle across event dispatch.
extern "C" void fn_80224CA8(CollisionNode*self,CollisionNode*other,const CollisionVec3*point,unsigned long long flags,int index){
    CollisionNode*otherOwner=resolve(other->owner);
    CollisionNode*first=resolve(self->records[index].first);
    CollisionNode*second=resolve(self->records[index].second);
    CollisionNode*selfAgent=resolve(self->linked);
    CollisionNode*firstAgent=first?resolve(first->linked):0;
    CollisionNode*secondAgent=second?resolve(second->linked):0;
    if(first)first->getHandle(0);
    fn_8021F518(self,CollisionEvent(*point,flags,self->records[index].direction),index);
    if(flags&0x800000000000ULL){
        if(first&&other==resolve(*first->getHandle(0)))return;
        if(otherOwner&&(otherOwner->flags&0x400000ULL))first=resolve(otherOwner->delegate);
        else first=0;
        float response=-1612.0f;
        if(first)response=(float)first->respond(CollisionZeroCopy(other->identityHandle()),CollisionEvent(*point,flags,self->records[index].direction));
        if(otherOwner){
            if(firstAgent)fn_802073E8(firstAgent,self->endEvent,resolve(CollisionCopy(otherOwner->identityHandle())),response);
            else if(selfAgent)fn_802073E8(selfAgent,self->endEvent,resolve(CollisionCopy(otherOwner->identityHandle())),-1612.0f);
            if(secondAgent==otherOwner){
                if(firstAgent)fn_802073E8(secondAgent,0x37,resolve(CollisionCopy(firstAgent->identityHandle())),-1612.0f);
                if(selfAgent)fn_802073E8(self,0x37,resolve(CollisionCopy(selfAgent->identityHandle())),-1612.0f);
            }
            if(firstAgent)fn_802073E8(otherOwner,self->endEvent,resolve(CollisionCopy(firstAgent->identityHandle())),-1612.0f);
        }
        else{
            if(firstAgent)fn_802073E8(other,self->endEvent,resolve(CollisionCopy(firstAgent->identityHandle())),-1612.0f);
            if(selfAgent)fn_802073E8(other,self->endEvent,resolve(CollisionCopy(selfAgent->identityHandle())),(float)index);
        }
    }
    else{
        if(firstAgent)fn_802073E8(self,self->beginEvent,resolve(CollisionCopy(firstAgent->identityHandle())),-1612.0f);
        if(secondAgent)fn_802073E8(self,0x38,resolve(CollisionCopy(secondAgent->identityHandle())),-1612.0f);
        if(selfAgent)fn_802073E8(other,self->beginEvent,resolve(CollisionCopy(selfAgent->identityHandle())),(float)index);
    }
}
typedef char RecordSize[sizeof(CollisionRecord)==0xA8?1:-1];
typedef char EventSize[sizeof(CollisionEvent)==0x28?1:-1];
