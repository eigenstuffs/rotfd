/* Merged translation unit: Game/scalar_constant_80378390.c, part_8002FBD0, Game/leaf_800309F8.c, Game/owner_handle_selection_80030A08.cpp, Game/early_scene_transition_controls_80030E9C.cpp, Game/short_control_delegate_8003125C.cpp, Game/leaf_80031288.c, Game/engine_callback_forward_80031290.cpp, Game/engine_handle_value_setup_800312D4.cpp, Game/leaf_80031324.c, Game/scene_resource_transition_80031328.cpp, Game/leaf_80031650.c, part_80031654, Game/scene_event_controls_80031740.cpp, Game/engine_scene_setup_more_80031CB0.cpp, Game/scene_handle_mode_selector_80031D68.cpp, Game/scene_handle_mode_selector_80032374.cpp, Game/scene_option_selectors_80032980.cpp, Game/early_scene_handle_event_selector_8003387C.cpp, part_80033F68. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();Handle_801F7F10(int){bits.index=0;bits.tag=0;}~Handle_801F7F10();};
struct Manager;
namespace A{struct Manager;struct Scene;struct Registry;struct ModeControl;}
namespace B{struct Manager;struct Scene;struct UI;}
namespace C{struct Manager;struct Scene;struct UI;}
namespace D{struct Manager;struct Scene;struct UI;}
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);
extern struct GContext{char unknown00[0x110];void*logger;char unknown114[4];
union{Manager*manager;A::Manager*managerA;B::Manager*managerB;C::Manager*managerC;D::Manager*managerD;};char unknown11C[8];
union{A::Scene*sceneA;B::Scene*sceneB;C::Scene*sceneC;D::Scene*sceneD;};char unknown128[0x14];
union{A::Registry*registryA;void*groups;};char unknown140[0x18];A::ModeControl*modeA;char unknown15C[8];
union{B::UI*uiB;C::UI*uiC;D::UI*uiD;};}lbl_801E9D24;}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct TransitionZero_30E9C:Handle_801F7F10{TransitionZero_30E9C(){word=0;}~TransitionZero_30E9C(){}};
struct Handle_80020C04:TransitionZero_30E9C{Handle_80020C04(){word=0;}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct TransitionZero1_31328:Handle_801F7F10{TransitionZero1_31328(){word=0;}~TransitionZero1_31328(){}};struct TransitionZero2_31328:TransitionZero1_31328{TransitionZero2_31328(){word=0;}~TransitionZero2_31328(){}};struct TransitionZero3_31328:TransitionZero2_31328{TransitionZero3_31328(){word=0;}~TransitionZero3_31328(){}};
struct Handle_8002DE2C:TransitionZero3_31328 {Handle_8002DE2C(){word=0;}~Handle_8002DE2C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
#pragma readonly_strings on
/* ---- part_8002FBD0 ---- */
namespace A {
/* Pause/menu text token formatter (fn_8002FBD0): maps a hashed token name to
 * a formatted value in the shared text buffer lbl_802F4108. Strings are
 * addressed from the translation unit string base lbl_8029A0C0. */

struct NameHash {
    Word value;
    NameHash(const char*);
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Node {
    char unknown00[0x84]; int count84; char unknown88[0x28]; Handle_801F7F10* linkB0;
    char unknownB4[0x188 - 0xB4]; unsigned int kind188; Word text[6];
};
struct Owner { char unknown00[0x2EC]; signed char flag2EC; signed char flag2ED; };
struct Save;
struct Scene { char unknown00[0x15058]; Owner* owner; Save* save; };
struct Registry { char unknown00[0x1C]; Handle_801F7F10* handle; };
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
    virtual void setA(float); virtual float getA(); virtual void setB(float); virtual float getB();
};

struct Self { char unknown00[0x7C]; Handle_801F7F10 target; };
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
Word fn_801F7EB8(const Handle_801F7F10*);
Word fn_801F948C(void*, const char*);
extern const char lbl_8029A0C0[];
extern char lbl_802F4108[];
int sprintf(char*, const char*, ...);
int fn_80055DA8(Owner*);
int fn_80055DB0(Owner*);
int fn_80055DB8(Owner*);
int fn_80055CD0(Owner*, unsigned int);
int fn_80055D30(Owner*, unsigned int);
int fn_80055CF0(Owner*, unsigned int);
int fn_80055D50(Owner*, unsigned int);
int fn_80055D10(Owner*, unsigned int);
int fn_80055D70(Owner*, unsigned int);
const char* fn_800B3E00(Node*, Word);
const char* fn_800B3C8C(Node*);
int* fn_800E8738(Save*);
extern const char lbl_8037836C[8], lbl_80378374[8], lbl_8037837C[4], lbl_80378380[8];
}

inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
inline Node* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.managerA;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline Node* pantsNode() {
    Handle_8002B67C handle(*lbl_801E9D24.registryA->handle);
    if (fn_801F7EB8(&handle)) {
        Handle_801F7F10* link = resolve(handle)->linkB0;
        if (fn_801F7EB8(link)) return resolve(*link);
    }
    return 0;
}


inline Node* resolveB(const Handle_801F7F10& h) {
    signed char tag = h.bits.tag;
    Manager* m = lbl_801E9D24.managerA;
    int index = h.bits.index;
    signed char entryTag = m->entries[index].getTag();
    return entryTag == tag ? m->entries[index].object : 0;
}
#define TASK(i) Node* node = resolveB(self->target); sprintf(lbl_802F4108, "%s", fn_800B3E00(node, resolveB(self->target)->text[i]));
#define RATIO2 float ratio = 1.0f; if (0.0f != total) { ratio = have / total; if (ratio > 1.0f) ratio = 1.0f; } ratio *= 100.0f;

