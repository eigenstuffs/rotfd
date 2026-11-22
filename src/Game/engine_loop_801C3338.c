extern void fn_801F2BD4(void *,void *,int);

void fn_801C3338(void *object,void *context) {int count=*(int *)((char *)object+0x40);int i;fn_801F2BD4(context,&count,4);for(i=0;i<count;++i)fn_801F2BD4(context,*(char **)((char *)object+0x48)+i*32,32);}
