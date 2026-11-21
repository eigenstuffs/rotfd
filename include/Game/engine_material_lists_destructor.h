#ifndef GAME_ENGINE_MATERIAL_LISTS_DESTRUCTOR_H
#define GAME_ENGINE_MATERIAL_LISTS_DESTRUCTOR_H

typedef unsigned long MaterialListsWord;

extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[];
extern char __vt__21MaterialAnim_802EC000[], __vt__17Resource_802E9E20[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
void* __dt__12BaseObject_ZFv(void*, short);
}

struct Handle_801F7F10 {
    MaterialListsWord word;
    ~Handle_801F7F10();
};
struct MaterialListsHandle1 : Handle_801F7F10 { ~MaterialListsHandle1() {} };
struct MaterialListsHandle2 : MaterialListsHandle1 { ~MaterialListsHandle2() {} };

struct CurveBase_801B1088 {
    unsigned short flags, unknown02;
    ~CurveBase_801B1088();
};

template<int N> struct MaterialListsElement {
    char unknown[N];
    ~MaterialListsElement() {}
};
struct MaterialListsHandleKey {
    MaterialListsWord unknown00;
    Handle_801F7F10 handle;
    ~MaterialListsHandleKey() {}
};

template<class T> struct MaterialListsArray {
    int count, capacity;
    T* data;

    ~MaterialListsArray() {
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

template<class T> struct MaterialListsCurve : CurveBase_801B1088 {
    MaterialListsArray<T> array;
    ~MaterialListsCurve() {}
};

/* Partial material-animation view; curve element meanings remain inferred. */
struct MaterialListsObject {
    MaterialListsWord unknown00, identity;
    const void* table;
    char flags, padding[3];
    MaterialListsCurve<MaterialListsHandleKey> curve10;
    MaterialListsCurve<MaterialListsElement<12> > curve20, curve30;
    MaterialListsCurve<MaterialListsElement<8> > curve40;
    MaterialListsCurve<MaterialListsElement<16> > curve50, curve60;
    MaterialListsCurve<MaterialListsElement<8> > curve70, curve80, curve90, curveA0;
    float first, second;
    MaterialListsHandle2 handle;
};

extern "C" MaterialListsObject* fn_80239D30(MaterialListsObject*, short);

#endif
