typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802EC6A0[];
    extern char lbl_8028F698[];
    extern int lbl_80378020;
    void fn_8028FD50(void*,void*,int);
    void fn_80256448();
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct LayerInitHandle1:Handle_801F7F10 {
    LayerInitHandle1(){
        value=0;
    }
    ~LayerInitHandle1(){
    }
};
struct LayerInitHandle2:LayerInitHandle1 {
    LayerInitHandle2(){
        value=0;
    }
    ~LayerInitHandle2(){
    }
};
struct LayerInitHandle3:LayerInitHandle2 {
    LayerInitHandle3(){
        value=0;
    }
    ~LayerInitHandle3(){
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
struct LayerInitPool {
    int size,capacity;
    Element*data;
    ~LayerInitPool(){
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
    LayerInitPool pool;
    int unknown54;
    LayerInitHandle2 handle58;
    char unknown5C[4];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC(){
        vtable=lbl_802EC720;
    }
};
struct LayerInitWord {
    u32 value;
    LayerInitWord(Object_8025F0D8*owner){
        owner->vtable=lbl_802EC6A0;
        value=0;
    }
};
struct ContainerLayerInitialization:ContainerBase_802563CC {
    LayerInitWord word60;
    LayerInitHandle3 handle64;
    u32 word68,word6C;
    ContainerLayerInitialization():word60(this){
        flags|=0x800ULL;
        word6C=0;
        word68=0;
    }
    ~ContainerLayerInitialization(){
        vtable=lbl_802EC6A0;
    }
};
extern "C" void fn_802558B8(){
    lbl_80378020=0;
    fn_80256448();
    ContainerLayerInitialization temporary;
}
