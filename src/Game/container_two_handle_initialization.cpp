typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802EC798[],lbl_802ED000[];
    extern char lbl_8028F698[];
    extern int lbl_80378030;
    void fn_8028FD50(void*,void*,int);
    void fn_8025E5FC();
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct TwoInitHandle1:Handle_801F7F10 {
    TwoInitHandle1(){
        value=0;
    }
    TwoInitHandle1(int){
        value=0;
    }
    ~TwoInitHandle1(){
    }
};
struct Object_8025F0D8;
inline int installTable(Object_8025F0D8*);
struct TwoInitHandle2:TwoInitHandle1 {
    TwoInitHandle2(){
        value=0;
    }
    TwoInitHandle2(Object_8025F0D8*owner):TwoInitHandle1(installTable(owner)){
        value=0;
    }
    ~TwoInitHandle2(){
    }
};
struct TwoInitHandle3:TwoInitHandle2 {
    TwoInitHandle3(){
        value=0;
    }
    ~TwoInitHandle3(){
    }
};
struct Object_8025F0D8 {
    u32 unknown[2];
    const void*vtable;
    char unknown0C[0x2C];
    unsigned long long flags;
    char unknown40[8];
    ~Object_8025F0D8();
};
struct Element {
    u32 value;
    ~Element(){
    }
};
struct TwoInitPool {
    int size,capacity;
    Element*data;
    ~TwoInitPool(){
        if(data){
            for(int i=0;
            i<size;
            i++)data[i].~Element();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
struct ContainerBase_802563CC:Object_8025F0D8 {
    TwoInitPool pool;
    int unknown54;
    TwoInitHandle2 handle58;
    char unknown5C[4];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC(){
        vtable=lbl_802EC720;
    }
};
inline int installTable(Object_8025F0D8*owner){
    owner->vtable=lbl_802EC798;
    return 0;
}
struct InitializationResource:ContainerBase_802563CC {
    InitializationResource(){
        vtable=lbl_802ED000;
    }
    ~InitializationResource(){
        vtable=lbl_802ED000;
    }
};
struct InitializationHandleLayer:InitializationResource {
    TwoInitHandle2 handle60;
    TwoInitHandle3 handle64;
    int index68;
    InitializationHandleLayer():handle60(this){
        flags|=0x4280ULL;
        index68=-1;
    }
    ~InitializationHandleLayer(){
        vtable=lbl_802EC798;
    }
};
extern "C" void fn_80258948(){
    lbl_80378030=0;
    fn_8025E5FC();
    InitializationHandleLayer temporary;
}
