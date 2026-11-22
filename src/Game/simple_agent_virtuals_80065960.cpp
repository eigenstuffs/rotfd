/* Part of the original SimpleAgent.cpp source: the CSimpleAgent destructor and virtual
 * members, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class (key function: the destructor).  The class
 * hierarchy comes from the original RTTI base lists; see
 * include/Game/agent_classes.h. */
#include "Game/agent_classes.h"
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

void slot40__17CActorScriptAgentFi(void*, int);
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
extern "C" {
    extern void* lbl_80377720;
    void fn_8025ED38(void*, void*, void*);
    int fn_8025E70C(void*, void*, void*);
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*, void*);
}
inline void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }

CSimpleAgent::~CSimpleAgent() {}
void CSimpleAgent::slot18(){BindObject*self=reinterpret_cast<BindObject*>(this);CActorScriptAgent::slot18();self->bind(fn_801B52EC(lbl_801E9D24.manager,"CSimpleMove"));}
void CSimpleAgent::script10(){CActorScriptAgent::script10();}
void CSimpleAgent::slot40(int argument){StateOwner*self=reinterpret_cast<StateOwner*>(this);((StateFlags*)resolveState(self->handle))->flags|=0x400ULL;((StateFlags*)resolveState(self->handle))->flags|=0x1000000000ULL;CActorScriptAgent::slot40(argument);}
void CSimpleAgent::slot44(const OpaqueHandle&value){CActorScriptAgent::slot44(value);}
void CSimpleAgent::slotB0(){CActorScriptAgent::slotB0();}
unsigned long CSimpleAgent::slot20(){return reinterpret_cast<unsigned long>(lbl_80377720);}
void CSimpleAgent::slot24(unsigned long value){lbl_80377720=reinterpret_cast<void*>(value);}
void CSimpleAgent::slot28(void*value){fn_8025ED38(this,value,lbl_80377720);CActorScriptAgent::slot28(value);}
int CSimpleAgent::slot2C(void*value){int result=fn_8025E70C(this,value,lbl_80377720);if(result!=-1)return result;return CActorScriptAgent::slot2C(value);}
