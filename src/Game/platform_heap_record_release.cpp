// Release a pool slot and compact or retain its observed backing records.
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[],lbl_802AFB58[],lbl_802AFB68[];void fn_801EF610(void*,void*);void *fn_801EF83C(void*,void*,u32,const char*,const char*,u32);}
struct HeapRecordReleaseEntry {
 unsigned char *memory;unsigned char first,freeCount,unknown[2];
 void release(void *p,u32 size){*(unsigned char*)p=first;first=((u32)p-(u32)memory)/size;++freeCount;}
 void clear(){if(memory){fn_801EF610(lbl_801EF5C8,memory);memory=0;freeCount=0;first=0;}}
 HeapRecordReleaseEntry&operator=(const HeapRecordReleaseEntry&r){memory=r.memory;first=r.first;freeCount=r.freeCount;return *this;}
};
struct HeapRecordReleasePool {
 HeapRecordReleasePool *next,*prev;u32 size;unsigned char capacity,unknown[3];HeapRecordReleaseEntry *records;u32 count;HeapRecordReleaseEntry *current,*selected;
 void storage(u32 n,u32 line){if(n)records=(HeapRecordReleaseEntry*)fn_801EF83C(lbl_801EF5C8,records,n*sizeof(HeapRecordReleaseEntry),lbl_802AFB58,lbl_802AFB68,line);else{fn_801EF610(lbl_801EF5C8,records);records=0;}}
};
extern "C" void fn_8029091C(HeapRecordReleasePool*self,void*memory){
 self->selected->release(memory,self->size);
 if(self->selected->freeCount==self->capacity && self->count>1){
  HeapRecordReleaseEntry *last=self->records+(self->count-1);
  if(last==self->selected){
   if(self->count>1 && (self->selected-1)->freeCount==self->capacity){
    last->clear();self->storage(self->count-1,0x150);--self->count;self->current=self->selected=self->records;
   }
  }else if(last->freeCount==self->capacity){
   last->clear();self->storage(self->count-1,0x161);--self->count;self->current=self->selected;
  }else{
   HeapRecordReleaseEntry temporary=*self->selected;*self->selected=*last;*last=temporary;self->current=self->records+(self->count-1);
  }
 }
}
