/* Signed-byte state predicate on the cached resource of the queried owner:
   accepts state 0 without a resource, state 1 when the retained resource
   handle resolves to a node with flags38 bit25, otherwise compares the
   node's game-table slot state byte. Handle layers follow
   handle_callback_selector_800461CC.cpp; the resolve keeps index/tag locals
   as in scene_control_actor_velocity_reset_800494B0.cpp. */
typedef unsigned long u32;
typedef unsigned long long u64;
struct Node;
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;u32 unknown04,unknown08;signed char tag;char opaque0D[3];bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{char opaque00[8];EntryArray entries;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager;}lbl_801E9D24;void fn_801F86C8(Manager*,const void*,int);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C" u32 fn_801F7EB8(const Handle_801F7F10*);
struct Handle_80020478:Handle_801F7F10{
Handle_80020478(){word=0;}~Handle_80020478(){}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Handle_80020834:Handle_80020478{
Handle_80020834(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}
Handle_80020834(const Handle_80020834&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}
~Handle_80020834(){}
bool valid()const{return fn_801F7EB8(this)!=0;}
static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct Node{char opaque00[0x30];u64 flags30;u64 flags38;char opaque40[0x1EC-0x40];signed char index1EC;};
struct Resource{char opaque00[0x130];Handle_801F7F10 handle130;};
extern "C" Resource*fn_8009F170(Node*);
struct Slot{char opaque00[0x10];signed char state10;};
struct Table{char opaque00[0x10];Slot*slots[1];};
struct Game{char opaque00[0x1F8];Table*table;};
struct ServicePrefix{u32 unknown00;};
struct Service:ServicePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual Game*getGame();};
extern "C" Service*lbl_803776B8;
struct QueryPrefix{u32 unknown00;};
struct Query:QueryPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual const Handle_801F7F10*getHandle();
};
extern "C" signed char fn_80067480(Query*self,signed char state)
{
    Table*table=lbl_803776B8->getGame()->table;
    self->slot14();
    if(!fn_8009F170(resolve(*self->getHandle())))return state==0;
    Handle_80020834 handle(fn_8009F170(resolve(*self->getHandle()))->handle130);
    if(handle.valid()&&(resolve(handle)->flags38&0x2000000ULL))return state==1;
    if(handle.valid()&&resolve(handle)->index1EC>=0)
        return state==table->slots[resolve(handle)->index1EC]->state10;
    return 0;
}
