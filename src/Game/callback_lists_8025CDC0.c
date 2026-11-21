// Callback list forwarding and first-result query; see unit note.
extern void *lbl_80378028,*lbl_80378070,*lbl_80378080;
extern void fn_8025ED38(void*,void*,void*);
void fn_8025CDC0(void *self,void *argument) {
 fn_8025ED38(self,argument,lbl_80378070);
 fn_8025ED38(self,argument,lbl_80378080);
 fn_8025ED38(self,argument,lbl_80378028);
}
