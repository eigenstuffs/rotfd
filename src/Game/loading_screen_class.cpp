// LoadingScreen class metadata access, enumeration, and lookup across its base class.
extern "C" {
extern void* lbl_80377820;
extern void* lbl_80378018;
void fn_8025ED38(void*,void*,void*);
int fn_8025E70C(void*,void*,void*);
void* fn_800C6098(void*) { return lbl_80377820; }
void fn_800C60A0(void*, void* metadata) { lbl_80377820 = metadata; }
void fn_800C60A8(void* self,void* output) {
 fn_8025ED38(self,output,lbl_80377820);
 fn_8025ED38(self,output,lbl_80378018);
}
int fn_800C60EC(void* self,void* name) {
 int result=fn_8025E70C(self,name,lbl_80377820);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378018);
 return result!=-1?result:-1;
}
}
