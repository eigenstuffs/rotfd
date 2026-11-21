#pragma fp_contract on
struct GridXClipPoint {float x,y,z;GridXClipPoint(float a,float b,float c):x(a),y(b),z(c){}};
struct GridXClipSelf {char unknown00[0x78];GridXClipPoint extent;};
extern "C" {extern const float lbl_8037B604;extern const float lbl_8037B608;}
extern "C" void fn_802665F4(GridXClipSelf* self,GridXClipPoint* start,const GridXClipPoint* end,unsigned long* flags) {
 if(*flags&1){
  GridXClipPoint delta(end->x-start->x,end->y-start->y,end->z-start->z);
  float fraction=-start->x/delta.x;
  start->x=lbl_8037B608;
  start->y+=fraction*delta.y;
  start->z+=fraction*delta.z;
 }else if(*flags&2){
  GridXClipPoint delta(end->x-start->x,end->y-start->y,end->z-start->z);
  float fraction=(start->x-self->extent.x)/delta.x;
  start->x=self->extent.x;
  start->y-=fraction*delta.y;
  start->z-=fraction*delta.z;
 }
 *flags=0;
 if(start->x<lbl_8037B604)*flags|=1;
 if(start->x>self->extent.x)*flags|=2;
 if(start->y<lbl_8037B604)*flags|=4;
 if(start->y>self->extent.y)*flags|=8;
 if(start->z<lbl_8037B604)*flags|=16;
 if(start->z>self->extent.z)*flags|=32;
}
