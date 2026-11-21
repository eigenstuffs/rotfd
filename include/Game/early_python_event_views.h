#ifndef GAME_EARLY_PYTHON_EVENT_VIEWS_H
#define GAME_EARLY_PYTHON_EVENT_VIEWS_H
struct EventPyObject;
struct EventPyType{char unknown00[0x18];void(*destroy)(EventPyObject*);};
struct EventPyObject{int references;EventPyType*type;};
struct PythonEventOwner{char unknown00[0x40];EventPyObject*script;char unknown44[0x30];signed char active[17];};
struct PythonEventContext{char unknown00[0x110];void*diagnostics;};
static inline void releaseEventObject(EventPyObject*object){if(object){if(--object->references==0)object->type->destroy(object);}}
extern "C" {
extern PythonEventContext lbl_801E9D24;
EventPyObject*PyObject_GetAttrString(EventPyObject*,const char*);
EventPyObject*fn_801308B4(EventPyObject*,void*);
void PyErr_Print();
void fn_801F9D68(void*,const char*,...);
void fn_801FA014(void*,const char*,...);
extern const char lbl_8029BF50[];
extern const char lbl_8029BF98[];
extern const char lbl_8029BFC4[];
extern const char lbl_8029C014[];
extern const char lbl_8029C044[];
extern const char lbl_8029C08C[];
extern const char lbl_8029C144[];
extern const char lbl_8029C190[];
extern const char lbl_8029C1C0[];
extern const char lbl_8029C20C[];
extern const char lbl_8029C59C[];
extern const char lbl_8029C5E8[];
extern const char lbl_8029C618[];
extern const char lbl_8029C660[];
extern const char lbl_8029C690[];
extern const char lbl_8029C6D8[];
extern const char lbl_8029C704[];
extern const char lbl_8029C750[];
extern const char lbl_80378780[5];
extern const char lbl_80378788[8];
extern const char lbl_80378790[6];
extern const char lbl_80378798[7];
extern const char lbl_803787A0[7];
extern const char lbl_803787A8[8];
extern const char lbl_803787B0[7];
extern const char lbl_803787B8[6];
extern const char lbl_803787C0[4];
extern const char lbl_803787C4[8];
extern void* lbl_80374498;
extern void* lbl_8037449C;
extern void* lbl_803744A0;
extern unsigned short lbl_803776C2;
extern unsigned short lbl_803776C4;
extern unsigned short lbl_803776C6;
extern unsigned short lbl_803776C8;
extern unsigned short lbl_803776CA;
extern void* lbl_803776CC;
extern void* lbl_803776D0;
extern void* lbl_803776D4;
extern void* lbl_803776D8;
extern void* lbl_803776DC;
extern void* lbl_803776E0;
extern void* lbl_803776E4;
extern PythonEventOwner*lbl_803776B8;
int printf(const char*,...);
void abort();
}
#endif
