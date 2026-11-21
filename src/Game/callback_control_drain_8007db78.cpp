#include "Game/early_callback_controller_operations.h"
extern "C" void fn_8007DB78(EarlyCallbackController*self){for(int index=0;index<self->count;++index){if(!self->activeCount)break;if(self->active&(1ULL<<(unsigned int)index))earlyStop(self,index);}}
