#include "Game/index_grid_acquire_internal.h"
extern "C" int fn_80267400(IndexGridAcquireView*self){
 int result=self->freeHead;
 IndexGridAcquireRecord*record=&self->records[result];
 self->freeHead=record->chain;
 if(self->freeHead<0){
  self->freeHead=self->records.count;
  self->freeCount+=16;
  int count=self->freeHead+16;
  self->records.resize(count);
  self->records[result].chain=self->freeHead;
  int i=self->freeHead;
  for(;i<count-1;++i){self->records[i].chain=i+1;self->records[i].cell=-1;}
  IndexGridAcquireRecord*last=&self->records[i];
  last->chain=-1;
  self->records[i].cell=-1;
 }
 --self->freeCount;
 return result;
}
