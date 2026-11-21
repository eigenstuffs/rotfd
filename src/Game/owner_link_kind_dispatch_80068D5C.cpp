/* Walks the resource owner's linked node chain (first +0x10, next +0x18) and
   forwards each node whose valid target (+0x1C) has kind 0x12 to fn_80069CA8.
   Handle layers follow actor_handle_pair_dispatch_8006ECE8.cpp. */
typedef unsigned long u32;
struct Node;
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;u32 unknown04,unknown08;signed char tag;char opaque0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{char opaque00[8];EntryArray entries;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager;}lbl_801E9D24;void fn_801F86C8(Manager*,const void*,int);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C" u32 fn_801F7EB8(const Handle_801F7F10*);
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{
Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
~Handle_80020B90(){}
Handle_80020B90&operator=(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline bool isValid(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
struct Node{char opaque00[0x10];Handle_801F7F10 first;char opaque14[4];Handle_801F7F10 next;Handle_801F7F10 target;char opaque20[0x6C-0x20];unsigned short kind;};
struct Resource{char opaque00[0x58];Handle_801F7F10 owner;};
struct QueryPrefix{u32 unknown00;};
struct Query:QueryPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual Resource*getResource();
};
extern "C" void fn_80069CA8(Query*,Node*,void*);
extern "C" int fn_80068D5C(Query*self,void*arg)
{
    Handle_80020B90 owner(self->getResource()->owner);
    for(Handle_80020B90 link(resolve(owner)->first);isValid(link);link=resolve(link)->next){
        if(isValid(resolve(link)->target)&&resolve(resolve(link)->target)->kind==0x12)
            fn_80069CA8(self,resolve(link),arg);
    }
    return 1;
}
