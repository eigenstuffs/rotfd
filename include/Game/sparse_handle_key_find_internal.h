#ifndef GAME_SPARSE_HANDLE_KEY_FIND_INTERNAL_H
#define GAME_SPARSE_HANDLE_KEY_FIND_INTERNAL_H

#include "Game/handle_list_operations_internal.h"
struct SparseHandleBits {int count,capacity;unsigned long*data;int bits;};
extern "C" int fn_80207B94(SparseHandleBits*,int,int);
struct SparseHandleKeyPool {int count,capacity;Handle*data;SparseHandleBits occupied;int limit,used;
 Handle&operator[](int i){return data[i];}
 int first(){if(limit==0)return -1;return fn_80207B94(&occupied,1,0);}
 int next(int i){if(i+1>=limit)return -1;return fn_80207B94(&occupied,1,i+1);}
};

typedef char CheckSparseHandleKeyBits[sizeof(SparseHandleBits)==16?1:-1];
typedef char CheckSparseHandleKeyPool[sizeof(SparseHandleKeyPool)==0x24?1:-1];
#endif
