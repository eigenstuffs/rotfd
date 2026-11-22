typedef unsigned long SphereRecordStreamWord;
extern "C"{
 extern char lbl_8028F698[];
 void*fn_8028FAF4(void*,void*,SphereRecordStreamWord,SphereRecordStreamWord);
 void*fn_8028FF24(void*,SphereRecordStreamWord);
 void fn_8028FD50(void*,void*,SphereRecordStreamWord);
 void*fn_801E9F40(void*,const void*,int);
 void fn_801D4F98(void*,void**);
 void fn_801D5B08(void*,int,int);
 void fn_801D58C4(void*,int,int);
}
inline void*operator new(unsigned long,void*p){return p;}
template<class T>struct SphereRecordStreamArray{
 int count,capacity;T*items;T&operator[](int i){return items[i];}
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
 void resize(int n){int i;if(n>count){reserve(n);for(i=count;i<n;++i)new(items+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;--i)items[i].~T();reserve(n);count=n;}}
};

extern "C"{void fn_80243DE4(void*,void**);extern const float lbl_8037A4D8[2];}
struct SphereRecordStreamVector{float x,y,z;};
struct SphereRecordStreamVector4{SphereRecordStreamVector position;float w;};
extern "C"SphereRecordStreamVector4 game_vec4_zero;
struct SphereRecordStreamRecord{SphereRecordStreamVector position;float value;char unknown10[0x50];unsigned short index;char unknown62[6];SphereRecordStreamRecord(){position=game_vec4_zero.position;value=lbl_8037A4D8[0];index=0xFFFF;}~SphereRecordStreamRecord(){}};
struct SphereRecordStreamOwner{char unknown00[0x24];SphereRecordStreamArray<SphereRecordStreamRecord>records;};
extern "C"void fn_801DA8C0(SphereRecordStreamOwner*self,void**stream){fn_80243DE4(self,stream);int count;*stream=fn_801E9F40(&count,*stream,4);self->records.resize(count);*stream=fn_801E9F40(self->records.items,*stream,count*sizeof(SphereRecordStreamRecord));}
