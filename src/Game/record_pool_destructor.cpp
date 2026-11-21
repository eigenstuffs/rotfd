#include "record_pool_internal.h"

RecordPool_80209D30::~RecordPool_80209D30() {
    for (int i=0; i<limit; ++i)
        fn_80209DF8(this,i);
}
