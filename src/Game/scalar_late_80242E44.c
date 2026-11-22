void fn_80242E44(void *object) { int i;for(i=0;i<*(int *)((char *)object+0xd8);++i) *(unsigned short *)((char *)*(void **)((char *)object+0xe0)+i*0x44+0x2c)&=0x3fff; }

void fn_80242E7C(void *object,int index,unsigned short mask) { *(unsigned short *)((char *)*(void **)((char *)object+0xe0)+index*0x44+0x2c)|=mask; }

unsigned short fn_80242E98(const void *object,int index) { return *(unsigned short *)((char *)*(void *const *)((const char *)object+0xe0)+index*0x44+0x2c); }
