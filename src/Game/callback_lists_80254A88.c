// Callback list forwarding and first-result query; see unit note.
extern void *lbl_80378020,*lbl_80378028;
extern int fn_8025E70C(void*,void*,void*);
int fn_80254A88(void *self,void *argument) {
 int value;
 value=fn_8025E70C(self,argument,lbl_80378020);
 if(value!=-1)return value;
 value=fn_8025E70C(self,argument,lbl_80378028);
 if(value!=-1)return value;
 return -1;
}
