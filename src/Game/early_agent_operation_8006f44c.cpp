#include "Game/early_agent_operation_views.h"
extern "C" void fn_8006F44C(AgentOperation*self,void*input){fn_801FA014(lbl_801E9D24.logger,lbl_8029C7B8);fn_8002B824(self,input);self->high=lbl_803788AC*resolveAgentOperation(self->controller)->radius;self->low=lbl_803788B0*resolveAgentOperation(self->controller)->radius;resolveAgentOperation(self->controller)->actorFlags|=0x200ULL;}
