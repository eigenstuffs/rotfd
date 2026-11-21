// The axis pair is an ordinary local value snapshot. Absolute-value
// normalization changes that copy; the observed input object stays borrowed.
struct InputThresholdFeedbackPrefix{char unknown00[0x1C];};
struct InputThresholdFeedback:InputThresholdFeedbackPrefix{
virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();
virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();
virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();
virtual void feedback(int,unsigned char,unsigned char);
};
struct InputThresholdContext{char unknown00[0x154];InputThresholdFeedback*feedback;};
struct InputThresholdOwner{char unknown00[0xC];void*controller;char unknown10[0x34];signed char active;unsigned char level,mode;};
struct InputThresholdAxes{char unknown00[0x110];float x,y;};
extern "C"{extern InputThresholdContext lbl_801E9D24;extern const double lbl_80378B08;double __fabs(double);InputThresholdAxes*fn_8007D074(void*);void fn_80255D88(void*,int,int,int,int);void fn_80255CBC(void*,int,int);}
struct InputAxisSnapshot_80085298{double x,y;InputAxisSnapshot_80085298(float a,float b):x(a),y(b){}};
inline int axisMotion_80085298(InputAxisSnapshot_80085298&v){v.x=__fabs(v.x);v.y=__fabs(v.y);signed char horizontal=v.x>lbl_80378B08;signed char moved=0;if(v.y>lbl_80378B08||horizontal)moved=1;return moved;}
extern "C" void fn_80085298(InputThresholdOwner*self){InputThresholdAxes*axes=fn_8007D074(self);InputAxisSnapshot_80085298 values(axes->x,axes->y);signed char moved=axisMotion_80085298(values);if(!self->active&&moved){fn_80255D88(self->controller,0x80,0xF,0,0);lbl_801E9D24.feedback->feedback(0,self->level,self->mode);self->active=1;}if(self->active&&!moved){fn_80255CBC(self->controller,0x80,0);self->active=0;lbl_801E9D24.feedback->feedback(0,0,0);}}
