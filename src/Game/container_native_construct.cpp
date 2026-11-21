typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[];
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ContainerConstructHandle1:Handle_801F7F10 {
    ContainerConstructHandle1(){
        value=0;
    }
    ~ContainerConstructHandle1(){
    }
};
struct ContainerConstructHandle2:ContainerConstructHandle1 {
    ContainerConstructHandle2(){
        value=0;
    }
    ~ContainerConstructHandle2(){
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
struct Pool {
    int size,capacity;
    void*data;
    Pool(Object_8025F0D8* owner){
        owner->vtable=lbl_802EC720;
        size=0;
        capacity=0;
        data=0;
    }
};
struct ContainerBase_802563CC:Object_8025F0D8 {
    Pool pool;
    int unknown54;
    ContainerConstructHandle2 handle58;
    char unknown5C[8];
    ContainerBase_802563CC();
};
ContainerBase_802563CC::ContainerBase_802563CC():pool(this){
    flags3C=0;
    flags38=0;
    unknown54=-1;
}
