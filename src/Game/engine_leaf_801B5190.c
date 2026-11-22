struct Handle {signed int tag:8;signed int index:24;};

void *fn_801B5190(void *object,const struct Handle *handle) {int offset=handle->index*16;short index=*(short *)(*(char **)((char *)object+8)+offset+8);return *(char **)((char *)object+0x30)+index*16;}
