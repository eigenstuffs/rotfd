// DamageVolume class metadata access, enumeration, and lookup across its base classes.
extern "C" {
extern void* lbl_80377870;
extern void* lbl_80377648;
extern void* lbl_80378078;
extern void* lbl_80378028;
void fn_8025ED38(void*,void*,void*);
int fn_8025E70C(void*,void*,void*);
void* fn_800C9DB8(void*) { return lbl_80377870; }
void fn_800C9DC0(void*, void* metadata) { lbl_80377870 = metadata; }
void fn_800C9DC8(void* self,void* output) {
 fn_8025ED38(self,output,lbl_80377870);
 fn_8025ED38(self,output,lbl_80377648);
 fn_8025ED38(self,output,lbl_80378078);
 fn_8025ED38(self,output,lbl_80378028);
}
int fn_800C9E2C(void* self,void* name) {
 int result=fn_8025E70C(self,name,lbl_80377870);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80377648);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378078);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378028);
 return result!=-1?result:-1;
}
}
