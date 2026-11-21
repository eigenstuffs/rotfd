#include "Game/callback_related_dispatch_internal.h"
struct RelatedRemoveNative {
    unsigned long word;
    RelatedRemoveNative();
    ~RelatedRemoveNative();
};
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    const CallbackRelatedHandle*fn_8023A5DC(void*,const CallbackRelatedHandle*);
}
inline RelatedRemoveNative::RelatedRemoveNative(){
    __ct__15Handle_801F7F10Fv(this);
}
inline RelatedRemoveNative::~RelatedRemoveNative(){
    __dt__15Handle_801F7F10Fv(this,0);
}
struct RelatedRemoveZero:RelatedRemoveNative {
    RelatedRemoveZero(){
        word=0;
    }
};
struct RelatedRemoveCopy:RelatedRemoveZero {
    RelatedRemoveCopy(const CallbackRelatedHandle&source){
        word=*(const unsigned long*)&source;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
};
struct RelatedRemoveOwner {
    char unknown0[0x188];
    CallbackRelatedHandle handle188;
};
struct RelatedRemoveContext {
    char unknown0[0x118];
    void*manager;
    char unknown11C[4];
    void*resources;
};
extern "C" signed char fn_802529E8(RelatedRemoveOwner*self){
    if(!slot1C__12BaseObject_ZFv(self))return 0;
    if(fn_801F7EB8(&self->handle188)){
        RelatedRemoveCopy copy(*fn_8023A5DC(((RelatedRemoveContext*)&lbl_801E9D24)->resources,&self->handle188));
        resolveRelated(self->handle188)->slot1C();
        if(fn_801F7EB8((const CallbackRelatedHandle*)&copy))resolveRelated(*(const CallbackRelatedHandle*)&copy)->slot1C();
    }
    return 1;
}
