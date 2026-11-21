// Callback list forwarding and first-result query; see unit note.
extern void *lbl_80378028,*lbl_80378030,*lbl_80378080;
extern int fn_8025E70C(void*,void*,void*);
int fn_802565EC(void *self,void *argument) {
 int value;
 value=fn_8025E70C(self,argument,lbl_80378030);
 if(value!=-1)return value;
 value=fn_8025E70C(self,argument,lbl_80378080);
 if(value!=-1)return value;
 value=fn_8025E70C(self,argument,lbl_80378028);
 if(value!=-1)return value;
 return -1;
}
