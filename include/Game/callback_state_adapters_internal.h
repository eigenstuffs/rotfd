#ifndef GAME_CALLBACK_STATE_ADAPTERS_INTERNAL_H
#define GAME_CALLBACK_STATE_ADAPTERS_INTERNAL_H
// Observed prefixes and declaration-only native virtual interfaces.
struct CallbackAdapterHandle {
    signed int generation:8;
    signed int index:24;
};
struct CallbackAdapterStorage8 {
    char unknown0[8];
};
struct CallbackAdapterTarget:CallbackAdapterStorage8 {
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
    virtual void* slot3C();
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
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual int slot90();
    unsigned long flagsC;
    char unknown10[0x10];
    CallbackAdapterHandle related20;
};
struct CallbackAdapterEntry {
    CallbackAdapterTarget*object;
    char unknown4[8];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct CallbackAdapterManager {
    char unknown0[8];
    CallbackAdapterEntry*entries;
};
struct CallbackAdapterRecord {
    char unknown0[0x10];
    short state;
};
struct CallbackAdapterReceiver:CallbackAdapterStorage8 {
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
    virtual void* slot3C();
    char unknownC[0x20];
    CallbackAdapterRecord*record;
};
struct CallbackAdapterOwner {
    char unknown0[0x38];
    unsigned long long flags;
    char unknown40[0x18];
    CallbackAdapterHandle handle58;
    char unknown5C[0x14];
    CallbackAdapterHandle handle70;
    char unknown74[0xC];
    CallbackAdapterHandle handle80;
};
struct CallbackAdapterIndexOwner {
    char unknown0[0x20];
    int index;
    char unknown24[0xC];
    short key;
};
extern "C" {
    extern struct {
        char unknown0[0x118];
        CallbackAdapterManager*manager;
        char unknown11C[0x50];
        void*recordOwner;
    }
    lbl_801E9D24;
    void fn_80252DE0(void*,const int*);
    void fn_80252E1C(void*,void*,short);
    void fn_8023D120(void*,const void*,const void*);
    void fn_8023D100(void*,const void*);
    void fn_8023DE28(void*);
    void fn_8025A244(void*);
    void fn_8025A190(void*);
    void fn_80213A18(void*);
    void fn_802139D8(void*);
    void fn_8022F474(void*,const void*);
    void fn_8022F49C(void*,const void*);
    int fn_8026C094(void*,void*,void*,void*,void*);
}
inline CallbackAdapterTarget*resolveAdapter(const CallbackAdapterHandle&h){
    int index=h.index;
    CallbackAdapterManager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==h.generation?m->entries[index].object:0;
}
#endif
