extern "C" {
extern char lbl_802ED518[];
void*__ct__26SixHandleResource_802EA840Fv(void*);
void*__ct__16Vector2_800C3BC4Fv(void*);
void*fn_80271B84(void*);
void fn_801EB634(void*,int);
void __construct_array(void*,void*(*)(void*),void(*)(void*,int),unsigned long,unsigned long);
}
struct SixInitView{char unknown00[8];void*table;char unknown0C[0x7C];signed char active;char unknown89[3];char vectors[32];char buffers[72];};
extern "C" SixInitView*fn_80271B04(SixInitView*self){__ct__26SixHandleResource_802EA840Fv(self);self->table=lbl_802ED518;__construct_array(self->vectors,__ct__16Vector2_800C3BC4Fv,0,8,4);__construct_array(self->buffers,fn_80271B84,fn_801EB634,12,6);self->active=1;return self;}
