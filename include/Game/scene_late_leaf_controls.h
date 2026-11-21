#ifndef GAME_SCENE_LATE_LEAF_CONTROLS_H
#define GAME_SCENE_LATE_LEAF_CONTROLS_H
#include "Game/python_owner_factories.h"
namespace SceneLateLeaf {
struct Prefix { char unknown00[8]; };
struct Object:Prefix {
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
virtual void slot21(int);
virtual void slot22(int);
char unknown0C[0x2C];unsigned long long flags;
char unknown40[0x5E4];Object*child;float elapsed;float duration;signed char timing;
};
struct Handle { int value; };
struct LargePrefix {char unknown00[0x278];};
struct Large:LargePrefix {
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
virtual void slot25(const Handle*);
};
struct SmallOwner {char unknown00[0x2C];Handle selected;char unknown30;signed char busy;};
struct Source {char unknown00[0x48];Large*target;};
struct EventOwner {char unknown00[0xC];void*controller;};
struct Scene {char unknown00[0x1505C];void*target;};
struct Context {char unknown00[0x124];Scene*scene;};
struct Property {const char*name;FactoryPyObject*(*get)();int(*set)(FactoryPyObject*);Property*next;};
struct Binding {char unknown00[8];Property*properties;};
}
extern "C" {
signed char slot1C__12BaseObject_ZFv(void*);
void slot18__11Activable_ZFv(void*);
void fn_8002AE88(void*);void fn_8002B0A8(void*);void fn_800A901C(void*);void fn_800A903C(void*);
void fn_80257828(void*,int,int,int);void fn_8025795C(void*,int,int);
void fn_80254F00(void*,const SceneLateLeaf::Handle&);
void fn_802597A4(void*);
unsigned long fn_801F7EB8(const SceneLateLeaf::Handle*);
void fn_802603A0(void*,int,void*,float);
extern SceneLateLeaf::Context lbl_801E9D24;
extern const float lbl_8037951C,lbl_80379538;
extern const char lbl_802A2AC8[];
extern FactoryPyObject*PyExc_NameError;
void PyErr_SetString(FactoryPyObject*,const char*);
int strcmp(const char*,const char*);
}
#endif
