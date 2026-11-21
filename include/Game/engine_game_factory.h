#ifndef GAME_ENGINE_GAME_FACTORY_H
#define GAME_ENGINE_GAME_FACTORY_H

struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct GameFactoryHandle : Handle_801F7F10 {
    GameFactoryHandle() { value = 0; }
};
struct GameFactoryPrefix { unsigned long unknown00[2]; };
struct Manipulator_Z : GameFactoryPrefix {
    Manipulator_Z();
    virtual ~Manipulator_Z();
    char unknown0C[0x20 - 0xC];
};
struct GameFactoryArray {
    int count, capacity;
    void *data;
    GameFactoryArray() { count = 0; capacity = 0; data = 0; }
};
extern "C" void __ct__15BitSet_80207EE8Fv(void *);
struct GameFactoryBitSet {
    int count, capacity;
    void *data;
    int bits;
    GameFactoryBitSet() { __ct__15BitSet_80207EE8Fv(this); }
};
struct ObjectsGame_802EB900 : Manipulator_Z {
    char unknown20[8];
    GameFactoryHandle handle28;
    GameFactoryArray array2C, array38;
    GameFactoryBitSet occupied;
    GameFactoryArray array54, array60, array6C, array78, array84, array90;
    ObjectsGame_802EB900() {}
    virtual ~ObjectsGame_802EB900();
};

typedef char CheckFactoryGameSize[sizeof(ObjectsGame_802EB900) == 0x9C ? 1 : -1];
extern "C" ObjectsGame_802EB900 *fn_80209814();

#endif
