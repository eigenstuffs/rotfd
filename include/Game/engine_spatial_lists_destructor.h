#ifndef GAME_ENGINE_SPATIAL_LISTS_DESTRUCTOR_H
#define GAME_ENGINE_SPATIAL_LISTS_DESTRUCTOR_H

typedef unsigned long SpatialListsWord;
extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[];
extern char __vt__23SpatialBinding_802EC2C0[], __vt__20SpatialBase_802EC118[];
extern char __vt__17Resource_802E9E20[];
extern struct SpatialListsGlobals { char unknown00[0x144]; void* manager; } lbl_801E9D24;
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
void fn_801AD8D4(void*, int);
void* __dt__12BaseObject_ZFv(void*, short);
}

struct Handle_801F7F10 { SpatialListsWord word; ~Handle_801F7F10(); };
struct SpatialListsHandle1 : Handle_801F7F10 { ~SpatialListsHandle1() {} };
struct SpatialListsHandle2 : SpatialListsHandle1 { ~SpatialListsHandle2() {} };
struct SpatialListsHandle3 : SpatialListsHandle2 { ~SpatialListsHandle3() {} };
struct SpatialListsElement { SpatialListsWord word; ~SpatialListsElement() {} };

struct SpatialListsRecordBase {
    SpatialListsWord unknown00;
    SpatialListsHandle2 handle;
    char unknown08[16];
    ~SpatialListsRecordBase() {}
};
struct SpatialListsRecord : SpatialListsRecordBase { ~SpatialListsRecord() {} };

template<class T> struct SpatialListsArray {
    int count, capacity;
    T* data;
    ~SpatialListsArray() {
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
typedef SpatialListsArray<SpatialListsElement> SpatialListsNumbers;

/* Partial storage view of the retained SpatialBinding destruction entry. */
struct SpatialListsObject {
    SpatialListsWord unknown00, identity;
    const void* table;
    char unknown0C[0x14];
    SpatialListsArray<SpatialListsHandle2> array20;
    SpatialListsHandle2 handle;
    SpatialListsArray<SpatialListsHandle2> array30;
    int index;
    SpatialListsArray<SpatialListsRecord> array40, array4C, array58;
    SpatialListsArray<SpatialListsHandle3> array64;
    SpatialListsArray<SpatialListsNumbers> array70;
};

extern "C" SpatialListsObject* fn_8024C8CC(SpatialListsObject*, short);

#endif
