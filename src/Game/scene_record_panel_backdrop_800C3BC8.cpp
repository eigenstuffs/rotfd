/* Scene record panel activation/deactivation and the four-quad backdrop draw.
 * One original translation unit (shared int-to-float pool): .text 800C3BC8..800C421C
 * (fn_800C3BC8, fn_800C3D44, fn_800C3DE8, fn_800C3DEC); private .sdata2 pool
 * 80379598..803795AC (1.0f, 0.5f, int-to-float bias, 0.0f; padded to 803795B0).
 * The const viewport keeps the renderer load unordered against the uv stores. */
typedef unsigned long u32;
struct Manager;
struct Node;
struct Entry {Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Scene;
struct Globals {char opaque00[0x110];void*logger110;char*lists114;Manager*manager118;char opaque11C[8];Scene*scene124;};
struct Handle_8002F6B0;
extern "C" { extern Globals lbl_801E9D24; extern char lbl_801EF5C8[]; void fn_801EF610(void*,void*); void fn_801F86C8(Manager*,const void*,int); void fn_801E2074(void*,const Handle_8002F6B0&,int); void fn_801E1F3C(void*,const Handle_8002F6B0&); void fn_80213A18(void*); void fn_802139D8(void*); void fn_801E2E70(const void*,int*,int*,int*,int*); }
struct Handle_801F7F10 {union{u32 word;struct{signed int tag:8,index:24;}bits;}; Handle_801F7F10(); ~Handle_801F7F10(); static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);} };
struct Manager {char unknown00[8];Entry*entries;};
struct RecordZero_800C3D44:Handle_801F7F10 {RecordZero_800C3D44(){word=0;} ~RecordZero_800C3D44(){} };
struct Handle_80021BCC:RecordZero_800C3D44 {Handle_80021BCC(){word=0;} ~Handle_80021BCC(){} };
struct Handle_8002F6B0:Handle_80021BCC {Handle_8002F6B0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager118,&h,1);} ~Handle_8002F6B0(){} };
struct Handle_8001FF78:Handle_801F7F10 {Handle_8001FF78(){word=0;}~Handle_8001FF78(){}};
struct Handle_800A8204:Handle_8001FF78 {Handle_800A8204(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager118,&h,1);}~Handle_800A8204(){}};
template<int D>struct ReturnLayer_800C3DEC:ReturnLayer_800C3DEC<D-1>{~ReturnLayer_800C3DEC(){}};template<>struct ReturnLayer_800C3DEC<1>:Handle_801F7F10{~ReturnLayer_800C3DEC(){}};
struct Handle_8003E120:ReturnLayer_800C3DEC<2>{~Handle_8003E120(){}};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager118;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}

struct Vec2 {float x,y;Vec2(){}Vec2(float a,float b):x(a),y(b){}Vec2(int a,int b):x((float)a),y((float)b){}Vec2 operator*(float t)const{return Vec2(x*t,y*t);}void set(float a,float b,float t){x=a*t;y=b*t;}};
struct Panel {char opaque00[4];Handle_801F7F10 handle04;char opaque08[0x10];signed char flag18;char opaque19[7];int value20,value24;float scaleX,scaleY;Vec2 lo,hi;};
extern "C" void fn_800C3BC8(Panel*self,int index){
 if(!self->flag18){
  const Handle_801F7F10&original=self->handle04;
  fn_801E2074(lbl_801E9D24.lists114+(index*=0x4C),Handle_8002F6B0(original),0);
  fn_80213A18(self);
  int x,y,w,h;
  fn_801E2E70(lbl_801E9D24.lists114+index,&x,&y,&w,&h);
  self->lo=Vec2(0.5f*w*(1.0f-self->scaleX),h*(1.0f-self->scaleY));
  self->hi=Vec2(0.5f*w*(1.0f+self->scaleX),(float)h);
  self->value24=0;
  self->value20=0;
 }
}

struct View {char opaque00[4];Handle_801F7F10 handle04;char opaque08[0x10];signed char flag18;};
extern "C" void fn_800C3D44(View*self,int index){if(self->flag18){const Handle_801F7F10&original=self->handle04;fn_801E1F3C(lbl_801E9D24.lists114+index*0x4C,Handle_8002F6B0(original));fn_802139D8(self);}}

extern "C" void fn_800C3DE8(void){}

struct Vec3 {float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}};
struct Rect {Vec2 lo,hi;};
struct RendererPrefix {char unknown00[0x278];};
struct Renderer:RendererPrefix {
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();
virtual void draw(const Vec2&,const Vec2&,const Vec2&,const Vec2&,const Vec3&,const Vec3&,float);
virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
virtual void slot98();virtual void slot9C();
virtual void bind(const Handle_800A8204&);
};
struct Viewport {char unknown00[0x48];Renderer*renderer;Renderer*getRenderer()const{return renderer;}};
struct Node {char unknown00[0x94];signed char flag94;int isHidden()const{return flag94;}char unknown95[0xB8-0x95];Handle_801F7F10 material;};
struct Backdrop {char unknown00[0x40];Handle_801F7F10 second,first;};
extern "C" Handle_8003E120 fn_800BCEF8(Scene*);
extern "C" void fn_800C3DEC(Backdrop*self,const Viewport*viewport){
 signed char hidden=resolve(fn_800BCEF8(lbl_801E9D24.scene124))->isHidden();
 if(hidden)return;
 Rect q1,q2,q3,q4;
 Vec3 color;
 Vec2 uvA(1.0f,0.0f),uvB(0.0f,1.0f),uvC(0.0f,0.0f),uvD(1.0f,1.0f);
 Renderer*renderer=viewport->getRenderer();
 int x,y,w,h;
 fn_801E2E70(viewport,&x,&y,&w,&h);
 float cx,cy,hh,hw;
 q1.lo=Vec2((float)x,(float)y);
 cx=x+w;cy=y+h;cx*=0.5f;cy*=0.5f;
 q1.hi.x=cx;q1.hi.y=cy;
 hw=0.5f*w;
 q2.lo.x=q1.lo.x+hw;q2.lo.y=q1.lo.y;q2.hi.x=w;hh=0.5f*h;q2.hi.y=hh;
 q3.lo.x=x;q3.lo.y=hh;q3.hi.x=hw;q3.hi.y=h;
 q4.lo.x=cx;q4.lo.y=cy;q4.hi.x=w;q4.hi.y=h;
 color.x=1.0f;color.y=1.0f;color.z=1.0f;
 renderer->bind(Handle_800A8204(resolve(self->first)->material));
 renderer->draw(q1.lo,q1.hi,uvA,uvB,color,color,1.0f);
 renderer->draw(q2.lo,q2.hi,uvC,uvD,color,color,1.0f);
 renderer->bind(Handle_800A8204(resolve(self->second)->material));
 renderer->draw(q3.lo,q3.hi,uvA,uvB,color,color,1.0f);
 renderer->draw(q4.lo,q4.hi,uvC,uvD,color,color,1.0f);
}
