#ifndef GAME_WORLD_LIFETIME_INTERNAL_H
#define GAME_WORLD_LIFETIME_INTERNAL_H
#include "world_records_internal.h"
#include "world_curve50_internal.h"
struct Resource_802E9E20 : BaseObject_Z {
    Resource_802E9E20(){}
    virtual ~Resource_802E9E20(){}
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct WorldArray50_801E4F9C {
    int count,capacity;CurveRecord50_802F15C0*data;
    WorldArray50_801E4F9C():count(0),capacity(0),data(0){}
    ~WorldArray50_801E4F9C();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct WorldArray4C_801E506C {
    int count,capacity;CurveRecord4C_802EA7D8*data;
    WorldArray4C_801E506C():count(0),capacity(0),data(0){}
    ~WorldArray4C_801E506C();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct WorldArray3C_801E513C {
    int count,capacity;CurveRecord3C_802EA7E4*data;
    WorldArray3C_801E513C():count(0),capacity(0),data(0){}
    ~WorldArray3C_801E513C();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct World_802EA7F0 : Resource_802E9E20 {
    // Other virtual callbacks are declared outside this lifetime unit.
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual signed char slot1C();
    WorldArray50_801E4F9C records0C;
    WorldArray4C_801E506C records18;
    WorldArray3C_801E513C records24;
    WorldCurveArray<WorldRecord1C> records30;
    WorldCurveArray<WorldRecord14> records3C;
    WorldCurveArray<u32> words48;
    WorldActionCurve_801F7560 actions54;
    WorldCurveArray<WorldCurveKey<128> > records68;
    u32 field74;
    World_802EA7F0();
    virtual ~World_802EA7F0();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
typedef char CheckWorldSize[sizeof(World_802EA7F0)==0x78?1:-1];
#endif
