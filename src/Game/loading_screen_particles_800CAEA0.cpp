/* Loading-screen particle object: constructor, destructor, standalone particle
 * draw, virtual update, virtual draw, particle-array static initializer and
 * element constructor (0x800CAEA0..0x800CBC80).  One original
 * translation unit: the first five functions share the .sdata2 literal pool
 * 0x80379660..0x80379690 (written as literals; the compiler-local int-to-float
 * bias is 0x80379680) and the .rodata strings 0x802A28A8..0x802A28F8. */
typedef unsigned long Word;
struct Node;struct Manager;struct Render;struct Handle_800A8204;
struct Bits{signed long tag:8,index:24;};
struct Handle_801F7F10{union{Word word;Bits bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}Node*getObject()const{return object;}};
struct Manager{Word unknown00,unknown04;Entry*entries;};
struct Viewport{char unknown00[0x48];Render*render;};
struct RenderPrefix{char unknown00[0x215];signed char selected;char unknown216[0x278-0x216];};
struct Vec2{float x,y;Vec2(){}Vec2(float a,float b):x(a),y(b){}};
struct Vec3{float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){}};
struct Render:RenderPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void finish18();virtual void finish1C();
virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void draw(const Vec2&,const Vec2&,const Vec2&,const Vec2&,const Vec3&,const Vec3&,float);virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void bind(const Handle_800A8204&);};
struct Target{char unknown00[0x234];unsigned int flags234;};
struct Context{char unknown00[0x114];union{Render*render;Target*target;};Manager*manager;char unknown11C[0x30];void*scope;};
extern "C" {extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);Node*fn_801F7EB8(const Handle_801F7F10*);float fn_801F463C(Context*);float fn_801F1200();void fn_801E2E70(Viewport*,int*,int*,int*,int*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_800723F4:Handle_8001FF78{Handle_800723F4(){word=0;}Handle_800723F4(const Handle_800723F4&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_800723F4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_800A8204:Handle_8001FF78{Handle_800A8204(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_800A8204(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct LoadingTwoZero_CAEA0:Handle_8001FF78{LoadingTwoZero_CAEA0(){word=0;}};
struct Handle_800C5EC8:LoadingTwoZero_CAEA0{Handle_800C5EC8(){word=0;}~Handle_800C5EC8();};
struct Name{Word word;Name(const char*s){word=fn_801F948C(this,s);}};
extern "C" Handle_800723F4 fn_802631B0(void*,const Name&);
struct Node{char unknown00[0x30];int width,height;char unknown38[0x48-0x38];Handle_801F7F10 progress48;char unknown4C[8];signed char enabled54;char unknown55[0x74-0x55];Handle_801F7F10 texture74;char unknown78[0xB8-0x78];Handle_801F7F10 materialB8;char unknownBC[0x108-0xBC];int total108,remaining10C;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Particle{float x,y,scale,lifetime,delay;signed char drawn;char unknown15[3];};
extern "C" Particle lbl_80318028[100];
extern "C" signed char lbl_80377880[8];

/* 0x800CAEA0: LoadingScreen constructor. */
struct RootPrefix{Word unknown00[2];};
struct Manipulator_Z:RootPrefix{Manipulator_Z();virtual ~Manipulator_Z();char unknown0C[0x14];};
struct ManipulatorDraw_802BC9D0:Manipulator_Z{ManipulatorDraw_802BC9D0(){}virtual ~ManipulatorDraw_802BC9D0();};
struct Object_800CB000:ManipulatorDraw_802BC9D0{Handle_800C5EC8 handle20;Handle_800723F4 handle24;Object_800CB000();virtual ~Object_800CB000();};
Object_800CB000::Object_800CB000(){
 if(!lbl_80377880[0]){
  lbl_80377880[0]=1;
  for(int i=0;i<100;i++){
   lbl_80318028[i].lifetime=10.0f*fn_801F1200();
   lbl_80318028[i].scale=2.2f*fn_801F1200();
   lbl_80318028[i].x=640.0f*fn_801F1200();
   lbl_80318028[i].y=440.0f*fn_801F1200();
   lbl_80318028[i].delay=1.5f*fn_801F1200();
   lbl_80318028[i].drawn=0;
  }
 }
}

/* 0x800CB000: LoadingScreen deleting destructor. */
namespace dtor_CB000{
struct H1:Handle_801F7F10{};
struct H2:H1{};
struct H3:H2{};
static inline void dispose(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
extern "C" char __vt__15Object_800CB000[];
extern "C" char __vt__13Manipulator_Z[],__vt__24ManipulatorDraw_802BC9D0[];
extern "C" void __dt__11Activable_ZFv(void*,int);
struct Root{char opaque00[8];void*vtable;~Root(){vtable=__vt__13Manipulator_Z;__dt__11Activable_ZFv(this,0);}};
struct Draw:Root{~Draw(){vtable=__vt__24ManipulatorDraw_802BC9D0;}};
struct View:Draw{char unknown0C[0x14];H3 handle20;H2 handle24;};
}
extern "C" void*fn_800CB000(dtor_CB000::View*self,int flag){
 if(self){
  self->vtable=dtor_CB000::__vt__15Object_800CB000;
  if(lbl_801E9D24.target)lbl_801E9D24.target->flags234&=~2u;
  self->handle24.~H2();
  self->handle20.~H3();
  static_cast<dtor_CB000::Draw*>(self)->~Draw();
  if((short)flag>0)dtor_CB000::dispose(self);
 }
 return self;
}

/* 0x800CB104..0x800CBC40: particle draw, update and loading text. */
struct Self{char unknown00[0x20];Handle_801F7F10 progress20;Handle_800723F4 resource24;};
struct Font{char unknown00[12];};struct Scope{char unknown00[0x24];Font*fonts;};
extern "C"{unsigned char fn_80262AB4(void*,const Name&);char*strncpy(char*,const char*,unsigned long);void fn_80261870(Font*,Render*,const char*,int,int,const Vec3&,const Vec3&,float,float);}
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager,&d,-1);d.word=s.word;fn_801F86C8(lbl_801E9D24.manager,&s,1);}
inline Font*fontFor(Name name){unsigned char index=fn_80262AB4(lbl_801E9D24.scope,name);return &((Scope*)lbl_801E9D24.scope)->fonts[index];}

extern "C" void fn_800CB104(){
 float elapsed=fn_801F463C(&lbl_801E9D24);
 for(int i=0;i<100;++i){if(lbl_80318028[i].delay>0.0f)lbl_80318028[i].delay-=elapsed;else lbl_80318028[i].lifetime-=elapsed;}
 Handle_800723F4 resource(fn_802631B0(lbl_801E9D24.scope,Name("PFX_BUBBLE")));
 if(!fn_801F7EB8(&resource))return;
 Viewport*viewport=&((Viewport*)lbl_801E9D24.render)[lbl_801E9D24.render->selected];
 Render*render=viewport->render;
 int x,y,width,height;fn_801E2E70(viewport,&x,&y,&width,&height);
 Vec2 lo,hi;
 float zero=0.0f;Vec2 uv0(zero,zero),uv1(1.0f,1.0f);Vec3 color(1.0f,1.0f,1.0f);
 lo.x=(float)x;lo.y=(float)y;hi.x=(float)(x+width);hi.y=(float)(y+height);
 Node*texture=resolve(resolve(resolve(resource)->materialB8)->texture74);int tw=texture->width,th=texture->height;
 render->bind(Handle_800A8204(resolve(resource)->materialB8));
 float*life;
 for(int i=0;i<100;++i){
  life=&lbl_80318028[i].lifetime;float&lifetime=*life;Particle&p=lbl_80318028[i];
  if(lifetime>0.0f){
   if(p.delay<=0.0f){signed char&drawn=p.drawn;if(!drawn){drawn=1;float scale=p.scale;lo.x=p.x;lo.y=p.y;float w=(float)tw*scale;float h=(float)th*scale;hi.x=p.x+w;hi.y=p.y+h;render->draw(lo,hi,uv0,uv1,color,color,1.0f);}}
  }else{lifetime=10.0f*fn_801F1200();p.scale=2.2f*fn_801F1200();p.x=640.0f*fn_801F1200();p.y=440.0f*fn_801F1200();p.delay=1.5f*fn_801F1200();p.drawn=0;}
 }
 lbl_801E9D24.render->finish1C();lbl_801E9D24.render->finish18();
}

extern "C" void fn_800CB5A4(float elapsed){for(int i=0;i<100;++i){if(lbl_80318028[i].delay>0.0f)lbl_80318028[i].delay-=elapsed;else lbl_80318028[i].lifetime-=elapsed;}}

extern "C" void fn_800CB5F4(Self*self,Viewport*viewport){
 if(!fn_801F7EB8(&self->resource24))assign(self->resource24,fn_802631B0(lbl_801E9D24.scope,Name("PFX_BUBBLE")));
 if(!fn_801F7EB8(&self->resource24))return;
 Render*render=viewport->render;int x,y,width,height;fn_801E2E70(viewport,&x,&y,&width,&height);
 float progress=0.0f;
 if(fn_801F7EB8(&self->progress20)){Node*p=resolve(resolve(self->progress20)->progress48);progress=1.0f-(float)p->remaining10C/(float)p->total108;}
 Vec2 lo,hi;float zero=0.0f;Vec2 uv0(zero,zero),uv1(1.0f,1.0f);Vec3 color(1.0f,1.0f,1.0f);
 lo.x=(float)x;lo.y=(float)y;hi.x=(float)(x+width);hi.y=(float)(y+height);
 Node*texture=resolve(resolve(resolve(self->resource24)->materialB8)->texture74);int tw=texture->width,th=texture->height;
 render->bind(Handle_800A8204(resolve(self->resource24)->materialB8));
 float*life;
 for(int i=0;i<100;++i){
  life=&lbl_80318028[i].lifetime;float&lifetime=*life;Particle&p=lbl_80318028[i];
  if(lifetime>0.0f){
   if(p.delay<=0.0f){signed char&drawn=p.drawn;if(!drawn){drawn=1;float scale=p.scale;lo.x=p.x;lo.y=p.y;float w=(float)tw*scale;float h=(float)th*scale;hi.x=p.x+w;hi.y=p.y+h;render->draw(lo,hi,uv0,uv1,color,color,1.0f);}}
  }else{lifetime=10.0f*fn_801F1200();p.scale=2.2f*fn_801F1200();p.x=640.0f*fn_801F1200();p.y=440.0f*fn_801F1200();p.delay=1.5f*fn_801F1200();p.drawn=0;}
 }
 if(fn_801F7EB8(&self->progress20)&&resolve(self->progress20)->enabled54){
  Font*font=fontFor(Name("BIG_FONT"));
  int length=(int)(10.0f*progress+1.0f);if(length>11)length=11;
  char text[12];strncpy(text,"Loading...",length);text[length]=0;
  fn_80261870(font,render,text,(int)(0.05f*(float)width),(int)(0.85f*(float)height),color,color,1.0f,1.0f);
 }
}

/* RTTI class name of LoadingScreen; referenced by the type record at 0x80375900. */
extern "C" const char lbl_802A28CC[]="LoadingScreen";
/* RTTI names of LoadingScreen's bases (type records in native_rtti_type_records_803755E8.cpp). */
#pragma force_active on
extern "C" const char lbl_802A28DC[] = "BaseObject_Z";
extern "C" const char lbl_802A28EC[] = "Activable_Z";
#pragma force_active reset

/* 0x800CBC40: static initializer of the particle array; 0x800CBC7C: element constructor. */
extern "C" void fn_800CBC7C(void*);
extern "C" void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned long,unsigned long);
extern "C" void fn_800CBC40(){__construct_array(lbl_80318028,fn_800CBC7C,0,sizeof(Particle),100);}
extern "C" void fn_800CBC7C(void*){}
__declspec(section ".ctors") static void(*const array_startup_reference)()=fn_800CBC40;
