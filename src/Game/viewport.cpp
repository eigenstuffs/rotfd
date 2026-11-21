/* Inferred viewport storage and perspective setup; see unit notes. */
#include "game_engine.h"

struct Viewport {
    unsigned char prefix[8];
    void *vtable;
    unsigned char reserved_0c[12];
    signed char enabled;
};
struct ViewContext { unsigned char prefix[0x48]; Engine *engine; };
extern "C" {
void fn_8021239C(Viewport *,ViewContext *,int *,int *,int *,int *,float *,float *);
void GXDrawDone();
void GXSetProjection(float *,int);
void GXSetViewport(float,float,float,float,float,float);
void GXSetScissor(int,int,int,int);
void fn_80211A10(Viewport *,ViewContext *);
void fn_80211508(Viewport *,short);
void __ct__28ViewportManipulator_802EB130Fv(Viewport *);
void fn_801EF610(void *,void *);
extern unsigned char lbl_801EF5C8[32];
extern unsigned int lbl_802EA908[20];
static inline void project(float *matrix,float width,float height,float horizontal,float vertical,float znear,float zfar) {
        float ratio=zfar/(zfar-znear);
        matrix[0]=2.0f*horizontal/width;
        matrix[1]=0.0f;
        matrix[2]=0.0f;
        matrix[3]=0.0f;
        matrix[4]=0.0f;
        matrix[5]=2.0f*vertical/height;
        matrix[6]=0.0f;
        matrix[7]=0.0f;
        matrix[8]=0.0f;
        matrix[9]=0.0f;
        matrix[10]=ratio;
        matrix[11]=1.0f;
        matrix[12]=0.0f;
        matrix[13]=0.0f;
        matrix[14]=znear*-ratio;
        matrix[15]=0.0f;
}
void fn_801F0290(Viewport *self,ViewContext *context)
{
    if(self->enabled && context) {
        Engine *engine=context->engine;
        int x,y,width,height;
        float horizontal,vertical;
        float matrix[16];
        fn_8021239C(self,context,&x,&y,&width,&height,&horizontal,&vertical);
        GXDrawDone();
        engine->set_rectangle(x,y,width,height);
        project(matrix,width,height,horizontal,vertical,0.0001f,32.0f);
        GXSetProjection(matrix,0);
        GXSetViewport(x,y,width,height,0.0f,1.0f);
        GXSetScissor(x,y,width,height);
        fn_80211A10(self,context);
    }
}
Viewport *fn_801F0474(Viewport *self,short flag)
{
    if(self) {
        self->vtable=lbl_802EA908;
        fn_80211508(self,0);
        if(flag>0) fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
Viewport *fn_801F04DC(Viewport *self)
{
    __ct__28ViewportManipulator_802EB130Fv(self);
    self->vtable=lbl_802EA908;
    return self;
}
}
