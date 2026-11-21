// Menu task-status update (fn_800B4628). Names and offset-based views are inferred.
// The strings are the original pooled literals addressed from one base register
// (r30 = lbl_802A0400); the Strings view spans lbl_802A0400 (0x60, world names,
// shared with fn_800B3C8C) and lbl_802A0460 (0x8C, task icon / GUI task names).
// The typed temporary emits a weak __dt__15Handle_800723F4Fv that the linker drops
// in favour of the existing strong copy at 0x800723F4.

typedef unsigned long Word;
struct Handle_801F7F10 {
    union {
        Word word;
        struct {
            signed int tag:8,index:24;
        }bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Node;
struct Entry {
    Node*object;
    Word unknown04,unknown08;
    signed char tag;
    char unknown0D[3];
    signed char getTag()const {
        return tag;
    }
};
struct Manager {
    int count,capacity;
    Entry*entries;
};
struct InputPrefix {
    char unknown00[0x1C];
};
struct Input:InputPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual signed char test(int);
};
struct Pair {
    Word unknown00,unknown04,left,right;
};
struct Gates {
    char unknown00[0x20];
    signed char flags[9];
    char unknown29[0x6B];
};
struct World {
    char unknown00[0xEC];
    Pair*pairs;
    int selected;
    char unknownF4[0x44];
    Gates*gates;
    char unknown13C[0xD4];
    short mode;
    char unknown212[0x107];
    signed char ready;
    Pair& getPair(int i) {
        return pairs[i];
    } Word getRight(int i) {
        return getPair(i).right;
    } Word getLeft(int i) {
        return getPair(i).left;
    }
};
struct System {
    char unknown00[0x15058];
    World*world;
};
struct Context {
    char unknown00[0x118];
    Manager*manager;
    char unknown11C[8];
    System*system;
    char unknown128[0x24];
    void*scene;
    char unknown150[4];
    Input*input;
};
extern "C" {
    extern Context lbl_801E9D24;
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
    void fn_801F86C8(Manager*,const void*,int);
    Word fn_801F948C(void*,const char*);
    extern signed char lbl_80377788,lbl_80377794;
    extern float lbl_8037778C;
    extern int lbl_80377790,lbl_80377798;
    extern const float lbl_803792F0,lbl_803792F4,lbl_803792F8,lbl_80379300,lbl_80379318,lbl_8037931C,lbl_80379320;
}
struct Strings {
    char worlds[0x60];
    char unknownTask[0x10];
    char taskIcon1[0xC];
    char taskIcon2[0xC];
    char taskIcon3[0xC];
    char taskIcon4[0xC];
    char taskIcon5[0xC];
    char taskIcon6[0xC];
    char guiTaskAction[0x10];
    char guiTaskNoCheck[0x14];
    char guiTaskCheck[0x10];
};
extern "C" const Strings lbl_802A0400;
struct Name {
    Word word;
    Name() {
    }Name(const char*s) {
        word=fn_801F948C(this,s);
    }Name(const Name&n) {
        word=n.word;
    }bool operator==(const Name&n)const {
        return word==n.word;
    }void operator=(const char*s) {
        word=fn_801F948C(this,s);
    }
};
struct Zero_B4628:Handle_801F7F10 {
    ~Zero_B4628() {
    }
};
struct Handle_800723F4:Zero_B4628 {
    Handle_800723F4();
    ~Handle_800723F4() {
    }static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
inline Word resolveWord(const Handle_801F7F10&h) {
    int index=h.bits.index;
    Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[index].getTag();
    if(tag==h.bits.tag)return(Word)m->entries[index].object;
    return 0;
}inline Node*resolve(const Handle_801F7F10&h) {
    return(Node*)resolveWord(h);
}
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&h) {
    fn_801F86C8(lbl_801E9D24.manager,&d,-1);
    d.word=h.word;
    fn_801F86C8(lbl_801E9D24.manager,&h,1);
}
struct Record {
    char unknown00[0x80];
    Name name;
    char unknown84[8];
    unsigned short flags;
    char unknown8E[0x32];
    Handle_801F7F10 handle;
    const Name&getName()const {
        return name;
    }
};
struct Decay {
    Word unknown00;
    float value,unknown08,time,slope;
};
struct Owner {
    char unknown00[0x1C];
    float phase;
    char unknown20[4];
    Handle_801F7F10 handle;
    char unknown28[0x40];
    int count,capacity;
    Record*records;
    Handle_801F7F10 pulseHandle;
    float pulse;
    char unknown7C[0x44];
    Decay decays[10];
    int selection;
    int ids[6];
    Record&getRecord(int i) {
        return records[i];
    }
};
struct SmallRecord {
    int id;
    Word unknown04;
    Name name;
    char unknown0C[0x40];
    signed char first;
    char unknown4D;
    signed char active;
    char unknown4F;
};
struct BigRecord {
    char unknown00[0x80];
    Word flags;
};
extern "C" {
    extern SmallRecord lbl_802F4208[300];
    extern BigRecord lbl_802F9FC8[400];
    void fn_80031654(Node*,Word,Word);
    float fn_80284FA8(float);
    Word fn_801F7EB8(const Handle_801F7F10*);
    void fn_80239828(Node*,float);
    void fn_8003FA74(World*);
    void fn_802073E8(void*,int,Node*,float);
    Handle_800723F4 fn_802631B0(void*,const Name&);
}
inline SmallRecord*getSmallRecord(int i) {
    return &lbl_802F4208[i];
} inline SmallRecord*find(int id) {
    SmallRecord*result=0;
    for(int i=0;i<300;++i) {
        SmallRecord*r=getSmallRecord(i);
        if(id==r->id) {
            result=r;
            break;
        }
    }return result;
}
inline World*world() {
    return lbl_801E9D24.system->world;
}
inline float pulseScale(float value) {
    return value*lbl_803792F8;
}
inline void advance(Owner*self) {
    for(int i=lbl_80377790;i<400;++i) {
        if(lbl_802F9FC8[i].flags&1) {
            lbl_80377790=i+1;
            return;
        }
    }
    World*w=world();
    if(w->mode==1) {
        w->ready=1;
        fn_8003FA74(w);
    }
    else fn_802073E8(self,0x5C,resolve(self->handle),lbl_8037931C);
}
extern "C" void fn_800B4628(Owner*self,float delta) {
    const Strings*const s=&lbl_802A0400;
    if(lbl_801E9D24.input->test(12)&&lbl_801E9D24.input->test(13)&&lbl_801E9D24.input->test(3)&&lbl_801E9D24.input->test(1)&&!lbl_801E9D24.input->test(0)&&!lbl_801E9D24.input->test(2)&&lbl_80377798==0)lbl_80377798=1;
    if(lbl_80377798>0&&lbl_801E9D24.input->test(10)) {
        Word right=world()->getRight(lbl_80377798);
        Word left=world()->getLeft(lbl_80377798);
        lbl_80377798=0;
        fn_80031654(resolve(self->handle),right,left);
    }
    self->pulse=pulseScale(lbl_803792F4*(lbl_803792F0+fn_80284FA8(lbl_80379320*self->phase)));
    if(fn_801F7EB8(&self->pulseHandle))fn_80239828(resolve(self->pulseHandle),delta);
    if(lbl_80377788) {
        if(!lbl_80377794)lbl_8037778C-=delta;
        if(lbl_8037778C<=lbl_80379300) {
            lbl_8037778C=lbl_80379318;
            advance(self);
        }
    }
    for(int i=0;i<10;++i) {
        self->decays[i].time-=delta;
        self->decays[i].value=self->decays[i].value-self->decays[i].slope*delta;
    }
    World*w=world();
    for(int i=0;i<9;++i) {
        if(!(self->selection==-1?w->gates[w->selected].flags[i]:w->gates[self->selection].flags[i])) {
            int id=self->selection*100+i;
            SmallRecord*r=find(id);
            if(r) {
                r->active=1;
                r->first=1;
            }
        }else {
            int id=self->selection*100+i;
            SmallRecord*r=find(id);
            if(r)r->active=0;
        }
    }
    for(int i=0;i<self->count;++i) {
        int kind=-1;
        if(self->getRecord(i).getName()==Name(s->taskIcon1))kind=0;
        else if(self->getRecord(i).getName()==Name(s->taskIcon2))kind=1;
        else if(self->getRecord(i).getName()==Name(s->taskIcon3))kind=2;
        else if(self->getRecord(i).getName()==Name(s->taskIcon4))kind=3;
        else if(self->getRecord(i).getName()==Name(s->taskIcon5))kind=4;
        else if(self->getRecord(i).getName()==Name(s->taskIcon6))kind=5;
        if(kind>-1) {
            self->getRecord(i).flags|=4;
            if(lbl_802F4208[self->ids[kind]].active)self->getRecord(i).flags&=~4;
            Name name=lbl_802F4208[self->ids[kind]].name;
            if(name==Name(s->guiTaskAction)) {
                name=s->guiTaskNoCheck;
                if(lbl_802F4208[self->ids[kind]].active)name=s->guiTaskCheck;
            }
            assign(self->getRecord(i).handle,fn_802631B0(lbl_801E9D24.scene,name));
        }
    }
}