extern "C" char* fn_8002FBD0(Self* self, const NameHash* key) {
    const char* strings = lbl_8029A0C0;
    lbl_802F4108[0] = 0;
    Owner* owner = lbl_801E9D24.sceneA->owner;
    if (*key == NameHash(strings + 0x1C0)) {
        sprintf(lbl_802F4108, lbl_8037836C, fn_80055DA8(owner));
    } else if (*key == NameHash(strings + 0x1CC)) {
        sprintf(lbl_802F4108, lbl_80378374, fn_80055DB0(owner));
    } else if (*key == NameHash(strings + 0x1D8)) {
        sprintf(lbl_802F4108, lbl_80378374, fn_80055DB8(owner));
    } else if (*key == NameHash(strings + 0x1E8)) {
        sprintf(lbl_802F4108, lbl_8037837C, pantsNode()->count84);
    } else if (*key == NameHash(lbl_80378380)) {
        float have = fn_80055CD0(owner, resolve(self->target)->kind188);
        float total = fn_80055D30(owner, resolve(self->target)->kind188);
        float ratio = 0.0f;
        if (0.0f != total) {
            ratio = have / total;
            if (ratio > 1.0f) ratio = 1.0f;
            ratio *= 100.0f;
        }
        sprintf(lbl_802F4108, "%d%%", (int)ratio);
    } else if (*key == NameHash("JELLIES")) {
        float have = fn_80055CF0(owner, resolve(self->target)->kind188);
        float total = fn_80055D50(owner, resolve(self->target)->kind188);
        RATIO2
        sprintf(lbl_802F4108, "%d%%", (int)ratio);
    } else if (*key == NameHash(strings + 0x1F4)) {
        float have = fn_80055D10(owner, resolve(self->target)->kind188);
        float total = fn_80055D70(owner, resolve(self->target)->kind188);
        RATIO2
        sprintf(lbl_802F4108, "%d%%", (int)ratio);
    } else if (*key == NameHash(strings + 0x200)) {
        TASK(0)
    } else if (*key == NameHash(strings + 0x20C)) {
        TASK(1)
    } else if (*key == NameHash(strings + 0x218)) {
        TASK(2)
    } else if (*key == NameHash(strings + 0x224)) {
        TASK(3)
    } else if (*key == NameHash(strings + 0x230)) {
        TASK(4)
    } else if (*key == NameHash(strings + 0x23C)) {
        TASK(5)
    } else if (*key == NameHash("WORLD")) {
        sprintf(lbl_802F4108, "%s", fn_800B3C8C(resolve(self->target)));
    } else if (*key == NameHash(strings + 0x248)) {
        { float v = 10.0f * lbl_801E9D24.modeA->getA(); sprintf(lbl_802F4108, "%0.0f", v); }
    } else if (*key == NameHash(strings + 0x258)) {
        { float v = 10.0f * lbl_801E9D24.modeA->getB(); sprintf(lbl_802F4108, "%0.0f", v); }
    } else if (*key == NameHash(strings + 0x268)) {
        if (lbl_801E9D24.sceneA->owner->flag2EC) sprintf(lbl_802F4108, "%s", "On");
        else sprintf(lbl_802F4108, "%s", "Off");
    } else if (*key == NameHash(strings + 0x278)) {
        if (lbl_801E9D24.sceneA->owner->flag2ED) sprintf(lbl_802F4108, "%s", "Mono");
        else sprintf(lbl_802F4108, "%s", "Stereo");
    } else if (*key == NameHash("LOAD_1")) {
        sprintf(lbl_802F4108, "%s", fn_800E8738(lbl_801E9D24.sceneA->save)[0]);
    } else if (*key == NameHash("LOAD_2")) {
        sprintf(lbl_802F4108, "%s", fn_800E8738(lbl_801E9D24.sceneA->save)[1]);
    } else if (*key == NameHash("LOAD_3")) {
        sprintf(lbl_802F4108, "%s", fn_800E8738(lbl_801E9D24.sceneA->save)[2]);
    } else if (*key == NameHash("SAVE_1")) {
        sprintf(lbl_802F4108, "%s", fn_800E8738(lbl_801E9D24.sceneA->save)[0]);
    } else if (*key == NameHash("SAVE_2")) {
        sprintf(lbl_802F4108, "%s", fn_800E8738(lbl_801E9D24.sceneA->save)[1]);
    } else if (*key == NameHash("SAVE_3")) {
        sprintf(lbl_802F4108, "%s", fn_800E8738(lbl_801E9D24.sceneA->save)[2]);
    }
    return lbl_802F4108;
}

}
/* ---- Game/leaf_800309F8.c ---- */
namespace leaf_800309F8 {
extern "C" {


float fn_800309F8(void) { return 1.0f; }

float fn_80030A00(void) { return 1.0f; }

}

}

/* ---- Game/owner_handle_selection_80030A08.cpp ---- */
namespace B {
/* Owner handle selection update; linker discards the weak inline handle destructor copy. */

struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void s18();virtual void s1C();virtual void s20();virtual void s24();virtual void s28();virtual void s2C();virtual void s30();virtual void s34();virtual void s38();virtual void s3C();virtual void s40();virtual void select(int);virtual void activate();char unknown0C[0x46-0xC];unsigned short count;};
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct SceneOwner{char unknown00[0xF0];int keyF0;};
struct Scene{char unknown00[0x15058];SceneOwner*owner;};
struct UI{char unknown00[0x1C];int*modes;const int&modeRef(int i)const{return modes[i];}};

extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);Word fn_801F7EB8(const Handle_801F7F10*);}

struct Owner{Word unknown00;Handle_801F7F10 self;char unknown08[0x64-0x8];int selected,mode;char unknown6C[4];Handle_801F7F10 h70;char unknown74[8];Handle_801F7F10 h7C;};
extern "C"{extern int lbl_803777B8;extern Word lbl_803777BC,lbl_803777B0;void fn_800B6C84(UI*,int,Word);void fn_800B6DA8(UI*,Word,int,const Handle_80020478&);void fn_800B6F70(UI*,Word,int,const Handle_80020478&);void fn_800B3C68(Node*,int);signed char fn_8021CDAC(Node*,int);}
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.managerB;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline void showFirst(Owner*self){const Handle_801F7F10&source=self->self;fn_800B6DA8(lbl_801E9D24.uiB,lbl_803777BC,0,Handle_80020478(source));}
inline void showSecond(Owner*self){const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.uiB,lbl_803777BC,0,Handle_80020478(source));}
extern "C" void fn_80030A08(Owner*self,const Handle_801F7F10&h,int selected){
 if(resolve(h)==resolve(self->h7C))return;
 if(resolve(Handle_801F7F10(0))==resolve(self->h7C)){
  self->selected=selected;
  if(lbl_803777B8==lbl_801E9D24.uiB->modeRef(0))self->mode=lbl_803777B8;
  fn_800B6C84(lbl_801E9D24.uiB,0,lbl_803777BC);
  showFirst(self);
  if(fn_801F7EB8(&self->h70)){SceneOwner*owner=lbl_801E9D24.sceneB->owner;fn_800B3C68(resolve(self->h70),owner->keyF0);}
 }else resolve(self->h7C)->activate();
 fn_801F86C8(lbl_801E9D24.manager,&self->h7C,-1);self->h7C.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);
 if(resolve(Handle_801F7F10(0))==resolve(self->h7C)){
  fn_800B6C84(lbl_801E9D24.uiB,0,lbl_803777B0);
  showSecond(self);
  self->selected=-1;
  return;
 }
 for(int i=0;i<resolve(self->h7C)->count;i++)if(fn_8021CDAC(resolve(self->h7C),i))break;
 resolve(self->h7C)->select(6);
}

}
/* ---- Game/early_scene_transition_controls_80030E9C.cpp ---- */
namespace u_early_scene_transition_controls_80030E9C_cpp {

extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}

struct Node{char unknown00[0xDC];int count;Word unknownE0;void*value;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct SoundPrefix{char unknown00[0x1C];};struct Sound:SoundPrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual void s11();virtual void reset(int,int,int);};
struct ModePrefix{char unknown00[0x7C];};struct Mode:ModePrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void reset(int);virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();virtual void s20();virtual void s21();virtual void s22();virtual void finish();};
struct UI{};struct SceneOwner{char unknown00[0x60];Handle_801F7F10 handle60;char unknown64[0x210-0x64];short state210;};struct Scene{char unknown00[0x15058];SceneOwner*owner;};
extern "C" struct Context{char unknown00[0x114];void*module;Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x154-0x128];Sound*sound;Mode*mode;char unknown15C[8];UI*ui;}lbl_801E9D24;
struct OwnerPrefix{char unknown00[8];};struct Owner:OwnerPrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void event(int);char unknown0C[0x60-0xC];Handle_801F7F10 handle60;int selected,mode;Handle_801F7F10 handle6C;char unknown70[0x88-0x70];Handle_801F7F10 handle88,handle8C,handle90;unsigned char active;};
extern "C" {void fn_800B720C(UI*,int);void fn_800B6C84(UI*,int,Word);Handle_8002B67C fn_800312D4(Owner*);void fn_80030A08(Owner*,const Handle_801F7F10&,int);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;const Entry*entries=lbl_801E9D24.manager->entries;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}



