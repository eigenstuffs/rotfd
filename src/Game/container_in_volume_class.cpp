// ContainerInVolume class metadata access, enumeration, and lookup across its base classes.
extern "C" {
extern void* lbl_80377878;
extern void* lbl_80378078;
extern void* lbl_80378028;
void fn_8025ED38(void*,void*,void*);
int fn_8025E70C(void*,void*,void*);
void* fn_800CADB8(void*) { return lbl_80377878; }
void fn_800CADC0(void*, void* metadata) { lbl_80377878 = metadata; }
void fn_800CADC8(void* self,void* output) {
 fn_8025ED38(self,output,lbl_80377878);
 fn_8025ED38(self,output,lbl_80378078);
 fn_8025ED38(self,output,lbl_80378028);
}
int fn_800CAE1C(void* self,void* name) {
 int result=fn_8025E70C(self,name,lbl_80377878);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378078);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378028);
 return result!=-1?result:-1;
}
}
