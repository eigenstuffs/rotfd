// Partial text split: fn_80282234 only. fn_802820B4 before it (98.8%:
// FPR colouring in the plane near-equality block) remains original code;
// best full draft: scratch/claude_match/auto_03_802820B4_text/best_full.cpp.
/* fn_80282234: shading plane of a projected-light owner.  When the owner's
   view (+0x18) is active, the node's cached world matrix (refreshed from its
   frame when flag 0x20 is set) is multiplied by the view matrix; the plane
   normal is that matrix's transformed y axis scaled by 256/|n|^2 and its
   distance is minus the dot product with the translation row.  Otherwise
   (0, 0, 0, 255).  Only this function of auto_03_802820B4_text is exact; its
   caller fn_802820B4 (same unit, preceding it) is not included.
   Matching notes: the matrix product is returned by value and then assigned
   (two 64-byte copies); &view->matrix is bound before the world-matrix
   refresh; some 0.0/1.0 literal uses read their labels through distinct
   pointer forms (pooled-literal emulation). */
#pragma fp_contract on
struct Vec3{float x,y,z;};
struct Vec4{float x,y,z,w;
 Vec4(){}
 Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
};
struct Mtx{float m[4][4];};
struct FrameBank{char*tables[6];unsigned char current;};
extern "C"{
extern struct{char unknown0[0x134];FrameBank*frames;}lbl_801E9D24;
extern const float lbl_8037B7E8;
extern const float lbl_8037B7EC;
extern const float lbl_8037B7F4;
extern const float lbl_8037B7F8;
void fn_801F230C(Mtx*,Mtx*);
void fn_801F1080(const Mtx*,const Mtx*,Mtx*);
}
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
struct Shade{char unknown0[0x10];Node*node;char unknown14[4];View*view;char unknown1C[0xBCC-0x1C];int resolution;};
inline Mtx multiply(const Mtx&a,const Mtx&b){Mtx r;fn_801F1080(&a,&b,&r);return r;}

extern "C" void fn_80282234(Shade*self,Vec4*out){
 View*view=self->view;
 if(view&&view->active){
  Node*node=self->node;
  const Mtx&vm=view->matrix;
  Mtx m;
  m=multiply(*node->world(),vm);
  float nx=m.m[0][0]*lbl_8037B7E8+m.m[1][0]*lbl_8037B7F4+m.m[2][0]**(const float*)&lbl_8037B7E8;
  float ny=m.m[0][1]*lbl_8037B7E8+m.m[1][1]**(const float*)&lbl_8037B7F4+m.m[2][1]*lbl_8037B7E8;
  float nz=m.m[0][2]*lbl_8037B7E8+m.m[1][2]**(const float*)(unsigned long)&lbl_8037B7F4+m.m[2][2]*lbl_8037B7E8;
  float len2=nx*nx+ny*ny+nz*nz;
  if(len2==len2){
   float s=lbl_8037B7F8/len2;
   nx*=s;ny*=s;nz*=s;
   out->x=nx;out->y=ny;out->z=nz;out->w=*(const float*)(long)&lbl_8037B7F4;
   float d=m.m[3][0]*nx+m.m[3][1]*ny+m.m[3][2]*nz;
   out->w=-d;
   return;
  }
 }
 out->x=lbl_8037B7E8;out->y=lbl_8037B7E8;out->z=lbl_8037B7E8;out->w=lbl_8037B7EC;
}
