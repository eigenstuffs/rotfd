extern "C" {extern void*lbl_80377728;int fn_8025E70C(void*,void*,void*);int slot2C__17CActorScriptAgentFPv(void*,void*);}
extern "C" int fn_80065E70(void*self,void*value){
 int result=fn_8025E70C(self,value,lbl_80377728);
 if(result!=-1)return result;
 return slot2C__17CActorScriptAgentFPv(self,value);
}
