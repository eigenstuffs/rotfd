/* Original callback forwarding/query delegate; see docs/notes/game-callback-delegate-leafs.md. */
extern "C" {extern void*lbl_80377738;void fn_8025ED38(void*,void*,void*);void fn_80070E54(void*,void*);}
extern "C" void fn_800710FC(void*self,void*value){
 fn_8025ED38(self,value,lbl_80377738);
 fn_80070E54(self,value);
}
