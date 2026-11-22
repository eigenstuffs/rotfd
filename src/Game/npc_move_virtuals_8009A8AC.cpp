/* Part of the original CNPCMove source: the destructor and the virtual
 * members, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class (key function: the destructor).  The class
 * hierarchy comes from the original RTTI base lists; see
 * include/Game/move_classes.h. */
#include "Game/move_classes.h"
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}

CNPCMove::~CNPCMove() {}

#include "Game/motion_forwarding.h"

extern "C" void slot18__8CNPCMoveFv(ForwardActor* self){slot18__10CActorMoveFv(self);}

extern "C" void slot34__8CNPCMoveFv(ForwardActor* self){slot34__10CActorMoveFv(self);fn_8007DCDC(self->component);}

extern "C" void slot38__8CNPCMoveFf(ForwardActor* self,float delta){slot38__10CActorMoveFf(self,delta);}

extern "C" void slot40__8CNPCMoveFPC4Vec3PC4Vec3PC4Vec3if(ForwardActor* self){slot40__10CActorMoveFPC4Vec3PC4Vec3PC4Vec3if();}

void CNPCMove::configureCallbacks(){}

/* Object of this unit ahead of the compiler RTTI data. */
extern "C" const float lbl_80378D48 = 0.0f;
