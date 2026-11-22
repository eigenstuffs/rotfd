typedef unsigned long Word;
extern "C" struct PropertyGlobals{char unknown00[0x118];void*manager;}lbl_801E9D24;
extern "C" void fn_801F86C8(void*,const void*,int);
struct PropertyHandle{Word word;PropertyHandle&operator=(const PropertyHandle&source){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=source.word;fn_801F86C8(lbl_801E9D24.manager,&source,1);return*this;}};
struct PropertyOwner{char unknown00[0x38];unsigned long long flags;char unknown40[0x20];unsigned char enabled;char unknown61[3];Word mode;char unknown68[8];unsigned char first,second;char unknown72[2];float lower,upper;unsigned char third,fourth;char unknown7E[2];PropertyHandle firstHandle,secondHandle;};
extern "C"{float fn_8025E268(PropertyOwner*,int);const PropertyHandle*fn_8025E1D4(PropertyOwner*,int);}
extern "C" void fn_8005074C(PropertyOwner*self){
self->flags|=0x40000000ULL;
self->enabled=(unsigned char)(int)fn_8025E268(self,0);
self->mode=(unsigned char)(int)fn_8025E268(self,1);
self->first=(unsigned char)(int)fn_8025E268(self,2);
self->second=(unsigned char)(int)fn_8025E268(self,5);
self->lower=fn_8025E268(self,4);
self->upper=fn_8025E268(self,7);
self->third=(unsigned char)(int)fn_8025E268(self,8);
self->fourth=(unsigned char)(int)fn_8025E268(self,3);
self->firstHandle=*fn_8025E1D4(self,0);
self->secondHandle=*fn_8025E1D4(self,1);
}
