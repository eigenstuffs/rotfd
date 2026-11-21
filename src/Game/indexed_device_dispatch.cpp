typedef unsigned long u32;
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct DevicePad {
    char unknown00[0x7C];
};
struct Device:DevicePad {
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54(Handle_801F7F10*,int,int,Handle_801F7F10*);
    virtual void s58(Handle_801F7F10*,int,float);
};
extern "C" {
    extern struct {
        char unknown00[0x118];
        void*manager;
    }
    lbl_801E9D24;
    Handle_801F7F10 fn_801F5C04(Device*,int);
    void fn_801F86C8(void*,const void*,int);
    extern const float lbl_8037B314;
}
struct DeviceZeroHandle:Handle_801F7F10 {
    DeviceZeroHandle(){
        value=0;
    }
};
struct DeviceCopyHandle:DeviceZeroHandle {
    DeviceCopyHandle(const Handle_801F7F10&source){
        value=source.value;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
    ~DeviceCopyHandle(){
    }
};
extern "C" void fn_8023B35C(Device*self,int value,int index){
    if(index>=0){
        DeviceCopyHandle copy(fn_801F5C04(self,index));
        self->s58(&copy,value,lbl_8037B314);
    }
}
