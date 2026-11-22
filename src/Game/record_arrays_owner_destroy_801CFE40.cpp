#include "Game/owner_viewport_interface_tables.h"
typedef unsigned long RecordArraysDestroyWord;
extern "C"{
 extern char lbl_8028F698[],lbl_801EF5C8[],lbl_802EA498[];
 void fn_8028FD50(void*,void*,RecordArraysDestroyWord);
 void fn_801EF610(void*,void*);
 void fn_80243E90(void*,int);
}
struct Handle_801F7F10{RecordArraysDestroyWord value;~Handle_801F7F10();};
struct RecordArraysDestroyZero:Handle_801F7F10{~RecordArraysDestroyZero(){}};
struct RecordArraysDestroyHandle:RecordArraysDestroyZero{~RecordArraysDestroyHandle(){}};
template<int N>struct RecordArraysDestroyElement{char bytes[N];~RecordArraysDestroyElement(){}};
template<class T>struct RecordArraysDestroyArray{
 int count,capacity;T*items;
 void release(){if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}}
 ~RecordArraysDestroyArray(){if(items){for(int i=0;i<count;++i)items[i].~T();release();items=0;}}
};
struct RecordArraysDestroyOwner{
 char unknown00[8];void*table;char unknown0C[0x68];
 RecordArraysDestroyArray<RecordArraysDestroyElement<12> >first;
 RecordArraysDestroyArray<RecordArraysDestroyElement<4> >second;
 RecordArraysDestroyArray<RecordArraysDestroyElement<4> >third;
 RecordArraysDestroyArray<RecordArraysDestroyElement<12> >fourth;
 RecordArraysDestroyArray<RecordArraysDestroyElement<8> >fifth;
 RecordArraysDestroyArray<RecordArraysDestroyHandle>handles;
};
extern "C"RecordArraysDestroyOwner*fn_801CFE40(RecordArraysDestroyOwner*self,int deleting){
 if(self){
  self->table=&lbl_802EA4F8;
  self->handles.~RecordArraysDestroyArray<RecordArraysDestroyHandle>();
  self->fifth.~RecordArraysDestroyArray<RecordArraysDestroyElement<8> >();
  self->fourth.~RecordArraysDestroyArray<RecordArraysDestroyElement<12> >();
  self->third.~RecordArraysDestroyArray<RecordArraysDestroyElement<4> >();
  if(self){
   self->table=lbl_802EA498;
   self->second.~RecordArraysDestroyArray<RecordArraysDestroyElement<4> >();
   self->first.~RecordArraysDestroyArray<RecordArraysDestroyElement<12> >();
   fn_80243E90(self,0);
  }
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
