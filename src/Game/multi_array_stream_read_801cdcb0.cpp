#include "Game/multi_array_stream_read_801cdcb0.h"

/* Partial serialized owner view. Original storage, native Handle identities, and zero constants remain external. */
typedef unsigned long MultiReadWord;
struct Handle_801F7F10 { MultiReadWord value; Handle_801F7F10(); ~Handle_801F7F10(); };
struct MultiReadZero4 {float x,y,z,w;};
struct MultiReadVec4 {float x,y,z,w;MultiReadVec4();~MultiReadVec4(){}};
struct MultiReadManager;
struct MultiReadGlobals {char unknown[0x118];MultiReadManager* manager;};
extern "C" {
extern MultiReadGlobals lbl_801E9D24;
extern char lbl_8028F698[];
extern MultiReadZero4 game_vec4_zero;
extern const float lbl_8037A460;
void fn_801CFC90(void*,MultiArrayInput*);
void* fn_801E9F40(void*,const void*,MultiReadWord);
void* fn_8028FAF4(void*,void*,MultiReadWord,MultiReadWord);
void* fn_8028FF24(void*,MultiReadWord);
void fn_8028FD50(void*,void*,MultiReadWord);
void fn_801CEC84(void*,int,signed char);
void fn_801CEA38(void*,int,signed char);
void fn_801B41B8(MultiReadManager*,Handle_801F7F10*,MultiArrayInput*);
}
inline MultiReadVec4::MultiReadVec4(){x=game_vec4_zero.x;y=game_vec4_zero.y;z=game_vec4_zero.z;w=lbl_8037A460;}
inline void*operator new(MultiReadWord,void*p){return p;}
struct MultiReadZeroHandle:Handle_801F7F10 {MultiReadZeroHandle(){value=0;}~MultiReadZeroHandle(){}};
struct MultiReadHandle:MultiReadZeroHandle {MultiReadHandle(){value=0;}~MultiReadHandle(){}};
template<int N>struct MultiReadElement {char bytes[N];MultiReadElement(){}~MultiReadElement(){}};
struct MultiReadRecord36 {MultiReadWord words[8];float last;MultiReadRecord36(){last=lbl_8037A460;}~MultiReadRecord36(){}};
template<class T>struct MultiReadArray {
 int count,capacity;T*data;
 void reserve(int n){
  if(n){
   if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
   else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
  }else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}
  capacity=n;
 }
 void resize(const int n){
  if(n>count){reserve(n);for(int i=count;i<n;i++)new(data+i)T;count=n;}
  else if(n<count){for(int i=count-1;i>=n;i--)data[i].~T();reserve(n);count=n;}
 }
 T&operator[](int i){return data[i];}
};
struct MultiReadShortRow:MultiReadArray<unsigned short>{char extra[8];};
struct MultiArrayStreamOwner {
 char unknown00[0x6E];unsigned short flags;char unknown70[0x1C];
 MultiReadArray<MultiReadElement<12> > twelve;
 MultiReadArray<MultiReadElement<8> > eight;
 MultiReadArray<MultiReadShortRow> shorts;
 MultiReadArray<MultiReadArray<MultiReadWord> > words;
 MultiReadArray<MultiReadHandle> handles;
 MultiReadArray<MultiReadVec4> positions;
 MultiReadArray<MultiReadElement<80> > records80;
 MultiReadArray<MultiReadRecord36> records36;
};
extern "C" void fn_801CDCB0(MultiArrayStreamOwner*self,MultiArrayInput*stream){
 fn_801CFC90(self,stream);
 int count;int i;
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->eight.resize(count);
 stream->current=fn_801E9F40(self->eight.data,stream->current,count*sizeof(MultiReadElement<8>));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->twelve.resize(count);
 stream->current=fn_801E9F40(self->twelve.data,stream->current,count*sizeof(MultiReadElement<12>));
 stream->current=fn_801E9F40(&count,stream->current,4);
 fn_801CEC84(&self->shorts,count,0);
 for(i=0;i<count;i++){
  int n;stream->current=fn_801E9F40(&n,stream->current,4);
  self->shorts[i].resize(n);
  stream->current=fn_801E9F40(self->shorts[i].data,stream->current,n*sizeof(unsigned short));
  stream->current=fn_801E9F40(self->shorts[i].extra,stream->current,8);
 }
 if(self->flags&4)for(int i=0;i<count;i++)stream->current=fn_801E9F40(self->shorts[i].extra,stream->current,4);
 stream->current=fn_801E9F40(&count,stream->current,4);
 fn_801CEA38(&self->words,count,0);
 for(i=0;i<count;i++){
  int n;stream->current=fn_801E9F40(&n,stream->current,4);
  self->words[i].resize(n);
  stream->current=fn_801E9F40(self->words[i].data,stream->current,n*sizeof(MultiReadWord));
 }
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->handles.resize(count);
 for(i=0;i<self->handles.count;i++)fn_801B41B8(lbl_801E9D24.manager,&self->handles[i],stream);
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->positions.resize(count);
 stream->current=fn_801E9F40(self->positions.data,stream->current,count*sizeof(MultiReadVec4));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->records80.resize(count);
 stream->current=fn_801E9F40(self->records80.data,stream->current,count*sizeof(MultiReadElement<80>));
 stream->current=fn_801E9F40(&count,stream->current,4);
 self->records36.resize(count);
 stream->current=fn_801E9F40(self->records36.data,stream->current,count*sizeof(MultiReadRecord36));
}