extern "C"{extern Word lbl_803777B4;void fn_800B3318(int);void fn_800A7840(Node*);void fn_800A84D8(Node*);void fn_80057294(SceneOwner*);void fn_80208C7C();void fn_80201F10(Node*,void*);void fn_8003125C(void*,void*,const Handle_80020C04&);}
extern "C" int fn_80030E9C(Owner*self,int selected,int mode){
 SceneOwner*owner=lbl_801E9D24.scene->owner;
 fn_800B720C(lbl_801E9D24.ui,1);lbl_801E9D24.sound->reset(0,0,0);
 signed char reset=1;if(lbl_801E9D24.scene->owner->state210==1)reset=0;
 switch(mode){
 case 0:fn_80030A08(self,self->handle6C,selected);break;
 case 1:fn_80030A08(self,self->handle88,selected);break;
 case 2:fn_80030A08(self,self->handle8C,selected);break;
 case 3:fn_80030A08(self,self->handle90,selected);break;
 case 4:fn_80030A08(self,self->handle6C,selected);fn_800B3318(1);break;
 }
 for(int i=0;i<resolve(fn_800312D4(self))->count;++i)if(i!=selected)fn_800B6C84(lbl_801E9D24.ui,i,lbl_803777B4);
 self->event(13);fn_800A7840(resolve(owner->handle60));fn_800A84D8(resolve(owner->handle60));
 lbl_801E9D24.mode->finish();lbl_801E9D24.mode->reset(7);
 if(reset)fn_80057294(lbl_801E9D24.scene->owner);
 fn_80208C7C();self->active=1;
 void*value=resolve(fn_800312D4(self))->value;
 fn_80201F10(resolve(fn_800312D4(self)),value);
 fn_8003125C(lbl_801E9D24.module,value,Handle_80020C04());return 1;
}

}
/* ---- Game/short_control_delegate_8003125C.cpp ---- */
namespace short_control_delegate_8003125C {
struct Handle;struct Record{char opaque00[0x4C];};extern "C"void fn_801E2E04(Record*,const Handle&);extern "C"void fn_8003125C(Record*self,int index,const Handle&value){fn_801E2E04(&self[index],value);}

}

/* ---- Game/leaf_80031288.c ---- */
namespace leaf_80031288 {
extern "C" {

void fn_80031288(void) { }

void fn_8003128C(void) { }

}

}

/* ---- Game/engine_callback_forward_80031290.cpp ---- */
namespace engine_callback_forward_80031290 {
extern "C" {
    void fn_8025ED38(void*, void*, void*);
    extern void* lbl_803775E0;
    extern void* lbl_80378028;
}

extern "C" void fn_80031290(void* self, void* value) {
    fn_8025ED38(self, value, lbl_803775E0);
    fn_8025ED38(self, value, lbl_80378028);
}

}

/* ---- Game/engine_handle_value_setup_800312D4.cpp ---- */
namespace engine_handle_value_setup_800312D4 {
typedef unsigned long u32;

struct Manager;
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[0x124-0x11C];void*scene;};
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct H1:Handle_801F7F10 {H1(){word=0;}~H1();};
struct Handle_80020834:H1 {Handle_80020834(){word=0;}~Handle_80020834();};
struct H3:Handle_80020834 {H3(){word=0;}~H3();};
struct Handle_8004A72C:H3 {Handle_8004A72C(){word=0;}~Handle_8004A72C();};
struct H5:Handle_8004A72C {H5(){word=0;}~H5();};
struct H6:H5 {H6(){word=0;}~H6();};
struct H7:H6 {H7(){word=0;}~H7();};
struct Handle_8004099C:H7 {Handle_8004099C(){word=0;}~Handle_8004099C();};
struct Owner {char unknown00[0x60];Handle_801F7F10 handle60;};
struct Copy:Handle_801F7F10 {Copy(const Handle_801F7F10&value){word=value.word;fn_801F86C8(lbl_801E9D24.manager,&value,1);}~Copy();};
extern "C" Copy fn_800312D4(const Owner*self){return Copy(self->handle60);}

}

/* ---- Game/leaf_80031324.c ---- */
namespace leaf_80031324 {
extern "C" {

void fn_80031324(void) { }

}

}

/* ---- Game/scene_resource_transition_80031328.cpp ---- */
namespace u_scene_resource_transition_80031328_cpp {

extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}


struct Node{char unknown00[0xDC];int count;Word unknownE0;void*value;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct SoundPrefix{char unknown00[0x1C];};struct Sound:SoundPrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual void s11();virtual void reset(int,int,int);};
struct ModePrefix{char unknown00[0x7C];};struct Mode:ModePrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void reset(int);virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void finish();};
struct UI{};struct SceneOwner{char unknown00[0x60];Handle_801F7F10 handle60;};struct Scene{char unknown00[0x15058];SceneOwner*owner;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x154-0x128];Sound*sound;Mode*mode;char unknown15C[8];UI*ui;}lbl_801E9D24;
struct Owner{char unknown00[0x60];Handle_801F7F10 handle60;int selected,mode;char unknown6C[0x7C-0x6C];Handle_801F7F10 handle7C;char unknown80[0x94-0x80];unsigned char active;};
extern "C" {void fn_800B720C(UI*,int);void fn_8025ECD8(Owner*,int);void fn_800B6C84(UI*,int,Word);extern Word lbl_803777B0;extern int lbl_803777B8;Handle_8002B67C fn_800312D4(Owner*);void fn_80030A08(Owner*,const Handle_8002DE2C&,int);Node*fn_801F7EB8(const Handle_801F7F10*);void fn_800A7798(Node*);void fn_80057100(SceneOwner*,int);void fn_80208C24();void fn_80201F94(Node*,void*);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;const Entry*entries=lbl_801E9D24.manager->entries;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}
extern "C" int fn_80031328(Owner*self){
 lbl_801E9D24.sound->reset(0,0,0);fn_800B720C(lbl_801E9D24.ui,0);fn_8025ECD8(self,13);
 for(int i=0;i<resolve(fn_800312D4(self))->count;++i)if(i!=self->selected)fn_800B6C84(lbl_801E9D24.ui,i,lbl_803777B0);
 if(self->mode==lbl_803777B8){fn_80030A08(self,Handle_8002DE2C(),0);fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777B8);}else if(fn_801F7EB8(&self->handle7C))fn_80030A08(self,Handle_8002DE2C(),0);
 fn_800A7798(resolve(lbl_801E9D24.scene->owner->handle60));lbl_801E9D24.mode->finish();lbl_801E9D24.mode->reset(0);fn_80057100(lbl_801E9D24.scene->owner,-1);fn_80208C24();self->active=0;
 void*value=resolve(fn_800312D4(self))->value;fn_80201F94(resolve(fn_800312D4(self)),value);return 1;
}

}
/* ---- Game/leaf_80031650.c ---- */
namespace leaf_80031650 {
extern "C" {

void fn_80031650(void) { }

}

}

