// Private construction views; opaque gaps and external virtual interfaces stay unclaimed.
#ifndef GAME_OBJECTS_CONSTRUCTORS_INTERNAL_H
#define GAME_OBJECTS_CONSTRUCTORS_INTERNAL_H

typedef unsigned long u32;

struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ObjectsConstructorHandle1 : Handle_801F7F10 {
    ObjectsConstructorHandle1() { value = 0; }
};
struct ObjectsConstructorHandle2 : ObjectsConstructorHandle1 {
    ObjectsConstructorHandle2() { value = 0; }
};
struct ObjectsConstructorHandle3 : ObjectsConstructorHandle2 {
    ObjectsConstructorHandle3() { value = 0; }
};
struct ObjectsConstructorHandle4 : ObjectsConstructorHandle3 {
    ObjectsConstructorHandle4() { value = 0; }
};
struct ObjectsConstructorArray {
    int count, capacity;
    void* data;
    ObjectsConstructorArray() { count = 0; capacity = 0; data = 0; }
};
struct ObjectsConstructorZero {
    u32 value;
    ObjectsConstructorZero() { value = 0; }
};
struct ObjectsConstructorHash;
extern "C" void __ct__15BitSet_80207EE8Fv(ObjectsConstructorHash*);
struct ObjectsConstructorHash {
    int cursor, capacity, count;
    void* slots;
    ObjectsConstructorHash() { __ct__15BitSet_80207EE8Fv(this); }
};
struct Prefix { u32 unknown00[2]; };
struct Manipulator_Z : Prefix {
    Manipulator_Z();
    virtual ~Manipulator_Z();
    char unknown0C[0x20 - 0xC];
};
struct ObjectsBase_802EB3F8 : Manipulator_Z {
    ObjectsConstructorHandle2 handle20, handle24;
    ObjectsConstructorHandle3 handle28;
    char unknown2C[0x38 - 0x2C];
    ObjectsConstructorArray array38, array44, array50, array5C;
    ObjectsConstructorHandle2 handle68;
    ObjectsConstructorArray array6C;
    ObjectsConstructorZero field78;
    char unknown7C[0x12C - 0x7C];
    ObjectsConstructorHandle2 handle12C;
    char unknown130[0x168 - 0x130];
    ObjectsBase_802EB3F8() {}
    virtual ~ObjectsBase_802EB3F8();
};
struct ObjectsMove : ObjectsBase_802EB3F8 {
    ObjectsConstructorHandle1 handle168;
    ObjectsConstructorZero field16C;
    int mode170;
    ObjectsConstructorHandle2 handle174;
    char unknown178[8];
    ObjectsConstructorArray array180;
    ObjectsConstructorHash hash18C;
    ObjectsConstructorZero field19C, field1A0;
    u32 unknown1A4;
    ObjectsMove();
    virtual ~ObjectsMove();
};
struct ObjectsBounce : ObjectsMove {
    ObjectsBounce();
    virtual ~ObjectsBounce();
};
struct ObjectsBreak : ObjectsBounce {
    ObjectsConstructorHandle4 handle1A8;
    ObjectsConstructorArray array1AC, array1B8, array1C4, array1D0, array1DC;
    u32 unknown1E8[2];
    ObjectsBreak();
    virtual ~ObjectsBreak();
};
typedef char CheckBase[sizeof(ObjectsBase_802EB3F8) == 0x168 ? 1 : -1];
typedef char CheckMove[sizeof(ObjectsMove) == 0x1A8 ? 1 : -1];
typedef char CheckBounce[sizeof(ObjectsBounce) == 0x1A8 ? 1 : -1];
typedef char CheckBreak[sizeof(ObjectsBreak) == 0x1F0 ? 1 : -1];

#endif
