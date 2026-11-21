// Menu backdrop and visible text records.
// The record cursor keeps a byte displacement because formatting can replace the array.
typedef unsigned long Word;
struct Handle_801F7F10 {union {Word word;struct {signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry {void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager {int count,capacity;Entry*entries;};
struct FontMetrics {int height;};
struct Font {char unknown00[8];FontMetrics*metrics;};
struct FontOwner {char unknown00[0x24];Font*fonts;Font*get(unsigned char i){return fonts+i;}};
struct Globals {char unknown00[0x118];Manager*manager;char unknown11C[8];void*game;char unknown128[0x24];FontOwner*fonts;};
extern "C" {extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);}
struct Handle_8001FF78:Handle_801F7F10 {Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_800A8204:Handle_8001FF78 {Handle_800A8204(){word=0;}Handle_800A8204(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_800A8204(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Vec2 {float x,y;Vec2(){}Vec2(float a,float b):x(a),y(b){}Vec2(int a,int b):x((float)a),y((float)b){}Vec2 operator*(float t)const{return Vec2(x*t,y*t);}};
inline Vec2 operator+(const Vec2&a,const Vec2&b){return Vec2(a.x+b.x,a.y+b.y);}
struct Vec3 {float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3 operator*(float t)const{return Vec3(x*t,y*t,z*t);}Vec3 operator/(float t)const{return Vec3(x/t,y/t,z/t);}};
struct Vec4 {float x,y,z,w;Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}};
struct RendererPrefix {char unknown00[0x278];};
struct Renderer:RendererPrefix {
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void draw(const Vec2&,const Vec2&,const Vec2&,const Vec2&,const Vec3&,const Vec3&,float);
virtual void slot80();
virtual void fill(const Vec2&,const Vec2&,const Vec4&,float);
virtual void drawOne(const Vec2&,const Vec2&,const Vec2&,const Vec2&,const Vec3&,float);
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual void slot9C();
virtual void bind(const Handle_800A8204&);
};
struct Viewport {char unknown00[0x48];Renderer*renderer;Renderer*getRenderer(){return renderer;}};

struct Record {char text[128];Word keyword,next,previous;unsigned short flags;char unknown8E[0x26];Vec2 position;unsigned short getFlags()const{return flags;}};
struct MenuRecordCursor {int offset;MenuRecordCursor(short i):offset(sizeof(Record)*i){}void next(){offset+=sizeof(Record);}Record&get(Record*base)const{return *reinterpret_cast<Record*>(reinterpret_cast<char*>(base)+offset);}};
struct Menu {char unknown00[0x28];short selected;char unknown2A[2];short start;char unknown2E[0x18];unsigned short count;char unknown48[12];Vec2 corner0,corner1;float alpha;char unknown68[8];Record*records;Handle_801F7F10 material;char unknown78[4];unsigned char fontIndex;char unknown7D[3];Vec3 first,second,selectedFirst,selectedSecond;Vec4 backdrop;Record&at(int i){return records[i];}};
struct MenuItemTextView;
extern "C" {Word fn_801F7EB8(const Handle_801F7F10*);void fn_801E2E70(Viewport*,int*,int*,int*,int*);int fn_80218874(MenuItemTextView*,int,char*);int fn_80261B64(Font*,const char*);void fn_80261870(Font*,Renderer*,const char*,int,int,const Vec3&,const Vec3&,float,float);}
inline long menuControlIndex(const short&i){return i;}
extern "C" void fn_80219510(Menu*self,Viewport*viewport){
 Renderer*renderer=viewport->getRenderer();
 if(fn_801F7EB8(&self->material)){
  Vec2 middle=(self->corner0+self->corner1)*0.5f;
  int sx,sy,width,height;fn_801E2E70(viewport,&sx,&sy,&width,&height);
  renderer->bind(Handle_800A8204());
  {Vec2 lo(0.0f,0.0f),hi((float)width,(float)height);Vec4 color(self->backdrop);renderer->fill(lo,hi,color,1.3f);}
  renderer->bind(Handle_800A8204(self->material));
  {Vec2 hi(1.0f+middle.x,1.0f+middle.y),uvLo(0.0f,0.0f),uvHi(1.0f,1.0f);Vec3 color(1.0f,1.0f,1.0f);renderer->drawOne(self->corner0,hi,uvLo,uvHi,color,1.2f);}
  {Vec2 lo(middle.x,self->corner0.y),hi(self->corner1.x,middle.y),uvLo(1.0f,0.0f),uvHi(0.0f,1.0f);Vec3 color(1.0f,1.0f,1.0f);renderer->drawOne(lo,hi,uvLo,uvHi,color,1.2f);}
  {Vec2 lo(self->corner0.x,middle.y),hi(middle.x,self->corner1.y),uvLo(0.0f,1.0f),uvHi(1.0f,0.0f);Vec3 color(1.0f,1.0f,1.0f);renderer->drawOne(lo,hi,uvLo,uvHi,color,1.2f);}
  {Vec2 lo(middle.x-1.0f,middle.y-1.0f),hi(self->corner1),uvLo(1.0f,1.0f),uvHi(0.0f,0.0f);Vec3 color(1.0f,1.0f,1.0f);renderer->drawOne(lo,hi,uvLo,uvHi,color,1.2f);}
 }
 Font*font=lbl_801E9D24.fonts->get(self->fontIndex);
 short i=self->start;MenuRecordCursor recordIndex(i);
 for(;i<self->start+self->count;recordIndex.next(),++i){
  if(recordIndex.get(self->records).flags&2)continue;
  char text[128];fn_80218874(reinterpret_cast<MenuItemTextView*>(self),menuControlIndex(i),text);
  float x=recordIndex.get(self->records).position.x,y=recordIndex.get(self->records).position.y;
  if((recordIndex.get(self->records).getFlags()&0x18)==0x18)x-=fn_80261B64(font,text)/2.0f;
  else if(recordIndex.get(self->records).getFlags()&0x10)x-=fn_80261B64(font,text);
  if(recordIndex.get(self->records).getFlags()&4){Vec3 first=self->first*0.5f,second=self->second*0.5f;fn_80261870(font,renderer,text,(int)x,(int)y,first,second,1.0f,self->alpha);}
  else if(self->selected==i&&(recordIndex.get(self->records).getFlags()&1))fn_80261870(font,renderer,text,(int)x,(int)y,self->selectedFirst,self->selectedSecond,1.0f,self->alpha);
  else fn_80261870(font,renderer,text,(int)x,(int)y,self->first,self->second,1.0f,self->alpha);
 }
 renderer->bind(Handle_800A8204());
}
