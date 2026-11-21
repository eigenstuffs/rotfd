// fn_80219AC8: 3D menu selection carousel (own original TU). Projects the
// selected object's bounding sphere, draws two background quads and the
// previous/current/next item icons. Owns the literal pool .sdata2
// 0x8037AEF8..0x8037AF20 (0.0, 1.0, 24, 9, 0.5, 0.1, 32, 16, signed int->float bias).
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();int getIndex()const{return bits.index;}signed char getTag()const{return bits.tag;}};
struct Vec2 {float x,y;Vec2(){}void set(float a,float b){x=a;y=b;}const Vec2&get()const{return *this;}Vec2 operator-(const Vec2&v)const{return Vec2(x-v.x,y-v.y);}Vec2 operator+(const Vec2&v)const{return Vec2(x+v.x,y+v.y);}Vec2(float a,float b):x(a),y(b){}Vec2(const Vec2&v):x(v.x),y(v.y){}Vec2&operator=(const Vec2&v){x=v.x;y=v.y;return *this;}};
struct Vec3 {float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}};
struct Sphere {Vec3 center;float radius;};
struct Matrix {float m[16];};
struct Entry {void*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager {int count,capacity;Entry*entries;Entry*get(int i)const{return &entries[i];}};
struct MatrixPool {Matrix*pages[6];unsigned char active;};
struct Global {char unknown00[0x118];Manager*manager;char unknown11C[0x18];MatrixPool*pool;};
extern "C" {extern Global lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_801F230C(const Matrix*,Matrix*);void fn_801F2788(Matrix*,const Matrix*);Sphere fn_80099A00(const Matrix*,const Sphere*);}
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
template<int Depth>struct CarouselHandleLayer_80219AC8:CarouselHandleLayer_80219AC8<Depth-1>{~CarouselHandleLayer_80219AC8(){}};template<>struct CarouselHandleLayer_80219AC8<1>:Handle_801F7F10{CarouselHandleLayer_80219AC8(){word=0;}~CarouselHandleLayer_80219AC8(){}};
struct CarouselCopyHandle_80219AC8:CarouselHandleLayer_80219AC8<1>{CarouselCopyHandle_80219AC8(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~CarouselCopyHandle_80219AC8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
template<class T> inline T*resolve(const Handle_801F7F10&h){int index=h.getIndex();Manager*m=lbl_801E9D24.manager;Entry*e=m->get(index);return e->getTag()==h.getTag()?(T*)e->object:0;}
struct Node {char unknown00[0x1C];Handle_801F7F10 parent;char unknown20[0x100];Word flags;Matrix*matrix,*inverse;short unknown12C,index;Matrix*getInverse(){if(flags&0x20){inverse=lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active]+index;fn_801F230C(matrix,inverse);flags&=~0x20;}return inverse;}};
struct BoundsResource {char unknown00[0xC];Sphere bounds;};
struct Texture {char unknown00[0x30];int width,height;};
struct TextureNode {char unknown00[0x74];Handle_801F7F10 resource;};
struct RendererFields {char unknown00[0x268];float scaleX,scaleY;int originX,originY;};
struct Renderer:RendererFields {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();
 virtual void quad(const Vec2&,const Vec2&,const Vec2&,const Vec2&,const Vec3&,const Vec3&,float);
 virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();
 virtual void bind(CarouselCopyHandle_80219AC8);
};
struct DrawContext {char unknown00[0x14];Handle_801F7F10 camera;char unknown18[0x30];Renderer*renderer;};
struct Item {char unknown00[0x90];Handle_801F7F10 texture;char unknown94[8];};
struct Menu {char unknown00[0x28];short selected;char unknown2A[0x1E];signed char wrap;char unknown49[3];int count,capacity;Item*items;Handle_801F7F10 object,background;};
typedef char RendererFieldsSize[sizeof(RendererFields)==0x278?1:-1];
typedef char ItemSize[sizeof(Item)==0x9C?1:-1];
extern "C" void fn_80219AC8(Menu*self,DrawContext*context){
 Renderer*renderer=context->renderer;
 int previous=self->selected-1,next=self->selected+1;
 if(previous<0&&self->wrap)previous=self->count-1;
 if(next>=self->count&&self->wrap)next=0;
 Matrix transform=*resolve<Node>(context->camera)->getInverse();
 fn_801F2788(&transform,resolve<Node>(self->object)->matrix);
 Sphere sphere=fn_80099A00(&transform,&resolve<BoundsResource>(resolve<Node>(self->object)->parent)->bounds);
 float zero=0.0f;float depth=sphere.center.z+zero;
 float inverse=1.0f/depth;
 float tx=sphere.center.x+zero;float x=inverse*(tx*renderer->scaleX)+renderer->originX;
 float ty=-(sphere.center.y+sphere.radius);float y=inverse*(ty*renderer->scaleY)+renderer->originY-24.0f;
 Texture*texture=resolve<Texture>(resolve<TextureNode>(self->background)->resource);
 Vec2 icon0,icon1;
 int width=texture->width,height=texture->height;width/=2;height/=4;Vec2 corner0;Vec2 corner1(x,y);corner0=corner1;
 corner0.x-=width;corner0.y=9.0f+(corner0.y-height);
 corner1.x+=width;corner1.y+=height+9;
 renderer->bind(self->background);
 {Vec2 arg2=Vec2(0.0f,0.0f);Vec2 arg3=Vec2(1.0f,0.5f);Vec3 arg4=Vec3(1.0f,1.0f,1.0f);Vec3 arg5=Vec3(1.0f,1.0f,1.0f);renderer->quad(corner0,corner1,arg2,arg3,arg4,arg5,0.1f+depth);}
 icon0=Vec2(x-32.0f-24.0f,y-16.0f);icon1.x=x-24.0f;float lower=16.0f+y;icon1.y=lower;
 renderer->bind(self->items[previous].texture);
 {Vec2 arg2=Vec2(0.0f,0.0f);Vec2 arg3=Vec2(1.0f,1.0f);Vec3 arg4=Vec3(1.0f,1.0f,1.0f);Vec3 arg5=Vec3(1.0f,1.0f,1.0f);renderer->quad(icon0,icon1,arg2,arg3,arg4,arg5,depth);}
 icon0=Vec2(x-24.0f,y-24.0f);x=24.0f+x;icon1=Vec2(x,24.0f+y);
 renderer->bind(self->items[self->selected].texture);
 {Vec2 arg2=Vec2(0.0f,0.0f);Vec2 arg3=Vec2(1.0f,1.0f);Vec3 arg4=Vec3(1.0f,1.0f,1.0f);Vec3 arg5=Vec3(1.0f,1.0f,1.0f);renderer->quad(icon0,icon1,arg2,arg3,arg4,arg5,depth);}
 icon0=Vec2(x,y-16.0f);icon1=Vec2(32.0f+x,lower);
 renderer->bind(self->items[next].texture);
 {Vec2 arg2=Vec2(0.0f,0.0f);Vec2 arg3=Vec2(1.0f,1.0f);Vec3 arg4=Vec3(1.0f,1.0f,1.0f);Vec3 arg5=Vec3(1.0f,1.0f,1.0f);renderer->quad(icon0,icon1,arg2,arg3,arg4,arg5,depth);}
 renderer->bind(self->background);
 {Vec2 arg2=Vec2(0.0f,0.5f);Vec2 arg3=Vec2(1.0f,1.0f);Vec3 arg4=Vec3(1.0f,1.0f,1.0f);Vec3 arg5=Vec3(1.0f,1.0f,1.0f);renderer->quad(corner0,corner1,arg2,arg3,arg4,arg5,depth-0.1f);}
}
