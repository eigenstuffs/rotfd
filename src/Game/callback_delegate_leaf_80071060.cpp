/* Original callback forwarding/query delegate; see docs/notes/game-callback-delegate-leafs.md. */
extern "C" {extern void*lbl_8037773C;void fn_8025ED38(void*,void*,void*);void fn_80070E54(void*,void*);}
extern "C" void fn_80071060(void*self,void*value){
 fn_8025ED38(self,value,lbl_8037773C);
 fn_80070E54(self,value);
}
