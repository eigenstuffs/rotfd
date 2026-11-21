#include "Game/engine_hierarchy_handle_append.h"

extern "C" HierarchyCreatedHandle fn_80260868(HierarchyCreateOwner*self,const HierarchyCreateName&name,const char*instance){
 HierarchyCreateName required(lbl_802AECDC);
 if(required.value!=name.value&&!fn_801B5230(lbl_801E9D24.manager,name,required))return HierarchyCreatedHandle();
 HierarchyCreatedHandle result;
 if(!instance)result=HierarchyCreatedHandle(fn_801B5408(lbl_801E9D24.manager,name));
 else result=HierarchyCreatedHandle(fn_801B550C(lbl_801E9D24.manager,name,HierarchyCreateName(instance)));
 if(!fn_801F7EB8(&result))return HierarchyCreatedHandle();
 fn_802072D4(resolve(result),name,0);
 self->children.append(result);
 return result;
}
