#ifndef GAME_ARRAY_PAIR_READ_INTERNAL_H
#define GAME_ARRAY_PAIR_READ_INTERNAL_H

inline void*operator new(unsigned long,void*p){return p;}
extern "C" {extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);void fn_801CDCB0(void*,const char**);const char*fn_801E9F40(void*,const void*,unsigned long);}
struct ReadRecord16 {float x,y,z,w;ReadRecord16(){}~ReadRecord16(){}};
struct ReadRecord4 {unsigned long value;ReadRecord4(){}~ReadRecord4(){}};
template<class T>struct ReadArray {int count,capacity;T*data;T&operator[](int i){return data[i];}
 void storage(int n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}capacity=n;}
 void resize(int n){if(n>count){storage(n);for(int i=count;i<n;++i)new(&(*this)[i])T;count=n;}else if(n<count){for(int i=count-1;i>=n;--i)(*this)[i].~T();storage(n);count=n;}}
};
struct ReadArrayPair {char unknown00[0xEC];ReadArray<ReadRecord16>first;ReadArray<ReadRecord4>second;};

typedef char CheckReadRecord16[sizeof(ReadRecord16)==16?1:-1];
typedef char CheckReadRecord4[sizeof(ReadRecord4)==4?1:-1];
typedef char CheckReadArray[sizeof(ReadArray<ReadRecord16>)==12?1:-1];
#endif
