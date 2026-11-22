
signed char fn_8023C798(const void *o){return *(const signed char*)o;}

void *fn_8023C7A4(void *o,unsigned int index){return (char*)*(void**)((char*)o+8)+index*16;}

struct PackedHandleLeaf {signed int generation:8; signed int index:24;}; int fn_8023C7B4(const struct PackedHandleLeaf *o){return o->index;}
