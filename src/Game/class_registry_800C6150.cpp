#include "qsnail_agent_internal.h"
typedef void (Agent_800C61B8::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377828;
extern MemberFunction lbl_802BFE28;
void fn_8006F254();
void fn_8025E714(Agent_800C61B8*, MemberFunction);
void fn_800C6150()
{
    lbl_80377828 = 0;
    fn_8006F254();
    Agent_800C61B8 object;
    fn_8025E714(&object, lbl_802BFE28);
}
}
