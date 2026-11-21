#include "Game/callback_handle_transfers_internal.h"
extern "C" void fn_80259164(CallbackTransferOwner*self) {
 fn_8025BB68(self);
 self->flags&=~0x8000ULL;
 resolveRelated(self->handle80)->slot34();
 fn_802139D8(resolveRelated(self->handle80));
}
