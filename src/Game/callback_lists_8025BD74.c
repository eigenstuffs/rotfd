// Callback list forwarding and first-result query; see unit note.
extern void *lbl_80378028,*lbl_80378068;
extern void fn_8025ED38(void*,void*,void*);
void fn_8025BD74(void *self,void *argument) {
 fn_8025ED38(self,argument,lbl_80378068);
 fn_8025ED38(self,argument,lbl_80378028);
}
