#ifndef GAME_ENGINE_BASE_FACTORY_H
#define GAME_ENGINE_BASE_FACTORY_H

struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct FactoryBaseHandle1 : Handle_801F7F10 {
    FactoryBaseHandle1() { value = 0; }
    ~FactoryBaseHandle1();
};
struct FactoryBaseHandle2 : FactoryBaseHandle1 {
    FactoryBaseHandle2() { value = 0; }
    ~FactoryBaseHandle2();
};
struct FactoryBaseHandle3 : FactoryBaseHandle2 {
    FactoryBaseHandle3() { value = 0; }
    ~FactoryBaseHandle3();
};
struct FactoryBaseArray {
    int count, capacity;
    void *data;
    FactoryBaseArray() { count = 0; capacity = 0; data = 0; }
};
struct FactoryBaseZero {
    unsigned long value;
    FactoryBaseZero() { value = 0; }
};
struct FactoryBasePrefix { unsigned long unknown00[2]; };
struct Manipulator_Z : FactoryBasePrefix {
    Manipulator_Z();
    virtual ~Manipulator_Z();
    char unknown0C[0x20 - 0xC];
};
struct ObjectMove_Z : Manipulator_Z {
    FactoryBaseHandle2 handle20, handle24;
    FactoryBaseHandle3 handle28;
    char unknown2C[0x38 - 0x2C];
    FactoryBaseArray array38, array44, array50, array5C;
    FactoryBaseHandle2 handle68;
    FactoryBaseArray array6C;
    FactoryBaseZero field78;
    char unknown7C[0x12C - 0x7C];
    FactoryBaseHandle2 handle12C;
    char unknown130[0x168 - 0x130];
    ObjectMove_Z() {}
    virtual ~ObjectMove_Z();
};

typedef char CheckFactoryBaseSize[sizeof(ObjectMove_Z) == 0x168 ? 1 : -1];
extern "C" ObjectMove_Z *fn_8020A1E4();

#endif
