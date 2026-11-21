extern "C"{
extern char lbl_802ED624[];extern int lbl_80378098,lbl_8037809C;
void*fn_801E1920(void*);void*fn_80271B84(void*);void fn_801EB634(void*,int);
void __construct_array(void*,void*(*)(void*),void(*)(void*,int),unsigned long,unsigned long);
}
struct RenderInitView {char unknown00[0x230];signed char flag230;char unknown231[0x47];void*table;char unknown27C[0x138];char small[36],large[1536];void*pointer9D8;char unknown9DC[8];void*pointer9E4;unsigned long size9E8;int unknown9EC;void*pointer9F0;void*pointer9F4;unsigned long field9F8,field9FC;signed char active;};
extern "C" RenderInitView*fn_80275A44(RenderInitView*self){fn_801E1920(self);self->table=lbl_802ED624;__construct_array(self->small,fn_80271B84,fn_801EB634,12,3);__construct_array(self->large,fn_80271B84,fn_801EB634,12,128);self->pointer9E4=0;self->size9E8=0;self->pointer9D8=0;self->flag230=0;lbl_80378098=0;lbl_8037809C=0;self->pointer9F0=0;self->pointer9F4=0;self->field9FC=0;self->field9F8=0;self->active=1;return self;}
