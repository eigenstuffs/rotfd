/* Original callback forwarding/query delegate; see docs/notes/game-callback-delegate-leafs.md. */
extern "C" {extern void*lbl_80377738;int fn_8025E70C(void*,void*,void*);int fn_80070F44(void*,void*);}
extern "C" int fn_8007113C(void*self,void*value){
 int result=fn_8025E70C(self,value,lbl_80377738);
 if(result!=-1)return result;
 return fn_80070F44(self,value);
}
