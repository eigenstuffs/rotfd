#include "Game/early_owner_operation_control_views.h"
extern "C" void fn_8006A874(OperationObject*self,OperationResource*other){
OperationResource*owner=resolveOperation(self->getResource()->owner);
OperationVector position(other->transform->position.x,other->transform->position.y,other->transform->position.z);

fn_8023D100(owner,&position);
fn_8023DE28(owner);
}
