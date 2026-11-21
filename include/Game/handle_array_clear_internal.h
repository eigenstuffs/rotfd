#ifndef GAME_HANDLE_ARRAY_CLEAR_INTERNAL_H
#define GAME_HANDLE_ARRAY_CLEAR_INTERNAL_H

#include "Game/handle_list_operations_internal.h"

inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10:Handle {Handle_801F7F10();~Handle_801F7F10();};
struct ArrayClearNativeHandle:Handle_801F7F10 {ArrayClearNativeHandle(){value=0;}};
struct ArrayClearTypedHandle:ArrayClearNativeHandle {ArrayClearTypedHandle(){value=0;}};
extern "C" {extern char lbl_8028F698[];void fn_8028FD50(void*,void*,unsigned long);void fn_8023EFAC(Object*,void*);}
struct ArrayClearHandles {
 int count,capacity;ArrayClearTypedHandle*data;
 ArrayClearTypedHandle&operator[](int i){return data[i];}
 void destroy(int n){for(int i=count-1;i>=n;--i)(*this)[i].~ArrayClearTypedHandle();}
 void resize(int n){
  if(n>count){
   if(n>capacity){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ArrayClearTypedHandle));data=0;}capacity=n;}
   for(int i=count;i<n;++i)new(&(*this)[i])ArrayClearTypedHandle;
   count=n;
  }else if(n<count){destroy(n);count=n;}
 }
};
struct ArrayClearView {char unknown00[12];ArrayClearHandles handles;char unknown18[24];Handle owner;};

typedef char CheckArrayClearElement[sizeof(ArrayClearTypedHandle)==4?1:-1];
typedef char CheckArrayClearArray[sizeof(ArrayClearHandles)==12?1:-1];
#endif
