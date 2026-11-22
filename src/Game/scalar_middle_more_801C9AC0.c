extern struct {char pad[0x110];void *logger;} lbl_801E9D24;

extern const char lbl_802ACCA8[],lbl_802ACCB4[];

extern void fn_801C9A2C(void);

extern void fn_801FAC64(void *,const char *,void (*)(void),const char *);

int fn_801C9AC0(void *object) {fn_801FAC64(lbl_801E9D24.logger,lbl_802ACCA8,fn_801C9A2C,lbl_802ACCB4);*((unsigned char *)object+1)=1;*(unsigned int *)((char *)object+4)=0;return 1;}

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

void fn_801C9B24(void *object) {void *buffer=*(void **)((char *)object+0x20);if(buffer)fn_801EF610(lbl_801EF5C8,buffer);*(void **)((char *)object+0x20)=0;}
