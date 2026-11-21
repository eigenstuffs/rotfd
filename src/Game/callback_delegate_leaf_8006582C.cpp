/* Original callback forwarding/query delegate; see docs/notes/game-callback-delegate-leafs.md. */
extern "C" {extern void*lbl_80377718;void fn_8025ED38(void*,void*,void*);void fn_800642A8(void*,void*);}
extern "C" void fn_8006582C(void*self,void*value){
 fn_8025ED38(self,value,lbl_80377718);
 fn_800642A8(self,value);
}
