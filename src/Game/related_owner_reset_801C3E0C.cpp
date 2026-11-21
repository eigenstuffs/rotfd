/* Reset the related owner through native retained Handle lifetimes. */
typedef unsigned long DrawPairResetWord;
struct DrawPairResetIndex {
    const int value;
    DrawPairResetIndex(int v):value(v) {
    }
    operator int()const {
        return value;
    }
};
struct Handle_801F7F10 {
    union {
        DrawPairResetWord value;
        struct {
            signed int tag:8,index:24;
        }
        bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct DrawPairResetResource {
    char unknown00[0x134];
    int key;
};
struct DrawPairResetEntry {
    DrawPairResetResource*object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char g)const {
        return tag==g;
    }
};
struct DrawPairResetEntries {
    DrawPairResetEntry*data;
    DrawPairResetEntry&operator[](const DrawPairResetIndex&i)const {
        return data[i];
    }
};
struct DrawPairResetManager {
    int count,capacity;
    DrawPairResetEntries entries;
};
struct DrawPairResetRegistry {
    int count,capacity;
    Handle_801F7F10*items;
};
struct DrawPairResetGlobals {
    char unknown00[0x118];
    DrawPairResetManager*manager;
    DrawPairResetRegistry*registry;
};
extern "C" DrawPairResetGlobals lbl_801E9D24;
extern "C" {
    void fn_801F86C8(DrawPairResetManager*,const Handle_801F7F10*,short);
    void*fn_801F7EB8(const Handle_801F7F10*);
    void fn_80240120(DrawPairResetResource*,int);
    void fn_80269FE0(DrawPairResetResource*);
    void fn_802139D8(void*);
} struct OwnerResetZeroHandle:Handle_801F7F10 {
    OwnerResetZeroHandle() {
        value=0;
    }
    ~OwnerResetZeroHandle() {
    }
};
struct OwnerResetDefaultHandle:OwnerResetZeroHandle {
    OwnerResetDefaultHandle() {
        value=0;
    }
    ~OwnerResetDefaultHandle() {
    }
};
struct OwnerResetCopyHandle:OwnerResetZeroHandle {
    OwnerResetCopyHandle(const Handle_801F7F10&from) {
        value=from.value;
        fn_801F86C8(lbl_801E9D24.manager,&from,1);
    }
    ~OwnerResetCopyHandle() {
    }
};
inline DrawPairResetResource*resolveReset(const Handle_801F7F10&h) {
    DrawPairResetManager*manager=lbl_801E9D24.manager;
    const DrawPairResetIndex index(h.bits.index);
    const signed char tag(h.bits.tag);
    if(manager->entries[index].matchesTag(tag))return manager->entries[index].object;
    return 0;
} inline void assignReset(Handle_801F7F10&to,const Handle_801F7F10&from) {
    fn_801F86C8(lbl_801E9D24.manager,&to,-1);
    to.value=from.value;
    fn_801F86C8(lbl_801E9D24.manager,&from,1);
} struct ManipulatorPrefix {
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
struct DrawPairResetOwner:Manipulator_Z {
    char unknown20[4];
    Handle_801F7F10 first,second;
    unsigned char flags;
};
extern "C" void fn_801C3E0C(DrawPairResetOwner*self) {
    self->Manipulator_Z::slot34();
    if((self->flags&1)&&fn_801F7EB8(&self->second)) {
        int key=resolveReset(self->second)->key;
        fn_80240120(resolveReset(self->second),1);
        if(key) {
            OwnerResetCopyHandle temp(lbl_801E9D24.registry->items[key]);
            fn_80269FE0(resolveReset(temp));
        }   assignReset(self->second,OwnerResetDefaultHandle());
    }  self->flags=0;
    assignReset(self->second,OwnerResetDefaultHandle());
    assignReset(self->first,OwnerResetDefaultHandle());
    fn_802139D8(self);
} typedef char OwnerRootSize[sizeof(Manipulator_Z)==0x20?1:-1];
typedef char OwnerResetHandleSize[sizeof(Handle_801F7F10)==4?1:-1];
typedef char OwnerDrawPairResetEntrySize[sizeof(DrawPairResetEntry)==16?1:-1];
