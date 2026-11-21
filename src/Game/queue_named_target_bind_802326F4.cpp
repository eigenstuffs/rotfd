// Native queue name/handle binding; partial receiver views preserve original lifetime owners.
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct {
            signed int tag:8,index:24;
        }
        bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ManipulatorPrefix {
    unsigned long unknown00[2];
};
struct Manipulator_Z:ManipulatorPrefix {
    Manipulator_Z();
    virtual ~Manipulator_Z();
    virtual void slot0C(unsigned long);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C(float);
    virtual void slot30();
    virtual void slot34();
    virtual void slot38(float)=0;
    virtual void slot3C();
    char unknown0C[0x20-0x0C];
};
struct QueueBindTarget : Manipulator_Z {
    virtual void notifySecond(QueueBindTarget*);
    virtual void notifyFirst(QueueBindTarget*);
    char unknown20[0x28-0x20];
    Handle_801F7F10 *handles;
};
struct QueueBindIndex {
    const int value;
    QueueBindIndex(int v):value(v) {
    }
    operator int()const {
        return value;
    }
};
struct QueueBindEntry {
    QueueBindTarget*object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char t)const {
        return tag==t;
    }
    QueueBindTarget*getObject()const {
        return object;
    }
};
struct QueueBindEntries {
    QueueBindEntry*p;
    QueueBindEntry&operator[](const QueueBindIndex&i)const {
        return p[i];
    }
};
struct QueueBindManager {
    int count,capacity;
    QueueBindEntries entries;
};
struct QueueBindLookup {
    char unknown00[0x94];
    int*indices;
    int at(const int&i)const {
        return indices[i];
    }
};
struct QueueBindContext {
    char unknown00[0x118];
    QueueBindManager*manager;
    char unknown11C[0x144-0x11C];
    QueueBindLookup*lookup;
};
extern "C" {
    extern QueueBindContext lbl_801E9D24;
    extern const char lbl_802AE9D8[];
    void fn_801F86C8(QueueBindManager*,const Handle_801F7F10*,short);
    QueueBindTarget*fn_801F7EB8(const Handle_801F7F10*);
    void fn_8024C5D4(QueueBindTarget*);
    unsigned long fn_801F948C(void*,const char*);
} struct QueueBindName {
    unsigned long value;
    QueueBindName(const char*text) {
        value=fn_801F948C(this,text);
    }
};
struct QueueBindOwner {
    QueueBindName name;
    char unknown04[0x1EC];
    Handle_801F7F10 first,second,third;
};
extern "C" Handle_801F7F10 fn_801B550C(QueueBindManager*,const QueueBindName&,const QueueBindName&);
struct QueueBindZero : Handle_801F7F10 {
    QueueBindZero() {
        value=0;
    }
};
struct QueueBindZero2 : QueueBindZero {
    QueueBindZero2() {
        value=0;
    }
};
struct QueueBindCopy : QueueBindZero2 {
    QueueBindCopy(const Handle_801F7F10&handle) {
        value=handle.value;
        fn_801F86C8(lbl_801E9D24.manager,&handle,1);
    }
};
static inline QueueBindTarget*resolve(const Handle_801F7F10&h) {
    QueueBindManager*manager=lbl_801E9D24.manager;
    const QueueBindIndex index(h.bits.index);
    const signed char tag(h.bits.tag);
    if(manager->entries[index].matchesTag(tag))return manager->entries[index].getObject();
    return 0;
} static inline void assign(Handle_801F7F10&to,const Handle_801F7F10&from) {
    fn_801F86C8(lbl_801E9D24.manager,&to,-1);
    to.value=from.value;
    fn_801F86C8(lbl_801E9D24.manager,&from,1);
} extern "C" void fn_802326F4(QueueBindOwner*self,const Handle_801F7F10*handle) {
    assign(self->first,*handle);
    QueueBindTarget *target=resolve(self->first);
    if(target) {
        fn_8024C5D4(target);
        if(!fn_801F7EB8(&self->third)) {
            for(int i=0;i<16;++i) {
                if(fn_801F7EB8(&target->handles[lbl_801E9D24.lookup->at(i+12)])) {
                    assign(self->third,QueueBindCopy(fn_801B550C(lbl_801E9D24.manager,QueueBindName(lbl_802AE9D8),self->name)));
                    break;
                }
            }
        }
    }  target=resolve(self->third);
    if(target) {
        target->notifyFirst(resolve(self->first));
        target->notifySecond(resolve(self->second));
    }
} typedef char QueueBindHandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char QueueBindEntrySize[(sizeof(QueueBindEntry)==16)?1:-1];
typedef char QueueBindNameSize[(sizeof(QueueBindName)==4)?1:-1];
typedef char QueueBindRootSize[(sizeof(Manipulator_Z)==0x20)?1:-1];
typedef char QueueBindTargetSize[(sizeof(QueueBindTarget)==0x2C)?1:-1];
typedef char QueueBindOwnerSize[(sizeof(QueueBindOwner)==0x1FC)?1:-1];
