struct HandleArrayInitOwner {char unknown00[8];void*table;char unknown0C[0x60];unsigned short type,flags;char unknown70[4];unsigned long field74,field78,field7C;char unknown80[8];unsigned long handles[10];char unknownB0[0x28];unsigned long fieldD8,fieldDC,fieldE0,fieldE4,fieldE8,fieldEC,fieldF0;};
extern "C" {
void fn_80243F28(void*);
extern char lbl_802EA1D8[];
void __ct__15Handle_80020B90Fv(void*);
void __dt__15Handle_80020B90Fv(void*,int);
void __construct_array(void*,void(*)(void*),void(*)(void*,int),unsigned long,unsigned long);
}
extern "C" HandleArrayInitOwner* fn_802435AC(HandleArrayInitOwner*self){
 fn_80243F28(self);self->table=lbl_802EA1D8;
 self->field74=0;self->field78=0;self->field7C=0;
 __construct_array(self->handles,__ct__15Handle_80020B90Fv,__dt__15Handle_80020B90Fv,4,10);
 self->fieldD8=0;self->fieldDC=0;self->fieldE0=0;self->fieldE4=0;self->fieldE8=0;self->fieldEC=0;self->fieldF0=0;
 self->type=14;
 return self;
}
