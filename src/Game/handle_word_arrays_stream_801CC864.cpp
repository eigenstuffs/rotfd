/* Handle and word array stream reconstruction; see docs/notes/game-handle-word-arrays-stream.md. */
typedef unsigned long HandleStreamWord;
struct Handle_801F7F10{HandleStreamWord value;Handle_801F7F10();~Handle_801F7F10();};
struct HandleArrayStream{void*position;};
extern "C"{extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,HandleStreamWord,HandleStreamWord);void*fn_8028FF24(void*,HandleStreamWord);void fn_8028FD50(void*,void*,HandleStreamWord);void*fn_801E9F40(void*,const void*,int);void fn_801B3FD0(void*,Handle_801F7F10*,HandleArrayStream*);}
inline void*operator new(unsigned long,void*p){return p;}
struct HandleWordStreamZero:Handle_801F7F10{HandleWordStreamZero(){value=0;}~HandleWordStreamZero(){}};
extern "C"{
 extern char lbl_801EF5C8[],lbl_802ACD08[],lbl_802ACD18[];
 void fn_80243DE4(void*,HandleArrayStream*);
 void*fn_801F7EB8(const Handle_801F7F10*);
 void fn_801F86C8(void*,const Handle_801F7F10*,int);
 void fn_801B41B8(void*,HandleStreamWord*,HandleArrayStream*);
 void*fn_801EF83C(void*,void*,HandleStreamWord,const char*,const char*,int);
 void*fn_801EFA1C(void*,HandleStreamWord,const char*,const char*,int,int);
 void fn_801EF610(void*,void*);
}
struct HandleWordStreamGlobals{char unknown00[0x118];void*manager;};
extern "C"HandleWordStreamGlobals lbl_801E9D24;
struct HandleStreamValue:HandleWordStreamZero{HandleStreamValue(){value=0;}~HandleStreamValue(){} HandleStreamValue&operator=(const HandleStreamValue&other){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=other.value;fn_801F86C8(lbl_801E9D24.manager,&other,1);return*this;}};
template<class T>struct HandleWordStreamArray{
 int count,capacity;T*items;T&operator[](int i){return items[i];}
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
 void resize(int n){int i;if(n>count){reserve(n);for(i=count;i<n;++i)new(items+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;--i)items[i].~T();reserve(n);count=n;}}
};
struct HandleWordStreamEmpty{HandleStreamWord value;HandleWordStreamEmpty(){}~HandleWordStreamEmpty(){}};
struct HandleWordStreamRawArray{
 unsigned int count,capacity;HandleStreamWord*items;
 void reserve(unsigned int n){if(n){if(items)items=(HandleStreamWord*)fn_801EF83C(lbl_801EF5C8,items,n*4,lbl_802ACD08,lbl_802ACD18,196);else items=(HandleStreamWord*)fn_801EFA1C(lbl_801EF5C8,n*4,lbl_802ACD08,lbl_802ACD18,198,4);}else if(items){fn_801EF610(lbl_801EF5C8,items);items=0;}capacity=n;}
 void resize(unsigned int n){if(n>count){reserve(n);capacity=n;count=n;}else if(n<count){reserve(n);count=n;}}
};
struct HandleWordStreamOwner{
 char unknown00[0x20];HandleWordStreamArray<HandleStreamValue>handles;
 char raw2C[0x20];char unknown4C[0x74];struct Raw{char bytes[0x38];}rawC0;struct Vector{float x,y,z;}tailF8;HandleStreamWord names[3];
 HandleWordStreamRawArray raw;HandleWordStreamArray<HandleWordStreamEmpty>words;
};
extern "C"void fn_801CC864(HandleWordStreamOwner*self,HandleArrayStream*stream){
 fn_80243DE4(self,stream);
 int count;stream->position=fn_801E9F40(&count,stream->position,4);self->handles.resize(count);
 for(int i=0;i<count;++i){
  fn_801B3FD0(lbl_801E9D24.manager,&self->handles[i],stream);
  if(!fn_801F7EB8(&self->handles[i]))self->handles[i]=self->handles[i-1];
 }
 stream->position=fn_801E9F40(self->raw2C,stream->position,(char*)self->unknown4C-self->raw2C);
 stream->position=fn_801E9F40(&self->rawC0,stream->position,(char*)&self->tailF8-(char*)&self->rawC0+sizeof(self->tailF8));
 fn_801B41B8(lbl_801E9D24.manager,&self->names[0],stream);
 fn_801B41B8(lbl_801E9D24.manager,&self->names[1],stream);
 fn_801B41B8(lbl_801E9D24.manager,&self->names[2],stream);
 stream->position=fn_801E9F40(&count,stream->position,4);self->raw.resize(count);
 stream->position=fn_801E9F40(self->raw.items,stream->position,count*4);
 stream->position=fn_801E9F40(&count,stream->position,4);self->words.resize(count);
 stream->position=fn_801E9F40(self->words.items,stream->position,count*4);
}
