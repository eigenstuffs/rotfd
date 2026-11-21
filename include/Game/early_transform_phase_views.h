#ifndef GAME_EARLY_TRANSFORM_PHASE_VIEWS_H
#define GAME_EARLY_TRANSFORM_PHASE_VIEWS_H

struct PhaseVector {float x,y,z;PhaseVector(){} PhaseVector(float a,float b,float c):x(a),y(b),z(c){}};
struct PhaseQuaternion {float x,y,z,w;PhaseQuaternion(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}};
struct PhasePrefix{char unknown00[8];};
struct PhaseNode:PhasePrefix {
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
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const PhaseVector*,int);
virtual void slot46(const PhaseVector*,const PhaseQuaternion*,int);
char unknown0C[0x190];float height;};
struct PhaseUpdater{char unknown00[8];PhaseNode*node;float value,phase,amplitude,speed,angleSpeed,angleDecay;};
extern "C"{float fn_8028506C(float);float fn_80284FA8(float);extern const float lbl_80378958,lbl_8037895C,lbl_80378960,lbl_80378964,lbl_8037896C;}

#endif
