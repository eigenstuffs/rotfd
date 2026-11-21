/* fn_800AE7E4: related resource activation (counterpart of fn_800AE4A0 deactivation). */
struct Handle_801F7F10{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct DeactivatePrefix{char unknown00[8];};
struct DeactivateObject:DeactivatePrefix{
    virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();
    virtual void finish();virtual void reset();virtual void slot13();virtual void destroy(int);virtual void begin(int);virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();
    virtual void bind(DeactivateObject*,DeactivateObject*)const;
    virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();
    virtual const Handle_801F7F10*getResource(int);
    char unknown0C[0x14];Handle_801F7F10 related20;char unknown24[0x14];unsigned long long flags;char unknown40[0x18];Handle_801F7F10 related58;char unknown5C[0x14];Handle_801F7F10 related70;char unknown74[0x14];DeactivateObject*effect;char unknown8C[0x24];const Handle_801F7F10*linked;char unknownB4[0x374];DeactivateObject*nested;
    void addFlags(unsigned long long mask){flags|=mask;}
    void clearFlags(unsigned long long mask){flags&=~mask;}
};
struct DeactivateActor{char unknown00[0x24];Handle_801F7F10 handle;char unknown28[0x2A0];signed char active;};
struct DeactivateOwner{char unknown00[8];DeactivateActor*actor;};
struct HandleIndex{int value;HandleIndex(int v):value(v){}operator const int&()const{return value;}};
struct DeactivateEntry{DeactivateObject*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{DeactivateEntry*p;DeactivateEntry&operator[](int i)const{return p[i];}};
struct DeactivateManager{int count,capacity;EntryArray entries;};
struct DeactivateScene{char unknown00[0x15058];void*mode;};
struct DeactivateService{char unknown00[0x1C];const Handle_801F7F10*handle;};
struct DeactivateContext{char unknown00[0x118];DeactivateManager*manager;char unknown11C[8];DeactivateScene*scene;char unknown128[0x14];DeactivateService*service;};
extern "C"{extern DeactivateContext lbl_801E9D24;unsigned long fn_801F948C(void*,const char*);extern const char lbl_802A0178[];void fn_802554F4(DeactivateObject*);unsigned long fn_801F7EB8(const Handle_801F7F10*);}
struct DeactivateName{unsigned long word;DeactivateName(const char*s){word=fn_801F948C(this,s);}};
struct DeactivateReturnedHandle:Handle_801F7F10{~DeactivateReturnedHandle(){}};
extern "C" DeactivateReturnedHandle fn_80058778(void*,const DeactivateName&,signed char);
/* The owner lookup uses the conditional-expression resolve shape; the other
   lookups use the early-return shape (required for the bind receiver order). */
inline DeactivateObject*resolveOwner(const Handle_801F7F10&h){int index=h.bits.index;DeactivateManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline DeactivateObject*resolveDeactivate(const Handle_801F7F10&h){int index=h.bits.index;DeactivateManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}

extern "C" void fn_800AE7E4(DeactivateOwner*self){
    DeactivateObject*owner=resolveOwner(self->actor->handle);
    resolveDeactivate(resolveDeactivate(owner->related58)->related20)->begin(-1);
    DeactivateObject*effect=resolveDeactivate(fn_80058778(lbl_801E9D24.scene->mode,DeactivateName(lbl_802A0178),0));
    if(effect){
        const Handle_801F7F10*h=&resolveDeactivate(*resolveDeactivate(*lbl_801E9D24.service->handle)->linked)->related70;
        DeactivateObject*actor=fn_801F7EB8(h)?resolveDeactivate(*h):0;
        DeactivateObject*resource=resolveDeactivate(*actor->getResource(0));
        DeactivateObject*nested=actor->nested;
        effect->reset();
        effect->clearFlags(0x40000ULL);
        effect->bind(resource,nested);
        fn_802554F4(effect);
        effect->addFlags(0x20000ULL);
    }
    DeactivateObject*second=owner->effect;
    if(second){
        second->reset();
        second->clearFlags(0x40000ULL);
        second->bind(resolveDeactivate(owner->related58),0);
        fn_802554F4(second);
        second->addFlags(0x20000ULL);
        second->finish();
    }
}
