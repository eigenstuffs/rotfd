// TeleportVolume reconstructed methods; unknown names describe observed ABI offsets.
extern "C" {
extern int lbl_80377868,lbl_80377648,lbl_80378078,lbl_80378028;
void fn_8025ED38(void*,void*,int);
int fn_8025E70C(void*,void*,int);
int fn_800C9130(void*){return lbl_80377868;}
void fn_800C9138(void*,int value){lbl_80377868=value;}
void fn_800C9140(void*self,void*arg){
 fn_8025ED38(self,arg,lbl_80377868);fn_8025ED38(self,arg,lbl_80377648);
 fn_8025ED38(self,arg,lbl_80378078);fn_8025ED38(self,arg,lbl_80378028);
}
int fn_800C91A4(void*self,void*arg){
 int value;
 if((value=fn_8025E70C(self,arg,lbl_80377868))!=-1)return value;
 if((value=fn_8025E70C(self,arg,lbl_80377648))!=-1)return value;
 if((value=fn_8025E70C(self,arg,lbl_80378078))!=-1)return value;
 if((value=fn_8025E70C(self,arg,lbl_80378028))!=-1)return value;
 return -1;
}
}
