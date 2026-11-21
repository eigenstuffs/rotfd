/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4ADC[];
struct MultiPrefix_800D8608{char unknown[8];};
struct MultiView_800D8608:MultiPrefix_800D8608{
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual signed char slot48(void*, unsigned long long);
};

extern "C" FactoryPyObject* fn_800D8608(FactoryPyObject*,FactoryPyObject* args){
    MultiView_800D8608* native0;
    void* native1;
    unsigned long long* native2;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A4ADC, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x28/4],1)==-1)return 0;
    if(fn_800CD864(arg1,(void**)&native1,lbl_80318988[0xC4/4],1)==-1)return 0;
    if(fn_800CD864(arg2,(void**)&native2,lbl_80318988[0x54/4],1)==-1)return 0;
    return PyInt_FromLong(native0->slot48(native1, *native2));
}
