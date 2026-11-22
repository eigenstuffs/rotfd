struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};extern "C"{extern struct{char unknown00[0x118];void*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);}
struct MotionStartHandle1:Handle_801F7F10{MotionStartHandle1(){value=0;}};
struct MotionStartHandle2:MotionStartHandle1{MotionStartHandle2(){value=0;}};
struct MotionStartHandle3:MotionStartHandle2{MotionStartHandle3(){value=0;}};
struct MotionStartHandle4:MotionStartHandle3{MotionStartHandle4(){value=0;}};
struct MotionStartHandle5:MotionStartHandle4{MotionStartHandle5(){value=0;}};
struct MotionStartCopy3:MotionStartHandle3{MotionStartCopy3(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
struct MotionStartPoint{float x,y,z;MotionStartPoint&operator=(const MotionStartPoint&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct MotionStartOwner{char unknown00[0x30];unsigned long long flags;char unknown38[0x1C4];MotionStartPoint point1FC,point208,point214,point220;signed char state22C,state22D;char unknown22E[2];Handle_801F7F10 handle230;char unknown234[0x1C];signed char state250;char unknown251[7];signed char state258;};
extern "C"{extern MotionStartPoint game_vec3_zero;void fn_8022A160(void*);void fn_80229098(void*,const Handle_801F7F10&);void fn_80224038(void*,const void*);void slot34__13ObjectThrow_ZFv(void*);}
inline void assignMotionStart(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
extern "C" void slot34__9LodMove_ZFv(MotionStartOwner*self){MotionStartHandle4 first;MotionStartHandle5 second;fn_80229098(self,MotionStartCopy3(first));fn_80224038(self,&second);slot34__13ObjectThrow_ZFv(self);self->flags|=0x1800000ULL;self->point214=game_vec3_zero;self->state250=0;self->state258=1;assignMotionStart(self->handle230,MotionStartHandle2());self->state22C=1;self->state22D=1;}
