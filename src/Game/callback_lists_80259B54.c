// Callback list forwarding and first-result query; see unit note.
extern void *lbl_80378028,*lbl_80378030,*lbl_80378048,*lbl_80378080;
extern void fn_8025ED38(void*,void*,void*);
void fn_80259B54(void *self,void *argument) {
 fn_8025ED38(self,argument,lbl_80378048);
 fn_8025ED38(self,argument,lbl_80378030);
 fn_8025ED38(self,argument,lbl_80378080);
 fn_8025ED38(self,argument,lbl_80378028);
}
