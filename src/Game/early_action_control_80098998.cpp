#include "Game/early_action_control_views.h"

/* First virtual of the owning class defined in this unit; its virtual table and
 * the secondary-base destructor adjustor follow it. */
namespace ObjectLayout_80098518 {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x30C];};
struct Secondary {virtual ~Secondary();char unknown04[0x28];};
}
struct Object_80098518:ObjectLayout_80098518::Primary,ObjectLayout_80098518::Secondary {
 virtual void control_80098998();
 virtual ~Object_80098518();
};
void Object_80098518::control_80098998(){ActionActor*self=reinterpret_cast<ActionActor*>(this);fn_80099CB4(self);}
