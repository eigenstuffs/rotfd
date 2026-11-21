/* fn_8006EEC0: resource activation toggle. Copies the owner's resource handle
   (+0x58 of the virtual resource()) and the resolved resource's control handle
   (+0x20). Mode 0 sets flags120 bit16 after fn_8006B220(...,0) and calls control
   slot 0x40(-1); mode 1 clears the bit, calls fn_8006B220(...,1) and control slot
   0x44(-1). Sibling of related_activation_toggle_80069CA8.cpp. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80027528:Handle_8001FF78{Handle_80027528(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80027528(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();
virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40(int);virtual void v44(int);
};
struct Related{char unknown00[0x20];Handle_801F7F10 handle20;char unknown24[0xFC];Word flags120;};
struct Resource{char unknown00[0x58];Handle_801F7F10 handle;};
struct OwnerPrefix{Word unknown00;};
struct Owner:OwnerPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual Resource*resource();};
extern "C" signed char fn_8006B220(void*,Related*,signed char);
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Related*resolveRelated(const Handle_801F7F10&h){return (Related*)resolve(h);}
/* Cached view of a handle lookup: the manager, index and tag are read before the
   mode branch; the entry itself is resolved inside each branch. */
struct Lookup{Manager*m;int index;signed char tag;
    Lookup(const Handle_801F7F10&h):m(lbl_801E9D24.manager),index(h.bits.index),tag(h.bits.tag){}
    Related*get()const{Entry*e=&m->entries[index];if(e->tag==tag)return (Related*)e->object;return 0;}};
extern "C" void fn_8006EEC0(Owner*self,signed char mode)
{
    Handle_80020B90 resource(self->resource()->handle);
    Handle_80027528 control(resolveRelated(self->resource()->handle)->handle20);
    Lookup lookup(resource);
    if(mode==0){
        if(lookup.get()->flags120&0x10000)return;
        fn_8006B220(self,lookup.get(),0);
        resolveRelated(resource)->flags120|=0x10000;
        if(fn_801F7EB8(&control))resolve(control)->v40(-1);
    }else if(mode==1){
        if(!(lookup.get()->flags120&0x10000))return;
        lookup.get()->flags120&=~0x10000;
        fn_8006B220(self,resolveRelated(resource),1);
        if(fn_801F7EB8(&control))resolve(control)->v44(-1);
    }
}
