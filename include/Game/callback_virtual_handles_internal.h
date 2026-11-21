#ifndef GAME_CALLBACK_VIRTUAL_HANDLES_INTERNAL_H
#define GAME_CALLBACK_VIRTUAL_HANDLES_INTERNAL_H
// Observed prefixes and declaration-only native virtual interfaces.
struct CallbackVirtualHandle {
    signed int generation:8;
    signed int index:24;
};
struct CallbackVirtualStorage8 {
    char unknown0[8];
};
struct CallbackVirtualTarget:CallbackVirtualStorage8 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28(int);
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual CallbackVirtualHandle* slot78(int);
    char unknownC[0x18];
    CallbackVirtualHandle owned24;
    CallbackVirtualHandle owned28;
    char unknown2C[0xC];
    unsigned long long flags;
    char unknown40[0x30];
    CallbackVirtualHandle handle70;
};
struct CallbackVirtualEntry {
    CallbackVirtualTarget*object;
    char unknown4[8];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct CallbackVirtualManager {
    char unknown0[8];
    CallbackVirtualEntry*entries;
};
extern "C" {
    extern struct {
        char unknown0[0x118];
        CallbackVirtualManager*manager;
    }
    lbl_801E9D24;
    CallbackVirtualTarget*fn_801F7EB8(const CallbackVirtualHandle*);
    void fn_801F86C8(CallbackVirtualManager*,const CallbackVirtualHandle*,int);
    signed char slot1C__12BaseObject_ZFv(void*);
    void fn_80213A18(void*);
    void fn_802139D8(void*);
    void fn_8025E8F8(void*);
    void fn_8025E8E0(void*);
    void fn_80257338(void*);
    void fn_802573E4(void*);
}
inline CallbackVirtualTarget*resolveVirtual(const CallbackVirtualHandle&h){
    int index=h.index;
    CallbackVirtualManager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==h.generation?m->entries[index].object:0;
}
#endif
