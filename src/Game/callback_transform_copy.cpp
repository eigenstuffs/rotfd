#include "Game/callback_handle_transfers_internal.h"
struct CallbackTransformMatrix16 {float data[16];};
struct CallbackTransformMatrix9 {float data[9];};
struct CallbackTransformVector3 {float x,y,z;};
struct CallbackTransformQuaternion {float x,y,z,w;};
struct CallbackTransformSource {
    char unknown0[0x30];CallbackTransformMatrix9 basis30;char unknown54[0xD0];CallbackTransformMatrix16*matrix124;
};
struct CallbackTransformOwner {char unknown0[0x68];CallbackTransformSource*primary;CallbackTransformSource*secondary;};
extern "C" {
    void fn_801F2788(CallbackTransformMatrix16*,const CallbackTransformMatrix16*);
    void fn_801F223C(CallbackTransformMatrix9*,const CallbackTransformMatrix9*);
    void fn_801F20F4(CallbackTransformQuaternion*,const CallbackTransformMatrix9*);
    void fn_8023D120(void*,const void*,const void*);
    void fn_8023DE28(void*);
}
extern "C" void fn_80254C74(CallbackTransferOwner*self){
    CallbackTransformSource*primary=((CallbackTransformOwner*)self)->primary;
    if(primary){
        CallbackTransformSource*secondary=((CallbackTransformOwner*)self)->secondary;
        CallbackTransformMatrix9 basis;
        CallbackTransformMatrix16 matrix=*primary->matrix124;
        basis=primary->basis30;
        if(secondary){fn_801F2788(&matrix,secondary->matrix124);fn_801F223C(&basis,&secondary->basis30);}
        CallbackTransformQuaternion rotation;
        CallbackTransformVector3 vector;
        vector.x=matrix.data[12];vector.y=matrix.data[13];vector.z=matrix.data[14];
        fn_801F20F4(&rotation,&basis);
        fn_8023D120(resolveRelated(self->handle58),&vector,&rotation);
        fn_8023DE28(resolveRelated(self->handle58));
    }
}
