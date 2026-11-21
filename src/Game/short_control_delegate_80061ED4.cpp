#include "Game/agent_owner_virtual_view_80061AC0.h"
/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Part;struct Control{char opaque00[0x60];};extern "C"{void fn_8005E670(Part*);void fn_80256370(Control*);}void Agent_80061AC0::method_80061ED4(){Control*self=reinterpret_cast<Control*>(this);fn_8005E670((Part*)((char*)self+0x60));fn_80256370(self);}
