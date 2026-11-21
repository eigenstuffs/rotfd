#include "Game/agent_controller_virtual_view_80062E18.h"
struct DispatchPrefix{char unknown00[8];};
struct DispatchObject:DispatchPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();};
extern "C" {void fn_8005E670(void*);void fn_8002B820(void*);void fn_802139D8(void*);signed char fn_8009FD38(void*);void fn_80069218(void*,int);}
void Agent_80062E18::method_8006311C(){fn_8005E670(&static_cast<SecondaryView_80062E18&>(*this));fn_8002B820(this);if(registered==1){static_cast<DispatchObject*>(resolve(&resource))->slot34();fn_802139D8(resolve(&resource));flags&=~0x8000ULL;if(fn_8009FD38(resolve(getControllerHandle()))==1)fn_80069218(&static_cast<SecondaryView_80062E18&>(*this),3);}}
