typedef unsigned long RecordOwnerWord;
extern "C" {
extern const char __vt__20SpatialBase_802EC118[],lbl_802EC368[],__vt__17Resource_802E9E20[];
extern char lbl_801EF5C8[],lbl_8028F698[];
extern struct {char unknown0[0x16C];void*records;}lbl_801E9D24;
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
void fn_80252DE0(void*,const int*);
}
struct BaseObject_Z {
    RecordOwnerWord unknown0[2];const void*vtable;
    ~BaseObject_Z();
    static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct RecordOwnerResource:BaseObject_Z {~RecordOwnerResource(){vtable=__vt__17Resource_802E9E20;}};
struct RecordOwnerBase:RecordOwnerResource {
    char unknownC[0x14];
    ~RecordOwnerBase(){vtable=__vt__20SpatialBase_802EC118;}
};
struct RecordOwnerElement {char unknown0[20];~RecordOwnerElement(){}};
struct RecordOwnerPool {
    int count,capacity;RecordOwnerElement*data;
    ~RecordOwnerPool(){if(data){for(int i=0;i<count;++i)data[i].~RecordOwnerElement();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(RecordOwnerElement));data=0;}data=0;}}
};
struct CallbackRecordOwner:RecordOwnerBase {
    int index;RecordOwnerPool pool;
    ~CallbackRecordOwner();
};
CallbackRecordOwner::~CallbackRecordOwner(){
    vtable=lbl_802EC368;
    if(lbl_801E9D24.records&&index!=-1){int old=index;fn_80252DE0(lbl_801E9D24.records,&old);}
    index=-1;
}
