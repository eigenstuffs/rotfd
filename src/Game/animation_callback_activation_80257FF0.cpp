// fn_80257FF0: animation callback activation (PlayAnim / SequenceMixAnim /
// SequenceAnim selection), then registry lookup and primary dispatch.
// The linked-handle resolve and the registry key read the handle generation
// through an explicit (signed char) cast; that colours the re-resolved
// incoming object, the handle word and the generation like the original.
struct Handle {
    signed int generation:8;
    signed int index:24;
};
struct HandleWord {
    unsigned long word;
};
struct Storage8 {
    char unknown0[8];
};
struct Target:Storage8 {
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
    virtual void slot30(const void*,void*,void*);
};
struct Entry {
    Target*object;
    char unknown4[8];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct Manager {
    int count;
    int capacity;
    Entry*entries;
};
extern "C" {
    extern struct {
        char unknown0[0x118];
        Manager*manager;
        char unknown11C[0x28];
        void*records;
    }
    lbl_801E9D24;
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void*fn_801F7EB8(const void*);
}
inline Target*resolve(const Handle&h){
    int index=h.index;
    Manager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==h.generation?m->entries[index].object:0;
}
inline unsigned long registryKey(const Handle&handle){
    Manager*manager=lbl_801E9D24.manager;
    int index=handle.index;
    int generation=(signed char)handle.generation;
    int valid=0;
    if(index<manager->count&&generation==((signed char*)manager->entries)[index*sizeof(Entry)+12])
        valid=1;
    return valid?*(unsigned long*)((char*)manager->entries+index*sizeof(Entry)+4):0;
}
struct NativeHandle {
    unsigned long word;
    NativeHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~NativeHandle(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct HandleLayer1:NativeHandle {
    HandleLayer1(){
        word=0;
    }
};
struct HandleLayer2:HandleLayer1 {
    HandleLayer2(){
        word=0;
    }
};
struct NameHandle {
    unsigned long word;
    NameHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~NameHandle(){
        __dt__15Handle_801F7F10Fv(this,-1);
    }
};
struct HandleCopy1:HandleLayer1 {
    HandleCopy1(const NameHandle&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct HandleCopy:HandleLayer2 {
    HandleCopy(const NameHandle&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct ValueHandle:NativeHandle {
    ValueHandle(const ValueHandle&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
    ValueHandle(){}
};
struct HandleLayer3:ValueHandle {
    HandleLayer3(){
        word=0;
    }
};
struct HandleLayer4:HandleLayer3 {
    HandleLayer4(){
        word=0;
    }
};
struct HandleLayer5:HandleLayer4 {
    HandleLayer5(){
        word=0;
    }
};
struct MemberCopy:HandleLayer5 {
    MemberCopy(const HandleWord&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct ReturnHandle {
    unsigned long word;
    ReturnHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~ReturnHandle(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct ReturnLayer:NativeHandle {
    ReturnLayer(){
        word=0;
    }
};
struct ReturnCopy:ReturnLayer {
    ReturnCopy(const ReturnHandle&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct Pool {
    char noStandOn[0xC];
    char playAnim[0xC];
    char sequenceMixAnim[0x10];
    char sequenceAnim[0x10];
};
struct Incoming {
    char unknown0[0x1C];
    Handle handle1C;
    char unknown20[0x100];
    unsigned long flags120;
};
struct Owner {
    char unknown0[4];
    HandleWord handle4;
    char unknown8[0x30];
    unsigned long long flags;
    char unknown40[0x20];
    Handle handle60;
    Handle handle64;
    unsigned long key68;
};
extern "C" {
    extern const Pool lbl_802AEB80;
    void fn_802560D8(void*);
    NameHandle fn_801B52EC(Manager*,const char*);
    void fn_80230F7C(void*,const Handle*);
    void fn_802585E8(void*,ValueHandle);
    signed char fn_801F5F28(void*,void*,const unsigned long*,unsigned long*,int);
    void fn_8023232C(void*,const Handle*);
    ReturnHandle fn_80257B70(Owner*,int);
    void fn_8023297C(void*,const ReturnCopy*,int,int);
}
inline Target*resolveLinked(const Handle&h){
    Entry*e=&lbl_801E9D24.manager->entries[h.index];
    if(e->generation==(signed char)h.generation)return e->object;
    return 0;
}
inline void assignHandle(Handle&target,const NativeHandle&value){
    fn_801F86C8(lbl_801E9D24.manager,&target,-1);
    *(unsigned long*)&target=value.word;
    fn_801F86C8(lbl_801E9D24.manager,&value,1);
}
inline signed char sequenceEnabled(Owner*self){
    if(self->flags&0x200ULL)return 1;
    return 0;
}
inline void dispatchPrimary(Owner*self){
    ReturnCopy value(fn_80257B70(self,0));
    if(!fn_801F7EB8(&value))return;
    if(fn_801F7EB8(&self->handle60))resolve(self->handle60)->slot30(&value,0,0);
    else if(fn_801F7EB8(&self->handle64))fn_8023297C(resolve(self->handle64),&value,0,1);
}
extern "C" void fn_80257FF0(Owner*self,const Handle*incoming){
    const Pool*const pool=&lbl_802AEB80;
    unsigned long key;
    fn_802560D8(self);
    if(!(self->flags&0x80ULL))return;
    if(!(((Incoming*)resolve(*incoming))->flags120&0x800))return;
    assignHandle(self->handle64,HandleCopy(fn_801B52EC(lbl_801E9D24.manager,pool->playAnim)));
    if(sequenceEnabled(self)){
        if(self->flags&0x100ULL)
            assignHandle(self->handle60,HandleCopy1(fn_801B52EC(lbl_801E9D24.manager,pool->sequenceMixAnim)));
        else
            assignHandle(self->handle60,HandleCopy1(fn_801B52EC(lbl_801E9D24.manager,pool->sequenceAnim)));
        fn_80230F7C(resolve(self->handle60),&self->handle64);
        const HandleWord&source=self->handle4;
        fn_802585E8(resolve(self->handle60),MemberCopy(source));
    }
    Incoming*object=(Incoming*)resolve(*incoming);
    Target*registered=resolveLinked(object->handle1C);
    key=registryKey(object->handle1C);
    fn_801F5F28(lbl_801E9D24.records,registered,&key,&self->key68,0);
    if(!fn_801F7EB8(&self->handle64))return;
    fn_8023232C(resolve(self->handle64),incoming);
    dispatchPrimary(self);
}
