typedef unsigned long u32;
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
}
struct QueueTargetStorage8 {
    u32 unknown[2];
};
struct QueueTargetNativeHandle {
    u32 value;
    QueueTargetNativeHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~QueueTargetNativeHandle(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct QueueTargetInterface:QueueTargetStorage8 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30(const QueueTargetNativeHandle*);
};
struct QueueTargetPacked {
    signed int generation:8;
    signed int index:24;
};
struct QueueTargetEntry {
    QueueTargetInterface*object;
    u32 unknown[2];
    signed char generation;
    char pad[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct QueueTargetManager {
    u32 unknown[2];
    QueueTargetEntry*entries;
};
extern "C" struct {
    char unknown[0x118];
    QueueTargetManager*manager;
}
lbl_801E9D24;
struct QueueTargetCopy:QueueTargetNativeHandle {
    QueueTargetCopy(const QueueTargetNativeHandle&h){
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
};
struct QueueTargetOwner {
    u32 unknown0;
    QueueTargetNativeHandle handle4;
    u32 unknown8;
    QueueTargetNativeHandle handleC;
};
inline void assignQueueTarget(QueueTargetNativeHandle&target,const QueueTargetNativeHandle&source){
    fn_801F86C8(lbl_801E9D24.manager,&target,-1);
    target.value=source.value;
    fn_801F86C8(lbl_801E9D24.manager,&source,1);
}
inline QueueTargetInterface*resolveQueueTarget(const QueueTargetNativeHandle&h){
    const QueueTargetPacked&p=*(const QueueTargetPacked*)&h;
    int index=p.index;
    QueueTargetManager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==p.generation?m->entries[index].object:0;
}
extern "C" void fn_80230F7C(QueueTargetOwner*self,const QueueTargetNativeHandle*value){
    assignQueueTarget(self->handleC,*value);
    const QueueTargetNativeHandle&previousSource=self->handle4;
    QueueTargetCopy previous(previousSource);
    resolveQueueTarget(*value)->slot30(&previous);
}
