#include "Game/callback_related_dispatch_internal.h"
struct CallbackLookupOwn;
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void*fn_801F948C(void*,const char*);
    void fn_801C8E00(void*,const char*,const CallbackLookupOwn&);
    extern char lbl_802AEB50[];
}
struct CallbackLookupName {
    void*value;
    CallbackLookupName(const char*name){
        value=fn_801F948C(this,name);
    }
};
struct CallbackLookupRaw {
    unsigned long word;
    CallbackLookupRaw(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~CallbackLookupRaw(){
        __dt__15Handle_801F7F10Fv(this,-1);
    }
};
extern "C" CallbackLookupRaw fn_801B550C(void*,const CallbackLookupName&,const CallbackLookupName&);
struct CallbackLookupNative {
    unsigned long word;
    CallbackLookupNative(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~CallbackLookupNative(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct CallbackLookupZero:CallbackLookupNative {
    CallbackLookupZero(){
        word=0;
    }
};
struct CallbackLookupZero2:CallbackLookupZero {
    CallbackLookupZero2(){
        word=0;
    }
};
struct CallbackLookupCopy:CallbackLookupZero2 {
    CallbackLookupCopy(const CallbackLookupRaw&raw){
        word=raw.word;
        fn_801F86C8(lbl_801E9D24.manager,&raw,1);
    }
};
struct CallbackLookupOwn:CallbackLookupZero {
    CallbackLookupOwn(const CallbackRelatedHandle&raw){
        word=*(const unsigned long*)&raw;
        fn_801F86C8(lbl_801E9D24.manager,&raw,1);
    }
};
struct CallbackLookupOwner {
    char unknown0[4];
    CallbackRelatedHandle handle4;
    char unknown8[0x40];
    CallbackRelatedHandle handle48;
};
struct CallbackLookupVirtualStorage {
    char unknown0[8];
};
struct CallbackLookupVirtual:CallbackLookupVirtualStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28(int);
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
};
inline void assignLookupTarget(CallbackRelatedHandle&target,const CallbackLookupCopy&source){
    fn_801F86C8(lbl_801E9D24.manager,&target,-1);
    *(unsigned long*)&target=source.word;
    fn_801F86C8(lbl_801E9D24.manager,&source,1);
}
extern "C" void fn_8025361C(CallbackLookupOwner*self,const char*name){
    assignLookupTarget(self->handle48,CallbackLookupCopy(fn_801B550C(lbl_801E9D24.manager,CallbackLookupName(lbl_802AEB50),CallbackLookupName(name))));
    const CallbackRelatedHandle&own=self->handle4;
    fn_801C8E00(resolveRelated(self->handle48),name,CallbackLookupOwn(own));
    ((CallbackLookupVirtual*)self)->slot50();
    ((CallbackLookupVirtual*)self)->slot28(4);
}
