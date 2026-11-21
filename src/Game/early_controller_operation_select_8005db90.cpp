#include "Game/early_controller_operation_select_views.h"
extern "C" void fn_8005DB90(SelectObject*self,int value){
fn_801FA014(lbl_801E9D24.logger,lbl_8029B738);
fn_8005C128(self,value);
resolveSelect(self->controller)->bind(self);
void* selector=lbl_801E9D24.scene->selector;
int selected=-1;
if(fn_8005643C(selector,&selected))fn_8007D6A0((char*)resolveSelect(self->controller)+0x318,5);
else fn_8007D6A0((char*)resolveSelect(self->controller)+0x318,4);
self->selection=selected;
}
