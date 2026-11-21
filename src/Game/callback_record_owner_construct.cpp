typedef unsigned long RecordOwnerWord;
extern "C" {
    extern const char __vt__20SpatialBase_802EC118[],lbl_802EC368[],__vt__17Resource_802E9E20[];
    extern char lbl_801EF5C8[],lbl_8028F698[];
    extern struct {
        char unknown0[0x16C];
        void*records;
    }
    lbl_801E9D24;
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
    void*fn_8028FAF4(void*,void*,int,int);
    void*fn_8028FF24(void*,int);
    extern const float lbl_8037B500;
    void fn_80252DE0(void*,const int*);
}
struct BaseObject_Z {
    RecordOwnerWord unknown0[2];
    const void*vtable;
    BaseObject_Z();
    ~BaseObject_Z();
    static void operator delete(void*p)throw(){
        fn_801EF610(lbl_801EF5C8,p);
    }
};
struct RecordOwnerResource:BaseObject_Z {
    RecordOwnerResource(){
        vtable=__vt__17Resource_802E9E20;
    }
    ~RecordOwnerResource(){
        vtable=__vt__17Resource_802E9E20;
    }
};
struct RecordOwnerVector {
    float x,y,z;
    void operator=(const RecordOwnerVector&v){
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
extern "C" const RecordOwnerVector game_vec4_zero;
struct RecordOwnerBase:RecordOwnerResource {
    RecordOwnerWord unknownC;
    RecordOwnerVector vector;
    float w;
    RecordOwnerBase(){
        vtable=__vt__20SpatialBase_802EC118;
        vector=game_vec4_zero;
        w=lbl_8037B500;
        unknownC=0;
    }
    ~RecordOwnerBase(){
        vtable=__vt__20SpatialBase_802EC118;
    }
};
struct RecordOwnerElement {
    RecordOwnerVector vector;
    float w;
    short kind;
    RecordOwnerElement(){
        vector=game_vec4_zero;
        w=lbl_8037B500;
        kind=-1;
    }
    ~RecordOwnerElement(){
    }
};
inline void*operator new(unsigned long,void*place){
    return place;
}
struct RecordOwnerPool {
    int count,capacity;
    RecordOwnerElement*data;
    RecordOwnerPool(){
    }
    void setCapacity(int size){
        if(data)data=(RecordOwnerElement*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(RecordOwnerElement),size*sizeof(RecordOwnerElement));
        else data=(RecordOwnerElement*)fn_8028FF24(lbl_8028F698,size*sizeof(RecordOwnerElement));
        capacity=size;
    }
    void resize(int size){
        if(size>count){
            setCapacity(size);
            for(int i=count;
            i<size;
            ++i)new(&data[i])RecordOwnerElement();
            count=size;
        }
        else if(size<count){
            for(int i=count-1;
            i>=size;
            --i)data[i].~RecordOwnerElement();
            setCapacity(size);
            count=size;
        }
    }
    ~RecordOwnerPool(){
        if(data){
            for(int i=0;
            i<count;
            ++i)data[i].~RecordOwnerElement();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(RecordOwnerElement));
                data=0;
            }
            data=0;
        }
    }
};
struct CallbackRecordOwner:RecordOwnerBase {
    int index;
    RecordOwnerPool pool;
    short key;
    CallbackRecordOwner();
    ~CallbackRecordOwner();
};
struct RecordOwnerIndex {
    int value;
    RecordOwnerIndex(const RecordOwnerIndex&r):value(r.value){
    }
};
extern "C" RecordOwnerIndex fn_80252E1C(void*,short);
inline void updateRecordOwnerIndex(CallbackRecordOwner*self){
    if(lbl_801E9D24.records){
        if(self->index!=-1){
            int old=self->index;
            fn_80252DE0(lbl_801E9D24.records,&old);
        }
        self->index=fn_80252E1C(lbl_801E9D24.records,self->key).value;
    }
    else self->index=-1;
}
CallbackRecordOwner::CallbackRecordOwner(){
    vtable=lbl_802EC368;
    index=-1;
    pool.count=0;
    pool.capacity=0;
    pool.data=0;
    key=0;
    pool.resize(8);
    updateRecordOwnerIndex(this);
}
