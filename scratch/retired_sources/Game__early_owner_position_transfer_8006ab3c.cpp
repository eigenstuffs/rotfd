#include "Game/early_owner_position_transfer_views.h"
extern "C" void fn_8006AB3C(TransferObject*self,TransferResource*other){
TransferVector position(other->transform->position.x,other->transform->position.y,other->transform->position.z);
position.x=resolveTransfer(self->getResource()->owner)->transform->position.x;
fn_8023D100(resolveTransfer(self->getResource()->owner),&position);
fn_8023DE28(resolveTransfer(self->getResource()->owner));
}
