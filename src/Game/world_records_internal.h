#ifndef GAME_WORLD_RECORDS_INTERNAL_H
#define GAME_WORLD_RECORDS_INTERNAL_H
#include "objects_owner_internal.h"
// Partial record layouts inferred from callbacks, loading, and native lifetime.
struct WorldNotifyObject : BaseObject_Z {
    virtual void slot20(Activable_Z*, int);
};
struct WorldHandle1 : Handle_801F7F10 { WorldHandle1(){value=0;} ~WorldHandle1(){} };
template<class T> struct WorldRecordHandle : WorldHandle1 {
    WorldRecordHandle(){value=0;}
    ~WorldRecordHandle(){}
    T* get() const {
        int index = bits.index;
        Manager* m = lbl_801E9D24.manager;
        int generation = m->entries[index].getGeneration();
        return generation == bits.generation ? (T*)m->entries[index].object : 0;
    }
};
struct WorldRecord50 { char unknown[0x50]; };
struct WorldRecordName {u32 value; WorldRecordName(){value=0;}};
struct WorldRecord1C {
    WorldRecordName name00, name04; u32 field08; signed char flag0C; char pad0D[3];
    WorldRecordHandle<Activable_Z> handle10, handle14, handle18;
    WorldRecord1C() {field08=~0UL; flag0C=0;}
    ~WorldRecord1C() {}
};
struct WorldRecord14 {
    u32 field00; WorldRecordName name04;
    WorldRecordHandle<Activable_Z> handle08, handle0C;
    WorldRecordHandle<WorldNotifyObject> handle10;
    WorldRecord14(){field00=~0UL;}
    ~WorldRecord14(){}
};
template<class T> struct WorldRecordArray { int count, capacity; T* data; };
struct WorldRecord4C { char unknown[0x4C]; };
struct WorldRecord3C { char unknown[0x3C]; };
struct WorldRecordView : BaseObject_Z {
    WorldRecordArray<WorldRecord50> records0C;
    WorldRecordArray<WorldRecord4C> records18;
    WorldRecordArray<WorldRecord3C> records24;
    WorldRecordArray<WorldRecord1C> records30;
    WorldRecordArray<WorldRecord14> records3C;
    char unknown48[0xC];
    char object54[0x20];
    u32 field74;
};
typedef char CheckWorldRecord14[sizeof(WorldRecord14)==0x14?1:-1];
typedef char CheckWorldRecord1C[sizeof(WorldRecord1C)==0x1C?1:-1];
typedef char CheckWorldRecordView[sizeof(WorldRecordView)==0x78?1:-1];
#endif
