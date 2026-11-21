/* Related-node activation toggle. Mode 0 activates (flags120 bit16): syncs the
   controller, notifies the control handle (+0x20) slot 40, runs the group
   transition, and for an actor (+0x130) with flags38 bit7 checks whether the
   linked container (+0x64) already holds the state record handle before
   calling fn_80257528. Mode 1 deactivates with the mirrored calls. Handle
   layers follow early_actor_group_transition_8006AE80.cpp and
   actor_disable_controls_800384DC.cpp; fn_80257B70 returns a typed handle
   with an inline destructor (Handle_80066960 layout). */
typedef unsigned long Word;
typedef unsigned long long u64;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
struct GroupService{char unknown00[8];Handle_801F7F10*state;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;GroupService*groups;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80027528:Handle_8001FF78{Handle_80027528(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80027528(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80066960:Handle_801F7F10{Handle_80066960(const Handle_80066960&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80066960(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80020478{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8006A740:Handle_80021BCC{Handle_8006A740(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8006A740(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct TargetManager{int count,capacity;Entry*entries;};
inline Node*resolveTarget(const Handle_801F7F10&h){TargetManager*m=(TargetManager*)lbl_801E9D24.manager;Entry*e=&m->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline bool isValid(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
struct Prefix{char unknown00[8];};
struct Node:Prefix{
virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();
virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40(int);virtual void v44(int);
};
struct Slot{char unknown00[4];Handle_801F7F10 handle;};
struct SlotRef{Slot*slot;char unknown04[0x70];};
struct Container:Node{char unknown0C[0xC];signed char active18;char unknown19[7];SlotRef slots[4];
    signed char contains(const Handle_801F7F10&h){for(int i=0;i<4;i++){if(slots[i].slot&&resolve(h)==resolve(slots[i].slot->handle))return 1;}return 0;}};
struct Group{char unknown00[0xBC];unsigned short flagsBC;};
struct Target{char unknown00[0x3D8];int value3D8;};
struct Actor{char unknown00[0x38];u64 flags38;char unknown40[0x24];Handle_801F7F10 handle64;const Handle_801F7F10&getHandle64()const{return handle64;}};
struct Related{char unknown00[4];Handle_801F7F10 self;const Handle_801F7F10&getSelf()const{return self;}char unknown08[0x18];Handle_801F7F10 handle20;const Handle_801F7F10&getHandle20()const{return handle20;}char unknown24[0xFC];Word flags120;bool isActive()const{return (flags120&0x10000)!=0;}char unknown124[0xC];Handle_801F7F10 handle130;};
struct StatePrefix{Word unknown00;};
struct State:StatePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual const Handle_801F7F10*getHandle();};
extern "C"{State*fn_8005EE10(Node*);const Handle_80066960&fn_80268080(Node*,const Handle_80020B90&);
signed char fn_8006B220(void*,Related*,signed char);signed char fn_8006B470(void*,Related*,unsigned char);
signed char fn_8009C12C(Target*,int);Handle_80066960 fn_80257B70(Actor*,int);void fn_80257528(Actor*,int);void fn_8025795C(Actor*,int,int);}
extern "C" signed char fn_80069CA8(void*self,Related*related,signed char mode)
{
    Handle_80027528 control(related->getHandle20());
    Actor*actor=(Actor*)resolve(related->handle130);
    if(mode==0){
        if(related->flags120&0x10000)return 0;
        fn_8006B220(self,related,0);
        related->flags120|=0x10000;
        if(isValid(control))resolve(control)->v40(-1);
        if(related->flags120&0x80){
            Handle_80066960 group(fn_80268080(resolve(*lbl_801E9D24.groups->state),Handle_80020B90(related->getSelf())));
            if(((Group*)resolve(group))->flagsBC&1)fn_8006B470(self,related,0);
        }
        if(actor&&(actor->flags38&0x80ULL)){
            Handle_8006A740 link(actor->getHandle64());
            if((actor->flags38&0x10000000ULL)&&isValid(link)&&((Container*)resolve(link))->active18){
                Target*target=(Target*)resolve(*fn_8005EE10(resolveTarget(related->handle130))->getHandle());
                if(fn_8009C12C(target,target->value3D8)){
                    signed char found=((Container*)resolve(link))->contains(fn_80257B70(actor,target->value3D8));
                    if(found)fn_80257528(actor,0);
                }
            }else fn_80257528(actor,0);
        }
    }else if(mode==1){
        if(!related->isActive())return 0;
        related->flags120&=~0x10000;
        if(actor){if(!(actor->flags38&0x1000000000ULL))fn_8006B220(self,related,1);}
        else fn_8006B220(self,related,1);
        if(isValid(control))resolve(control)->v44(-1);
        if(related->flags120&0x80){
            Handle_80066960 group(fn_80268080(resolve(*lbl_801E9D24.groups->state),Handle_80020B90(related->getSelf())));
            if(((Group*)resolve(group))->flagsBC&0x100)fn_8006B470(self,related,3);
        }
        if(actor&&(actor->flags38&0x80ULL)){
            Handle_8006A740 link(actor->getHandle64());
            if(actor&&(actor->flags38&0x10000000ULL)){
                Target*target=(Target*)resolve(*fn_8005EE10(resolveTarget(related->handle130))->getHandle());
                if(fn_8009C12C(target,target->value3D8))fn_8025795C(actor,target->value3D8,0);
            }else if(isValid(link))resolve(link)->v3C();
        }
        if(related->flags120&0x80){
            Handle_80066960 group(fn_80268080(resolve(*lbl_801E9D24.groups->state),Handle_80020B90(related->getSelf())));
            if(((Group*)resolve(group))->flagsBC&0x100)fn_8006B470(self,related,3);
        }
    }
    return 1;
}
