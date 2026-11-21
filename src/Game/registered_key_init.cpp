extern "C"{extern char lbl_802ED2A0[],lbl_801E9D24[];void*__ct__19CallbackRecordOwnerFv(void*);void fn_8026E97C(int*,void*,int);}
struct KeyInitView{char unknown00[8];void*table;char unknown0C[0x28];int key;};
extern "C" KeyInitView*fn_8026E8D4(KeyInitView*self){__ct__19CallbackRecordOwnerFv(self);self->table=lbl_802ED2A0;self->key=-1;void*registry=*(void**)(lbl_801E9D24+0x180);if(registry){int key;fn_8026E97C(&key,registry,1);self->key=key;}return self;}
