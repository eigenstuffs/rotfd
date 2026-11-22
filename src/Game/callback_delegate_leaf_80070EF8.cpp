extern "C" {extern void*lbl_80377740;int fn_8025E70C(void*,void*,void*);int fn_80070F44(void*,void*);}
extern "C" int fn_80070EF8(void*self,void*value){
 int result=fn_8025E70C(self,value,lbl_80377740);
 if(result!=-1)return result;
 return fn_80070F44(self,value);
}
