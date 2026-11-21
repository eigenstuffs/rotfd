/* Early quaternion callback and indexed record controls; see docs/notes/game-early-callback-value-controls.md. */
struct Record{float first,second,third,fourth,fifth;};
struct Owner{char unknown0[0xC0];Record records[1];};
extern "C"{float fn_801F1200();extern const float lbl_80379304,lbl_80379308,lbl_8037930C,lbl_80379310,lbl_803792FC,lbl_80379314;}
extern "C"void fn_800B3288(Owner*self,int i){self->records[i].fourth=lbl_80379304*fn_801F1200();self->records[i].third=lbl_80379308*fn_801F1200();self->records[i].first=lbl_8037930C*fn_801F1200();self->records[i].second=lbl_80379310;self->records[i].fifth=(lbl_803792FC+fn_801F1200())*lbl_80379314;}
