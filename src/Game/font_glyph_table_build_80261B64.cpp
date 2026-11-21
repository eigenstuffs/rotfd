typedef unsigned long Word;
struct FontManager;
struct HandleEntry{void*object;char unknown04[8];signed char tag;char pad[3];signed char getTag()const{return tag;}};
struct HandleManager{char unknown00[8];HandleEntry*entries;};
struct FontGlobals{char unknown00[0x118];HandleManager*manager;};
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
extern "C"{
extern FontGlobals lbl_801E9D24;
void fn_801F86C8(HandleManager*,const Handle*,int);
extern char lbl_801EF5C8[];
extern const char lbl_802AEF28[],lbl_802AEF38[];
void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);
void fn_801EF610(void*,void*);
unsigned long strlen(const char*);
extern float game_vec2_zero[2];
}
struct Bitmap{char unknown00[0x30];int width,height;Word unknown38;unsigned char format;};
inline Bitmap*resolveBitmap(const Handle&h){int index=h.bits.index;HandleManager*m=lbl_801E9D24.manager;
 int tag=m->entries[index].getTag();return tag==h.bits.tag?(Bitmap*)m->entries[index].object:0;}
inline void*resolve(const Handle&h){int index=h.bits.index;HandleManager*m=lbl_801E9D24.manager;
 int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline void*operator new(unsigned long,void*p){return p;}
struct Vec2{float x,y;};
struct TexturePayloadRecord{Vec2 min,max;float height;TexturePayloadRecord();};
struct FontTable{int rowHeight;float scaleU,scaleV;TexturePayloadRecord glyphs[144];};

struct Color{float r,g,b,a;Color(float r_,float g_,float b_,float a_):r(r_),g(g_),b(b_),a(a_){}};
extern "C"{
Word*fn_80237CA0(Bitmap*);
Word fn_802380D0(Bitmap*,Word);
int fn_80238900(Bitmap*,const Color*);
}
struct Font{Word unknown00;Handle texture;FontTable*table;};
struct TextureObject{char unknown00[0x44];FontTable*table;};
struct FontGlyph {float left,unknown04,right,unknown0C,unknown10;};
struct FontData {char unknown00[12];FontGlyph glyphs[144];};
struct FontOwner {char unknown00[8];FontData*font;};
extern "C" int fn_80261B64(FontOwner*self,const char*text){FontGlyph*glyphs=self->font->glyphs;float width=0.0f;int length=strlen(text);for(int i=0;i<length;++i){signed char index=text[i]-32;if(index<0||index>=144)break;width+=glyphs[index].right-glyphs[index].left;}return (int)width;}
extern "C" void fn_80261C0C(Font*self,const Handle&bitmapHandle,const Handle&textureHandle){
 fn_801F86C8(lbl_801E9D24.manager,&self->texture,-1);
 self->texture.word=textureHandle.word;
 fn_801F86C8(lbl_801E9D24.manager,&textureHandle,1);
 self->table=((TextureObject*)resolve(self->texture))->table;
 if(self->table==0){
  self->table=new(fn_801EFA1C(lbl_801EF5C8,sizeof(FontTable),lbl_802AEF28,lbl_802AEF38,0x60,4))FontTable;
  Bitmap*bitmap=resolveBitmap(bitmapHandle);
  int width=bitmap->width;
  int height=bitmap->height;
  Word*pixels=fn_80237CA0(bitmap);
  Color magenta(1.0f,0.0f,1.0f,1.0f);
  Word key;
  switch(bitmap->format){
  case 8:{int c=fn_80238900(bitmap,&magenta);key=((c<<8)&0xF80000)+((c<<5)&0xFC00)+((c&0x1F)<<3)+0xFF000000;break;}
  case 1:case 2:key=fn_802380D0(bitmap,(unsigned char)fn_80238900(bitmap,&magenta));break;
  case 7:break;
  case 10:break;
  }
  Word row[512];
  for(int i=0;i<width;i++)row[i]=pixels[i];
  int rowHeight=0;
  int x,y;
  for(y=0;y<height;y++){
   for(x=0;x<width;x++)if(row[x]!=pixels[y*width+x])rowHeight=y;
   if(rowHeight!=0)break;
  }
  FontTable*table=self->table;
  table->rowHeight=rowHeight;
  self->table->scaleU=1.0f/(float)width;
  self->table->scaleV=1.0f/(float)height;
  TexturePayloadRecord*glyphs=self->table->glyphs;
  glyphs[0].min=*(Vec2*)game_vec2_zero;
  glyphs[0].max=glyphs[0].min;
  int index=1;
  for(y=0;y<height;){
   for(x=1;x<width;x++){
    if(key!=pixels[y*width+x]){
     if(pixels[y*width+x]!=pixels[x-1+y*width]){
      glyphs[index-1].max.x=(float)x;glyphs[index-1].max.y=(float)y+(float)rowHeight;
      glyphs[index].height=0.0f;glyphs[index].min.x=(float)x;glyphs[index++].min.y=(float)y;
     }
    }else{
     glyphs[index-1].max.x=(float)x;glyphs[index-1].max.y=(float)y+(float)rowHeight;
     glyphs[index].height=0.0f;glyphs[index].min.x=0.0f;glyphs[index++].min.y=(float)y+(float)rowHeight;break;
    }
   }
   y+=rowHeight;
   if(x==width){
    glyphs[index-1].max.x=(float)width;glyphs[index-1].max.y=(float)y;
    glyphs[index].height=0.0f;glyphs[index].min.x=0.0f;glyphs[index++].min.y=(float)y;
   }
   if(key==pixels[y*width])break;
  }
  fn_801EF610(lbl_801EF5C8,pixels);
 }
}
