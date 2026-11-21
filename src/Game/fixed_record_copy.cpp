#include "Game/fixed_record_copy_internal.h"
extern "C" void fn_80268B80(FixedRecordArray256*self,const FixedRecordArray256&source){self->resize(0);for(int i=0;i<source.count;++i)self->append(source[i]);}
