// Recovered GSQE78 hierarchy entry dispatch and resource replacement.
// Private names describe observed roles; the original class names remain unknown.
typedef unsigned long u32;
struct Handle_801F7F10;
struct Handle { union {u32 value; struct {signed int generation:8; signed int index:24;}bits;}; Handle&operator=(const Handle_801F7F10&); };
struct HandleList {int count,capacity;Handle*data;};
struct Handle_801F7F10 {Handle_801F7F10();~Handle_801F7F10();u32 value;};
struct ObjectStorage {char unknown[8];};
struct Object:ObjectStorage {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void setOwner(const Handle_801F7F10&);
};
struct Hierarchy {u32 unused;Handle owner;char unknown[0xD0-8];HandleList entries;int count,width,offset;const Handle&getOwner()const{return owner;}};
struct Entry {Object*object;u32 unused[2];signed char generation;char pad[3];};
struct Manager {u32 unused[2];Entry*entries;};
struct Globals {char unused[0x118];Manager*manager;char unused11C[8];void*dispatcher;};
extern "C" {
extern Globals lbl_801E9D24;
void fn_802073E8(Hierarchy*,int,Object*,float);
void fn_801FC26C(Hierarchy*,int,Handle*,int,float);
void fn_802603E8(void*,float);
}
// Returning a derived handle preserves native base cleanup with delete flag zero.
struct ReturnedHandle:Handle_801F7F10 {};
extern "C" {
void fn_801F86C8(Manager*,const void*,short);
u32 fn_801F7EB8(const void*);
ReturnedHandle fn_80260868(void*,const void*,int);
void fn_8025D588(Object*,int);
}
inline Handle&Handle::operator=(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}
// Three observed initialization layers precede the resource handle copy.
template<int N>struct ZeroHandle:ZeroHandle<N-1>{ZeroHandle(){value=0;}};
template<>struct ZeroHandle<0>:Handle_801F7F10{};
struct ResourceHandle:ZeroHandle<3>{ResourceHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct IdentityHandle:Handle_801F7F10{IdentityHandle(const Handle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
static inline Object*resolve(const Handle&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;return e->generation==h.bits.generation?e->object:0;}
extern "C" void fn_80206B44(Hierarchy*self,int index,int offset){
 // This expression form preserves the original position/index register allocation.
 int position=offset<0?self->offset:self->offset+offset;
 const Handle&h=self->entries.data[index];
 Entry*e=lbl_801E9D24.manager->entries+h.bits.index;
 fn_802073E8(self,30,e->generation==h.bits.generation?e->object:0,position);
 fn_801FC26C(self,11,&self->entries.data[index],30,position);
 fn_802603E8(lbl_801E9D24.dispatcher,0.0f);
}

extern "C" void fn_80206C54(Hierarchy*self,int index,int argument,const void*name){
 if(index<0 || index>=self->entries.count)return;
 ResourceHandle resource=fn_80260868(lbl_801E9D24.dispatcher,name,0);
 if(!fn_801F7EB8(&resource))return;
 self->entries.data[index]=resource;
 IdentityHandle identity(self->getOwner());
 fn_8025D588(resolve(*(Handle*)&resource),argument);
 resolve(*(Handle*)&resource)->setOwner(identity);
}
