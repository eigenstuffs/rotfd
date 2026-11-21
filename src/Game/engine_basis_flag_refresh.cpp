struct BasisRefreshOwner {char unknown00[0xC];unsigned char flags;char unknown0D[0xB0-0xD];float value;};
extern "C" const float lbl_8037B300;
extern "C" void fn_802397E0(BasisRefreshOwner*self){
 if((!(self->flags&1)&&(self->flags&6)!=6)||(self->flags&14)==6){
  self->flags|=1;self->flags&=~2;self->value=lbl_8037B300;
 }
}
