#include "Game/callback_handle_transfers_internal.h"
struct OwnerLinkNative {
    unsigned long word;
    OwnerLinkNative();
    ~OwnerLinkNative();
};
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void fn_8025A0A4(CallbackTransferOwner*,const CallbackRelatedHandle&);
}
inline OwnerLinkNative::OwnerLinkNative(){
    __ct__15Handle_801F7F10Fv(this);
}
inline OwnerLinkNative::~OwnerLinkNative(){
    __dt__15Handle_801F7F10Fv(this,0);
}
struct OwnerLinkRaw:OwnerLinkNative {
    OwnerLinkRaw(const CallbackRelatedHandle&source){
        word=*(const unsigned long*)&source;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
};
struct OwnerLinkZero:OwnerLinkNative {
    OwnerLinkZero(){
        word=0;
    }
};
struct OwnerLinkTyped:OwnerLinkZero {
    OwnerLinkTyped(const OwnerLinkRaw&source){
        word=source.word;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
};
struct OwnerLinkTarget {
    char unknown0[0x24];
    unsigned long handle24;
};
struct OwnerLinkOwner {
    char unknown0[4];
    CallbackRelatedHandle handle4;
};
inline void assignOwnerLink(unsigned long&target,const OwnerLinkTyped&source){
    fn_801F86C8(lbl_801E9D24.manager,&target,-1);
    target=source.word;
    fn_801F86C8(lbl_801E9D24.manager,&source,1);
}
extern "C" void fn_80259008(CallbackTransferOwner*self,const CallbackRelatedHandle&incoming){
    fn_802001D4(resolveRelated(incoming),&self->handle80,4);
    {
        const CallbackRelatedHandle&own=((OwnerLinkOwner*)self)->handle4;
        OwnerLinkRaw copy(own);
        OwnerLinkTarget*target=(OwnerLinkTarget*)resolveRelated(self->handle80);
        OwnerLinkTyped temp(copy);
        assignOwnerLink(target->handle24,temp);
    }
    fn_8025A0A4(self,incoming);
}
