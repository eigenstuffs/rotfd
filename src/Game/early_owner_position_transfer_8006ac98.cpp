#include "Game/early_owner_position_transfer_views.h"
extern "C" void fn_8006AC98(TransferObject*self){
TransferVector position;position=resolveTransfer(*self->getHandle())->saved;
fn_8023D100(resolveTransfer(self->getResource()->owner),&position);
fn_80069CA8(self,resolveTransfer(self->getResource()->owner),1);
fn_8023DE28(resolveTransfer(self->getResource()->owner));
if(self->pending)fn_80067808(self);
}
