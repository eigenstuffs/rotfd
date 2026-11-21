/* Sphere query record filter; see docs/notes/game-early-sphere-record-filter.md. */
typedef unsigned long Word;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){value=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Node;
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];};struct Manager{int count,capacity;Entry*entries;};
struct Choice{char unknown0[0x2A];signed char active;char unknown2B[0x94-0x2B];};
struct Root{char unknown0[0xF0];int choice;char unknownF4[0x138-0xF4];Choice*choices;};struct Scene{char unknown0[0x15058];Root*root;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
extern "C"void fn_801F86C8(Manager*,const Handle_801F7F10*,int);
struct Handle_80027614:Handle_8001FF78{Handle_80027614(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80027614(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void notify();char unknownC[0x38-0xC];unsigned long long flags;};
struct Candidate{char unknown0[0x1C];Handle_801F7F10 handle;char unknown20[0x130-0x20];Handle_801F7F10 related;const Handle_801F7F10&getHandle()const{return handle;}};
struct Result{char unknown0[0x30];Candidate*object;char unknown34[8];signed char active;char unknown3D[3];unsigned long long unknown40;};
struct Owner{char unknown0[0x24];Handle_801F7F10 handle;char unknown28[0x318-0x28];char control;};
struct Service{char unknown0[0x140];void*enabled;};
extern "C"{extern Service*lbl_803776B8;void fn_800927A0(Result*);void __construct_array(void*,void(*)(Result*),void*,unsigned long,unsigned long);signed char fn_80268794(void*,const void*,void*,Result*,int,unsigned long long,unsigned long long,signed char,float);void fn_8006845C(Service*,Node*);signed char fn_8007D604(void*,int);void fn_800567F0(Root*);}
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
extern "C"void fn_80092510(Owner*self,void*query,const void*center,void*other,float radius){Result records[30];__construct_array(records,fn_800927A0,0,sizeof(Result),30);if(resolve(self->handle)){if(fn_80268794(query,center,other,records,30,0x4E1000000000ULL,0,1,radius)){for(unsigned int i=0;i<30;++i){if(records[i].active){Candidate*c=records[i].object;Handle_80027614 retained(c->getHandle());Node*n=resolve(c->related);if(n&&(n->flags&0x1000000000ULL)){n->notify();if(lbl_803776B8&&lbl_803776B8->enabled)fn_8006845C(lbl_803776B8,n);}else if(n&&(n->flags&0x800000000ULL)){if(fn_8007D604(&self->control,0x20)){Root*r=lbl_801E9D24.scene->root;if(!r->choices[r->choice].active){fn_800567F0(r);n->notify();}}}}}}}}
