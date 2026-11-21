#include "Game/early_action_control_views.h"

/* First virtual of the owning class defined in this unit; its virtual table and
 * the secondary-base destructor adjustor follow it. */
namespace ObjectLayout_8009798C {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x30C];};
struct Secondary {virtual ~Secondary();char unknown04[0x28];};
}
struct Object_8009798C:ObjectLayout_8009798C::Primary,ObjectLayout_8009798C::Secondary {
 virtual void control_80098020();
 virtual ~Object_8009798C();
};
void Object_8009798C::control_80098020(){ActionActor*self=reinterpret_cast<ActionActor*>(this);fn_80098CD0(self);}
