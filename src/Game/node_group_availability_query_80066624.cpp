/* Group availability query for a node: looks up the node's group handle
   through fn_80268080 (group root from the engine context's group service,
   keyed by a retained copy of the node's self handle) and tests the group
   flagsBC bits: choice 0 -> bit8 set; choice 1 -> bit8 clear and bit0 set;
   otherwise bit0 clear and bit8 clear.
   Handle layers follow early_actor_group_transition_8006AE80.cpp; the
   resolve helper (ActorIndex/EntryArray/matchesTag) is the one used by the
   neighboring owner_resource_state_predicate_80067480.cpp, which gives the
   original index/tag register allocation for the repeated group lookups.
   The original evaluated an unused group-root lookup before building the
   key handle (its address computation of the context's group service
   survives dead-code elimination ahead of the key constructor). */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
struct GroupService{char unknown00[8];Handle_801F7F10*state;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;GroupService*groups;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);}
struct Node{char unknown00[4];Handle_801F7F10 self;const Handle_801F7F10&getSelf()const{return self;}char unknown08[0xB4];unsigned short flagsBC;};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80066960:Handle_801F7F10{Handle_80066960(const Handle_80066960&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80066960(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"const Handle_80066960&fn_80268080(Node*,const Handle_80020B90&);
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}

extern "C" signed char fn_80066624(void*, Node* actor, unsigned char choice)
{
    Handle_80020B90 alive(actor->getSelf());
    Node* root = resolve(*lbl_801E9D24.groups->state);
    Handle_80066960 group(fn_80268080(resolve(*lbl_801E9D24.groups->state), Handle_80020B90(actor->getSelf())));
    int mode = choice;
    if (mode == 0) {
        if (resolve(group)->flagsBC & 0x100) return 1;
        return 0;
    }
    if (mode == 1) {
        if (!(resolve(group)->flagsBC & 0x100) && (resolve(group)->flagsBC & 1)) return 1;
        return 0;
    }
    if (!(resolve(group)->flagsBC & 1) && !(resolve(group)->flagsBC & 0x100)) return 1;
    return 0;
}
