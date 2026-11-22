typedef unsigned long GroupArrayStreamWord;
struct Handle_801F7F10{GroupArrayStreamWord value;Handle_801F7F10();~Handle_801F7F10();};
struct GroupArrayInputStream{void*position;};
extern "C"{extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,GroupArrayStreamWord,GroupArrayStreamWord);void*fn_8028FF24(void*,GroupArrayStreamWord);void fn_8028FD50(void*,void*,GroupArrayStreamWord);void*fn_801E9F40(void*,const void*,int);void fn_801B3FD0(void*,Handle_801F7F10*,GroupArrayInputStream*);}
inline void*operator new(unsigned long,void*p){return p;}
struct GroupArrayStreamZero:Handle_801F7F10{GroupArrayStreamZero(){value=0;}~GroupArrayStreamZero(){}};
extern "C"{
 extern char lbl_801EF5C8[],lbl_802ACD08[],lbl_802ACD18[];
 void fn_80243DE4(void*,GroupArrayInputStream*);
 void*fn_801F7EB8(const Handle_801F7F10*);
 void fn_801F86C8(void*,const Handle_801F7F10*,int);
 void fn_801B41B8(void*,GroupArrayStreamWord*,GroupArrayInputStream*);
 void*fn_801EF83C(void*,void*,GroupArrayStreamWord,const char*,const char*,int);
 void*fn_801EFA1C(void*,GroupArrayStreamWord,const char*,const char*,int,int);
 void fn_801EF610(void*,void*);
}
struct GroupArrayStreamGlobals{char unknown00[0x118];void*manager;};
extern "C"GroupArrayStreamGlobals lbl_801E9D24;
struct GroupArrayStreamValue:GroupArrayStreamZero{GroupArrayStreamValue(){value=0;}~GroupArrayStreamValue(){} GroupArrayStreamValue&operator=(const GroupArrayStreamValue&other){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=other.value;fn_801F86C8(lbl_801E9D24.manager,&other,1);return*this;}};
template<class T>struct GroupArrayStreamArray{
 int count,capacity;T*items;T&operator[](int i){return items[i];}
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
 void resize(int n){int i;if(n>count){reserve(n);for(i=count;i<n;++i)new(items+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;--i)items[i].~T();reserve(n);count=n;}}
};

extern "C"void fn_801CFC90(void*,GroupArrayInputStream*);
template<int N>struct GroupArrayStreamElement{char bytes[N];GroupArrayStreamElement(){}~GroupArrayStreamElement(){}};
struct GroupArrayStreamOwner{
 char unknown00[0x8C];GroupArrayStreamArray<GroupArrayStreamElement<4> >words;
 GroupArrayStreamArray<GroupArrayStreamElement<12> >vectors;
 GroupArrayStreamArray<GroupArrayStreamElement<8> >pairs;
 GroupArrayStreamArray<GroupArrayStreamValue>handles;unsigned short tail;
};
extern "C"void fn_801D0650(GroupArrayStreamOwner*self,GroupArrayInputStream*stream){
 fn_801CFC90(self,stream);
 int count;stream->position=fn_801E9F40(&count,stream->position,4);self->words.resize(count);
 stream->position=fn_801E9F40(self->words.items,stream->position,count*sizeof(GroupArrayStreamElement<4>));
 stream->position=fn_801E9F40(&count,stream->position,4);self->vectors.resize(count);
 stream->position=fn_801E9F40(self->vectors.items,stream->position,count*sizeof(GroupArrayStreamElement<12>));
 stream->position=fn_801E9F40(&count,stream->position,4);self->pairs.resize(count);
 stream->position=fn_801E9F40(self->pairs.items,stream->position,count*sizeof(GroupArrayStreamElement<8>));
 stream->position=fn_801E9F40(&count,stream->position,4);self->handles.resize(count);
 for(int i=0;i<count;++i)fn_801B41B8(lbl_801E9D24.manager,&self->handles[i].value,stream);
 stream->position=fn_801E9F40(&self->tail,stream->position,2);
}
