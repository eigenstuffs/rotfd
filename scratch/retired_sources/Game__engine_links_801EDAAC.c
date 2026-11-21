/* Original engine lifetime and record routines.
* See docs/notes/game-engine-links.md. */
extern const float lbl_8037A648;
extern const double lbl_8037A668;
extern double __fabs(double);
typedef struct Object{
    char pad[0xbc];
    unsigned short flags;
    char padbe[2];
    float valuec0,valuec4,valuec8;
}Object;
void fn_801EDAAC(Object*self,float first,float second,float third){
    if(((signed char)(self->flags&1)||((self->flags&0x28)==0x28))&&((self->flags&0x38)!=0x28))return;
    self->flags|=6;
    self->flags&=~0x20;
    if(self->flags&0x100){
        self->flags^=0x100;
        self->flags|=1;
        return;
    }if(third>=lbl_8037A648)self->valuec8=third;
    self->valuec0=second;
    self->valuec4=first;
    if(__fabs(self->valuec4)<=lbl_8037A668)self->flags|=1;
}
