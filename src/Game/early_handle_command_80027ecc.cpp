#include "Game/early_handle_command_views.h"
extern "C" void fn_80027ECC(CommandTarget*self,unsigned long value,int selector){resolveCommand(*self->slot37(selector))->flags=value;}
