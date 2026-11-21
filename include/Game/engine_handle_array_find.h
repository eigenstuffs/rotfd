#ifndef GAME_ENGINE_HANDLE_ARRAY_FIND_H
#define GAME_ENGINE_HANDLE_ARRAY_FIND_H

struct Handle_801F7F10 {
    union { unsigned long value; struct { signed int tag:8; signed int index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ArrayFindObject { unsigned long key; };
struct ArrayFindEntry { ArrayFindObject *object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct ArrayFindManager { int count,capacity; ArrayFindEntry *entries; };
extern "C" {
extern struct ArrayFindContext { char unknown00[0x118]; ArrayFindManager *manager; } lbl_801E9D24;
void fn_801F86C8(ArrayFindManager *,const Handle_801F7F10 *,short);
unsigned long fn_801F7EB8(const Handle_801F7F10 *);
}
struct ArrayFindZero : Handle_801F7F10 { ArrayFindZero(){value=0;} };
struct ArrayFindZero2 : ArrayFindZero { ArrayFindZero2(){value=0;} };
struct ArrayFind { int count,capacity; Handle_801F7F10 *handles; };

extern "C" void fn_8023A8C0(ArrayFind *, const unsigned long *, Handle_801F7F10 *);

#endif