/* ---- part_80031654 ---- */
namespace u_part_80031654 {


struct Scene_80031654;
struct Menu_80031654;
struct Context_80031654{char unknown00[0x124];char*world;char unknown128[0x14];void*groups;char unknown140[0x24];char*state;};
extern "C"{
extern Context_80031654 lbl_801E9D24;
Handle_8002B67C fn_800312D4(Scene_80031654*);
int fn_801FF18C(void*,const Handle_801F7F10*);
void fn_80057294(Menu_80031654*);
void fn_80031328(Scene_80031654*);
void fn_801FEE10(void*,int);
int fn_800596E4(Menu_80031654*,short,short);
void fn_802603A0(void*,int,Menu_80031654*,float);
void fn_80031654(Scene_80031654*self,int a,int b){
    Menu_80031654*menu;
    int group=fn_801FF18C(lbl_801E9D24.groups,&fn_800312D4(self));
    fn_80057294(*(Menu_80031654**)(lbl_801E9D24.world+0x15058));
    fn_80031328(self);
    fn_801FEE10(lbl_801E9D24.groups,group);
    menu=*(Menu_80031654**)(lbl_801E9D24.world+0x15058);
    int value=fn_800596E4(menu,(short)a,(short)b);
    lbl_801E9D24.state[0x2d]=0;
    fn_802603A0(lbl_801E9D24.world,0x56,menu,(float)value);
}
}

}
/* ---- Game/scene_event_controls_80031740.cpp ---- */
namespace C {
/* Scene event controls (fn_80031740): event gates C2/C4/C5 toggle the agent's
 * stream selection and the primary scene flag; E0/CF reset whichever of the
 * third/first handles currently resolves to the same node as the second.
 * The temporaries live in small inline helpers: that both orders the stack
 * slots (C2 handle 0x14, C4 name 0x10, C5 name 0xC, C5 handle 0x8) and gives
 * the original saved-register coloring. The resolve helper reads the handle
 * tag before the manager and index (signed char comparison). */

struct Name { Word word; Name(const char*); };
struct Resource { char unknown00[0x80]; Name name; };
struct Node { char unknown00[0x28]; short selected; char unknown2A[0x16]; Resource** resources; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Input { Word unknown00; Handle_801F7F10 handle; };
struct Agent { char unknown00[0x24]; Input* input; char unknown28[0x5F8]; Word selected; };
struct Primary { char unknown00[0x319]; unsigned char active; };
struct Scene { char unknown00[0x15058]; Primary* primary; Input* input; Agent* agent; };
struct UI { char unknown00[0x1C]; int* modes; const int& modeRef(int i) const { return modes[i]; } };

extern "C" { extern char lbl_801EF5C8[]; void fn_801EF610(void*, void*);  }

struct Owner { char unknown00[0x78]; Handle_801F7F10 first, second; char unknown80[0xC]; Handle_801F7F10 third; };
extern "C" {
signed char fn_8025E9FC(Owner*, int);
extern int lbl_803777C4, lbl_803777BC;
void fn_800B6C84(UI*, int, Word);
void fn_800B6F70(UI*, Word, int, const Handle_80020478&);
void fn_800C2700(Agent*);
void fn_8003FA74(Primary*);
void fn_800B50DC(Node*, int, int, int, float);
void fn_800B5134(Node*, int);
Word fn_801F948C(Name*, const char*);
extern const char lbl_8029A348[];
extern const float lbl_80378410;
}
inline Name::Name(const char* s) { word = fn_801F948C(this, s); }
inline Node* resolve(const Handle_801F7F10& h) {
    signed char tag = h.bits.tag;
    Manager* m = lbl_801E9D24.managerC;
    int index = h.bits.index;
    signed char entryTag = m->entries[index].getTag();
    return entryTag == tag ? m->entries[index].object : 0;
}
inline bool same(const Handle_801F7F10& a, const Handle_801F7F10& b) { Node* first = resolve(a); Node* second = resolve(b); return first == second; }
inline bool isTarget(Node* n) { Name selected = n->resources[n->selected]->name; return selected.word == Name(lbl_8029A348).word; }
inline void showAgent(Agent* a) {
    fn_800B6C84(lbl_801E9D24.uiC, 0, a->selected);
    fn_800B6F70(lbl_801E9D24.uiC, lbl_803777C4, 0, Handle_80020478(lbl_801E9D24.sceneC->input->handle));
    fn_800C2700(a);
}
inline void hideAgent() {
    fn_800B6F70(lbl_801E9D24.uiC, lbl_803777C4, 0, Handle_80020478(lbl_801E9D24.sceneC->agent->input->handle));
    fn_800B6C84(lbl_801E9D24.uiC, 0, lbl_803777BC);
    fn_800C2700(lbl_801E9D24.sceneC->agent);
}

extern "C" void fn_80031740(Owner* self) {
    if (fn_8025E9FC(self, 0xC2) && lbl_803777C4 == lbl_801E9D24.uiC->modeRef(0)) showAgent(lbl_801E9D24.sceneC->agent);
    if (fn_8025E9FC(self, 0xC4)) {
        if (isTarget(resolve(self->second))) { Primary* primary = lbl_801E9D24.sceneC->primary; primary->active = 1; fn_8003FA74(primary); }
    } else if (fn_8025E9FC(self, 0xC5)) {
        if (isTarget(resolve(self->second))) hideAgent();
    }
    if (fn_8025E9FC(self, 0xE0)) {
        if (same(self->third, self->second)) fn_800B50DC(resolve(self->third), 0, 0, 100, lbl_80378410);
        else if (same(self->first, self->second)) fn_800B50DC(resolve(self->first), 0, 0, 100, lbl_80378410);
    }
    if (fn_8025E9FC(self, 0xCF)) {
        if (same(self->third, self->second)) fn_800B5134(resolve(self->third), 0);
        else if (same(self->first, self->second)) fn_800B5134(resolve(self->first), 0);
    }
}

}
/* A declaration here makes mwcc emit the deferred fn_80031740 before fn_80031CB0. */
struct EmitOrder_80031740;
/* ---- Game/engine_scene_setup_more_80031CB0.cpp ---- */
namespace engine_scene_setup_more_80031CB0 {
extern "C" unsigned int fn_80031CB0(void*,unsigned int value){switch(value){case 0:value=5;break;case 3:value=0;break;case 6:value=3;break;case 1:value=6;break;case 2:value=1;break;case 4:value=2;break;case 5:value=4;break;}return value;}
extern "C" unsigned int fn_80031D0C(void*,unsigned int value){switch(value){case 0:value=3;break;case 3:value=6;break;case 6:value=1;break;case 1:value=2;break;case 2:value=4;break;case 4:value=5;break;case 5:value=0;break;}return value;}

}

/* ---- Game/scene_handle_mode_selector_80031D68.cpp ---- */
namespace scene_handle_mode_selector_80031D68 {
/* Scene callback event selector with handle-specific mode transition (fn_80031D68).
 * Shares the callback dispatch shape of fn_8003387C. The member-pointer records
 * at lbl_802B1918+0x80 (0x802B1998) and the compiler switch table that follows
 * them (0x802B19D4) are original data of this translation unit. */
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };

struct NameHash {
    Word value;
    NameHash(const char*);
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    char unknown00[0x28]; short index28; char unknown2A[0x16]; Mode** modes;
    char unknown44[0x2C]; Handle current; char unknown74[8]; Handle target;
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Scene { char unknown00[0x15058]; Node* owner; };
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
};
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x30]; ModeControl* mode;
} lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    signed char tag = h.bits.tag;
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    signed char entryTag = m->entries[index].getTag();
    return entryTag == tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
inline Node* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle_801F7F10& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A318[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0x80]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern signed char lbl_80377788;
extern const char lbl_8029A354[];
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
void fn_80059340(Node*, int);
void fn_80057100(Node*, int);
signed char fn_800B3F10(Node*);
void fn_8021D26C(Node*);
}
inline bool isMode(Node* n, const NameHash& h) { return n->modes[n->index28]->name == h; }

extern "C" MemberPointer lbl_802B1998[5] = { {0, 0x74, 8}, {0, 0x74, 8}, {0, 0x74, 8}, {0, 0x74, 8}, {0, 0x74, 8} };

