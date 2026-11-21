// Read the observed32-byte row records,32-byte header and nested ushort grid.
// Earlier object fields, allocation storage and the three existing resizers remain external.
typedef unsigned long NestedStreamWord;
extern "C"{
 extern char lbl_8028F698[];
 void*fn_8028FAF4(void*,void*,NestedStreamWord,NestedStreamWord);
 void*fn_8028FF24(void*,NestedStreamWord);
 void fn_8028FD50(void*,void*,NestedStreamWord);
 void*fn_801E9F40(void*,const void*,unsigned long);
 void fn_801D4F98(void*,void**);
 void fn_801D5B08(void*,int,signed char);
 void fn_801D58C4(void*,int,signed char);
}
inline void*operator new(unsigned long,void*p){return p;}
template<class T>struct NestedStreamArray{
 int count,capacity;T*items;T&operator[](int i){return items[i];}
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
 void resize(int n){int i;if(n>count){reserve(n);for(i=count;i<n;++i)new(items+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;--i)items[i].~T();reserve(n);count=n;}}
};
struct NestedShortRow{NestedStreamArray<unsigned short>first,second;NestedStreamWord tail[2];};
struct NestedShortStreamView{
 char unknown00[0xA0];NestedStreamArray<NestedShortRow>rows;
 struct Header{char unknown00[24];int width,height;}header;
 NestedStreamArray<NestedStreamArray<unsigned short> >grid;
};
extern "C"void fn_801D5338(NestedShortStreamView*self,void**stream){
 fn_801D4F98(self,stream);
 int rows;int i;*stream=fn_801E9F40(&rows,*stream,4);fn_801D5B08(&self->rows,rows,0);
 for(i=0;i<rows;++i){
  int count;*stream=fn_801E9F40(&count,*stream,4);self->rows[i].first.resize(count);
  *stream=fn_801E9F40(self->rows[i].first.items,*stream,count*2);
  *stream=fn_801E9F40(&count,*stream,4);self->rows[i].second.resize(count);
  *stream=fn_801E9F40(self->rows[i].second.items,*stream,count*2);
  *stream=fn_801E9F40(self->rows[i].tail,*stream,8);
 }
 *stream=fn_801E9F40(&self->header,*stream,(char*)&self->header.height-(char*)&self->header+sizeof(self->header.height));
 fn_801D58C4(&self->grid,self->header.width*self->header.height,0);
 for(i=0;i<self->grid.count;++i){
  rows=self->grid[i].count;*stream=fn_801E9F40(&rows,*stream,4);self->grid[i].resize(rows);
  *stream=fn_801E9F40(self->grid[i].items,*stream,rows*2);
 }
}

typedef char RowStride[(sizeof(NestedShortRow)==32)?1:-1];
typedef char ArrayStride[(sizeof(NestedStreamArray<unsigned short>)==12)?1:-1];
typedef char OwnerPrefix[(sizeof(NestedShortStreamView)==0xD8)?1:-1];
