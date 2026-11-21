struct PairMembersDestroyOwner {char unknown00[0x14];char first[0x38];char second[4];};
extern "C" {extern char lbl_801EF5C8[];void fn_80231B28(void*,int);void fn_801B252C(void*,int);void fn_801EF610(void*,void*);}
extern "C" PairMembersDestroyOwner*fn_80231ABC(PairMembersDestroyOwner*self,int deleting){if(self){fn_80231B28(self->second,-1);fn_801B252C(self->first,-1);if((short)deleting>0)fn_801EF610(lbl_801EF5C8,self);}return self;}
