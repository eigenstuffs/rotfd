/* Resource row-array resizing reconstructed from GSQE78. */
typedef unsigned long u32;
extern "C" {extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,u32,u32);void*fn_8028FF24(void*,u32);void fn_8028FD50(void*,void*,u32);}
inline void*operator new(unsigned long,void*p){return p;}
namespace {
template<class T>struct Array {
 int size,capacity;T*data;
 Array(){size=0;capacity=0;data=0;}
 void storage(int count){if(count){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),count*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 ~Array(){if(data){for(int i=0;i<size;++i)data[i].~T();storage(0);data=0;}}
};
struct ResizeEntry {int type;u32 reference,unknown;~ResizeEntry(){}};
struct ResizeRow {short id;Array<ResizeEntry>entries;ResizeRow():id(0){}};
}
extern "C" void fn_801F6F04(Array<ResizeRow>*a,int count,char keepCapacity){
 if(count>a->size){
  if(count>a->capacity||!keepCapacity){a->storage(count);a->capacity=count;}
  for(int i=a->size;i<count;++i)new(a->data+i)ResizeRow;
  a->size=count;
 }else if(count<a->size){
  for(int i=a->size-1;i>=count;--i)a->data[i].~ResizeRow();
  if(keepCapacity)a->size=count;
  else {a->storage(count);a->capacity=count;a->size=count;}
 }
}
