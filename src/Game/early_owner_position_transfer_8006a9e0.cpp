#include "Game/early_owner_position_transfer_views.h"
extern "C" void fn_8006A9E0(TransferObject*self,TransferResource*other){
TransferVector position(other->transform->position.x,other->transform->position.y,other->transform->position.z);
position.z=resolveTransfer(self->getResource()->owner)->transform->position.z;
fn_8023D100(resolveTransfer(self->getResource()->owner),&position);
fn_8023DE28(resolveTransfer(self->getResource()->owner));
}
