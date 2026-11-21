/* fn_802820B4: per-vertex shading-plane colouring.  When the owner's view
   (+0x18) is active, fetches the shading plane (fn_80282234) and, unless it
   is (0, 0, 0, 255) within epsilon, replaces the low byte of each of the
   (resolution+1)^2 vertex colours with fn_800A8E8C(plane . p + w, 0, 255).
   Only fn_802820B4 is in this file; fn_80282234 (same original unit) is
   src/Game/shade_plane_vertex_colors_80282234.cpp.
   Matching notes: the difference plane - (0,0,0,255) is a temporary whose
   equality with game_vec4_zero goes through the free vecEqual(float,float,
   float) form (the original passes the y difference twice, so z is never
   tested); a two-local pairwise helper inside a member gave an FPR swap. */
#pragma fp_contract on
struct Vec3{float x,y,z;};
struct Vec4{float x,y,z,w;
 Vec4(){}
 Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
 Vec4 operator-(const Vec4&o)const{return Vec4(x-o.x,y-o.y,z-o.z,w-o.w);}
 signed char nearlyEqual(const Vec4&o)const;
};
struct Mtx{float m[4][4];};
struct FrameBank{char*tables[6];unsigned char current;};
extern "C"{
extern struct{char unknown0[0x134];FrameBank*frames;}lbl_801E9D24;
extern const Vec4 game_vec4_zero;
extern const float lbl_8037B7E8;
extern const float lbl_8037B7EC;
extern const float lbl_8037B7F0;
extern const float lbl_8037B7F4;
extern const float lbl_8037B7F8;
double __fabs(double);
void fn_801F230C(Mtx*,Mtx*);
void fn_801F1080(const Mtx*,const Mtx*,Mtx*);
float fn_800A8E8C(float,float,float);
}
inline int pairEqual(float x,float y){int result=0;if((float)__fabs(x)<lbl_8037B7F0){if((float)__fabs(y)<lbl_8037B7F0)result=1;}return result;}
inline signed char vecEqual(float x,float y,float z){signed char result=0;if(pairEqual(x,y)&&(float)__fabs(z)<lbl_8037B7F0)result=1;return result;}
inline signed char Vec4::nearlyEqual(const Vec4&o)const{return vecEqual(x-o.x,y-o.y,y-o.y);}
struct Node{char unknown0[0x120];unsigned long flags120;Mtx*frame124;Mtx*frame128;char unknown12C[2];short index12E;
 Mtx*world(){
  if(flags120&0x20){
   FrameBank*bank=lbl_801E9D24.frames;
   frame128=(Mtx*)(bank->tables[bank->current]+index12E*0x40);
   fn_801F230C(frame124,frame128);
   flags120&=~0x20;
  }
  return frame128;
 }
};
struct View{char unknown0[0x80];signed char active;char unknown81[0x6B];Mtx matrix;};
struct Vertices{Vec3*positions;void*unknown4;unsigned long*colors;};
struct Shade{char unknown0[0x10];Node*node;char unknown14[4];View*view;char unknown1C[0xBCC-0x1C];int resolution;};
inline Mtx multiply(const Mtx&a,const Mtx&b){Mtx r;fn_801F1080(&a,&b,&r);return r;}
inline Mtx viewMatrix(Node*node,View*view){return multiply(*node->world(),view->matrix);}
extern "C" void fn_80282234(Shade*self,Vec4*out);

extern "C" void fn_802820B4(Shade*self,Vertices*vertices){
 View*view=self->view;
 if(!view||!view->active)return;
 int count=(self->resolution+1)*(self->resolution+1);
 Vec4 plane;
 fn_80282234(self,&plane);
 if((plane-Vec4(lbl_8037B7E8,lbl_8037B7E8,lbl_8037B7E8,lbl_8037B7EC)).nearlyEqual(game_vec4_zero))return;
 unsigned long*c;
 Vec3*p=vertices->positions;
 c=vertices->colors;
 while(count--){
  *c&=0xFFFFFF00;
  *c|=(unsigned long)fn_800A8E8C(plane.x*p->x+plane.y*p->y+plane.z*p->z+plane.w,lbl_8037B7E8,lbl_8037B7EC);
  p++;c++;
 }
}

