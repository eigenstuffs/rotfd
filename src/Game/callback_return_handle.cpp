// Partial handle views; native value-return and lifetime behavior.
struct ReturnHandleWord{
    unsigned long word;
    ReturnHandleWord();
    ~ReturnHandleWord();
};
extern "C" {
    extern struct {
        char unknown0[0x118];
        void*manager;
        char unknown11C[0x28];
        void*records;
    }
    lbl_801E9D24;
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    ReturnHandleWord fn_801F5C04(void*,int,int);
}
inline ReturnHandleWord::ReturnHandleWord(){
    __ct__15Handle_801F7F10Fv(this);
}
inline ReturnHandleWord::~ReturnHandleWord(){
    __dt__15Handle_801F7F10Fv(this,-1);
}
struct ReturnHandleNative {
    unsigned long word;
    ReturnHandleNative(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~ReturnHandleNative(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct ReturnHandleLayer:ReturnHandleNative {
    ReturnHandleLayer(){
        word=0;
    }
};
struct ReturnHandleCopy:ReturnHandleLayer {
    ReturnHandleCopy(const ReturnHandleWord&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct ReturnHandleResult:ReturnHandleLayer {
    ReturnHandleResult(){
        word=0;
    }
    ReturnHandleResult(const ReturnHandleCopy&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct ReturnHandleOwner{
    char unknown0[0x68];
    int index;
};
extern "C" ReturnHandleResult fn_80257B70(ReturnHandleOwner*self,int value){
    if(self->index<0)return ReturnHandleResult();
    ReturnHandleCopy typed(fn_801F5C04(lbl_801E9D24.records,self->index,value));
    return ReturnHandleResult(typed);
}
