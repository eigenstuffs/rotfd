extern "C" {extern void*lbl_8037773C;int fn_8025E70C(void*,void*,void*);int fn_80070F44(void*,void*);}
extern "C" int fn_800710A0(void*self,void*value){
 int result=fn_8025E70C(self,value,lbl_8037773C);
 if(result!=-1)return result;
 return fn_80070F44(self,value);
}
