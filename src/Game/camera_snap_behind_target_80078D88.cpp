/* Camera snap behind target (fn_80078D88): stores the raised context
   position (fn_80076D98) as the focus (0x158), resolves the target's frame
   node (handle 0x24, virtual slot 0x9C) and rotates the offset
   (0, 5 sin 7.5deg, 5 cos 7.5deg) by its 3x3 rows at +0x30; the camera point
   is that offset plus the focus plus (0, height, 0). It is written to *out,
   to the view node's position (0xB8; scene record selected by 0x20), to the
   previous (0x118) and current (0xF4) points; then the follow flag, zoom and
   flag 0x130 are cleared, fn_800788C4 runs with lbl_80378A38 and the
   position is recomputed into 0x1E0.

   The rotation helper takes the temporary vector by const reference and
   returns a named local (this gives the two dead stack copies and the frsp
   of the rotated components before the additions). The original zero was
   the pooled literal 0.0f, now the shared label lbl_8037899C. Copy
   propagation of a loaded v.x merges the zero differently from the literal
   (which propagated as a constant into each of the three x terms), so the
   helper reads the label for its x terms directly. */
typedef unsigned long Word;
extern "C" const float lbl_8037899C;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry{void*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct SceneRecord{char unknown00[0x14];Handle handle;char unknown18[0x34];};
extern "C" struct Globals{char unknown00[0x114];SceneRecord*records;Manager*manager;}lbl_801E9D24;
template<class T> inline T*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (T*)m->entries[index].object;return 0;}
struct Vec{float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}Vec(const Vec&v):x(v.x),y(v.y),z(v.z){}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}Vec operator+(const Vec&v)const{return Vec(x+v.x,y+v.y,z+v.z);}};
struct Frame{char unknown00[0x30];float m[3][3];
 /* rotates (0, v.y, v.z) */
 Vec rotateYZ(const Vec&v)const{Vec r;r.x=m[0][0]*lbl_8037899C+m[1][0]*v.y+m[2][0]*v.z;r.y=m[0][1]*lbl_8037899C+m[1][1]*v.y+m[2][1]*v.z;r.z=m[0][2]*lbl_8037899C+m[1][2]*v.y+m[2][2]*v.z;return r;}};
struct Prefix{char unknown00[8];};
struct ViewNode{char unknown00[0xB8];Vec position;};
struct TargetNode:Prefix{
virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();
virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();
virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void s28();virtual void s29();
virtual void s30();virtual void s31();virtual void s32();virtual void s33();virtual void s34();virtual void s35();virtual void s36();virtual const Handle*frame(int);
};
struct Camera{
 char unknown00[0x20];int viewIndex;Handle target;char unknown28[0x9C];signed char followHeight;char unknownC5[7];float zoom;char unknownD0[0xC];float height;char unknownE0[0x14];
 Vec current;char unknown100[0x18];Vec previous;char unknown124[0xC];unsigned char flag130;char unknown131[0x27];Vec focus;char unknown164[0x7C];Vec output1E0;};
extern "C"{
void fn_80076D98(Camera*,Vec*);void fn_800788C4(Camera*,float);
float fn_8028506C(float);float fn_80284FA8(float);
extern const float lbl_803789C8,lbl_80378A34,lbl_80378A38;}
extern "C" void fn_80078D88(Camera*self,Vec*out){
 ViewNode*node=resolve<ViewNode>(lbl_801E9D24.records[self->viewIndex].handle);
 Vec position;
 fn_80076D98(self,&position);
 self->focus=position;
 Frame*frame=resolve<Frame>(*resolve<TargetNode>(self->target)->frame(0));
 float height=self->height;
 float c=lbl_803789C8*fn_8028506C(lbl_80378A34);
 float s=lbl_803789C8*fn_80284FA8(lbl_80378A34);
 *out=frame->rotateYZ(Vec(lbl_8037899C,s,c))+position+Vec(lbl_8037899C,height,lbl_8037899C);
 node->position=*out;
 self->previous=*out;
 self->current=self->previous;
 self->followHeight=0;
 self->zoom=lbl_8037899C;
 self->flag130=0;
 fn_800788C4(self,lbl_80378A38);
 fn_80076D98(self,&self->output1E0);
}
