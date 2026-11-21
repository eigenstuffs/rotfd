#include "Game/cfsm_native.h"
extern "C" void fn_8007DCDC(CFSM*);
void CFSM::configure(int value) {
 count=value;reset();enabled=1;current=-1;pending=-1;changing=0;fn_8007DCDC(this);
}
