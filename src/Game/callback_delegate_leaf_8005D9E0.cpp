extern "C" {extern void*lbl_803776A8;int fn_8025E70C(void*,void*,void*);int fn_8005CBDC(void*,void*);}
extern "C" int fn_8005D9E0(void*self,void*value){
 int result=fn_8025E70C(self,value,lbl_803776A8);
 if(result!=-1)return result;
 return fn_8005CBDC(self,value);
}
