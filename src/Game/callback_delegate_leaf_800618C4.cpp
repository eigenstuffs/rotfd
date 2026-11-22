extern "C" {extern void*lbl_803776FC;int fn_8025E70C(void*,void*,void*);int fn_80061910(void*,void*);}
extern "C" int fn_800618C4(void*self,void*value){
 int result=fn_8025E70C(self,value,lbl_803776FC);
 if(result!=-1)return result;
 return fn_80061910(self,value);
}
