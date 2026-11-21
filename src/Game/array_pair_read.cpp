#include "Game/array_pair_read_internal.h"
extern "C" void fn_8026DFD8(ReadArrayPair*self,const char**stream){
 fn_801CDCB0(self,stream);
 const int*cursor=(const int*)*stream;int count=*cursor++;
 self->first.resize(count);
 cursor=(const int*)fn_801E9F40(self->first.data,cursor,count*sizeof(ReadRecord16));
 count=*cursor++;
 self->second.resize(count);
 *stream=fn_801E9F40(self->second.data,cursor,count*sizeof(ReadRecord4));
}
