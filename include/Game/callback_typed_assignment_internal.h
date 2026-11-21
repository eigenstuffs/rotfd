#ifndef GAME_CALLBACK_TYPED_ASSIGNMENT_INTERNAL_H
#define GAME_CALLBACK_TYPED_ASSIGNMENT_INTERNAL_H
// Observed handle layers and partial callback interfaces.
struct CallbackHandleWord {
    unsigned long word;
};
extern "C" {
    extern struct {
        char unknown0[0x118];
        void*manager;
    }
    lbl_801E9D24;
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void fn_801B52EC(void*,void*,const char*);
    void fn_8025885C(void*);
    extern char lbl_802AEB70[],lbl_802AEBD8[],lbl_802AEC38[];
}
struct CallbackHandleNative {
    unsigned long word;
    CallbackHandleNative(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~CallbackHandleNative(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct CallbackHandleLayer1:CallbackHandleNative {
    CallbackHandleLayer1(){
        word=0;
    }
};
struct CallbackHandleLayer2:CallbackHandleLayer1 {
    CallbackHandleLayer2(){
        word=0;
    }
};
struct CallbackHandleCopy:CallbackHandleLayer2 {
    CallbackHandleCopy(const CallbackHandleWord&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct CallbackAssignmentOwner {
    char unknown0[0x38];
    unsigned long long flags;
    char unknown40[0x24];
    CallbackHandleWord handle64;
    char unknown68[8];
    CallbackHandleWord handle70;
};
inline void assignHandle(CallbackHandleWord&target,const CallbackHandleCopy&value){
    fn_801F86C8(lbl_801E9D24.manager,&target,-1);
    target.word=value.word;
    fn_801F86C8(lbl_801E9D24.manager,&value,1);
}
struct CallbackAssignmentVirtualStorage {
    char unknown0[8];
};
struct CallbackAssignmentVirtual:CallbackAssignmentVirtualStorage{
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28(int);
    char unknownC[0x2C];
    unsigned long long flags;
    char unknown40[0x20];
    CallbackHandleWord handle60;
};
#endif