extern "C" int fn_80031D68(Node* self, int event, Callback* callback) {
    const SelectorPool* members = &lbl_802B1918;
    int result = 1;
    switch (event) {
    case 0: fn_8025EF34(self, members->entries[0], -1); return 1;
    case 1: fn_8025EEB4(self, members->entries[1]); return 1;
    case 2: fn_8025EB70(self, members->entries[2]); return 1;
    case 3:
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        return 0;
    case 4:
        if (callback) return (signed char)(callback->flags & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback) return (signed char)(callback->flags & 1);
        return 0;
    case 5: return 1;
    case 6: if (callback) return callback->index; return -9999;
    }
    lbl_8037808C = 0; lbl_80378090 = 0; lbl_80378094 = -1;
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, lbl_8029A354);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x58); break;
    case 15:
        if (equal(self->current, self->target)) {
            if (fn_800B3F10(resolve(self->target))) {
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                for (int i = 0; i < 5; i++) { if (!fn_800B3F10(resolve(self->target))) break; }
            } else fn_80059340(lbl_801E9D24.scene->owner, 0x27);
        } else if (!lbl_80377788) {
            if (!equal(Handle_801F7F10(0), self->target)) {
                fn_8021D26C(resolve(self->target));
                int mode = 15;
                if (isMode(resolve(self->target), NameHash(lbl_8029A318))) mode ^= 8;
                lbl_801E9D24.mode->reset(mode);
                if (isMode(resolve(self->target), NameHash(lbl_8029A318))) fn_80057100(lbl_801E9D24.scene->owner, -1);
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
            }
        }
        break;
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

}

/* ---- Game/scene_handle_mode_selector_80032374.cpp ---- */
namespace scene_handle_mode_selector_80032374 {
/* Scene callback event selector with handle-specific mode transition (fn_80032374).
 * Shares the callback dispatch shape of fn_8003387C. The member-pointer records
 * at lbl_802B1918+0xD8 (0x802B19F0) and the compiler switch table that follows
 * them (0x802B1A2C) are original data of this translation unit. */
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };

struct NameHash {
    Word value;
    NameHash(const char*);
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    char unknown00[0x28]; short index28; char unknown2A[0x16]; Mode** modes;
    char unknown44[0x2C]; Handle current; char unknown74[8]; Handle target;
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Scene { char unknown00[0x15058]; Node* owner; };
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
};
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x30]; ModeControl* mode;
} lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    signed char tag = h.bits.tag;
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    signed char entryTag = m->entries[index].getTag();
    return entryTag == tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
inline Node* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle_801F7F10& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A318[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0xD8]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern signed char lbl_80377788;
extern const char lbl_8029A354[];
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
void fn_80059340(Node*, int);
void fn_80057100(Node*, int);
signed char fn_800B3E58(Node*);
void fn_8021CFBC(Node*);
}
inline bool isMode(Node* n, const NameHash& h) { return n->modes[n->index28]->name == h; }

extern "C" MemberPointer lbl_802B19F0[5] = { {0, 0x78, 8}, {0, 0x78, 8}, {0, 0x78, 8}, {0, 0x78, 8}, {0, 0x78, 8} };

extern "C" int fn_80032374(Node* self, int event, Callback* callback) {
    const SelectorPool* members = &lbl_802B1918;
    int result = 1;
    switch (event) {
    case 0: fn_8025EF34(self, members->entries[0], -1); return 1;
    case 1: fn_8025EEB4(self, members->entries[1]); return 1;
    case 2: fn_8025EB70(self, members->entries[2]); return 1;
    case 3:
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        return 0;
    case 4:
        if (callback) return (signed char)(callback->flags & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback) return (signed char)(callback->flags & 1);
        return 0;
    case 5: return 1;
    case 6: if (callback) return callback->index; return -9999;
    }
    lbl_8037808C = 0; lbl_80378090 = 0; lbl_80378094 = -1;
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, lbl_8029A354);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x59); break;
    case 15:
        if (equal(self->current, self->target)) {
            if (fn_800B3E58(resolve(self->target))) {
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                for (int i = 0; i < 5; i++) { if (!fn_800B3E58(resolve(self->target))) break; }
            } else fn_80059340(lbl_801E9D24.scene->owner, 0x27);
        } else if (!lbl_80377788) {
            if (!equal(Handle_801F7F10(0), self->target)) {
                fn_8021CFBC(resolve(self->target));
                int mode = 15;
                if (isMode(resolve(self->target), NameHash(lbl_8029A318))) mode ^= 8;
                lbl_801E9D24.mode->reset(mode);
                if (isMode(resolve(self->target), NameHash(lbl_8029A318))) fn_80057100(lbl_801E9D24.scene->owner, -1);
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
            }
        }
        break;
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

}

/* ---- Game/scene_option_selectors_80032980.cpp ---- */
namespace scene_option_selectors_80032980 {
/* Scene option selectors and their mode-control helpers: one original source
 * file spanning 80032980..8003387C, with its member-pointer records and switch
 * tables in .data. Parts keep their local type views in separate namespaces. */
namespace option_selector_80032980 {
/* Scene callback event selector with option-menu handle transitions (fn_80032980).
 * Same dispatch shape as fn_80031D68/fn_8003387C. The member-pointer records at
 * lbl_802B1918+0x130 (0x802B1A48) and the two compiler switch tables that follow
 * (0x802B1A84 for the inlined fn_80031CB0 enum map, 0x802B1AA0 for the event
 * switch) are original data of this translation unit. Strings are addressed from
 * the translation unit string base lbl_8029A0C0. */
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct NameHash {
    Word value;
    NameHash(const char*);
    NameHash(const NameHash& o) : value(o.value) {}
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    char unknown00[0x28]; short index28; char unknown2A[0x16]; Mode** modes;
    char unknown44[0x2C]; Handle current; char unknown74[4]; Handle h78; Handle target;
    char unknown80[0xC]; Handle h8C; char unknown90[0xF8]; unsigned int kind188;
    void setKey(int key);
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Owner { char unknown00[0x2EC]; signed char flag2EC; signed char flag2ED; };
struct Scene { char unknown00[0x15058]; Owner* owner; };
struct ServicePrefix { char unknown00[0x1C]; };
struct Service : ServicePrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(int, int); virtual void v38(int, int, int);
};
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
    virtual void setA(float); virtual float getA(); virtual void setB(float); virtual float getB();
    char unknown80[0x408 - 0x80]; Word flags408;
    void setFlag(bool on) { if (on) flags408 |= 2; else flags408 &= ~2; }
};
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x2C]; Service* service; ModeControl* mode;
} lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A0C0[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0x130]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern int lbl_80377798;
extern const float lbl_80378410;
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
void fn_80059340(Owner*, int);
void fn_800B3C68(Node*, int);
void fn_80033040(Node*);
void fn_80055C88(Owner*, signed char);
}
inline void Node::setKey(int key) { fn_800B3C68(this, key); }
/* Inlined body of fn_80031CB0; original case order reproduces its table and layout. */
inline unsigned int convertKey(unsigned int value) {
    switch (value) {
    case 0: value = 5; break;
    case 3: value = 0; break;
    case 6: value = 3; break;
    case 1: value = 6; break;
    case 2: value = 1; break;
    case 4: value = 2; break;
    case 5: value = 4; break;
    }
    return value;
}
inline const NameHash& modeName(Node* n) { return n->modes[n->index28]->name; }

extern "C" MemberPointer lbl_802B1A48[5] = { {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8} };

