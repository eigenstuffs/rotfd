struct CallbackRelatedHandle {
    signed int generation:8;
    signed int index:24;
};
struct DescriptorFactoryEntry {
    void*object;
    char unknown4[8];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct DescriptorFactoryManager {
    char unknown0[8];
    DescriptorFactoryEntry*entries;
};
extern "C" {
    extern struct {
        char unknown0[0x118];
        DescriptorFactoryManager*manager;
        char unknown11C[0x50];
        void*records;
    }
    lbl_801E9D24;
}
inline void*resolveRelated(const CallbackRelatedHandle&h){
    int index=h.index;
    DescriptorFactoryManager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==h.generation?m->entries[index].object:0;
}
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void*fn_801F948C(void*,const char*);
    void fn_80252DE0(void*,const int*);
    void fn_80252E1C(void*,void*,short);
    extern char lbl_802AEB08[];
}
struct DescriptorFactoryName {
    void*value;
    DescriptorFactoryName(const char*name){
        value=fn_801F948C(this,name);
    }
};
struct DescriptorFactoryInput {
    DescriptorFactoryName name;
    char unknown4[0xC];
    float values10[4];
};
struct DescriptorFactoryRaw {
    unsigned long word;
    DescriptorFactoryRaw(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~DescriptorFactoryRaw(){
        __dt__15Handle_801F7F10Fv(this,-1);
    }
};
extern "C" DescriptorFactoryRaw fn_801B550C(void*,const DescriptorFactoryName&,const DescriptorFactoryName&);
struct DescriptorFactoryNative {
    unsigned long word;
    DescriptorFactoryNative(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~DescriptorFactoryNative(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct DescriptorFactoryZero:DescriptorFactoryNative {
    DescriptorFactoryZero(){
        word=0;
    }
};
struct DescriptorFactoryCopy:DescriptorFactoryZero {
    DescriptorFactoryCopy(const DescriptorFactoryRaw&source){
        word=source.word;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
};
struct DescriptorFactoryTarget {
    char unknown0[0x10];
    float values10[4];
    int index20;
    char unknown24[0xC];
    short key30;
};
struct DescriptorFactoryParent {
    char unknown0[0x74];
    short key74;
};
inline void assignDescriptorHandle(CallbackRelatedHandle&target,const DescriptorFactoryCopy&source){
    fn_801F86C8(lbl_801E9D24.manager,&target,-1);
    *(unsigned long*)&target=source.word;
    fn_801F86C8(lbl_801E9D24.manager,&source,1);
}
inline void updateDescriptorIndex(DescriptorFactoryTarget*object){
    if(lbl_801E9D24.records){
        if(object->index20!=-1){
            int old=object->index20;
            fn_80252DE0(lbl_801E9D24.records,&old);
        }
        int result;
        fn_80252E1C(&result,lbl_801E9D24.records,object->key30);
        object->index20=result;
    }
    else object->index20=-1;
}
extern "C" void fn_8025222C(const DescriptorFactoryInput*input,CallbackRelatedHandle&result,const CallbackRelatedHandle&parent){
    assignDescriptorHandle(result,DescriptorFactoryCopy(fn_801B550C(lbl_801E9D24.manager,DescriptorFactoryName(lbl_802AEB08),input->name)));
    DescriptorFactoryTarget*object=(DescriptorFactoryTarget*)resolveRelated(result);
    object->values10[0]=input->values10[0];
    object->values10[1]=input->values10[1];
    object->values10[2]=input->values10[2];
    object->values10[3]=input->values10[3];
    object=(DescriptorFactoryTarget*)resolveRelated(result);
    object->key30=((DescriptorFactoryParent*)resolveRelated(parent))->key74;
    updateDescriptorIndex(object);
}
