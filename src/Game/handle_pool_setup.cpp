/* Observed engine handle pool attachment and initialization. */
typedef unsigned long u32;
struct Handle_801F7F10 { signed long generation:8; signed long index:24; };
struct Object { u32 unknown; Handle_801F7F10 handle; };
struct Slot;
template<class T>struct Array {
 int size,capacity;T*data;
 void initialize(){size=0;capacity=0;data=0;}
};
struct Pool {Array<Slot> slots;Array<int> free;int limit,freeCount;char autoDestroy;void**vtable;};
extern "C" {
Handle_801F7F10*fn_801F7914(Handle_801F7F10*,const Handle_801F7F10*);
void fn_801F88AC(Pool*,int);
int fn_801F8D50(Pool*);
void fn_801F9140(Pool*);
void fn_801B4BF0(Pool*,const Handle_801F7F10*);
void* lbl_802EAAB8[6]={0,0,(void*)fn_801F8D50,(void*)fn_801F9140,(void*)fn_801B4BF0,0};
void fn_801F93FC(Object*object,const Handle_801F7F10*handle){fn_801F7914(&object->handle,handle);}
Pool*fn_801F9420(Pool*p){
 p->vtable=lbl_802EAAB8;
 p->slots.initialize();p->free.initialize();
 p->freeCount=0;p->limit=0;p->autoDestroy=1;
 fn_801F88AC(p,0x4000);return p;
}
}
