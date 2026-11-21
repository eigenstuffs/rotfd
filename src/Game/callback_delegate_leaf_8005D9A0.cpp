/* Original callback forwarding/query delegate; see docs/notes/game-callback-delegate-leafs.md. */
extern "C" {extern void*lbl_803776A8;void fn_8025ED38(void*,void*,void*);void fn_8005CB38(void*,void*);}
extern "C" void fn_8005D9A0(void*self,void*value){
 fn_8025ED38(self,value,lbl_803776A8);
 fn_8005CB38(self,value);
}
