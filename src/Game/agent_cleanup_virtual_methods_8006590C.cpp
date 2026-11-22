#include "Game/early_handle_bind_views.h"
#ifndef GAME_OWNER_STATE_QUERY_VIEWS_H
#define GAME_OWNER_STATE_QUERY_VIEWS_H

struct StateHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct StateEntry {
    char* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct StateManager {
    int count, capacity;
    StateEntry* entries;
};

struct StateContext {
    char unknown00[0x118];
    StateManager* manager;
};

extern "C" {

void fn_80063290(void*, int);
unsigned long fn_8009F170(void*);
}

inline char* resolveState(const StateHandle& handle)
{
    StateEntry* entry = reinterpret_cast<StateEntry*>(&lbl_801E9D24.manager->entries[handle.bits.index]);
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct StateFlags {
    char unknown00[0x30];
    unsigned long long flags;
};

struct StateOwner {
    char unknown00[0x70];
    StateHandle handle;
};



struct StateQueryPrefix {
    int unknown00;
};

struct StateQuery : StateQueryPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual const StateHandle* getHandle();
};

#endif

#include "Game/agent_cleanup_virtual_view_8006590C.h"
extern "C" {
 extern void*lbl_80377720;
 void method_80063074__14Agent_80062E18Fv(void*);void method_8006311C__14Agent_80062E18Fv(void*);void fn_80063290(void*,int);
 void fn_80063F98(void*,const OpaqueHandle&);void fn_80063FB8(void*);
 void fn_8025ED38(void*,void*,void*);void fn_800642A8(void*,void*);
 int fn_8025E70C(void*,void*,void*);int fn_8006434C(void*,void*);
}
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B6D40[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_80062E18Fv(void*,int);
}
struct CleanupFields_8006590C {
    char unknown00[8];
    void*vtable;
    char unknown0C[136];
    void*secondary;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
inline void*cleanup_impl_8006590C(CleanupFields_8006590C*self,int flag) {
    if(self) {
        self->vtable=lbl_802B6D40;
        self->secondary=lbl_802B6D40+180;
        __dt__14Agent_80062E18Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

void*ObjectCleanupVirtualView_8006590C::cleanup(int flag){return cleanup_impl_8006590C(reinterpret_cast<CleanupFields_8006590C*>(this),flag);}
void ObjectCleanupVirtualView_8006590C::method_80063074(){BindObject*self=reinterpret_cast<BindObject*>(this);method_80063074__14Agent_80062E18Fv(self);self->bind(fn_801B52EC(lbl_801E9D24.manager,lbl_8029BDE0));}
void ObjectCleanupVirtualView_8006590C::method_8006311C(){method_8006311C__14Agent_80062E18Fv(this);}
void ObjectCleanupVirtualView_8006590C::slot_040(int argument){StateOwner*self=reinterpret_cast<StateOwner*>(this);((StateFlags*)resolveState(self->handle))->flags|=0x400ULL;((StateFlags*)resolveState(self->handle))->flags|=0x1000000000ULL;fn_80063290(this,argument);}
void ObjectCleanupVirtualView_8006590C::slot_044(const OpaqueHandle&value){fn_80063F98(this,value);}
void ObjectCleanupVirtualView_8006590C::slot_0B0(){fn_80063FB8(this);}
unsigned long ObjectCleanupVirtualView_8006590C::slot_020(){return reinterpret_cast<unsigned long>(lbl_80377720);}
void ObjectCleanupVirtualView_8006590C::slot_024(unsigned long value){lbl_80377720=reinterpret_cast<void*>(value);}
void ObjectCleanupVirtualView_8006590C::slot_028(void*value){fn_8025ED38(this,value,lbl_80377720);fn_800642A8(this,value);}
int ObjectCleanupVirtualView_8006590C::slot_02C(void*value){int result=fn_8025E70C(this,value,lbl_80377720);if(result!=-1)return result;return fn_8006434C(this,value);}
