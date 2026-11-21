#ifndef GAME_CALLBACK_OBJECT_WRAPPERS_INTERNAL_H
#define GAME_CALLBACK_OBJECT_WRAPPERS_INTERNAL_H
// Partial observed layouts and declaration-only native virtual interfaces.
struct CallbackWrapperHandle {
    signed int generation:8;
    signed int index:24;
};
struct CallbackWrapperStorage8 {
    char unknown0[8];
};
struct CallbackWrapperObject:CallbackWrapperStorage8 {
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
    virtual void slot48(int);
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68(int);
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual CallbackWrapperHandle* slot78(int);
    char unknownC[0x14];
    unsigned long word20;
    signed char state;
    char unknown25[0x3F];
    CallbackWrapperHandle related;
};
struct CallbackWrapperEntry {
    CallbackWrapperObject*object;
    char unknown4[8];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const{
        return generation;
    }
};
struct CallbackWrapperManager {
    char unknown0[8];
    CallbackWrapperEntry*entries;
};
struct CallbackWrapperLargeStorage {
    char unknown0[0xB10];
};
struct CallbackWrapperLarge:CallbackWrapperLargeStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(int);
};
extern "C" {
    extern struct {
        char unknown0[0x110];
        CallbackWrapperLarge*dispatch;
        char unknown114[4];
        CallbackWrapperManager*manager;
    }
    lbl_801E9D24;
    void fn_8025ECD8(void*,int);
    void fn_8025E5CC(void*);
    void fn_801FFEFC(void*,void*);
    void fn_801FFF64(void*,void*);
    void fn_8020ED58(void*);
    void fn_80285E10(void*);
    void fn_8025EBF0(void*,void*);
    void fn_8020E938(void*,void*,int);
}
inline CallbackWrapperObject*resolve(const CallbackWrapperHandle&h){
    int index=h.index;
    CallbackWrapperManager*m=lbl_801E9D24.manager;
    int generation=m->entries[index].getGeneration();
    return generation==h.generation?m->entries[index].object:0;
}
struct CallbackWrapperFlagPrefix {
    char unknown0[0x38];
    unsigned long long flags;
    char unknown40[8];
    unsigned long key;
};
struct CallbackWrapperOwnerArray {
    char unknown0[0x24];
    struct Record {
        char unknown0[0x18];
    }
    *records;
};
#endif
