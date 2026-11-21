// Message-box drawing and text layout share one native conversion-constant owner.
// The render context is read-only; its const type preserves native load ordering.
struct Point2 { float x,y; Point2(){} };
struct Color3 { float r,g,b; };
struct Color4 { float r,g,b,a; Color4(float x,float y,float z,float w):r(x),g(y),b(z),a(w){} };
struct MessageBoxFont;
struct RendererPrefix { char unknown00[0x278]; };
struct TextRenderer:RendererPrefix {
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
    virtual void slot7C();
    virtual void drawRect(const Point2&,const Point2&,const Color4&,const Color4&,float);
};
struct MessageBoxRenderContext { char unknown00[0x48]; TextRenderer*renderer; };
struct MessageBoxDrawView {
 char unknown00[0x28]; signed char active; char unknown29[0x34-0x29]; MessageBoxFont*font;
 const char*lines[10]; int lineCount; char unknown64[0x164-0x64];
 char textA[256],textB[256]; signed char selectionVisible; char unknown365[0x564-0x365];
 int ax,ay,aw,ah,selected,bx,by,bw,bh;float alpha;
 int textAx,textAy,textBx,textBy;int lineX[10],lineY[10];
 Color3 first,second;char unknown604[12];int left,top,width,height;
};
struct MessageBoxGlobals {char unknown00[0x110];void*console;void*renderer;};
extern "C" {
 extern MessageBoxGlobals lbl_801E9D24;
 extern const char lbl_802A226C[];
 void fn_801FA014(void*,const char*,...);
 void fn_80261870(MessageBoxFont*,TextRenderer*,const char*,int,int,const Color3&,const Color3&,float,float);
}
extern "C" const float lbl_80379538=-1612.0f;
static inline const float&half(){static const float h=0.5f;return h;}
extern "C" void fn_800C293C(MessageBoxDrawView*self,const MessageBoxRenderContext*ctx) {
 if (!self->active) return;
 if (!self->font) { fn_801FA014(lbl_801E9D24.console,lbl_802A226C,self->lines[0]); return; }
 Color4 background(half(),half(),half(),0.8f);
 TextRenderer*renderer=ctx->renderer;
 Point2 low; low.x=float(self->left);low.y=float(self->top);
 Point2 high;high.x=float(self->left+self->width);high.y=float(self->top+self->height);
 low.y-=20.0f;low.x-=20.0f;high.x+=20.0f;high.y+=20.0f;
 renderer->drawRect(low,high,background,background,1.0f);
 for(int i=0;i<self->lineCount;++i)fn_80261870(self->font,renderer,self->lines[i],self->lineX[i],self->lineY[i],self->first,self->second,0.6f,1.0f);
 if(self->selectionVisible) {
  Color4 selected(half(),0.58f,0.12f,self->alpha);
  Point2 low;low.x=float(self->ax);low.y=float(self->ay);
  Point2 high;high.x=low.x+float(self->aw);high.y=low.y+float(self->ah);
  if(self->selected==0)renderer->drawRect(low,high,selected,selected,1.0f);
  low.x=float(self->bx);low.y=float(self->by);
  high.x=low.x+float(self->bw);high.y=low.y+float(self->bh);
  if(self->selected==1)renderer->drawRect(low,high,selected,selected,1.0f);
 }
 fn_80261870(self->font,renderer,self->textA,self->textAx,self->textAy,self->first,self->second,0.6f,1.0f);
 fn_80261870(self->font,renderer,self->textB,self->textBx,self->textBy,self->first,self->second,0.6f,1.0f);
}

typedef unsigned long Word;
struct MessageBoxFontMetrics {int height;};
struct MessageBoxFont {char unknown00[8];MessageBoxFontMetrics*metrics;};

