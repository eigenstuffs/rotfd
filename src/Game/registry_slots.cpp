typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[];
void*fn_8028FAF4(void*,void*,u32,u32);
void*fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
void fn_80208888(void*);
int fn_80207B94(void*,int,int);
}
inline void*operator new(unsigned long,void*p){return p;}
struct HashTable {int cursor,capacity,count;void**slots;HashTable(){fn_80208888(this);}};
struct RegistryValue {u32 value;RegistryValue(){} RegistryValue(const RegistryValue&v):value(v.value){}};
template<class T>struct Array {
 int size,capacity;T*data;
 void storage(int count){
  if(count){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),count*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));}
  else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}
 }
 void resize(int count){
  if(count>size){storage(count);capacity=count;for(int i=size;i<count;++i)new(data+i)T;size=count;}
  else if(count<size){for(int i=size-1;i>=count;--i)data[i].~T();storage(count);capacity=count;size=count;}
 }
 void append(){if(size+1>capacity){storage(capacity+32);capacity+=32;}new(data+size++)T;}
 void append(const T&v){if(size+1>capacity){storage(capacity+32);capacity+=32;}new(data+size++)T(v);}
};
struct BitFlags:Array<u32> {
 long bits;
 void resizeBits(int count){bits=count;if(count&&((count>>5)+1)>size)resize((bits>>5)+1);}
 void set(int i){data[i>>5]|=1UL<<(i&31);}
};
template<class T>struct Pool:Array<T>{BitFlags flags;int limit,count;};
extern "C" {
int fn_801F6038(Pool<HashTable>*p){
 int index=p->limit==0?-1:fn_80207B94(&p->flags,0,0);
 ++p->count;
 if(index==-1){p->append();p->flags.resizeBits(p->limit+1);p->flags.set(p->limit);return p->limit++;}
 new(p->data+index)HashTable;
 p->flags.set(index);return index;
}
int fn_801F6330(Pool<RegistryValue>*p,const RegistryValue*v){
 int index=p->limit==0?-1:fn_80207B94(&p->flags,0,0);
 ++p->count;
 if(index==-1){p->append(*v);p->flags.resizeBits(p->limit+1);p->flags.set(p->limit);return p->limit++;}
 p->data[index]=*v;
 p->flags.set(index);return index;
}
}