extern "C" int fn_80032980(Node* self, int event, Callback* callback) {
    const char* strings = lbl_8029A0C0;
    const SelectorPool* members = &lbl_802B1918;
    int result = 1;
    switch (event) {
    case 0: fn_8025EF34(self, members->entries[0], -1); return 1;
    case 1: fn_8025EEB4(self, members->entries[1]); return 1;
    case 2: fn_8025EB70(self, members->entries[2]); return 1;
    case 3:
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        return 0;
    case 4:
        if (callback) return (signed char)(callback->flags & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback) return (signed char)(callback->flags & 1);
        return 0;
    case 5: return 1;
    case 6: if (callback) return callback->index; return -9999;
    }
    lbl_8037808C = 0; lbl_80378090 = 0; lbl_80378094 = -1;
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, strings + 0x294);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x5B); break;
    case 15: {
        if (lbl_80377798 > 0) { if (--lbl_80377798 < 1) lbl_80377798 = 29; }
        NameHash name = modeName(resolve(self->target));
        if (equal(self->current, self->target)) {
            resolve(self->target)->setKey(convertKey(resolve(self->target)->kind188));
            fn_80059340(lbl_801E9D24.scene->owner, 0x29);
        } else if (equal(self->h78, self->target) || equal(self->h8C, self->target)) {
            if (name == NameHash(strings + 0x248)) {
                float value = lbl_801E9D24.mode->getA() - lbl_80378410;
                /* The re-read keeps the shared constant's load short-lived, as the
                 * original 0.0f literal did. */
                if (value < 0.0f) value = 0.0f;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setA(value);
            } else if (name == NameHash(strings + 0x258)) {
                float value = lbl_801E9D24.mode->getB() - lbl_80378410;
                if (value < 0.0f) value = 0.0f;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setB(value);
            } else if (name == NameHash(strings + 0x268)) {
                fn_80033040(self);
            } else if (name == NameHash(strings + 0x278)) {
                Owner* owner = lbl_801E9D24.scene->owner;
                signed char value = !owner->flag2ED;
                fn_80055C88(owner, value);
                lbl_801E9D24.mode->setFlag(value);
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
            }
        }
        break;
    }
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
}
extern "C" void fn_80033038(void) { }
extern "C" void fn_8003303C(void) { }
namespace scene_setup_80033040 {
struct Owner{};struct Target{char opaque00[0x2EC];signed char enabled2EC;};struct Scene{char opaque00[0x15058];Target*first15058;};struct Prefix{char opaque00[0x1C];};struct Service:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34(int,int);virtual void v38(int,int,int);};
extern "C" struct Global{char opaque00[0x124];Scene*scene;char opaque128[0x2C];Service*service;}lbl_801E9D24;extern "C"{void fn_80059340(Target*,int);void fn_802073E8(Owner*,int,Owner*,float);extern const float lbl_80378414;}
extern "C" void fn_80033040(Owner*self){Target*t=lbl_801E9D24.scene->first15058;signed char enabled=!t->enabled2EC;t->enabled2EC=enabled;lbl_801E9D24.service->v34(0,enabled);fn_80059340(lbl_801E9D24.scene->first15058,0x29);lbl_801E9D24.service->v38(0,0,0);if(enabled)fn_802073E8(self,0xE0,self,lbl_80378414);else fn_802073E8(self,0xCF,self,lbl_80378414);}
}
extern "C" void fn_80033118(void) { }
namespace option_selector_8003311C {
/* Scene callback event selector with option-menu handle transitions (fn_8003311C).
 * Mirror of fn_80032980. The member-pointer records at lbl_802B1918+0x1A4
 * (0x802B1ABC) and the two compiler switch tables that follow (0x802B1AF8 for
 * the inlined fn_80031D0C enum map, 0x802B1B14 for the event switch) are
 * original data of this translation unit. Strings are addressed from
 * the translation unit string base lbl_8029A0C0. */
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct NameHash {
    Word value;
    NameHash(const char*);
    NameHash(const NameHash& o) : value(o.value) {}
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    char unknown00[0x28]; short index28; char unknown2A[0x16]; Mode** modes;
    char unknown44[0x2C]; Handle current; char unknown74[4]; Handle h78; Handle target;
    char unknown80[0xC]; Handle h8C; char unknown90[0xF8]; unsigned int kind188;
    void setKey(int key);
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Owner { char unknown00[0x2EC]; signed char flag2EC; signed char flag2ED; };
struct Scene { char unknown00[0x15058]; Owner* owner; };
struct ServicePrefix { char unknown00[0x1C]; };
struct Service : ServicePrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(int, int); virtual void v38(int, int, int);
};
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
    virtual void setA(float); virtual float getA(); virtual void setB(float); virtual float getB();
    char unknown80[0x408 - 0x80]; Word flags408;
    void setFlag(bool on) { if (on) flags408 |= 2; else flags408 &= ~2; }
};
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x2C]; Service* service; ModeControl* mode;
} lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A0C0[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0x1A4]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern int lbl_80377798;
extern const float lbl_80378410, lbl_80378414;
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
void fn_80059340(Owner*, int);
void fn_800B3C68(Node*, int);
void fn_802073E8(Node*, int, Node*, float);
void fn_80055C88(Owner*, signed char);
}
inline void Node::setKey(int key) { fn_800B3C68(this, key); }
/* Inlined body of fn_80031D0C; original case order reproduces its table and layout. */
inline unsigned int convertKey(unsigned int value) {
    switch (value) {
    case 0: value = 3; break;
    case 3: value = 6; break;
    case 6: value = 1; break;
    case 1: value = 2; break;
    case 2: value = 4; break;
    case 4: value = 5; break;
    case 5: value = 0; break;
    }
    return value;
}
/* Inlined body of fn_80033040 (defined between the two selectors). */
inline void toggle(Node* self) {
    Owner* t = lbl_801E9D24.scene->owner;
    signed char enabled = !t->flag2EC;
    t->flag2EC = enabled;
    lbl_801E9D24.service->v34(0, enabled);
    fn_80059340(lbl_801E9D24.scene->owner, 0x29);
    lbl_801E9D24.service->v38(0, 0, 0);
    if (enabled) fn_802073E8(self, 0xE0, self, lbl_80378414);
    else fn_802073E8(self, 0xCF, self, lbl_80378414);
}
inline const NameHash& modeName(Node* n) { return n->modes[n->index28]->name; }

extern "C" MemberPointer lbl_802B1ABC[5] = { {0, 0x80, 8}, {0, 0x80, 8}, {0, 0x80, 8}, {0, 0x80, 8}, {0, 0x80, 8} };

