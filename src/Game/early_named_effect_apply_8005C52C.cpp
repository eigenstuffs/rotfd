typedef unsigned long Word;
extern "C" {Word fn_801F948C(void*,const char*);extern const char lbl_80378608[6];}
struct TargetName {Word word;TargetName(const char*s){word=fn_801F948C(this,s);}};
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct TargetReturn_8005C52C:Handle_801F7F10 {TargetReturn_8005C52C();~TargetReturn_8005C52C(){}};
struct TargetEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TargetManager{int count,capacity;TargetEntry*entries;};
extern "C" struct TargetContext {char unknown00[0x118];TargetManager*manager;}lbl_801E9D24;
inline void*resolve(const Handle_801F7F10&h){int index=h.bits.index;TargetManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct TargetRelated{char unknown00[0x1F0];Handle_801F7F10 handle;};
struct TargetRecord{char unknown00[0x64];Handle_801F7F10 handle;};
struct EffectResource;
struct EffectPrefix{char unknown00[8];};
struct Effect:EffectPrefix {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void prepare();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void apply(EffectResource*,void*);};
struct EffectOwner{char unknown00[0x58];Handle_801F7F10 target;char unknown5C[8];Handle_801F7F10 related;};
extern "C" {extern Effect*lbl_80377694;signed char fn_80255618(Effect*);void fn_802554F4(Effect*);TargetReturn_8005C52C fn_8024BDA0(void*,const TargetName&);}

extern "C" void fn_8005C52C(EffectOwner* self) {
    void* resource = resolve(((TargetRelated*)resolve(self->related))->handle);
    TargetName name(lbl_80378608);
    resource = resolve(fn_8024BDA0(resource, name));
    if (lbl_80377694 && fn_80255618(lbl_80377694)) {
        lbl_80377694->prepare();
        lbl_80377694->apply((EffectResource*)resolve(self->target), resource);
        fn_802554F4(lbl_80377694);
    }
}
