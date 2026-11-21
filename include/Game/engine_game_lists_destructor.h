#ifndef GAME_ENGINE_GAME_LISTS_DESTRUCTOR_H
#define GAME_ENGINE_GAME_LISTS_DESTRUCTOR_H

typedef unsigned long GameListsWord;
extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[];
extern char __vt__20ObjectsGame_802EB900[], __vt__13Manipulator_Z[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
void* __dt__11Activable_ZFv(void*, short);
}

struct Handle_801F7F10 { GameListsWord word; ~Handle_801F7F10(); };
struct GameListsHandle1 : Handle_801F7F10 { ~GameListsHandle1() {} };
struct GameListsHandle2 : GameListsHandle1 { ~GameListsHandle2() {} };
struct GameListsHandle3 : GameListsHandle2 { ~GameListsHandle3() {} };
struct BitSet_80207EE8 { GameListsWord unknown[4]; ~BitSet_80207EE8(); };
struct GameListsElement { GameListsWord word; ~GameListsElement() {} };

template<class T> struct GameListsArray {
    int count, capacity;
    T* data;
    ~GameListsArray() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};

struct GameListsBuffer {
    int count, capacity;
    void* data;
    ~GameListsBuffer() {
        if (data) {
            fn_801EF610(lbl_801EF5C8, data);
            data = 0;
        }
    }
};

/* Partial storage view of the retained ObjectsGame destruction entry. */
struct GameListsObject {
    GameListsWord unknown00, identity;
    const void* table;
    char unknown0C[0x1C];
    GameListsHandle1 handle;
    GameListsArray<GameListsHandle3> array2C;
    GameListsArray<GameListsElement> array38;
    BitSet_80207EE8 bits;
    GameListsArray<GameListsHandle2> array54;
    GameListsArray<GameListsHandle3> array60, array6C;
    GameListsBuffer buffer78, buffer84, buffer90;
};

extern "C" GameListsObject* fn_8022A1A0(GameListsObject*, short);

#endif
