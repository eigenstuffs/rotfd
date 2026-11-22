extern void fn_801C932C(void *,void *,int,int,int);

void fn_801C9290(void *object,void *out) {switch(*((unsigned char *)object+0x3c)){case 12:fn_801C932C(out,*(void **)((char *)object+0xc),*(int *)((char *)object+0x30),*(int *)((char *)object+0x34),32);break;case 13:fn_801C932C(out,*(void **)((char *)object+0xc),*(int *)((char *)object+0x30),*(int *)((char *)object+0x34),24);break;case 7:case 8:case 10:case 11:fn_801C932C(out,*(void **)((char *)object+0xc),*(int *)((char *)object+0x30),*(int *)((char *)object+0x34),16);break;}}
