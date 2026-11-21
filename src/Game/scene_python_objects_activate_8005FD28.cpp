/* Two passes over the scene's object handle list (scene at lbl_801E9D24+0x124,
 * count at +0x34, handles at +0x3C). The current Python owner (lbl_803776B8)
 * goes first in each pass. Pass one calls virtual slot 0x30 on every object
 * flagged 0x10000000. Pass two forwards each flagged object's event owner to
 * fn_80067808. The event-owner cast is the inlined body of fn_8005EE10
 * (flag_member_query.cpp): a base at +0x90 for 0x10000000/0x100/0x200 (high
 * word), +0x60 for 0x80, otherwise null. It is inlined through an inner
 * helper that takes the derived pointer.
 * Register allocation notes:
 * - Declaring one shared loop index is required.
 * - The resolve helper must bind the entry by reference and pass the tag
 *   through a signed char parameter.
 * - The cast must go through the two-level helper.
 * Private layout views only. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Object;
struct Entry{Object*object;char opaque4[8];signed char tag;char opaqueD[3];bool matchesTag(signed char t)const{return tag==t;}};
struct Manager{int count,capacity;Entry*entries;};
struct Scene{char opaque00[0x34];int count;int capacity;Handle_801F7F10*handles;};
struct Globals{char opaque00[0x118];Manager*manager;char opaque11C[8];Scene*scene;};
struct PythonEventOwner;
extern "C"{extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);void fn_80067808(PythonEventOwner*);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_80020834&operator=(const Handle_80020834&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Prefix8{char opaque00[8];};
struct Activatable:Prefix8{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void activate();};
struct Prefix4{char opaque00[4];};
struct Control:Prefix4{virtual void slot08();virtual void slot0C();virtual void slot10();virtual Activatable*target();};
struct FlagFirst{char opaque[0x30];};
struct FlagSecond{char opaque[0x30];};
struct Object:Activatable{char opaque0C[0x38-0xC];unsigned long long flags;char opaque40[0x20];
 signed char hasFlags(unsigned long long mask)const{return(flags&mask)?1:0;}};
struct FlagOwner:Object,FlagFirst,FlagSecond{};
inline void*eventOwnerOf(FlagOwner*self){
 if(self->hasFlags(0x10000000ULL))return static_cast<FlagSecond*>(self);
 if(self->flags&0x10000000000ULL)return static_cast<FlagSecond*>(self);
 if(self->flags&0x20000000000ULL)return static_cast<FlagSecond*>(self);
 if(self->flags&0x8000000000ULL)return static_cast<FlagFirst*>(self);
 return 0;}
inline void*eventOwner(Object*o){return eventOwnerOf((FlagOwner*)o);}
extern "C" Control*lbl_803776B8;
struct HandleIndex{int value;HandleIndex(int v):value(v){}operator const int&()const{return value;}};
inline Object*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const HandleIndex index(h.bits.index);Entry&e=m->entries[index];if(e.matchesTag(h.bits.tag))return m->entries[index].object;return 0;}
extern "C" void fn_8005FD28(){
 Handle_80020834 h;
 if(lbl_803776B8)lbl_803776B8->target()->activate();
 int i;
 for(i=0;i<lbl_801E9D24.scene->count;i++){
  h=Handle_80020834(lbl_801E9D24.scene->handles[i]);
  if(resolve(h)->flags&0x10000000ULL)resolve(h)->activate();
 }
 if(lbl_803776B8)fn_80067808((PythonEventOwner*)lbl_803776B8);
 for(i=0;i<lbl_801E9D24.scene->count;i++){
  h=Handle_80020834(lbl_801E9D24.scene->handles[i]);
  if(resolve(h)->flags&0x10000000ULL)fn_80067808((PythonEventOwner*)eventOwner(resolve(h)));
 }
}
