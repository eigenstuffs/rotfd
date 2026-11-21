/* StreamFile_Z BigFile stream: fn_801C8708 is the per-frame state pump
 * (callback, abort, open/retry states, two-buffer block reads, completion) and
 * fn_801C8E00 begins a stream (open, version check, buffer setup, first read).
 * The diagnostic strings stay external: lbl_802ACAF8..lbl_802ACC20 is owned by
 * native_readable_pools_802ACAD8.cpp and viewed here as one const pool struct.
 * A single const pool pointer per function keeps the base in r29 from entry;
 * the offset-0 string is (member pointer to the +0x24 string) minus 0x24 at
 * the use, which keeps the original `addi r4,r29,0`. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Context{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;};
struct Allocator;
struct Stream;
extern "C" {
extern Context lbl_801E9D24;extern Allocator lbl_801EF5C8;
extern const char lbl_802AC7D0[];
extern const float lbl_8037A410,lbl_8037A414,lbl_8037A418;
void fn_801FA014(void*,const char*,...);float fn_801F45D8();void fn_801EF610(Allocator*,void*);
void*fn_801EFA1C(Allocator*,unsigned long,const char*,const char*,int,int);
void fn_801B4350(Manager*);void fn_801B4494(Manager*);void fn_801B4634(Manager*,Word*);
signed char fn_801F3F30(void*);int fn_801F3FA4(void*);int fn_801F415C(void*,void*,int);
int fn_801F43D0(void*,const char*);int fn_801F42A8(void*,void*,int);
Word fn_801E9F40(int*,void*,int);
void fn_801F86C8(Manager*,const void*,int);
void fn_802073BC(Stream*,int,void*,float,float);void fn_802073E8(Stream*,int,void*,float);
unsigned long strlen(const char*);int strncmp(const char*,const char*,unsigned long);
}
struct Pool{char aborted[0x24];char loading[0x2C];char endLoad[0xC];char readTime[0x24];char init[0x10];
 char unableOpen[0x1C];char anonymous[0x10];char fileName[0x14];char wrongVersion[0x28];char streamInit[0x10];
 char sizeInfo[0x20];char separator[0x31];};
extern "C" const Pool lbl_802ACAF8;
inline const char*loadingText(const Pool*p){const char(Pool::*m)[0x2C]=&Pool::loading;return p->*m;}
inline const char*abortedText(const Pool*p){return loadingText(p)-sizeof(p->aborted);}
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(Word)m->entries[index].object:0;}
struct Buffer{void*raw;void*aligned;};
struct Header{char unknown00[0x100];int size;};
struct Stream{
 char unknown00[0x20];char file[0x40];char filename[0x88];int sizeE8;char unknownEC[8];int state;char unknownF8[8];
 int length,blockSize,block,pending;Buffer buffers[2];int selected;Handle_801F7F10 handle;float start,elapsed;
 signed char active,ready,reading,finished;void(*callback)(Stream*,void*);void*callbackArg;
 void freeBuffers(){
  if(buffers[0].raw)fn_801EF610(&lbl_801EF5C8,buffers[0].raw);buffers[0].raw=0;
  if(buffers[1].raw)fn_801EF610(&lbl_801EF5C8,buffers[1].raw);buffers[1].raw=0;
 }
 void abort(const Pool*pool){
  finished=0;active=0;freeBuffers();
  fn_801B4350(lbl_801E9D24.manager);
  Word millis=(Word)(lbl_8037A410*(fn_801F45D8()-start));
  fn_801FA014(lbl_801E9D24.logger,abortedText(pool),millis/60000,(millis/1000)%60,millis%1000);
  fn_802073E8(this,0x50,(void*)resolveWord(handle),lbl_8037A414);
 }
 void finish(const Pool*pool){
  active=0;freeBuffers();
  fn_801B4494(lbl_801E9D24.manager);
  Word millis=(Word)(lbl_8037A410*(fn_801F45D8()-start));
  fn_801FA014(lbl_801E9D24.logger,pool->loading,millis/60000,(millis/1000)%60,millis%1000);
  fn_802073BC(this,0x4B,(void*)resolveWord(handle),lbl_8037A418,lbl_8037A414);
 }
 void sendEvent(int event){fn_802073E8(this,event,(void*)resolveWord(handle),lbl_8037A414);}
};
extern "C" void fn_801C8E00(Stream*,const char*,const Handle_801F7F10&);
extern "C" void fn_801C8708(Stream*self)
{
 const Pool*const pool=&lbl_802ACAF8;
 if(self->callback)self->callback(self,self->callbackArg);
 if(!self->active)return;
 if(self->finished){self->abort(pool);return;}
 int state=self->state;
 if(state==6||state==7){
  if(!fn_801F3F30(self->file))return;
  if(self->ready){
   if(state==7){
    fn_801C8E00(self,self->filename,self->handle);
    if(self->state==7)self->sendEvent(0x4C);
    else self->sendEvent(0x4D);
   }else{
    self->state=5;
    self->sendEvent(0x4D);
    self->ready=0;self->reading=1;
   }
  }else self->sendEvent(0x4E);
  return;
 }
 if(!self->reading){
  int status=fn_801F3FA4(self->file);
  if(status==6){self->ready=0;++self->pending;self->sendEvent(0x4C);return;}
  if(status==0||status==2)return;
 }else self->selected=(self->selected+1)&1;
 --self->pending;
 float start=fn_801F45D8();self->elapsed+=fn_801F45D8()-start;
 if(self->pending<self->block){
  int count;Word key=fn_801E9F40(&count,self->buffers[self->selected].aligned,4);
  while(count!=0){fn_801B4634(lbl_801E9D24.manager,&key);--count;}
 }
 int selected=self->selected;
 self->reading=0;
 if(self->pending!=0){
  if(fn_801F415C(self->file,self->buffers[selected].aligned,self->blockSize)==6){
   self->ready=0;++self->pending;
   self->sendEvent(0x4C);
   self->selected=selected;return;
  }
 }
 if(self->pending==0){
  fn_801FA014(lbl_801E9D24.logger,pool->endLoad);
  Word millis=(Word)(lbl_8037A410*self->elapsed);
  fn_801FA014(lbl_801E9D24.logger,pool->readTime,millis/60000,(millis/1000)%60,millis%1000);
  self->finish(pool);
 }
 self->selected=selected;
}
extern "C" void fn_801C8E00(Stream*self,const char*name,const Handle_801F7F10&handle)
{
 const Pool*const pool=&lbl_802ACAF8;
 fn_801FA014(lbl_801E9D24.logger,pool->init);
 self->active=0;self->finished=0;self->reading=0;self->ready=0;
 fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.word=handle.word;fn_801F86C8(lbl_801E9D24.manager,&handle,1);
 self->start=fn_801F45D8();
 if(fn_801F43D0(self->file,name)!=5){fn_801FA014(lbl_801E9D24.logger,pool->unableOpen,name);return;}
 self->length=self->sizeE8;
 Header*header=(Header*)fn_801EFA1C(&lbl_801EF5C8,0x800,pool->anonymous,pool->fileName,0x27,0x20);
 if(fn_801F42A8(self->file,header,1)!=5){fn_801FA014(lbl_801E9D24.logger,pool->unableOpen,name);fn_801EF610(&lbl_801EF5C8,header);return;}
 if(strncmp((const char*)header,lbl_802AC7D0,strlen(lbl_802AC7D0))!=0){
  self->state=7;fn_801FA014(lbl_801E9D24.logger,pool->wrongVersion);fn_801EF610(&lbl_801EF5C8,header);return;
 }
 int size=header->size;
 fn_801EF610(&lbl_801EF5C8,header);
 if(size==0){self->finish(pool);return;}
 self->blockSize=size/2048;
 self->block=(self->length-1)/self->blockSize;
 self->pending=self->block;
 self->buffers[0].raw=fn_801EFA1C(&lbl_801EF5C8,size+0x80,pool->anonymous,pool->fileName,0x49,4);
 self->buffers[0].aligned=(void*)(((Word)self->buffers[0].raw+0x7F)&~0x7F);
 self->selected=0;
 fn_801FA014(lbl_801E9D24.logger,pool->streamInit,name);
 fn_801FA014(lbl_801E9D24.logger,pool->sizeInfo,self->length,size);
 fn_801FA014(lbl_801E9D24.logger,pool->separator);
 self->active=1;
 self->elapsed=fn_801F45D8();
 if(fn_801F415C(self->file,self->buffers[self->selected].aligned,self->blockSize)==6){
  self->ready=0;++self->pending;self->state=7;
  self->sendEvent(0x4C);
  return;
 }
 self->elapsed=fn_801F45D8()-self->elapsed;
}
