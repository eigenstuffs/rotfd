// fn_8025E714: collect the callback's keys into a snapshot through the member
// callback (message 8), then append a copy of the callback to each key's group
// list (state != 0: first list, else second), creating missing groups.
// Inline helper boundaries (firstGroup, newGroup, addCallback, sizeOf) and the
// operator new / CallbackEntry new-expression are what fix the register
// colouring; flattening any of them changes the allocation.
typedef unsigned long u32;
struct CallbackCycle;
struct DispatchNode;
typedef int (CallbackCycle::*CycleCallback)(int,DispatchNode*);
struct CallbackEntry {
    CycleCallback callback;
    CallbackEntry*next;
    CallbackEntry(const CycleCallback&value){
        callback=value;
        next=0;
    }
};
struct CallbackGroup {
    int key;
    CallbackEntry*first,*second;
    CallbackGroup*next;
};
struct SnapshotKey {
    int key;
    signed char state;
    char unknown5[3];
};
struct Snapshot {
    void*table;
    char unknown4[0xc];
    int length,capacity;
    SnapshotKey*data;
    u32 unknown1C;
    void*bytes;
    int size;
    unsigned short flags,count;
};
struct CallbackPrefix {
    char unknown0[8];
};
struct CallbackCycle:CallbackPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual CallbackGroup*groups();
    virtual void setGroups(CallbackGroup*);
};
extern "C" {
    extern char lbl_801EF5C8[];
    extern const char lbl_802AEC80[],lbl_802AEC90[];
    void*fn_801EFA1C(void*,int,const char*,const char*,int,int);
    CallbackGroup*fn_8025FCE4(void*,int,int);
    Snapshot*fn_8025F92C(Snapshot*);
    Snapshot*fn_8025F6F4(Snapshot*,int);
}
inline void*operator new(unsigned long size,const char*name,const char*file,int line){
    return fn_801EFA1C(lbl_801EF5C8,size,name,file,line,4);
}
inline CallbackGroup*firstGroup(CallbackCycle*self){
    return self->groups();
}
inline CallbackGroup*newGroup(int key){
    CallbackGroup*group=(CallbackGroup*)fn_801EFA1C(lbl_801EF5C8,0x10,lbl_802AEC80,lbl_802AEC90,0x2c1,4);
    if(group)group=fn_8025FCE4(group,key,0);
    return group;
}
inline void addCallback(CallbackCycle*self,int key,signed char state,CycleCallback callback){
    CallbackGroup*group;
    for(group=firstGroup(self);group;group=group->next){
        if(key==group->key)break;
    }
    if(!group){
        group=newGroup(key);
        group->next=self->groups();
        self->setGroups(group);
    }
    CallbackEntry*entry=new(lbl_802AEC80,lbl_802AEC90,0x2c6)CallbackEntry(callback);
    if(state){
        entry->next=group->first;
        group->first=entry;
    }else{
        entry->next=group->second;
        group->second=entry;
    }
}
inline int sizeOf(const Snapshot&s){return s.length;}
extern "C" void fn_8025E714(CallbackCycle*self,const CycleCallback&callback){
    Snapshot snapshot;
    fn_8025F92C(&snapshot);
    (self->*callback)(8,(DispatchNode*)&snapshot);
    int count=sizeOf(snapshot);
    for(int i=0;i<count;i++)
        addCallback(self,snapshot.data[i].key,snapshot.data[i].state,callback);
    fn_8025F6F4(&snapshot,-1);
}
