#ifndef GAME_ENGINE_OWNER_TRANSFORM_UPDATE_H
#define GAME_ENGINE_OWNER_TRANSFORM_UPDATE_H

typedef unsigned long TransformUpdateWord;
struct TransformUpdateHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct TransformUpdateOwner;
struct TransformUpdateStorage { char unknown00[8]; };
struct TransformUpdateHook : TransformUpdateStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void bind(TransformUpdateOwner*);
    virtual void slot28();
    virtual float query();
    virtual void apply(TransformUpdateOwner*, TransformUpdateHook*);
};
struct TransformUpdateMatrix { float a[16]; };
struct TransformUpdateEntry {
    char* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct TransformUpdateManager {
    char unknown00[8];
    TransformUpdateEntry* entries;
};
struct TransformUpdateMatrixPool {
    TransformUpdateMatrix* pages[6];
    unsigned char active;
};
extern "C" {
    extern struct {
        char unknown00[0x118];
        TransformUpdateManager* manager;
        char unknown11C[0x18];
        TransformUpdateMatrixPool* pool;
    } lbl_801E9D24;
    void fn_8027B508(TransformUpdateOwner*, const TransformUpdateOwner*);
    void fn_8027B2E4(TransformUpdateOwner*);
    void fn_8023F90C(TransformUpdateOwner*, void*, TransformUpdateHook*);
    void fn_8023D9B8(TransformUpdateOwner*, void*, const TransformUpdateOwner*);
}
struct TransformUpdateOwner {
    char unknown00[0x10];
    TransformUpdateHandle first;
    char unknown14[4];
    TransformUpdateHandle next, primary, secondary;
    char unknown24[0xFC];
    TransformUpdateWord flags;
    TransformUpdateMatrix* matrix;
    TransformUpdateMatrix* inverse;
    short index;
};
static inline char* transformUpdateResolve(const TransformUpdateHandle& handle) {
    int index = handle.index;
    TransformUpdateManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.generation)
        return manager->entries[index].object;
    return 0;
}

typedef char TransformUpdateHandleSize[sizeof(TransformUpdateHandle) == 4 ? 1 : -1];
typedef char TransformUpdateEntrySize[sizeof(TransformUpdateEntry) == 16 ? 1 : -1];
typedef char TransformUpdateMatrixSize[sizeof(TransformUpdateMatrix) == 64 ? 1 : -1];
typedef char TransformUpdateHookSize[sizeof(TransformUpdateHook) == 12 ? 1 : -1];
#endif
