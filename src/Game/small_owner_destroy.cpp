struct SmallOwnerDestroy {char unknown00[8];void*table;};
extern "C" {extern char lbl_802EBD20[],lbl_801EF5C8[];void fn_8023106C(void*,int);void fn_801EF610(void*,void*);}
extern "C" SmallOwnerDestroy*fn_802309C4(SmallOwnerDestroy*self,int deleting){if(self){self->table=lbl_802EBD20;fn_8023106C(self,0);if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);}return self;}
