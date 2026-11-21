// Native callback control wrappers and observed 64-bit state flags.
struct CallbackCallbackVirtualControlStorage {char unknown0[8];};
struct CallbackVirtualControl:CallbackCallbackVirtualControlStorage {
 virtual void slot08 ();
 virtual void slot0C ();
 virtual void slot10 ();
 virtual void slot14 ();
 virtual void slot18 ();
 virtual void slot1C ();
 virtual void slot20 ();
 virtual void slot24 ();
 virtual void slot28 (int);
 virtual void slot2C ();
 virtual void slot30 ();
 virtual void slot34 ();
 virtual void slot38 ();
 virtual void slot3C ();
 virtual void slot40 ();
 virtual void slot44 ();
 virtual void slot48 ();
 virtual void slot4C ();
 virtual void slot50 ();
 virtual void slot54 ();
 virtual void slot58 ();
 virtual void slot5C (int);
 virtual void slot60 (int);
 virtual void slot64 ();
 virtual void slot68 ();
 virtual void slot6C ();
 virtual void slot70 ();
 virtual void slot74 ();
 virtual void slot78 ();
 virtual void slot7C ();
 virtual void slot80 ();
 char unknownC[0x2C];unsigned long long flags;
};
extern "C" void fn_80258654(void*);



extern "C" {extern char lbl_802AEC2C[],lbl_801E9D24[];void fn_8025A48C(void*);void fn_8025A3C8(void*,void*);void fn_801B52EC(void*,void*,const char*);void __dt__15Handle_801F7F10Fv(void*,int);}



extern "C" void fn_8025BB14(CallbackVirtualControl*self) {self->slot5C(0);self->slot60(0);}
extern "C" void fn_8025BB68(CallbackVirtualControl*self) {fn_80258654(self);self->slot80();}
extern "C" void fn_8025BBA8(CallbackVirtualControl*self) {
 fn_8025A48C(self);self->slot80();self->slot28(0);
 if(self->flags&4ULL) {
  unsigned long handle;
  fn_801B52EC(&handle,*(void**)(lbl_801E9D24+0x118),lbl_802AEC2C);
  fn_8025A3C8(self,&handle);__dt__15Handle_801F7F10Fv(&handle,-1);
 }
}
#include "Game/engine_callback_control_ctor.h"

CallbackControl_802ECC00::CallbackControl_802ECC00(){vtable=lbl_802ECC00;flags&=~1ULL;flags|=4ULL;}
