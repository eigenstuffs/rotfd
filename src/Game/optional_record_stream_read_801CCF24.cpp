typedef unsigned long OptionalStreamWord;
struct OptionalStream{void*position;};
struct OptionalStreamEntry{void*object;OptionalStreamWord metadata;int unknown08;signed char generation;char unknown0D[3];};
struct OptionalStreamManager{int count,capacity;OptionalStreamEntry*entries;};
struct OptionalStreamGlobals{char unknown00[0x118];OptionalStreamManager*manager;char unknown11C[0x28];void*service144;char unknown148[0x10];void*service158;};
extern "C"{extern OptionalStreamGlobals lbl_801E9D24;extern char lbl_801EF5C8[],lbl_802ACD28[],lbl_802ACD38[],lbl_8028F698[];extern const float lbl_8037A45C;void*fn_801EFA1C(void*,OptionalStreamWord,const char*,const char*,int,int);void*fn_8028FAF4(void*,void*,OptionalStreamWord,OptionalStreamWord);void*fn_8028FF24(void*,OptionalStreamWord);void fn_8028FD50(void*,void*,OptionalStreamWord);void*fn_801E9F40(void*,const void*,int);void fn_80243E44(void*,OptionalStream*);void fn_801B41B8(void*,void*,OptionalStream*);void fn_801F67E4(void*,void*,OptionalStreamWord*,OptionalStream*);}
struct OptionalStreamVector{float x,y,z;OptionalStreamVector();};
struct OptionalStreamVector4{float x,y,z,w;};extern "C" OptionalStreamVector4 game_vec4_zero;
inline OptionalStreamVector::OptionalStreamVector(){x=game_vec4_zero.x;y=game_vec4_zero.y;z=game_vec4_zero.z;}
struct OptionalStreamAllocated{static void*operator new(unsigned long size,const char*type,const char*file,int line,int alignment){return fn_801EFA1C(lbl_801EF5C8,size,type,file,line,alignment);}};
struct OptionalStreamSphere:OptionalStreamAllocated{OptionalStreamVector position;float radius;OptionalStreamSphere(){radius=lbl_8037A45C;}};
struct OptionalStreamBox:OptionalStreamAllocated{char unknown00[0x20];float value;OptionalStreamBox(){value=lbl_8037A45C;}};
struct OptionalStreamRecord80:OptionalStreamAllocated{char unknown00[0x50];OptionalStreamRecord80(){}};
struct OptionalStreamIndexedSphere:OptionalStreamSphere{int index;OptionalStreamIndexedSphere(){index=-1;}};
template<class T>inline void readOptional(T*&destination,OptionalStream*stream,int line){signed char active=1;stream->position=fn_801E9F40(&active,stream->position,1);if(active){destination=new(lbl_802ACD28,lbl_802ACD38,line,4)T;stream->position=fn_801E9F40(destination,stream->position,sizeof(T));}}
struct Handle_801F7F10{union{OptionalStreamWord value;struct{signed int generation:8; signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct OptionalStreamZero:Handle_801F7F10{OptionalStreamZero(){value=0;}~OptionalStreamZero(){}};
struct OptionalStreamHandle:OptionalStreamZero{OptionalStreamHandle(){value=0;}~OptionalStreamHandle(){}};
inline void*operator new(unsigned long,void*p){return p;}
template<class T>struct OptionalStreamArray{int count,capacity;T*items;T&operator[](int i){return items[i];}void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}void resize(int n){int i;if(n>count){reserve(n);for(i=count;i<n;++i)new(items+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;--i)items[i].~T();reserve(n);count=n;}}};
struct OptionalStreamOwner{char unknown00[4];Handle_801F7F10 handle;char unknown08[0x68];OptionalStreamSphere*record70;
 OptionalStreamSphere*record74,*record78;OptionalStreamBox*record7C;OptionalStreamRecord80*record80;OptionalStreamSphere*record84;OptionalStreamBox*record88;OptionalStreamRecord80*record8C;OptionalStreamSphere*record90;OptionalStreamBox*record94;OptionalStreamRecord80*record98;OptionalStreamSphere*record9C;OptionalStreamBox*recordA0;OptionalStreamRecord80*recordA4;OptionalStreamSphere*recordA8;OptionalStreamIndexedSphere*recordAC;OptionalStreamSphere*recordB0;
 char rawB4[8];unsigned short flagsBC;char unknownBE[2];OptionalStreamArray<OptionalStreamHandle>handles;};
struct HandleIndex{int value;HandleIndex(int v):value(v){}operator int()const{return value;}};
inline OptionalStreamWord getMetadata(const Handle_801F7F10&handle){OptionalStreamManager*manager=lbl_801E9D24.manager;const HandleIndex index(handle.bits.index);signed char generation=handle.bits.generation;int valid=0;if(index<manager->count&&generation==((signed char*)manager->entries)[index*sizeof(OptionalStreamEntry)+12])valid=1;return valid?*(OptionalStreamWord*)((char*)manager->entries+index*sizeof(OptionalStreamEntry)+4):0;}
extern "C"void fn_801CCF24(OptionalStreamOwner*self,OptionalStream*stream){fn_80243E44(self,stream);
 readOptional(self->record74,stream,21);
 readOptional(self->record78,stream,22);
 readOptional(self->record7C,stream,23);
 readOptional(self->record80,stream,24);
 readOptional(self->record84,stream,25);
 readOptional(self->record88,stream,26);
 readOptional(self->record8C,stream,27);
 readOptional(self->record90,stream,28);
 readOptional(self->record94,stream,29);
 readOptional(self->record98,stream,30);
 readOptional(self->record9C,stream,31);
 readOptional(self->recordA0,stream,32);
 readOptional(self->recordA4,stream,33);
 readOptional(self->recordA8,stream,34);
 readOptional(self->recordAC,stream,35);
 readOptional(self->recordB0,stream,36);
 OptionalStreamSphere*record=0;readOptional(record,stream,38);self->record70=record;
 stream->position=fn_801E9F40(self->rawB4,stream->position,(char*)&self->flagsBC-self->rawB4+sizeof(self->flagsBC));int count;stream->position=fn_801E9F40(&count,stream->position,4);self->handles.resize(count);
 for(int i=0;i<self->handles.count;++i)fn_801B41B8(lbl_801E9D24.manager,&self->handles[i],stream);
 OptionalStreamWord metadata=getMetadata(self->handle);if(self->flagsBC&0x80)fn_801F67E4(lbl_801E9D24.service144,self,&metadata,stream);fn_801F67E4(lbl_801E9D24.service158,self,&metadata,stream);
}
