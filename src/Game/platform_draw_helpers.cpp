#include "Game/platform_draw_internal.h"
extern "C" void fn_80283064(PlatformDrawOwner*self,PlatformDrawOutput*out,void*context){
 unsigned long buffer[4096] __attribute__((aligned(32)));
 out->valueBDC=self->value7C;out->valueBD8=self->value94;
 fn_800F22F4(buffer,self->count74*4);
 self->draw(out,context,self->stateBC,buffer);
 GXDrawDone();
}
void PlatformIndexBlock_8028310C::reset(){flag00=0;}
void PlatformIndexBlock_8028310C::hook(){}
PlatformIndexBlock_8028310C::~PlatformIndexBlock_8028310C(){}
