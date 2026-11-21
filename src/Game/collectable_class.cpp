// Collectable class metadata access, enumeration, and lookup across its base classes.
extern "C" {
extern void* lbl_80377808;
extern void* lbl_803775C0;
extern void* lbl_80378050;
extern void* lbl_80378030;
extern void* lbl_80378080;
extern void* lbl_80378028;
void fn_8025ED38(void*,void*,void*);
int fn_8025E70C(void*,void*,void*);
void* fn_800C5790(void*) { return lbl_80377808; }
void fn_800C5798(void*, void* metadata) { lbl_80377808 = metadata; }
void fn_800C57A0(void* self,void* output) {
 fn_8025ED38(self,output,lbl_80377808);
 fn_8025ED38(self,output,lbl_803775C0);
 fn_8025ED38(self,output,lbl_80378050);
 fn_8025ED38(self,output,lbl_80378030);
 fn_8025ED38(self,output,lbl_80378080);
 fn_8025ED38(self,output,lbl_80378028);
}
int fn_800C5824(void* self,void* name) {
 int result=fn_8025E70C(self,name,lbl_80377808);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_803775C0);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378050);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378030);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378080);
 if(result!=-1)return result;
 result=fn_8025E70C(self,name,lbl_80378028);
 return result!=-1?result:-1;
}
}
