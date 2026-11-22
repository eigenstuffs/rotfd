int fn_80255C80(void *object,int needle) { int i;for(i=0;i<*(int *)((char *)object+0x48);++i) if((*(int **)((char *)object+0x50))[i]==needle)return 1;return 0; }
