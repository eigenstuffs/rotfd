/* Original callback forwarding/query delegate; see docs/notes/game-callback-delegate-leafs.md. */
extern "C" {extern void*lbl_80377728;int fn_8025E70C(void*,void*,void*);int fn_8006434C(void*,void*);}
extern "C" int fn_80065E70(void*self,void*value){
 int result=fn_8025E70C(self,value,lbl_80377728);
 if(result!=-1)return result;
 return fn_8006434C(self,value);
}
