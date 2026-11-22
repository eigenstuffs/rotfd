typedef unsigned long NestedRecordDestroyWord;
extern "C"{
 extern char lbl_8028F698[],lbl_801EF5C8[],lbl_802EA388[],lbl_802EA498[];
 void fn_8028FD50(void*,void*,NestedRecordDestroyWord);
 void fn_801EF610(void*,void*);
 void fn_80243E90(void*,int);
}
struct Handle_801F7F10{NestedRecordDestroyWord value;~Handle_801F7F10();};
struct NestedRecordDestroyZero:Handle_801F7F10{~NestedRecordDestroyZero(){}};
struct NestedRecordDestroyHandle:NestedRecordDestroyZero{~NestedRecordDestroyHandle(){}};
template<int N>struct NestedRecordDestroyElement{char bytes[N];~NestedRecordDestroyElement(){}};
template<class T>struct NestedRecordDestroyArray{
 int count,capacity;T*items;
 void release(){if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}}
 ~NestedRecordDestroyArray(){if(items){for(int i=0;i<count;++i)items[i].~T();release();items=0;}}
};
struct NestedRecordDestroyWords:NestedRecordDestroyArray<NestedRecordDestroyElement<4> >{~NestedRecordDestroyWords(){}};
struct NestedRecordDestroyShorts:NestedRecordDestroyArray<NestedRecordDestroyElement<2> >{char unknown0C[8];~NestedRecordDestroyShorts(){}};
struct NestedRecordDestroyOwner{
 char unknown00[8];void*table;char unknown0C[0x68];
 NestedRecordDestroyArray<NestedRecordDestroyElement<12> >first;
 NestedRecordDestroyArray<NestedRecordDestroyElement<4> >second;
 NestedRecordDestroyArray<NestedRecordDestroyElement<12> >third;
 NestedRecordDestroyArray<NestedRecordDestroyElement<8> >fourth;
 NestedRecordDestroyArray<NestedRecordDestroyShorts>shorts;
 NestedRecordDestroyArray<NestedRecordDestroyWords>words;
 NestedRecordDestroyArray<NestedRecordDestroyHandle>handles;
 NestedRecordDestroyArray<NestedRecordDestroyElement<16> >seventh;
 NestedRecordDestroyArray<NestedRecordDestroyElement<80> >eighth;
 NestedRecordDestroyArray<NestedRecordDestroyElement<36> >ninth;
};
extern "C"NestedRecordDestroyOwner*fn_801CEED0(NestedRecordDestroyOwner*self,int deleting){
 if(self){
  self->table=lbl_802EA388;
  self->ninth.~NestedRecordDestroyArray<NestedRecordDestroyElement<36> >();
  self->eighth.~NestedRecordDestroyArray<NestedRecordDestroyElement<80> >();
  self->seventh.~NestedRecordDestroyArray<NestedRecordDestroyElement<16> >();
  self->handles.~NestedRecordDestroyArray<NestedRecordDestroyHandle>();
  self->words.~NestedRecordDestroyArray<NestedRecordDestroyWords>();
  self->shorts.~NestedRecordDestroyArray<NestedRecordDestroyShorts>();
  self->fourth.~NestedRecordDestroyArray<NestedRecordDestroyElement<8> >();
  self->third.~NestedRecordDestroyArray<NestedRecordDestroyElement<12> >();
  if(self){
   self->table=lbl_802EA498;
   self->second.~NestedRecordDestroyArray<NestedRecordDestroyElement<4> >();
   self->first.~NestedRecordDestroyArray<NestedRecordDestroyElement<12> >();
   fn_80243E90(self,0);
  }
  if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
