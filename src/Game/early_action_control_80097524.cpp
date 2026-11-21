#include "Game/early_action_control_views.h"

/* First virtual of the owning class defined in this unit; its virtual table and
 * the secondary-base destructor adjustor follow it. */
namespace ObjectLayout_8009731C {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual ~Primary();char unknown0C[0x30C];};
struct Secondary {virtual ~Secondary();char unknown04[0x28];};
}
struct Object_8009731C:ObjectLayout_8009731C::Primary,ObjectLayout_8009731C::Secondary {
 virtual void control_80097524(int unused,void*value);
 virtual ~Object_8009731C();
};
void Object_8009731C::control_80097524(int unused,void*value){ActionActor*self=reinterpret_cast<ActionActor*>(this);self->slot45(value,0);}
