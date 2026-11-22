#include "Game/path_owner_operations_table.h"
typedef unsigned long SparseHandleDestroyWord;
extern "C"{
 extern char lbl_8028F698[],lbl_801EF5C8[],lbl_802EAAB8[];
 void fn_8028FD50(void*,void*,SparseHandleDestroyWord);
 void fn_801EF610(void*,void*);
}
struct Handle_801F7F10{SparseHandleDestroyWord value;~Handle_801F7F10();};
template<int N>struct SparseHandleDestroyElement{char bytes[N];~SparseHandleDestroyElement(){}};
struct SparseHandleDestroyRecord{char bytes[129];};
template<class T>struct SparseHandleDestroyArray{
 int count,capacity;T*items;
 void release(){if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}}
 ~SparseHandleDestroyArray(){if(items){for(int i=0;i<count;++i)items[i].~T();release();items=0;}}
};
struct BitSet_80207EE8{
 int count,capacity;SparseHandleDestroyWord*words;int bits;
 ~BitSet_80207EE8();
 const SparseHandleDestroyWord&word(int i)const{return words[i];}
 signed char test(int i)const{const SparseHandleDestroyWord&flags=word(i>>5);return ((1UL<<(i&31))&flags)?1:0;}
 void clear(int i){words[i>>5]&=~(1UL<<(i&31));}
};
struct SparseHandleDestroyRecords{int count,capacity;SparseHandleDestroyRecord*items;~SparseHandleDestroyRecords(){if(items){if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(SparseHandleDestroyRecord));items=0;}items=0;}}};
struct SparseHandleDestroySparse:SparseHandleDestroyRecords{
 BitSet_80207EE8 occupied;int limit,used;
 ~SparseHandleDestroySparse(){for(int i=0;i<limit;++i){if(occupied.test(i)){items[i].~SparseHandleDestroyRecord();occupied.clear(i);--used;}}}
};
struct SparseHandleDestroyOwner{
 SparseHandleDestroyArray<SparseHandleDestroyElement<16> >first;
 SparseHandleDestroyArray<SparseHandleDestroyElement<4> >second;
 char unknown18[0xC];void*table;
 SparseHandleDestroyArray<SparseHandleDestroyElement<16> >third;
 char unknown34[0x84];SparseHandleDestroyArray<Handle_801F7F10>handles;
 char unknownC4[8];SparseHandleDestroySparse sparse;
};
extern "C"SparseHandleDestroyOwner*fn_801B58D0(SparseHandleDestroyOwner*self,int deleting){
 if(self){
  self->table=&lbl_802E9E70;
  self->sparse.~SparseHandleDestroySparse();
  self->handles.~SparseHandleDestroyArray<Handle_801F7F10>();
  self->third.~SparseHandleDestroyArray<SparseHandleDestroyElement<16> >();
  if(self){self->table=lbl_802EAAB8;
   self->second.~SparseHandleDestroyArray<SparseHandleDestroyElement<4> >();
   self->first.~SparseHandleDestroyArray<SparseHandleDestroyElement<16> >();
  }
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}

typedef char SparseHandleDestroyOwnerSize[sizeof(SparseHandleDestroyOwner)==0xF0?1:-1];