struct Rectangle {int x,y,width,height;};
struct MessageBoxLayoutView {
 char unknown00[0x2c];void*mode;int selection;MessageBoxFont*font;
 char*lines[10];int lineCount;
 char text[256],button1[256],button2[256],choice1[256],choice2[256];
 Rectangle firstRect;int selected;Rectangle secondRect;int unknown588;
 int button1X,button1Y,button2X,button2Y;
 int lineX[10],lineY[10];char unknown5EC[0x24];Rectangle box;
 int unknown620;void*table;
};
struct Name;
extern "C" {
 char*strncpy(char*,const char*,unsigned long);
 int sprintf(char*,const char*,...);
 Word fn_801F948C(Name*,const char*);
 const char*fn_800C1B0C(void*,const int*);
 int fn_80261B64(MessageBoxFont*,const char*);
 void fn_801E2E70(void*,int*,int*,int*,int*);
 extern MessageBoxGlobals lbl_801E9D24;
 extern const char lbl_802A2218[],lbl_80379560[8],lbl_80379568[7];
 extern const float lbl_80379570,lbl_80379574,lbl_80379578;
}
struct Name {int value;Name(const char*s){value=fn_801F948C(this,s);}};
struct NameArgument {int value;NameArgument(const Name&n):value(n.value){} operator const int*()const{return &value;}};
inline int fontHeight(MessageBoxFont*f){return f->metrics->height;}
extern "C" void fn_800C2CB8(MessageBoxLayoutView*self,const char*text,void*mode){
 int totalHeight;
 const char*pool=lbl_802A2218;
 strncpy(self->text,text,256);
 self->mode=mode;
 self->lines[0]=self->text;
 self->lineCount=1;
 char*p=self->text;
 while(*p){if(*p=='\n'&&p[1]){*p=0;self->lines[self->lineCount++]=p+1;}++p;}
 self->choice1[0]=0;self->choice2[0]=0;self->selected=1;self->button1[0]=0;self->button2[0]=0;
 const char*first=0;
 const char*second=0;
 switch((Word)self->mode){
  case 0:first=fn_800C1B0C(self->table,NameArgument(Name(lbl_80379560)));break;
  case 1:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0x74)));break;
  case 3:first=fn_800C1B0C(self->table,NameArgument(Name(lbl_80379568)));break;
  case 4:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0x80)));break;
  case 8:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0x90)));break;
  case 9:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0xa4)));break;
  case 13:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0xbc)));break;
  case 12:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0xdc)));second=fn_800C1B0C(self->table,NameArgument(Name(pool+0xf0)));break;
  case 11:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0xdc)));second=fn_800C1B0C(self->table,NameArgument(Name(pool+0xfc)));break;
  case 10:first=fn_800C1B0C(self->table,NameArgument(Name(pool+0xdc)));second=fn_800C1B0C(self->table,NameArgument(Name(pool+0x108)));break;
  case 2:strncpy(self->choice1,fn_800C1B0C(self->table,NameArgument(Name(pool+0x118))),256);strncpy(self->choice2,fn_800C1B0C(self->table,NameArgument(Name(pool+0x128))),256);break;
  case 6:self->button1[0]=0;break;
 }
 if(first)strncpy(self->button1,first,256);
 if(second)strncpy(self->button2,second,256);
 void*renderer=lbl_801E9D24.renderer;
 int i;
 int maxWidth=(int)(0.6f*fn_80261B64(self->font,self->button1));
 int x,y,width,height;
 fn_801E2E70(renderer,&x,&y,&width,&height);
 totalHeight=(int)(self->lineCount*(0.6f*fontHeight(self->font)));
 if(self->button1[0])totalHeight+=(int)(lbl_80379570*(0.6f*fontHeight(self->font)));
 if(self->button2[0])totalHeight+=(int)(lbl_80379570*(0.6f*fontHeight(self->font)));
 if(self->choice1[0])totalHeight+=(int)(lbl_80379570*(0.6f*fontHeight(self->font)));
 for(i=0;i<self->lineCount;++i){
  x=(int)(0.6f*fn_80261B64(self->font,self->lines[i]));
  if(x>maxWidth)maxWidth=x;
  self->lineX[i]=(width-x)/2;
  self->lineY[i]=(int)((height-totalHeight)/2+i*(0.6f*fontHeight(self->font)));
 }
 if(self->choice1[0]){
  sprintf(self->button1,pool+0x138,self->choice1,self->choice2);
  self->button1X=(int)((width-0.6f*fn_80261B64(self->font,self->button1))*half());
  self->button1Y=(int)((height-totalHeight)/2+(self->lineCount+1)*(0.6f*fontHeight(self->font)));
  self->firstRect.x=(int)(self->button1X+(0.6f*fn_80261B64(self->font,self->choice1))*half()-lbl_80379574);
  self->firstRect.y=self->button1Y-2;self->firstRect.width=100;
  self->firstRect.height=(int)(0.6f*fontHeight(self->font)+lbl_80379578);
  self->secondRect.x=(int)((self->button1X+0.6f*fn_80261B64(self->font,self->button1))-(0.6f*fn_80261B64(self->font,self->choice2))*half()-lbl_80379574);
  self->secondRect.y=self->button1Y-2;self->secondRect.width=100;
  self->secondRect.height=(int)(0.6f*fontHeight(self->font)+lbl_80379578);
 }else{
  if(self->button1[0]){
   self->button1X=(int)((width-0.6f*fn_80261B64(self->font,self->button1))*half());
   self->button1Y=(int)((height-totalHeight)/2+(self->lineCount+1)*(0.6f*fontHeight(self->font)));
  }
  if(self->button2[0]){
   self->button2X=(int)((width-0.6f*fn_80261B64(self->font,self->button1))*half());
   self->button2Y=(int)((height-totalHeight)/2+(self->lineCount+2)*(0.6f*fontHeight(self->font)));
  }
 }
 self->box.width=maxWidth+10;self->box.height=totalHeight;
 self->box.x=(width-self->box.width)/2;self->box.y=(height-self->box.height)/2;
}
