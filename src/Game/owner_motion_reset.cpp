struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};extern "C"{extern struct{char unknown00[0x118];void*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);}
struct MotionResetHandle1:Handle_801F7F10{MotionResetHandle1(){value=0;}};
struct MotionResetHandle2:MotionResetHandle1{MotionResetHandle2(){value=0;}};
struct MotionResetHandle3:MotionResetHandle2{MotionResetHandle3(){value=0;}};
struct MotionResetHandle4:MotionResetHandle3{MotionResetHandle4(){value=0;}};
struct MotionResetHandle5:MotionResetHandle4{MotionResetHandle5(){value=0;}};
struct MotionResetCopy3:MotionResetHandle3{MotionResetCopy3(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
struct MotionResetPoint{float x,y,z;MotionResetPoint&operator=(const MotionResetPoint&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct MotionResetOwner{char unknown00[0x30];unsigned long long flags;char unknown38[0x1C4];MotionResetPoint point1FC,point208,point214,point220;signed char state22C,state22D;char unknown22E[2];Handle_801F7F10 handle230;char unknown234[0x1C];signed char state250;char unknown251[7];signed char state258;};
extern "C"{extern MotionResetPoint game_vec3_zero;void fn_8022A160(void*);void fn_80229098(void*,const Handle_801F7F10&);void fn_80224038(void*,const void*);void slot34__13ObjectThrow_ZFv(void*);}
inline void assignMotionReset(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
extern "C" void fn_80224A10(MotionResetOwner*self){fn_8022A160(self);self->flags|=0x1800001ULL;self->point220=game_vec3_zero;self->point214=self->point220;self->point208=self->point214;self->point1FC=self->point208;{MotionResetHandle2 empty;assignMotionReset(self->handle230,empty);}self->state250=0;self->state258=0;self->state258=1;self->state22C=1;self->state22D=1;}
