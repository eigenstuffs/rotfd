#include "Game/index_grid_records_internal.h"
extern "C" int fn_80267400(IndexGridView*);
extern "C" int fn_802672CC(IndexGridView*self,int cell,int previous,void*context){
    int index=fn_80267400(self);
    int head=self->cellHeads[cell];
    if(head!=-1)self->records[head].next=index;
    IndexGridRecord*record=&self->records[index];
    record->chain=previous;
    record->previous=head;
    record->next=-1;
    record->context=context;
    record->cell=cell;
    self->cellHeads[cell]=index;
    return index;
}
extern "C" void fn_8026736C(IndexGridView*self,int index){
    while(index!=-1){
        int released=index;
        IndexGridRecord*record=&self->records[index];
        if(record->previous!=-1)self->records[record->previous].next=record->next;
        if(record->next!=-1)self->records[record->next].previous=record->previous;
        else self->cellHeads[record->cell]=record->previous;
        index=record->chain;
        record->chain=self->freeHead;
        record->cell=-1;
        self->freeHead=released;
        ++self->freeCount;
    }
}
