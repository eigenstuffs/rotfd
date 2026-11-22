extern void fn_80243DE4(void *);

extern unsigned int fn_801E9F40(void *,unsigned int,int);

extern void fn_802525F0(void *);

void fn_801DC3A0(void *object,unsigned int *value) {fn_80243DE4(object);*value=fn_801E9F40((char *)object+0x30,*value,2);fn_802525F0(object);}
