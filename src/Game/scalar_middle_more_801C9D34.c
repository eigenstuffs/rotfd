extern struct {char pad[0x118];void *manager;} lbl_801E9D24;

extern void fn_801F86C8(void *,void *,int);

void fn_801C9D34(unsigned int *out,unsigned int *handle) {fn_801F86C8(lbl_801E9D24.manager,out,-1);*out=*handle;fn_801F86C8(lbl_801E9D24.manager,handle,1);}
