inline long formatControlIndex(const short&i){return i;}
#pragma force_active on
extern "C" {
/* Native menu record parser tokens and shared scalar constants. */
__declspec(section ".sdata2") extern const char lbl_80379238[] __attribute__((aligned(4))) = "NORMAL";

// Existing shared float constant; native identity and extent are preserved.
extern const float lbl_80379240 __attribute__((aligned(8))) = 1.0f;

/* Native menu and resource token names, with their shared numeric bias. */
__declspec(section ".sdata2") extern const char lbl_80379244[] __attribute__((aligned(4))) = "NAME";
__declspec(section ".sdata2") extern const char lbl_8037924C[] __attribute__((aligned(4))) = "PARAM";
__declspec(section ".sdata2") extern const char lbl_80379254[] __attribute__((aligned(4))) = "SCALE";
__declspec(section ".sdata2") extern const char lbl_8037925C[] __attribute__((aligned(4))) = "IT_NEXT";
__declspec(section ".sdata2") extern const char lbl_80379264[] __attribute__((aligned(4))) = "IT_PREC";
__declspec(section ".sdata2") extern const char lbl_8037926C[] __attribute__((aligned(4))) = "KEYWORD";
__declspec(section ".sdata2") extern const char lbl_80379274[] __attribute__((aligned(4))) = "ALIGN";
__declspec(section ".sdata2") extern const char lbl_8037927C[] __attribute__((aligned(4))) = "LEFT";
__declspec(section ".sdata2") extern const char lbl_80379284[] __attribute__((aligned(4))) = "RIGHT";
__declspec(section ".sdata2") extern const char lbl_8037928C[] __attribute__((aligned(4))) = "CENTER";
__declspec(section ".sdata2") extern const char lbl_80379294[] __attribute__((aligned(4))) = "LINE_UP";
__declspec(section ".sdata2") extern const char lbl_8037929C[] __attribute__((aligned(4))) = "ACCESS";
__declspec(section ".sdata2") extern const char lbl_803792A4[] __attribute__((aligned(4))) = "HIDE";
__declspec(section ".sdata2") extern const char lbl_803792AC[] __attribute__((aligned(4))) = "GREY";

}
extern "C" const float lbl_803792B8;
inline const float& creditsZero(){return lbl_803792B8;}
extern "C" const float lbl_803792B8 __attribute__((aligned(8))) = 0.0f;
#pragma force_active reset
// Credits backdrop, bitmap particles, and centered text.
// Recovered layouts use native field offsets; renderer and handle ABIs are unchanged.
typedef unsigned long Word;
struct Handle_801F7F10 {union {Word word;struct {signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry {void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager {int count,capacity;Entry*entries;};
struct FontMetrics {int height;};
struct Font {char unknown00[8];FontMetrics*metrics;};
struct FontOwner {char unknown00[0x24];Font*fonts;Font*get(unsigned char i){return fonts+i;}};
struct MessageRecord {Word unknown00;const char*text;char unknown08[8];};
struct MessageOwner {char unknown00[0xEC];MessageRecord*messages;};
struct GameState {char unknown00[0x15058];MessageOwner*messageOwner;};
struct Globals {char unknown00[0x118];Manager*manager;char unknown11C[8];GameState*game;char unknown128[0x24];FontOwner*fonts;};
extern "C" {extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);extern const char lbl_802A03A8[],lbl_802A03B4[];extern int lbl_80377790;}
struct Handle_8001FF78:Handle_801F7F10 {Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_800A8204:Handle_8001FF78 {Handle_800A8204(){word=0;}Handle_800A8204(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_800A8204(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct BitmapZero:Handle_801F7F10 {BitmapZero(){word=0;}~BitmapZero(){}};
struct Handle_800723F4:BitmapZero {Handle_800723F4(){word=0;}~Handle_800723F4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_800723F4&operator=(const Handle_800723F4&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
inline void*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Name {Word value;Name(const char*s){value=fn_801F948C(this,s);}};
struct NameArgument {Word value;NameArgument(const Name&n):value(n.value){}};
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
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual void slot9C();
virtual void bind(const Handle_800A8204&);
};
struct Viewport {char unknown00[0x48];Renderer*renderer;Renderer*getRenderer(){return renderer;}};
struct Bitmap {char unknown00[0xB8];Handle_801F7F10 material;};
struct Material {char unknown00[0x74];Handle_801F7F10 texture;};
struct Texture {char unknown00[0x30];int width,height;};
inline Texture*textureFor(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (Texture*)m->entries[index].object;return 0;}
struct Particle {Vec2 position;float scale,time;Word unknown10;};
struct MenuRecord;
struct CreditsView {char unknown00[0x28];short selected;char unknown2A[2];short start;char unknown2E[0x18];unsigned short count;char unknown48[12];Vec2 corner0,corner1;float alpha;char unknown68[8];MenuRecord*records;MenuRecord&at(int i);char unknown74[8];unsigned char fontIndex;char unknown7D[3];Vec3 first,second,selectedFirst,selectedSecond;char unknownB0[16];Particle particles[10];};
struct TextRecord {char text[128];Word flags;};
extern "C" {void fn_801E2E70(Viewport*,int*,int*,int*,int*);Handle_800723F4 fn_802631B0(void*,const Name&);unsigned char fn_80262AB4(const FontOwner*,const NameArgument&);void fn_800B3288(CreditsView*,int);int fn_80261B64(Font*,const char*);void fn_80261870(Font*,Renderer*,const char*,int,int,const Vec3&,const Vec3&,float,float);extern TextRecord lbl_802F9FC8[400];}
extern "C" void fn_800B16E0(CreditsView*self,Viewport*viewport){
 Renderer*renderer=viewport->renderer;
 int sx,sy,width,height;fn_801E2E70(viewport,&sx,&sy,&width,&height);
 renderer->bind(Handle_800A8204());
 {Vec2 lo(creditsZero(),creditsZero());Vec2 hi((float)width,(float)height);Vec4 color(creditsZero(),creditsZero(),creditsZero(),1.0f);renderer->fill(lo,hi,color,1.3f);}
 Handle_800723F4 bitmap;
 bitmap=fn_802631B0(lbl_801E9D24.fonts,Name("PFX_BUBBLE"));
 Texture*texture=textureFor(((Material*)resolve(((Bitmap*)resolve(bitmap))->material))->texture);
 int tw=texture->width,th=texture->height;
 renderer->bind(Handle_800A8204(((Bitmap*)resolve(bitmap))->material));
 // Ten independently timed bitmap particles.
 for(int i=0;i<10;++i){
  if(self->particles[i].time>creditsZero()){Vec2 lo(self->particles[i].position);Vec2 wh((float)tw,(float)th);Vec2 hi=self->particles[i].position+wh*self->particles[i].scale;Vec2 uvLo(creditsZero(),creditsZero());Vec2 uvHi(1.0f,1.0f);Vec3 first(0.5f,0.5f,0.5f);Vec3 second(0.5f,0.5f,0.5f);renderer->draw(lo,hi,uvLo,uvHi,first,second,1.0f);}
  else fn_800B3288(self,i);
 }
 Font*font=lbl_801E9D24.fonts->get(fn_80262AB4(lbl_801E9D24.fonts,NameArgument(Name("BIG_FONT"))));
 // Credit records terminate at the low flag bit or the 400-record capacity.
 float x=float(width/2),y=30.0f;
 Vec3 first(160.0f/255.0f,1.0f,1.0f),second(1.0f/255.0f,0.8f,1.0f);
 for(int i=lbl_80377790;i<400;++i){TextRecord&r=lbl_802F9FC8[i];if(r.flags&1)break;
  x-=0.75f*fn_80261B64(font,r.text)/2.0f;
  fn_80261870(font,renderer,r.text,(int)x,(int)y,first,second,0.75f,1.0f);
  x=float(width/2);y+=1.05f*(0.75f*font->metrics->height);
 }
 renderer->bind(Handle_800A8204());
}

struct MenuRecord {char text[128];Word keyword,next,previous;unsigned short flags;unsigned short getFlags()const{return flags;}char unknown8E[0x26];Vec2 position;float scale;Handle_800723F4 bitmap;};
extern "C" void fn_800B1C98(void){}

extern "C" {extern signed char lbl_80377788;extern int lbl_80377798;Word fn_801F7EB8(const Handle_801F7F10*);void fn_800B3B94(CreditsView*,int,char*);}
inline const char*backgroundName(Word offset){return (const char*)((Word)lbl_802A03A8+offset);}
inline MenuRecord&CreditsView::at(int i){return records[i];}
extern "C" void fn_800B1C9C(CreditsView*self,Viewport*viewport){
 if(lbl_80377788){fn_800B16E0(self,viewport);return;}
 Renderer*renderer=viewport->getRenderer();
 int sx,sy,width,height;fn_801E2E70(viewport,&sx,&sy,&width,&height);
 {
  Handle_800723F4 background;
  background=fn_802631B0(lbl_801E9D24.fonts,Name("STATUS_SCREEN_0"));
  Vec2 middle=(self->corner0+self->corner1)*0.5f;
  Vec3 shade(0.5f,0.5f,0.5f);
  Vec2 lo,hi,uvLo,uvHi;
  if(fn_801F7EB8(&background)){
   renderer->bind(Handle_800A8204(((Bitmap*)resolve(background))->material));
   lo=Vec2((float)sx,(float)sy);hi=middle;uvLo.x=creditsZero();uvLo.y=uvLo.x;uvHi=Vec2(1.0f,1.0f);
   renderer->draw(lo,hi,uvLo,uvHi,shade,shade,1.0f);
  }
  background=fn_802631B0(lbl_801E9D24.fonts,Name("STATUS_SCREEN_1"));
  if(fn_801F7EB8(&background)){
   renderer->bind(Handle_800A8204(((Bitmap*)resolve(background))->material));
   lo=Vec2(middle.x,(float)sy);hi=Vec2((float)width,middle.y);
   renderer->draw(lo,hi,uvLo,uvHi,shade,shade,1.0f);
  }
  background=fn_802631B0(lbl_801E9D24.fonts,Name("STATUS_SCREEN_2"));
  if(fn_801F7EB8(&background)){
   renderer->bind(Handle_800A8204(((Bitmap*)resolve(background))->material));
   lo=Vec2((float)sx,middle.y);hi=Vec2(middle.x,(float)height);
   renderer->draw(lo,hi,uvLo,uvHi,shade,shade,1.0f);
  }
  background=fn_802631B0(lbl_801E9D24.fonts,Name("STATUS_SCREEN_3"));
  if(fn_801F7EB8(&background)){
   renderer->bind(Handle_800A8204(((Bitmap*)resolve(background))->material));
   lo=middle;hi=Vec2((float)width,(float)height);
   renderer->draw(lo,hi,uvLo,uvHi,shade,shade,1.0f);
  }
 }
 Handle_800723F4 bitmap;
 bitmap=fn_802631B0(lbl_801E9D24.fonts,Name("PFX_BUBBLE"));
 Texture*texture=textureFor(((Material*)resolve(((Bitmap*)resolve(bitmap))->material))->texture);
 int tw=texture->width,th=texture->height;
 renderer->bind(Handle_800A8204(((Bitmap*)resolve(bitmap))->material));
 for(int i=0;i<10;++i){
  if(self->particles[i].time>creditsZero()){
   Vec2 lo(self->particles[i].position);Vec2 wh((float)tw,(float)th);Vec2 hi=self->particles[i].position+wh*self->particles[i].scale;
   Vec2 uvLo(creditsZero(),creditsZero()),uvHi(1.0f,1.0f);Vec3 first(1.0f,1.0f,1.0f),second(1.0f,1.0f,1.0f);
   renderer->draw(lo,hi,uvLo,uvHi,first,second,1.0f);
  }else fn_800B3288(self,i);
 }
 Font*font=lbl_801E9D24.fonts->get(self->fontIndex);
 for(short i=self->start;i<self->start+self->count;++i){
  if(self->at(i).getFlags()&2)continue;
  float scale=self->at(i).scale;char text[128];fn_800B3B94(self,formatControlIndex(i),text);
  Vec2 position(self->at(i).position);
  if((self->at(i).getFlags()&0x38)!=0x38){
   if((self->at(i).getFlags()&0x18)==0x18)position.x-=fn_80261B64(font,text)/2.0f;
   else if(self->at(i).getFlags()&0x10)position.x-=fn_80261B64(font,text);
  }
  if(fn_801F7EB8(&self->at(i).bitmap)){
   float shade=1.0f;if(self->at(i).getFlags()&4)shade=0.5f;
   Texture*t=textureFor(((Material*)resolve(((Bitmap*)resolve(self->at(i).bitmap))->material))->texture);
   Word w=(Word)(t->width*scale),h=(Word)(t->height*scale);
   renderer->bind(Handle_800A8204());
   renderer->bind(Handle_800A8204(((Bitmap*)resolve(self->at(i).bitmap))->material));
   Vec2 hi;hi.x=position.x+(int)w;hi.y=position.y+(int)h;Vec2 uvLo;uvLo.x=creditsZero();uvLo.y=uvLo.x;Vec2 uvHi(1.0f,1.0f);
   renderer->draw(position,hi,uvLo,uvHi,Vec3(0.5f*shade,0.5f*shade,0.5f*shade),Vec3(0.5f*shade,0.5f*shade,0.5f*shade),1.0f);
   position.x+=(int)(w+4);
  }
  if(self->at(i).getFlags()&4){
   Vec3 first=self->first/1.5f,second=self->second/1.5f;
   fn_80261870(font,renderer,text,(int)position.x,(int)position.y,first,second,scale,self->alpha);
  }else{
   Vec3 black(creditsZero(),creditsZero(),creditsZero());
   if(self->selected==i&&(self->at(i).getFlags()&1)){
    fn_80261870(font,renderer,text,(int)position.x+3,(int)position.y+2,self->selectedFirst*0.5f,self->selectedSecond*0.5f,scale,self->alpha);
    fn_80261870(font,renderer,text,(int)position.x,(int)position.y,self->selectedFirst,self->selectedSecond,scale,self->alpha);
   }else{
    fn_80261870(font,renderer,text,(int)position.x+3,(int)position.y+2,black,black,scale,self->alpha);
    fn_80261870(font,renderer,text,(int)position.x,(int)position.y,self->first,self->second,scale,self->alpha);
   }
  }
 }
 if(lbl_80377798>0){
  const MessageRecord&record=lbl_801E9D24.game->messageOwner->messages[lbl_80377798];const char*message=record.text;
  Vec3 first(1.0f,1.0f,creditsZero()),second(1.0f,0.8f,first.z);
  fn_80261870(font,renderer,message,15,20,first,second,0.9f,self->alpha);
 }
 renderer->bind(Handle_800A8204());
}
