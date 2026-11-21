/* Group-state update for a related node: mode 1 clears flags120 bit20 and asks
   fn_80268194; modes 0/2/3 apply scale/blend calls to the group handle from
   fn_80268080 and, for 0/2, refresh the 3D8 value of the state handle owner
   when the related actor (+0x130) has flags38 bit28. The flag test uses a
   separate handle view and the state lookup a separate manager view, as the
   original reloads those bits/entries. Layout follows
   early_actor_group_transition_8006AE80.cpp. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct GroupService{char unknown00[8];Handle_801F7F10*state;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;GroupService*groups;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct FlagView{union{Word word;struct{signed int tag:8,index:24;}bits;};};
inline Node*resolveFlags(const FlagView&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct TargetManager{int count,capacity;Entry*entries;};
inline Node*resolveTarget(const Handle_801F7F10&h){TargetManager*m=(TargetManager*)lbl_801E9D24.manager;Entry*e=&m->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline bool isValid(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
struct Node{char unknown00[4];Handle_801F7F10 self;const Handle_801F7F10&getSelf()const{return self;}char unknown08[0x30];unsigned long long flags38;char unknown40[0xE0];Word flags120;char unknown124[0xC];Handle_801F7F10 handle130;char unknown134[0x3D8-0x134];int value3D8;void refreshValue3D8(){int saved=value3D8;value3D8=-1;value3D8=saved;}};
struct StatePrefix{Word unknown00;};
struct State:StatePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual const Handle_801F7F10*getHandle();};
extern "C"{State*fn_8005EE10(Node*);const Handle_801F7F10&fn_80268080(Node*,const Handle_80020B90&);signed char fn_80268194(Node*,const Handle_80020B90&);
void fn_801ED9FC(Node*,float);void fn_801EDA54(Node*,float);void fn_801EDAAC(Node*,float,float,float);void fn_8023DE28(Node*);
extern const float lbl_803787D4,lbl_803787F8;}
extern "C" signed char fn_8006B470(void*self,Node*related,unsigned char mode)
{
    Handle_80020B90 handle(related->getSelf());
    Node*groups=resolve(*lbl_801E9D24.groups->state);
    int m=mode;
    if(m==1){
        related->flags120&=~0x100000;
        return fn_80268194(groups,handle);
    }
    if(m==0){
        fn_801ED9FC(resolve(fn_80268080(groups,handle)),lbl_803787D4);
        fn_8023DE28(resolve(handle));
        if(isValid(related->handle130)&&(resolveFlags(*(const FlagView*)&related->handle130)->flags38&0x10000000ULL)){
            resolve(*fn_8005EE10(resolveTarget(related->handle130))->getHandle())->refreshValue3D8();
        }
        return 1;
    }
    if(m==3){
        fn_801EDAAC(resolve(fn_80268080(groups,handle)),lbl_803787D4,lbl_803787D4,lbl_803787F8);
        return 1;
    }
    if(m==2){
        fn_801EDA54(resolve(fn_80268080(groups,handle)),lbl_803787D4);
        if(isValid(related->handle130)&&(resolveFlags(*(const FlagView*)&related->handle130)->flags38&0x10000000ULL)){
            resolve(*fn_8005EE10(resolveTarget(related->handle130))->getHandle())->refreshValue3D8();
        }
        return 1;
    }
    return 0;
}