extern "C" int fn_8003311C(Node* self, int event, Callback* callback) {
    const char* strings = lbl_8029A0C0;
    const SelectorPool* members = &lbl_802B1918;
    int result = 1;
    switch (event) {
    case 0: fn_8025EF34(self, members->entries[0], -1); return 1;
    case 1: fn_8025EEB4(self, members->entries[1]); return 1;
    case 2: fn_8025EB70(self, members->entries[2]); return 1;
    case 3:
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        return 0;
    case 4:
        if (callback) return (signed char)(callback->flags & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback) return (signed char)(callback->flags & 1);
        return 0;
    case 5: return 1;
    case 6: if (callback) return callback->index; return -9999;
    }
    lbl_8037808C = 0; lbl_80378090 = 0; lbl_80378094 = -1;
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, strings + 0x294);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x5A); break;
    case 15: {
        if (lbl_80377798 > 0) { if (++lbl_80377798 > 29) lbl_80377798 = 1; }
        NameHash name = modeName(resolve(self->target));
        if (equal(self->current, self->target)) {
            resolve(self->target)->setKey(convertKey(resolve(self->target)->kind188));
            fn_80059340(lbl_801E9D24.scene->owner, 0x29);
        } else if (equal(self->h78, self->target) || equal(self->h8C, self->target)) {
            if (name == NameHash(strings + 0x248)) {
                float value = lbl_801E9D24.mode->getA();
                value += lbl_80378410;
                /* The re-read keeps the shared constant's load short-lived, as the
                 * original 1.0f literal did. */
                if (value > 1.0f) value = 1.0f;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setA(value);
            } else if (name == NameHash(strings + 0x258)) {
                float value = lbl_801E9D24.mode->getB();
                value += lbl_80378410;
                if (value > 1.0f) value = 1.0f;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setB(value);
            } else if (name == NameHash(strings + 0x268)) {
                toggle(self);
            } else if (name == NameHash(strings + 0x278)) {
                Owner* owner = lbl_801E9D24.scene->owner;
                signed char value = !owner->flag2ED;
                fn_80055C88(owner, value);
                lbl_801E9D24.mode->setFlag(value);
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
            }
        }
        break;
    }
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
}

}

/* ---- Game/early_scene_handle_event_selector_8003387C.cpp ---- */
namespace early_scene_handle_event_selector_8003387C {
/* Scene callback dispatch and handle-specific selection transitions. */
struct MemberPointer { Word a,b,c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union {Word value;struct{signed int tag:8,index:24;}bits;}; };
struct Node { char unknown00[0x64]; Word transition; Word unknown68; Handle current,alternate,group,subgroup,target,subobject,other,state,previous,mode; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag()const{return tag;} };
struct Manager { int count,capacity; Entry* entries; };
struct Scene { char unknown00[0x15058]; Node* owner; };
extern "C" struct Context { char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene; }lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline bool equal(const Handle&left,const Handle&right){Node*first=resolve(left);return first==resolve(right);}
extern "C" {
extern const struct SelectorPool {char unknown00[0x218];MemberPointer entries[5];}lbl_802B1918;
extern Word lbl_8037808C,lbl_80378090;extern int lbl_80378094;extern signed char lbl_80377788;
extern const char lbl_8029A354[];
void fn_8025EF34(Node*,MemberPointer,int);void fn_8025EEB4(Node*,MemberPointer);void fn_8025EB70(Node*,MemberPointer);Callback*fn_8025F074(Node*,MemberPointer);
void fn_8025F4F4(Callback*,int,const char*);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,Word);void fn_8025F620(Callback*,Word);signed char fn_8025E9FC(Node*,int);
void fn_80057294(Node*);void fn_80059340(Node*,int);void fn_80031328(Node*);void fn_80030A08(Node*,const Handle*,Word);
}
extern "C" MemberPointer lbl_802B1B30[5]={{0,0x84,8},{0,0x84,8},{0,0x84,8},{0,0x84,8},{0,0x84,8}};
extern "C" int fn_8003387C(Node*self,int event,Callback*callback){
 const SelectorPool*members=&lbl_802B1918;int result=1;
 switch(event){
 case 0:fn_8025EF34(self,members->entries[0],-1);return 1;
 case 1:fn_8025EEB4(self,members->entries[1]);return 1;
 case 2:fn_8025EB70(self,members->entries[2]);return 1;
 case 3:if(callback)return(signed char)((callback->flags>>2)&1);callback=fn_8025F074(self,members->entries[3]);if(callback)return(signed char)((callback->flags>>2)&1);return 0;
 case 4:if(callback)return(signed char)(callback->flags&1);callback=fn_8025F074(self,members->entries[4]);if(callback)return(signed char)(callback->flags&1);return 0;
 case 5:return 1;
 case 6:if(callback)return callback->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(event==8||event==7)fn_8025F4F4(callback,13,lbl_8029A354);
 if(event==11&&callback->index==-1)return 1;
 fn_8025F658(callback,lbl_80378090);
 int action;if(event>=14)action=event+callback->index*2;else action=event;
 switch(action){
 case 7:fn_8025F694(callback,lbl_8037808C);
 case 8:break;
 case 14:result=fn_8025E9FC(self,0x5D);break;
 case 15:
  if(!lbl_80377788)fn_80057294(lbl_801E9D24.scene->owner);
  if(equal(self->current,self->target)){if(!lbl_80377788)fn_80031328(self);}
  else if(equal(self->previous,self->target))fn_80031328(self);
  else if(equal(self->state,self->target))fn_80031328(self);
  else if(equal(self->mode,self->target))fn_80031328(self);
  else if(equal(self->alternate,self->target))fn_80030A08(self,&self->current,self->transition);
  else if(equal(self->group,self->target))fn_80030A08(self,&self->current,self->transition);
  else if(equal(self->subgroup,self->target))fn_80030A08(self,&self->group,self->transition);
  else if(equal(self->other,self->target))fn_80030A08(self,&self->group,self->transition);
  else if(equal(self->subobject,self->target))fn_80030A08(self,&self->group,self->transition);
  if(!lbl_80377788)fn_80059340(lbl_801E9D24.scene->owner,0x28);
  break;
 default:result=2;break;
 }
 fn_8025F620(callback,lbl_80378090);return result;
}

}

/* ---- part_80033F68 ---- */
namespace D {
/* Scene callback event selector for the main/pause menu root (fn_80033F68).
 * Member-pointer records at lbl_802B1918+0x270 and the event switch table
 * jumptable_802B1BC4 are original data of this translation unit. Strings are
 * addressed from the translation unit string base lbl_8029A0C0. The menu
 * transition helper is the inlined body of fn_80031654.
 * "long next = -1" keeps the trailing sentinel test (an int/int compare is
 * folded away by const propagation). resolve() reads the tag before the
 * manager and index.
 * Register allocation notes (wave 17): the six SAVE_n/LOAD_n sub-branches go
 * through saveSlot()/loadSlot(), whose dead conditional copy
 * "if (save) checked = save;" emits no code but leaves one coalesced copy
 * node in the interference graph of each sub-branch (the test is removed, the
 * copy survives to the register allocator). The fn_800312D4 results are
 * plain temporaries. The second half of the transition is expanded at
 * function level so that 'menu' is a function-level local (coloured after
 * 'source' has opened r22). */
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };

typedef Handle_801F7F10 Handle;
struct NameHash {
    Word value;
    NameHash(const char*);
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    Word unknown00; Handle handle4; char unknown08[0x20]; short index28; char unknown2A[0xA];
    signed char flag34; char unknown35[0xB]; Mode** modes;
    char unknown44[0x20]; Word transition; Word unknown68;
    Handle current, alternate, group, subgroup, target, subobject, other, state, previous, mode;
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Owner { char unknown00[0x64]; Handle handle64; };
struct Save;
struct Agent { char unknown00[0x620]; Word selected; };
struct Scene { char unknown00[0x15058]; Owner* owner; Save* save; Agent* agent; };
struct UI { char unknown00[0x1C]; Word* modes; char unknown20[0xD]; signed char flag2D; };

extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}


