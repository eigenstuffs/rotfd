// QSnail base callbacks; observed resource state begins at offset 0x318.
#include "qsnail_agent_internal.h"
extern "C" {
void fn_8006F44C(Agent_800C61B8*);
void fn_800CC7D0(void*,Agent_800C61B8*);
void fn_8007D6A0(void*,int);
void fn_800C63D0() {}
void fn_800C63D4(Agent_800C61B8 *object) {
 fn_8006F44C(object);
 fn_800CC7D0((void*)object->fields.fieldA0,object);
 fn_8007D6A0((char*)object->fields.fieldA0+0x318,0);
}
}
