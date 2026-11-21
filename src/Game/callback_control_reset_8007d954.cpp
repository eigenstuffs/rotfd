#include "Game/cfsm_native.h"
#include "Game/early_callback_controller_operations.h"
void CFSM::reset() {
 EarlyCallbackController*self=(EarlyCallbackController*)this;
 if(self->enabled){earlyStart(self,-1);fn_8007DB78(self);self->enabled=0;}
}
