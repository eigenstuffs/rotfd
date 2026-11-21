/* fn_802568F4 / fn_80256BA0: indexed bone direction helpers.
 * Both resolve the owner's scene object (handle 0x64), its skeleton
 * (related handle 0x1F0) and two bones through the skeleton's handle array
 * (indices mapped by lbl_801E9D24.records->indices).
 * fn_802568F4 stores the normalized direction from the first to the second
 * bone, expressed in the frame of the object behind related handle 0x1F4.
 * fn_80256BA0 rotates the first bone so that the bone-to-bone direction
 * (expressed in its parent's cached inverse frame) turns toward `input`.
 *
 * Matching notes: the second resolve of handle 0x64 in fn_802568F4 is a
 * separate (non-CSE'd) read in the original, kept with a cast read form.
 * The squared length is built without contraction (fp_contract off helper);
 * the frsqrte normalize is the engine reciprocalSqrt helper. */
#pragma fp_contract on
struct Handle{signed int generation:8;signed int index:24;};
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}
 Vec3 get()const{return Vec3(x,y,z);}
 void operator-=(const Vec3&v){x-=v.x;y-=v.y;z-=v.z;}
 void operator*=(float s){x*=s;y*=s;z*=s;}
};
struct Frame{float m[3][4];Vec3 position;float w3C;};
struct Quat{
 float w,x,y,z;
 Quat(){}
 Quat(const Quat&q){w=q.w;x=q.x;y=q.y;z=q.z;}
 void operator=(const Quat&q){w=q.w;x=q.x;y=q.y;z=q.z;}
};
struct FrameBank{char*tables[6];unsigned char current;};
struct Target{
 char unknown0[0xC];Handle parent0C;
 char unknown10[0x18];Handle*handles28;
 char unknown2C[0x9C];Quat rotationC8;
 char unknownD8[0x48];unsigned long flags120;Frame*frame124;Frame*frame128;
 char unknown12C[2];short index12E;
 char unknown130[0xC0];Handle related1F0;Handle related1F4;
};
struct Entry{Target*object;char unknown4[8];signed char generation;char unknownD[3];signed char getGeneration()const{return generation;}};
struct Manager{char unknown0[8];Entry*entries;};
struct Indices{char unknown0[0x94];int*indices;};
extern "C"{
extern struct{char unknown0[0x118];Manager*manager;char unknown11C[0x18];FrameBank*frames;char unknown138[0xC];Indices*records;}lbl_801E9D24;
void fn_801F230C(Frame*,Frame*);
void fn_801F27BC(Quat*,const Vec3*,const Vec3*);
void fn_801F1BB0(Quat*,const Quat*);
}
inline Target*resolve(const Handle&h){
 int index=h.index;Manager*m=lbl_801E9D24.manager;
 int generation=m->entries[index].getGeneration();
 return generation==h.generation?m->entries[index].object:0;
}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
#pragma fp_contract off
inline float lengthSq(const Vec3&v){return v.x*v.x+v.y*v.y+v.z*v.z;}
#pragma fp_contract on
static inline float dot3(float a,float b,float c,float x,float y,float z){return a*x+b*y+c*z;}
inline void normalize(Vec3&v){float r=reciprocalSqrt(lengthSq(v));v*=r;}
inline Vec3&normalizeR(Vec3&v){float r=reciprocalSqrt(lengthSq(v));v*=r;return v;}
struct Owner{char unknown0[0x64];Handle handle64;};

extern "C" signed char fn_802568F4(Owner*self,int first,int second,Vec3*out){
 Target*a=resolve(self->handle64);
 Target*b=resolve(a->related1F0);
 Target*c=resolve(resolve(*(const Handle*)&self->handle64)->related1F4);
 Target*o1=resolve(b->handles28[lbl_801E9D24.records->indices[first]]);
 Target*o2=resolve(b->handles28[lbl_801E9D24.records->indices[second]]);
 if(o1&&o2){
  *out=o2->frame124->position.get();
  *out-=o1->frame124->position.get();
  Frame*f=c->frame124;
  float x=dot3(f->m[0][0],f->m[1][0],f->m[2][0],out->x,out->y,out->z);
  float y=dot3(f->m[0][1],f->m[1][1],f->m[2][1],out->x,out->y,out->z);
  float z=dot3(f->m[0][2],f->m[1][2],f->m[2][2],out->x,out->y,out->z);
  out->x=x;out->y=y;out->z=z;
  float r=reciprocalSqrt(lengthSq(*out));
  *out*=r;
  return 1;
 }
 return 0;
}

extern "C" signed char fn_80256BA0(Owner*self,int first,int second,const Vec3*input){
 Target*a=resolve(self->handle64);
 Target*b=resolve(a->related1F0);
 Target*o1=resolve(b->handles28[lbl_801E9D24.records->indices[first]]);
 Target*o2=resolve(b->handles28[lbl_801E9D24.records->indices[second]]);
 if(o1&&o2){
  Target*parent=resolve(o1->parent0C);
  if(parent){
   Frame*f2=o2->frame124;Frame*f1=o1->frame124;
   Vec3 d=f2->position.get();
   d-=f1->position.get();
   Vec3 n=normalizeR(d);
   if(parent->flags120&0x20){
    FrameBank*bank=lbl_801E9D24.frames;
    parent->frame128=(Frame*)(bank->tables[bank->current]+parent->index12E*0x40);
    fn_801F230C(parent->frame124,parent->frame128);
    parent->flags120&=~0x20;
   }
   Frame*f=parent->frame128;
   float fromx=dot3(f->m[0][0],f->m[1][0],f->m[2][0],n.x,n.y,n.z);
   float fromy=dot3(f->m[0][1],f->m[1][1],f->m[2][1],n.x,n.y,n.z);
   float fromz=dot3(f->m[0][2],f->m[1][2],f->m[2][2],n.x,n.y,n.z);
   Vec3 from(fromx,fromy,fromz);
   float tox=dot3(f->m[0][0],f->m[1][0],f->m[2][0],input->x,input->y,input->z);
   float toy=dot3(f->m[0][1],f->m[1][1],f->m[2][1],input->x,input->y,input->z);
   float toz=dot3(f->m[0][2],f->m[1][2],f->m[2][2],input->x,input->y,input->z);
   Vec3 to(tox,toy,toz);
   normalize(from);
   normalize(to);
   Quat q;
   fn_801F27BC(&q,&from,&to);
   Quat rotation(o1->rotationC8);
   fn_801F1BB0(&rotation,&q);
   o1->rotationC8=rotation;
   return 1;
  }
 }
 return 0;
}
