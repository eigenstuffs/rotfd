#ifndef GAME_HANDLE_KEY_FIND_INTERNAL_H
#define GAME_HANDLE_KEY_FIND_INTERNAL_H

#include "Game/handle_array_clear_internal.h"
extern "C" void fn_801F86C8(Manager*,const Handle*,short);
struct KeyFindNativeHandle:Handle_801F7F10 {KeyFindNativeHandle(){value=0;}KeyFindNativeHandle(const KeyFindNativeHandle&h){value=0;value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct KeyFindTypedHandle:KeyFindNativeHandle {KeyFindTypedHandle(){value=0;}};
struct KeyFindArray {int count,capacity;KeyFindTypedHandle*data;KeyFindTypedHandle&operator[](int i){return data[i];}};
struct KeyFindView {char unknown00[12];KeyFindArray first;char unknown18[12];KeyFindArray second;};

typedef char CheckKeyFindHandle[sizeof(KeyFindTypedHandle)==4?1:-1];
typedef char CheckKeyFindArray[sizeof(KeyFindArray)==12?1:-1];
#endif
