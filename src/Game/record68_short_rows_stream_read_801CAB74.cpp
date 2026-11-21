// Read the observed68-byte records and nested16-bit rows from an advancing stream.
// Record fields remain opaque; the original preceding reader and nested-array resizer remain external.
typedef unsigned long StreamWord;
extern "C"{
 extern char lbl_8028F698[];
 void*fn_8028FAF4(void*,void*,StreamWord,StreamWord);
 void*fn_8028FF24(void*,StreamWord);
 void fn_8028FD50(void*,void*,StreamWord);
 void*fn_801E9F40(void*,const void*,unsigned long);
}
inline void*operator new(unsigned long,void*p){return p;}
template<class T>struct StreamArray{
 int count,capacity;T*items;T&operator[](int i){return items[i];}
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
 void resize(int n){int i;if(n>count){reserve(n);for(i=count;i<n;++i)new(items+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;--i)items[i].~T();reserve(n);count=n;}}
};

extern "C"void fn_801D5338(void*,void**);
extern "C"void fn_801CAEE0(void*,int,signed char);
struct Record68{StreamWord value[17];Record68(){}~Record68(){}};
struct RecordRowsStreamView{char unknown00[0xD8];StreamArray<Record68>words;StreamArray<StreamArray<unsigned short> >rows;};
extern "C"void fn_801CAB74(RecordRowsStreamView*self,void**stream){
 fn_801D5338(self,stream);int count;
 *stream=fn_801E9F40(&count,*stream,4);self->words.resize(count);
 *stream=fn_801E9F40(self->words.items,*stream,count*sizeof(Record68));
 *stream=fn_801E9F40(&count,*stream,4);fn_801CAEE0(&self->rows,count,0);
 for(int i=0;i<count;++i){int size;*stream=fn_801E9F40(&size,*stream,4);self->rows[i].resize(size);*stream=fn_801E9F40(self->rows[i].items,*stream,size*2);}
}

typedef char RecordStride[(sizeof(Record68)==68)?1:-1];
typedef char RowSize[(sizeof(StreamArray<unsigned short>)==12)?1:-1];
