typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[];
    extern int lbl_80378028;
    extern char lbl_8028F698[];
    void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ContainerInitHandle1:Handle_801F7F10 {
    ContainerInitHandle1(){
        value=0;
    }
    ~ContainerInitHandle1(){
    }
};
struct ContainerInitHandle2:ContainerInitHandle1 {
    ContainerInitHandle2(){
        value=0;
    }
    ~ContainerInitHandle2(){
    }
};
struct Object_8025F0D8 {
    u32 unknown[2];
    const void*vtable;
    char unknown0C[0x2C];
    u32 flags38,flags3C;
    char unknown40[8];
    Object_8025F0D8();
    ~Object_8025F0D8();
};
struct Element {
    u32 value;
    ~Element(){
    }
};
struct Pool {
    int size,capacity;
    Element*data;
    Pool(Object_8025F0D8* owner){
        owner->vtable=lbl_802EC720;
        size=0;
        capacity=0;
        data=0;
    }
    ~Pool(){
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
struct ContainerInitializationView:Object_8025F0D8 {
    Pool pool;
    int unknown54;
    ContainerInitHandle2 handle58;
    char unknown5C[4];
    ContainerInitializationView():pool(this){
        flags3C=0;
        flags38=0;
        unknown54=-1;
    }
    ~ContainerInitializationView(){
        vtable=lbl_802EC720;
    }
};
extern "C" void fn_80256448(){
    lbl_80378028=0;
    ContainerInitializationView temporary;
}
