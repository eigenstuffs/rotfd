/* Read an optional named resource, dispatch its stream reader, and retain it.
 * This partial unit emits only the original 428-byte C entry. */
typedef unsigned long Word;
struct Stream{void*position;};
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10(){}Handle_801F7F10(const Handle_801F7F10&);~Handle_801F7F10();};
struct NodeStorage{Word unknown00[2];};
struct Node:NodeStorage{virtual void slot08();virtual void read(Stream*);};
extern "C"{
 extern char lbl_8028F698[];
 void*fn_8028FAF4(void*,void*,Word,Word);void*fn_8028FF24(void*,Word);void fn_8028FD50(void*,void*,Word);
 void*fn_801E9F40(void*,const void*,int);
 Handle_801F7F10 fn_801B550C(void*,const Word&,const Word&);
 void fn_801F7914(Handle_801F7F10*,const Handle_801F7F10&);
 void fn_801F7CB4(Handle_801F7F10*,const Handle_801F7F10*);
 Node*fn_801F7EB8(const Handle_801F7F10*);
}
inline void*operator new(unsigned long,void*p){return p;}
struct Element:Handle_801F7F10{Element(const Handle_801F7F10&h){fn_801F7CB4(this,&h);}~Element(){}};
struct Array{int count,capacity;Element*items;
 void grow(){int n=capacity+32;if(n){if(items)items=(Element*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(Element),n*sizeof(Element));else items=(Element*)fn_8028FF24(lbl_8028F698,n*sizeof(Element));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(Element));items=0;}capacity+=32;}
 void append(const Handle_801F7F10&h){if(count+1>capacity)grow();new(items+count++)Element(h);}
};
struct Manager{char unknown00[0xB8];Array retained;};
inline void clearOptionalHandle(Handle_801F7F10*handle){
  Handle_801F7F10 zero;zero.bits.index=0;zero.bits.tag=0;
  fn_801F7914(handle,zero);
}
extern "C"void fn_801B3FD0(Manager*self,Handle_801F7F10*handle,Stream*stream){
 Word first=0;stream->position=fn_801E9F40(&first,stream->position,4);
 if(first){
  Word second=0;stream->position=fn_801E9F40(&second,stream->position,4);
  fn_801F7914(handle,fn_801B550C(self,first,second));
  fn_801F7EB8(handle)->read(stream);
  self->retained.append(*handle);
 }else{clearOptionalHandle(handle);
 }
}
