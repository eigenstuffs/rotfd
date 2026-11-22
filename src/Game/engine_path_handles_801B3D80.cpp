typedef unsigned int u32;
struct Handle_801B3D80 {
    signed int generation:8;
    signed int index:24;
};
struct Key_801B3D80 {
    u32 value;
    Key_801B3D80(const Key_801B3D80&v):value(v.value) {
    }
};
struct HandleArray_801B3D80 {
    int count,capacity;
    Handle_801B3D80*data;
};
extern "C" {
    void*fn_801F7EB8(const Handle_801B3D80*);
    void fn_801F86C8(void*,Handle_801B3D80*,int);
}
extern "C" void fn_801B3D80(void*manager,Handle_801B3D80*output,HandleArray_801B3D80*array) {
    signed char found=0;
    Key_801B3D80 key=*(Key_801B3D80*)output;
    for(int i=0; i<array->count; ++i) {
        void*object=fn_801F7EB8(&array->data[i]);
        if(object&&*(u32*)object==key.value) {
            output->index=array->data[i].index;
            output->generation=array->data[i].generation;
            fn_801F86C8(manager,output,1);
            found=1;
            break;
        }
    }
    if(!found)output->index=0;
}
