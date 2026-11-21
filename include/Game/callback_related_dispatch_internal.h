#ifndef GAME_CALLBACK_RELATED_DISPATCH_INTERNAL_H
#define GAME_CALLBACK_RELATED_DISPATCH_INTERNAL_H
// Partial native layouts and declaration-only virtual interfaces.
struct CallbackRelatedHandle {
    signed int generation:8;
    signed int index:24;
};
struct CallbackRelatedStorage8 {
    char unknown0[8];
};
struct CallbackRelatedTarget:CallbackRelatedStorage8 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(int,int);
    virtual void slot24();
    virtual void slot28();
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
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84(void*);
    char unknownC[0x52];
    signed char byte5E;
};
struct CallbackRelatedEntry {
    CallbackRelatedTarget*object;
    char unknown4[8];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct CallbackRelatedManager {
    char unknown0[8];
    CallbackRelatedEntry*entries;
};
struct CallbackRelatedOwner;
extern "C" {
    extern struct {
        char unknown0[0x118];
        CallbackRelatedManager*manager;
    }
    lbl_801E9D24;
    CallbackRelatedTarget*fn_801F7EB8(const CallbackRelatedHandle*);
    signed char slot1C__12BaseObject_ZFv(void*);
    signed char fn_80257C78(CallbackRelatedOwner*);
    void fn_80256370(void*);
    void fn_80213A18(void*);
    void fn_802139D8(void*);
    void fn_80257FF0(void*,void*);
}
inline CallbackRelatedTarget*resolveRelated(const CallbackRelatedHandle&h){
    int index=h.index;
    CallbackRelatedManager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==h.generation?m->entries[index].object:0;
}
struct CallbackRelatedOwner {
    char unknown0[0x38];
    unsigned long long flags;
    char unknown40[8];
    CallbackRelatedHandle handle48;
    char unknown4C[0x14];
    CallbackRelatedHandle handle60;
    CallbackRelatedHandle handle64;
    char unknown68[8];
    CallbackRelatedHandle handle70;
};
#endif
