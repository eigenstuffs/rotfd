// Callback list forwarding and first-result query; see unit note.
extern void *lbl_80378020,*lbl_80378028;
extern void fn_8025ED38(void*,void*,void*);
void fn_80254A3C(void *self,void *argument) {
 fn_8025ED38(self,argument,lbl_80378020);
 fn_8025ED38(self,argument,lbl_80378028);
}
