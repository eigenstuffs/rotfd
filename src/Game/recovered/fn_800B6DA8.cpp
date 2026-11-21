typedef unsigned long u32;inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C"{extern char lbl_8028F698[];void fn_8028FD50(void*,void*,int);void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_801F86C8(void*,const Handle_801F7F10*,int);}
struct Entry{void*object;u32 opaque04,opaque08;signed char tag;char opaque0D[3];signed char getTag()const{return tag;}};
struct Manager{char opaque00[8];Entry*entries;};
extern "C" struct Context{char opaque00[0x118];Manager*manager;}lbl_801E9D24;
struct RetainedHandle:Handle_801F7F10{RetainedHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
inline void*resolveA(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline void*resolveB(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct HandleArray{int count,capacity;RetainedHandle*data;
 int getCount()const{return count;}
 RetainedHandle&at(int i){return data[i];}
 void resize(int n){if(n){if(data)data=(RetainedHandle*)fn_8028FAF4(lbl_8028F698,data,capacity*4,n*4);else data=(RetainedHandle*)fn_8028FF24(lbl_8028F698,n*4);}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}}
 void append(const Handle_801F7F10&h){if(count+1>capacity){resize(capacity+1);capacity+=1;}new(data+count++)RetainedHandle(h);}};
struct Record{char unknown00[8];HandleArray*arrays;HandleArray&at(int i){return arrays[i];}};
struct RecordArray{int count,capacity;Record**data;Record*&at(const int&i){return data[i];}};
struct RecordService{char unknown00[0x20];RecordArray records;};
extern "C" void fn_800B6DA8(RecordService*self,u32 ri,int ai,const Handle_801F7F10*handle){
for(int i=0;i<self->records.at(ri)->at(ai).getCount();++i){if(resolveA(self->records.at(ri)->at(ai).at(i))==resolveA(*handle))break;}
    self->records.at(ri)->at(ai).append(*handle);
}
