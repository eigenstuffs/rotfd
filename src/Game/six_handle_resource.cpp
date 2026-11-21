#include "six_handle_resource_internal.h"
extern "C" {
void fn_801B3E54(Manager*,void*);
void fn_801B41B8(Manager*,void*,u32*);
u32 fn_801E9F40(void*,u32,int);
}
SixHandleResource_802EA840::~SixHandleResource_802EA840(){}
void SixHandleResource_802EA840::slot20(){}
void SixHandleResource_802EA840::slot10(){
    for(int i=0;i<6;++i)fn_801B3E54(lbl_801E9D24.manager,&handles[i]);
}
void SixHandleResource_802EA840::slot0C(u32 stream){
    BaseObject_Z::slot0C(stream);
    *(u32*)stream=fn_801E9F40(&field0C,*(u32*)stream,4);
    for(int i=0;i<6;++i)fn_801B41B8(lbl_801E9D24.manager,&handles[i],(u32*)stream);
    *(u32*)stream=fn_801E9F40(data28,*(u32*)stream,0x60);
}
