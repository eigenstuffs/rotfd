/* Resource record deserialization reconstructed from GSQE78. */
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[];
void*fn_8028FAF4(void*,void*,u32,u32);
void*fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
void*fn_801E9F40(void*,void*,int);
void fn_801F6F04(void*,int,char);
u32 fn_801B4C30(void*,const char*);
void fn_801B41F4(void*,u32*,void**);
}
inline void*operator new(unsigned long,void*p){return p;}
template<class T>struct RefArray {
 u32 prefix;int size,capacity;T*data;
 T&operator[](int i){return data[i];}
 void storage(int count){if(count){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),count*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 void resize(int count){if(count>size){storage(count);capacity=count;for(int i=size;i<count;++i)new(data+i)T;size=count;}else if(count<size){for(int i=size-1;i>=count;--i)data[i].~T();storage(count);capacity=count;size=count;}}
};
struct RefEntry {int type;u32 reference,unknown;RefEntry(){unknown=0;type=-1;reference=0;}int isType(int value)const{return type==value;}~RefEntry(){}};
struct RefRow:RefArray<RefEntry>{};
struct ActionList:RefArray<RefRow>{u32 extra;};
struct GameGlobals {char unknown[0x118];void*context;};
extern "C" {
extern GameGlobals lbl_801E9D24;
void fn_801F6BFC(ActionList*o,void**stream){
 char buffer[128];int rows,entries,length;
 *stream=fn_801E9F40(&o->prefix,*stream,2);
 *stream=fn_801E9F40(&rows,*stream,4);
 fn_801F6F04(&o->size,rows,0);
 for(int i=0;i<rows;++i){
  *stream=fn_801E9F40(&(*o)[i].prefix,*stream,2);
  *stream=fn_801E9F40(&entries,*stream,4);
  (*o)[i].resize(entries);
  for(int j=0;j<entries;++j){
   *stream=fn_801E9F40(&(*o)[i][j],*stream,8);
   if((*o)[i][j].isType(17)||(*o)[i][j].isType(18)||(*o)[i][j].isType(19)){
    *stream=fn_801E9F40(&length,*stream,4);
    *stream=fn_801E9F40(buffer,*stream,length);
    buffer[length]=0;
    (*o)[i][j].reference=fn_801B4C30(lbl_801E9D24.context,buffer);
   }
   fn_801B41F4(lbl_801E9D24.context,&(*o)[i][j].unknown,stream);
  }
 }
}
}
