void fn_80249924(void *object,int index) { if(index>=0) (*(unsigned short **)((char *)object+0x2c))[index]|=8; else { int i; for(i=0;i<*(int *)((char *)object+0x30);++i) (*(unsigned short **)((char *)object+0x2c))[i]|=8; } }

void fn_80249978(void *object,int index) { if(index>=0) (*(unsigned short **)((char *)object+0x2c))[index]&=~8U; else { int i; for(i=0;i<*(int *)((char *)object+0x30);++i) (*(unsigned short **)((char *)object+0x2c))[i]&=~8U; } }
