#ifndef GAME_ENGINE_OWNER_LISTS_DESTRUCTOR_H
#define GAME_ENGINE_OWNER_LISTS_DESTRUCTOR_H

/* Partial storage view for the retained ObjectsBreak cleanup entry. */
typedef unsigned long OwnerListsWord;

extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[];
extern char __vt__12ObjectsBreak[], __vt__13ObjectsBounce[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
void* __dt__11ObjectsMoveFv(void*, short);
}

struct Handle_801F7F10 {
    OwnerListsWord word;
    ~Handle_801F7F10();
};

struct OwnerListsHandle1 : Handle_801F7F10 { ~OwnerListsHandle1() {} };
struct OwnerListsHandle2 : OwnerListsHandle1 { ~OwnerListsHandle2() {} };
struct OwnerListsHandle3 : OwnerListsHandle2 { ~OwnerListsHandle3() {} };
struct OwnerListsHandle4 : OwnerListsHandle3 { ~OwnerListsHandle4() {} };

template<int N> struct OwnerListsElement {
    char unknown[N];
    ~OwnerListsElement() {}
};

template<class T> struct OwnerListsArray {
    int count, capacity;
    T* data;

    ~OwnerListsArray() {
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

struct OwnerListsObject {
    OwnerListsWord unknown00, identity;
    const void* table;
    char unknown0C[0x19C];
    OwnerListsHandle4 handle;
    OwnerListsArray<OwnerListsElement<4> > first, second, third;
    OwnerListsArray<OwnerListsElement<16> > fourth;
    OwnerListsArray<OwnerListsElement<4> > fifth;
};

extern "C" OwnerListsObject* fn_8022D2B0(OwnerListsObject*, short);

#endif
