// Original owner/child dispatch; typed lookup preserves the native member lifetimes.
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
struct ChildDispatchObject:Manipulator_Z {
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
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
    virtual const Handle_801F7F10& get(int);
    char unknown20[0x168-0x20];
    Handle_801F7F10 first,second;
};
struct ChildDispatchIndex {
    const int value;
    ChildDispatchIndex(int v):value(v) {
    }
    operator int()const {
        return value;
    }
};
struct ChildDispatchEntry {
    ChildDispatchObject*object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char t)const {
        return tag==t;
    }
    ChildDispatchObject*getObject()const {
        return object;
    }
};
struct ChildDispatchEntries {
    ChildDispatchEntry*p;
    ChildDispatchEntry&operator[](const ChildDispatchIndex&i)const {
        return p[i];
    }
};
struct ChildDispatchManager {
    int count,capacity;
    ChildDispatchEntries entries;
};
struct ChildDispatchContext {
    char unknown00[0x118];
    ChildDispatchManager*manager;
};
struct ChildDispatchOwner {
    char unknown00[0x1A8];
    Handle_801F7F10 handle;
};
extern "C" {
    extern ChildDispatchContext lbl_801E9D24;
    extern const char lbl_8037B1A0[6],lbl_8037B1A8[6];
    void fn_802279A0(ChildDispatchOwner*);
    int fn_8024A120(ChildDispatchObject*,const char*,int);
    int fn_8024A094(ChildDispatchObject*,const char*,int);
    void fn_80246314(ChildDispatchObject*,const Handle_801F7F10&);
} static inline ChildDispatchObject*resolve(const Handle_801F7F10&h) {
    ChildDispatchManager*m=lbl_801E9D24.manager;
    const ChildDispatchIndex i(h.bits.index);
    const signed char tag(h.bits.tag);
    if(m->entries[i].matchesTag(tag))return m->entries[i].getObject();
    return 0;
} extern "C" void fn_8023050C(ChildDispatchOwner*self) {
    fn_802279A0(self);
    resolve(self->handle)->slot34();
    ChildDispatchObject *second=resolve(resolve(self->handle)->second);
    ChildDispatchObject *first=resolve(resolve(self->handle)->first);
    fn_8024A120(second,lbl_8037B1A0,1);
    fn_8024A094(second,lbl_8037B1A8,1);
    fn_80246314(first,resolve(self->handle)->get(0));
} typedef char ChildDispatchHandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char ChildDispatchRootSize[(sizeof(Manipulator_Z)==0x20)?1:-1];
typedef char ChildDispatchEntrySize[(sizeof(ChildDispatchEntry)==16)?1:-1];
typedef char ChildDispatchNodeSize[(sizeof(ChildDispatchObject)==0x170)?1:-1];
typedef char ChildDispatchOwnerSize[(sizeof(ChildDispatchOwner)==0x1AC)?1:-1];
