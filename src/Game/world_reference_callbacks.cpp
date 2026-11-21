#include "objects_owner_internal.h"
struct WorldNotifyHandle:OwnerHandle {
    WorldNotifyHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
    ~WorldNotifyHandle(){}
};
struct WorldRegistryStorage {char unknown[0x30];};
struct WorldRegistry:WorldRegistryStorage {
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
    virtual void slot3C(const WorldNotifyHandle&);
    virtual void slot40(const WorldNotifyHandle&);
};
struct WorldReferenceGlobals {char unknown[0x11C];void*manager11C;u32 field120;WorldRegistry*registry;char unknown128[0x24];void*manager14C;};
static inline WorldRegistry*registry(){return ((WorldReferenceGlobals*)&lbl_801E9D24)->registry;}
struct WorldHandleArray {int count,capacity;OwnerHandle*data;};
struct WorldFixedHandles { OwnerHandle data[8];int count;OwnerHandle&operator[](unsigned int i){return data[i];} };
struct WorldReferenceView:BaseObject_Z {
    WorldHandleArray handlesC,handles18,handles24;
    OwnerHandle handle30;
    char index34[0x4044],index4078[0x4044],index80BC[0x4044];
    char unknownC100[0x10];
    WorldFixedHandles handlesC110;
    WorldHandleArray handlesC134;
    WorldFixedHandles handlesC140;
    OwnerHandle handleC164,handleC168;
};
extern "C" {
void fn_801B3E54(Manager*,const Handle_801F7F10*);
void fn_802667F0(void*);
void fn_80263650(void*,void*);
void fn_8026B768(void*,const WorldNotifyHandle&);
}
extern "C" void fn_801E8B10(WorldReferenceView*self){
    registry()->slot3C(WorldNotifyHandle(self->getIdentity()));
    registry()->slot40(WorldNotifyHandle(self->getIdentity()));
}
extern "C" void fn_801E8C08(WorldReferenceView*self){
    Manager*manager=lbl_801E9D24.manager;
    int i;
    for(i=0;i<self->handlesC.count;++i)fn_801B3E54(manager,&self->handlesC.data[i]);
    for(i=0;i<self->handles24.count;++i)fn_801B3E54(manager,&self->handles24.data[i]);
    for(i=0;i<self->handles18.count;++i)fn_801B3E54(manager,&self->handles18.data[i]);
    fn_801B3E54(manager,&self->handle30);
    fn_802667F0(self->index34);fn_802667F0(self->index4078);fn_802667F0(self->index80BC);
    for(i=0;i<self->handlesC110.count;++i)fn_801B3E54(manager,&self->handlesC110[i]);
    for(i=0;i<self->handlesC134.count;++i)fn_801B3E54(manager,&self->handlesC134.data[i]);
    for(i=0;i<self->handlesC140.count;++i)fn_801B3E54(manager,&self->handlesC140[i]);
    fn_801B3E54(manager,&self->handleC164);fn_801B3E54(manager,&self->handleC168);
    if(fn_801F7EB8(&self->handleC168))fn_80263650(((WorldReferenceGlobals*)&lbl_801E9D24)->manager14C,&self->handleC168);
    fn_8026B768(((WorldReferenceGlobals*)&lbl_801E9D24)->manager11C,WorldNotifyHandle(self->getIdentity()));
}

// Partial layout through the last handle visited by these callbacks.
typedef char CheckWorldReferenceView[sizeof(WorldReferenceView)==0xC16C?1:-1];
typedef char CheckWorldFixedHandles[sizeof(WorldFixedHandles)==0x24?1:-1];
typedef char CheckWorldRegistry[sizeof(WorldRegistry)==0x34?1:-1];