inline Node* resolve(const Handle& h) {
    signed char tag = h.bits.tag;
    Manager* m = lbl_801E9D24.managerD;
    int index = h.bits.index;
    signed char entryTag = m->entries[index].getTag();
    return entryTag == tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A0C0[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0x270]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern int lbl_8037767C;
extern signed char lbl_80377788;
extern Word lbl_803777C4;
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
Handle_8002B67C fn_800312D4(Node*);
int fn_801FF18C(void*, const Handle_801F7F10*);
void fn_80057294(Owner*);
void fn_80031328(Node*);
void fn_801FEE10(void*, int);
int fn_800596E4(Owner*, short, short);
void fn_802603A0(Scene*, int, Owner*, float);
void fn_80059340(Owner*, int);
void fn_80057100(Owner*, int);
void fn_800B3318(int);
void fn_80030A08(Node*, const Handle*, Word);
void fn_800E88EC(Save*);
void fn_800E8880(Save*, int);
void fn_800E8968(Save*, int);
void fn_800B6C84(UI*, int, Word);
void fn_800B6DA8(UI*, Word, int, Handle_80020478);
void fn_800C2540(Agent*);
void fn_800C3934(Agent*, Node*, NameHash, int, int, int, int);
void fn_801FA014(void*, const char*, ...);
}
inline const NameHash& modeName(Node* n) { return n->modes[n->index28]->name; }
inline void beginTransition(Node* self) {
    int group; group = fn_801FF18C(lbl_801E9D24.groups, &fn_800312D4(self));
    fn_80057294(lbl_801E9D24.sceneD->owner);
    fn_80031328(self);
    fn_801FEE10(lbl_801E9D24.groups, group);
}
#define transition(self, a, b) { beginTransition(self); Owner* menu = lbl_801E9D24.sceneD->owner; int value = fn_800596E4(menu, (short)(a), (short)(b)); lbl_801E9D24.uiD->flag2D = 0; fn_802603A0(lbl_801E9D24.sceneD, 0x56, menu, (float)value); }
inline void clearPending() {
    lbl_8037767C = 0;
    resolve(lbl_801E9D24.sceneD->owner->handle64)->flag34 = 0;
}

extern "C" MemberPointer lbl_802B1B88[5] = { {0, 0x88, 8}, {0, 0x88, 8}, {0, 0x88, 8}, {0, 0x88, 8}, {0, 0x88, 8} };
inline void saveSlot(Save* save, int n) { Save* checked; if (save) checked = save; fn_800E8880(save, n); }
inline void loadSlot(Save* save, int n) { Save* checked; if (save) checked = save; fn_800E8968(save, n); }
extern "C" int fn_80033F68(Node* self, int event, Callback* callback) {
    const char* strings = lbl_8029A0C0;
    const SelectorPool* members = &lbl_802B1918;
    int result = 1;
    switch (event) {
    case 0: fn_8025EF34(self, members->entries[0], -1); return 1;
    case 1: fn_8025EEB4(self, members->entries[1]); return 1;
    case 2: fn_8025EB70(self, members->entries[2]); return 1;
    case 3:
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        return 0;
    case 4:
        if (callback) return (signed char)(callback->flags & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback) return (signed char)(callback->flags & 1);
        return 0;
    case 5: return 1;
    case 6: if (callback) return callback->index; return -9999;
    }
    lbl_8037808C = 0; lbl_80378090 = 0; lbl_80378094 = -1;
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, strings + 0x294);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x5C); break;
    case 15: {
        long next = -1;
        NameHash name = modeName(resolve(self->target));
        fn_801FF18C(lbl_801E9D24.groups, &fn_800312D4(self));
        if (equal(self->current, self->target)) {
            if (lbl_80377788) {
                fn_800B3318(0);
                fn_80030A08(self, &self->mode, self->transition);
                fn_80057294(lbl_801E9D24.sceneD->owner);
            } else if (name == NameHash(strings + 0x2A8)) {
                fn_80030A08(self, &self->group, self->transition);
            } else if (name == NameHash(strings + 0x2B8)) {
                fn_80030A08(self, &self->alternate, self->transition);
            }
            fn_80059340(lbl_801E9D24.sceneD->owner, 0x26);
        } else if (equal(self->group, self->target) || equal(self->previous, self->target)) {
            if (name == NameHash(strings + 0x2CC)) {
                fn_800E88EC(lbl_801E9D24.sceneD->save);
                fn_80030A08(self, &self->other, self->transition);
                fn_80059340(lbl_801E9D24.sceneD->owner, 0x26);
            } else if (name == NameHash(strings + 0x2D8)) {
                fn_800E88EC(lbl_801E9D24.sceneD->save);
                fn_80030A08(self, &self->subobject, self->transition);
                fn_80059340(lbl_801E9D24.sceneD->owner, 0x26);
            } else if (name == NameHash(strings + 0x2E4)) {
                fn_80030A08(self, &self->subgroup, self->transition);
                fn_80059340(lbl_801E9D24.sceneD->owner, 0x26);
            } else if (name == NameHash(strings + 0x288)) {
                fn_80059340(lbl_801E9D24.sceneD->owner, 0x26);
                lbl_801E9D24.sceneD->agent->selected = lbl_801E9D24.uiD->modes[0];
                fn_800B6C84(lbl_801E9D24.uiD, 0, lbl_803777C4);
                { const Handle& source = self->handle4; fn_800B6DA8(lbl_801E9D24.uiD, lbl_803777C4, 0, Handle_80020478(source)); }
                fn_800C2540(lbl_801E9D24.sceneD->agent);
                { Agent* agent = lbl_801E9D24.sceneD->agent; fn_800C3934(agent, self, NameHash(strings + 0x2F4), 1, 0, 0, 0); }
            }
        } else if (equal(self->other, self->target)) {
            fn_80059340(lbl_801E9D24.sceneD->owner, 0x26);
            if (name == NameHash("SAVE_1")) {
                fn_801FA014(lbl_801E9D24.logger, strings + 0x308);
                saveSlot(lbl_801E9D24.sceneD->save, 1);
            } else if (name == NameHash("SAVE_2")) {
                fn_801FA014(lbl_801E9D24.logger, strings + 0x320);
                saveSlot(lbl_801E9D24.sceneD->save, 2);
            } else if (name == NameHash("SAVE_3")) {
                fn_801FA014(lbl_801E9D24.logger, strings + 0x338);
                saveSlot(lbl_801E9D24.sceneD->save, 3);
            }
        } else if (equal(self->subobject, self->target) || equal(self->state, self->target)) {
            fn_80059340(lbl_801E9D24.sceneD->owner, 0x26);
            if (name == NameHash("LOAD_1")) {
                clearPending();
                fn_801FA014(lbl_801E9D24.logger, strings + 0x350);
                loadSlot(lbl_801E9D24.sceneD->save, 1);
            } else if (name == NameHash("LOAD_2")) {
                clearPending();
                fn_801FA014(lbl_801E9D24.logger, strings + 0x368);
                loadSlot(lbl_801E9D24.sceneD->save, 2);
            } else if (name == NameHash("LOAD_3")) {
                clearPending();
                fn_801FA014(lbl_801E9D24.logger, strings + 0x380);
                loadSlot(lbl_801E9D24.sceneD->save, 3);
            }
        } else if (equal(self->mode, self->target)) {
            clearPending();
            if (name == NameHash(strings + 0x398)) {
                transition(self, -1, 1);
            } else if (name == NameHash(strings + 0x3AC)) {
                transition(self, -1, 2);
            } else if (name == NameHash(strings + 0x3BC)) {
                transition(self, -1, 3);
            } else if (name == NameHash(strings + 0x3CC)) {
                transition(self, -1, 0);
            } else if (name == NameHash(strings + 0x3DC)) {
                fn_800B3318(1);
                fn_80057100(lbl_801E9D24.sceneD->owner, -1);
                fn_80030A08(self, &self->current, self->transition);
            }
        }
        if (next != -1) transition(self, -1, -1);
        break;
    }
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

}
