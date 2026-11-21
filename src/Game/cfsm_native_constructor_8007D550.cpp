#include "Game/cfsm_native.h"
CFSM::CFSM() {
 enabled=0;changing=0;current=0;previous=-1;pending=0;
 active=0;activeCount=0;count=0;callbacks=0;
}
