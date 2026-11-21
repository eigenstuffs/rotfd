#include "Game/typed_array_stream_read_801dab34.h"

/* Partial stream owner view. Native constructors, allocation services, diagnostics, and zero storage remain borrowed. */
typedef unsigned long TypedReadWord;
struct Handle_801F7F10 {TypedReadWord value;Handle_801F7F10();~Handle_801F7F10();};
struct Vector2_800C3BC4 {float x,y;Vector2_800C3BC4();};
struct Vector3_801D5330 {float x,y,z;Vector3_801D5330();};
struct TypedReadVec4 {float x,y,z,w;TypedReadVec4();~TypedReadVec4(){}};
struct TypedReadZero4 {float x,y,z,w;};
struct TypedReadManager;
struct TypedReadGlobals {char unknown[0x118];TypedReadManager*manager;};
extern "C" {
extern TypedReadGlobals lbl_801E9D24;
extern char lbl_8028F698[],lbl_801EF5C8[],lbl_802ACD48[],lbl_802ACD58[];
extern TypedReadZero4 game_vec4_zero;
extern const float lbl_8037A4D8;
void fn_801CFC90(void*,TypedArrayStreamInput_801DAB34*);
void*fn_801E9F40(void*,const void*,TypedReadWord);
void*fn_8028FAF4(void*,void*,TypedReadWord,TypedReadWord);
void*fn_8028FF24(void*,TypedReadWord);
void fn_8028FD50(void*,void*,TypedReadWord);
void fn_801B41B8(TypedReadManager*,Handle_801F7F10*,TypedArrayStreamInput_801DAB34*);
void*fn_801EFA1C(void*,TypedReadWord,const char*,const char*,int,int);
void*fn_80266758(void*);
void fn_802647FC(void*,TypedArrayStreamInput_801DAB34*);
void fn_801D8494(void*,void*,void*);
}
inline TypedReadVec4::TypedReadVec4(){x=game_vec4_zero.x;y=game_vec4_zero.y;z=game_vec4_zero.z;w=lbl_8037A4D8;}
inline void*operator new(TypedReadWord,void*p){return p;}
struct TypedReadZeroHandle:Handle_801F7F10 {TypedReadZeroHandle(){value=0;}~TypedReadZeroHandle(){}};
struct TypedReadLocalHandle:TypedReadZeroHandle {TypedReadLocalHandle(){value=0;}~TypedReadLocalHandle(){}};
template<int N>struct TypedReadEmptyRecord {char bytes[N];TypedReadEmptyRecord(){}~TypedReadEmptyRecord(){}};
struct TypedReadRecord24A {TypedReadWord unknown[2];TypedReadVec4 position;};
struct TypedReadRecord144 {Vector2_800C3BC4 uv[4];Vector3_801D5330 points[4];char unknown[0x38];TypedReadLocalHandle handle;TypedReadWord index;};
struct TypedReadRecord104 {TypedReadVec4 position;char unknown[0x50];unsigned short tag;char tail[6];TypedReadRecord104(){tag=0xffff;}~TypedReadRecord104(){}};
struct TypedReadRecord24B {TypedReadVec4 position;TypedReadWord index,unknown;TypedReadRecord24B(){index=0;}~TypedReadRecord24B(){}};
struct TypedReadRecord192 {Vector3_801D5330 positions[16];};
template<class T>struct TypedReadArray {
 int count,capacity;T*data;
 void reserve(int n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}capacity=n;}
 void resize(const int n){int i;if(n>count){reserve(n);for(i=count;i<n;i++)new(data+i)T;count=n;}else if(n<count){for(i=count-1;i>=n;i--)data[i].~T();reserve(n);count=n;}}
 T&operator[](int i){return data[i];}
};
struct TypedArrayStreamOwner_801DAB34 {
 char unknown00[0x6e];unsigned short flags;char unknown70[0x1c];
 TypedReadArray<TypedReadRecord24A> first,second;
 TypedReadArray<TypedReadRecord144> records;
 TypedReadArray<TypedReadEmptyRecord<8> > eight;
 TypedReadArray<TypedReadEmptyRecord<12> > twelve;
 TypedReadArray<TypedReadRecord104> records104;
 TypedReadArray<unsigned short> indices;
 TypedReadArray<TypedReadRecord192> positions;
 TypedReadArray<TypedReadRecord24B> last;
 void*aux;
};
extern "C" void fn_801DAB34(TypedArrayStreamOwner_801DAB34*self,TypedArrayStreamInput_801DAB34*stream){
 fn_801CFC90(self,stream);
 int count=self->first.count;int i;
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->first.resize(count);
 stream->current=fn_801E9F40(self->first.data,stream->current,count*sizeof(TypedReadRecord24A));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->second.resize(count);
 stream->current=fn_801E9F40(self->second.data,stream->current,count*sizeof(TypedReadRecord24A));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->records.resize(count);
 for(i=0;i<count;i++){
  TypedReadRecord144*record=&self->records[i];
  stream->current=fn_801E9F40(record,stream->current,(char*)&record->handle-(char*)record);
  fn_801B41B8(lbl_801E9D24.manager,&self->records[i].handle,stream);
  self->records[i].index=i;
 }
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->eight.resize(count);
 stream->current=fn_801E9F40(self->eight.data,stream->current,count*sizeof(TypedReadEmptyRecord<8>));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->twelve.resize(count);
 stream->current=fn_801E9F40(self->twelve.data,stream->current,count*sizeof(TypedReadEmptyRecord<12>));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->records104.resize(count);
 stream->current=fn_801E9F40(self->records104.data,stream->current,count*sizeof(TypedReadRecord104));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->indices.resize(count);
 stream->current=fn_801E9F40(self->indices.data,stream->current,count*sizeof(unsigned short));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->last.resize(count);
 stream->current=fn_801E9F40(self->last.data,stream->current,count*sizeof(TypedReadRecord24B));
 if(!(self->flags&4)){
  signed char present;
  stream->current=fn_801E9F40(&present,stream->current,1);
  if(present){void*p=fn_801EFA1C(lbl_801EF5C8,0x88,lbl_802ACD48,lbl_802ACD58,0x3f,4);if(p)p=fn_80266758(p);self->aux=p;fn_802647FC(self->aux,stream);}
  else self->aux=0;
 }
 self->positions.resize(self->records.count);
 for(i=0;i<self->records.count;i++)fn_801D8494(self,&self->records[i],&self->positions[i]);
}
