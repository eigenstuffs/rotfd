/* Part of the original MediumAgent.cpp source: the CMediumAgent destructor and virtual
 * members, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class (key function: the destructor).  The class
 * hierarchy comes from the original RTTI base lists; see
 * include/Game/agent_classes.h. */
#include "Game/agent_classes.h"
#include "Game/early_handle_bind_views.h"
extern "C" {
    extern void* lbl_80377718;
    void fn_8025ED38(void*, void*, void*);
    int fn_8025E70C(void*, void*, void*);
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*, void*);
}
inline void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }

CMediumAgent::~CMediumAgent() {}
void CMediumAgent::slot18(){BindObject*self=reinterpret_cast<BindObject*>(this);CActorScriptAgent::slot18();self->bind(fn_801B52EC(lbl_801E9D24.manager,"CMediumMove"));}
void CMediumAgent::script10(){CActorScriptAgent::script10();}
void CMediumAgent::slot40(int argument){CActorScriptAgent::slot40(argument);}
void CMediumAgent::slot44(const OpaqueHandle&value){CActorScriptAgent::slot44(value);}
void CMediumAgent::slotB0(){CActorScriptAgent::slotB0();}
unsigned long CMediumAgent::slot20(){return reinterpret_cast<unsigned long>(lbl_80377718);}
void CMediumAgent::slot24(unsigned long value){lbl_80377718=reinterpret_cast<void*>(value);}
void CMediumAgent::slot28(void*value){fn_8025ED38(this,value,lbl_80377718);CActorScriptAgent::slot28(value);}
int CMediumAgent::slot2C(void*value){int result=fn_8025E70C(this,value,lbl_80377718);if(result!=-1)return result;return CActorScriptAgent::slot2C(value);}
