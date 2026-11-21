/* Original callback forwarding/query delegate; see docs/notes/game-callback-delegate-leafs.md. */
extern "C" {extern void*lbl_803776F0;void fn_8025ED38(void*,void*,void*);void fn_8005CB38(void*,void*);}
extern "C" void fn_80060DFC(void*self,void*value){
 fn_8025ED38(self,value,lbl_803776F0);
 fn_8005CB38(self,value);
}
