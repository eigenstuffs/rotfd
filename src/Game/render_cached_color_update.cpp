extern "C" {double __fabs(double);extern const float lbl_8037B6E8,lbl_8037B6EC;}
struct CachedRenderVec3 {float x,y,z;};
struct CachedRenderColor {unsigned char r,g,b,a;};
struct CachedRenderColorOwner {char unknown[0x3A0];CachedRenderVec3 color;};
extern "C" void GXSetTevColor(int,CachedRenderColor);
inline int cachedColorPairEqual(float x,float y){int result=0;if((float)__fabs(x)<lbl_8037B6E8){if((float)__fabs(y)<lbl_8037B6E8)result=1;}return result;}
inline signed char cachedColorEqual(float x,float y,float z){signed char result=0;if(cachedColorPairEqual(x,y)&&(float)__fabs(z)<lbl_8037B6E8)result=1;return result;}
extern "C" void fn_80272708(CachedRenderColorOwner*self,const CachedRenderVec3*value){
 float x=self->color.x-value->x;float z=self->color.z-value->z;float y=self->color.y-value->y;
 if(!cachedColorEqual(x,y,z)){
  self->color.x=value->x;self->color.y=value->y;self->color.z=value->z;
  CachedRenderColor c;c.a=255;c.r=lbl_8037B6EC*value->x;c.g=lbl_8037B6EC*value->y;c.b=lbl_8037B6EC*value->z;
  GXSetTevColor(2,c);
 }
}
