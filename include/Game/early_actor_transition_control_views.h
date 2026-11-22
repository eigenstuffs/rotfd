#ifndef GAME_EARLY_ACTOR_TRANSITION_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_TRANSITION_CONTROL_VIEWS_H
struct TransitionControlHandle{signed int tag:8;signed int index:24;};
struct TransitionControlVector{float x,y,z;TransitionControlVector&operator=(const TransitionControlVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct TransitionControlActor{char unknown00[0x24];TransitionControlHandle handle;char unknown28[8];unsigned long long flags;char unknown38[0x10C];TransitionControlVector velocity;char unknown150[0xC];TransitionControlVector previousVelocity;char controller168[8];char unknown170[0x1A8];char controller318[0xB4];int state;char unknown3D0[0x42];signed char active;};
struct TransitionControlOwner{char unknown00[8];TransitionControlActor*actor;};
struct TransitionControlResource{char unknown00[0x38];unsigned long long flags;};
struct TransitionControlEntry{TransitionControlResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TransitionControlManager{char unknown00[8];TransitionControlEntry*entries;};
struct TransitionControlBehavior{char unknown00[0x3C];signed char active;};
struct TransitionControlStatus{char unknown00[0x152];short count;};
struct TransitionControlWindowPrefix{char unknown00[0x230];signed char active;char unknown231[0x47];};
struct TransitionControlWindow:TransitionControlWindowPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
signed char getActive()const{return active;}
virtual void begin();
virtual void end();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void*getOutput();
};
struct TransitionControlScenePrefix{char unknown00[8];};
struct TransitionControlSceneService:TransitionControlScenePrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void apply(TransitionControlWindow*);
};
struct TransitionControlScene{char unknown00[0x15058];TransitionControlStatus*status;char unknown1505C[8];TransitionControlSceneService*service;};
struct TransitionControlContext{char unknown00[0x114];TransitionControlWindow*window;TransitionControlManager*manager;char unknown11C[8];TransitionControlScene*scene;};
extern "C"TransitionControlContext lbl_801E9D24;
inline TransitionControlResource*resolveResource(const TransitionControlHandle&h){int index=h.index;TransitionControlManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"{TransitionControlBehavior*fn_8005EE10(TransitionControlResource*);void fn_800699A8(TransitionControlBehavior*,int);void fn_800A4DF0(TransitionControlOwner*,float);void slot34__11CScriptMoveFv(TransitionControlActor*);signed char fn_8007D604(void*,int);void fn_8007D6A0(void*,int);void fn_8007DA74(void*,float);void fn_801EBB9C(void*);extern const TransitionControlVector game_vec3_zero;}
#endif
