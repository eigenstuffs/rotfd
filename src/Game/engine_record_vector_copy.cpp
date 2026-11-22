#include "Game/engine_record_vector_copy.h"
extern "C" RecordVectorCopyArray<RecordVectorCopyRecord28>*fn_802495A0(RecordVectorCopyArray<RecordVectorCopyRecord28>*self,const RecordVectorCopyArray<RecordVectorCopyRecord28>*source){
 self->resize(0,1);
 self->setCapacity(source->count);
 for(int i=0;i<source->count;++i)self->append((*source)[i]);
 return self;
}
extern "C" RecordVectorCopyArray<RecordVectorCopyScalar2>*fn_80249250(RecordVectorCopyArray<RecordVectorCopyScalar2>*self,const RecordVectorCopyArray<RecordVectorCopyScalar2>*source){
 self->resize(0,1);
 self->setCapacity(source->count);
 for(int i=0;i<source->count;++i)self->append((*source)[i]);
 return self;
}
