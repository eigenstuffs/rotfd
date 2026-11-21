#include "Game/engine_input_glyphs.h"

extern "C" {
extern const char lbl_8037AB10[3],lbl_8037AB14[2],lbl_8037AB18[2],lbl_8037AB1C[2],lbl_8037AB20[8],lbl_8037AB28[8];
void fn_801F372C(void*,char*);
int strcmp(const char*,const char*);
char*strcpy(char*,const char*);
char*strcat(char*,const char*);
int fn_801BA714(char*,const char*,...);
}
static inline void appendGlyphText(char*output,const char*text){
 if(!*output)strcpy(output,text);
 else{strcat(output,lbl_8037AB14);strcat(output,text);}
}
static inline void appendGlyph(char*output,int code){
 char text[128];fn_801BA714(text,lbl_8037AB10,code);appendGlyphText(output,text);
}
extern "C" void fn_8020F488(void*,void*stream,char*output){
 char token[128];*output=0;
 fn_801F372C(stream,token);
 while(!strcmp(token,lbl_8037AB18))fn_801F372C(stream,token);
 while(strcmp(token,lbl_8037AB1C)){
  if(!strcmp(token,"ITEM_UPDOWN"))appendGlyph(output,128);
  else if(!strcmp(token,"ITEM_LEFTRIGHT"))appendGlyph(output,129);
  else if(!strcmp(token,"ITEM_DIRPAD"))appendGlyph(output,130);
  else if(!strcmp(token,"ITEM_CROSS"))appendGlyph(output,123);
  else if(!strcmp(token,"ITEM_CIRCLE"))appendGlyph(output,124);
  else if(!strcmp(token,"ITEM_SQUARE"))appendGlyph(output,125);
  else if(!strcmp(token,"ITEM_TRIANGLE"))appendGlyph(output,126);
  else if(!strcmp(token,lbl_8037AB20))appendGlyph(output,131);
  else if(!strcmp(token,lbl_8037AB28))appendGlyph(output,132);
  else appendGlyphText(output,token);
  fn_801F372C(stream,token);
 }
}

typedef unsigned long GlyphWord;
struct Handle_801F7F10{GlyphWord value;Handle_801F7F10();~Handle_801F7F10();};
struct GlyphParseManager;
struct GlyphParseGlobals{char unknown00[0x110];void*console;char unknown114[4];GlyphParseManager*manager;char unknown11C[0x30];void*fonts;};
extern "C" {
extern GlyphParseGlobals lbl_801E9D24;
void fn_801F86C8(GlyphParseManager*,const void*,short);
GlyphWord fn_801F948C(void*,const char*);
char fn_801F2F3C(void*);
void fn_801F34B0(void*,long*);
void fn_801F3374(void*,GlyphWord*);
void fn_801F35EC(void*,float*);
int sprintf(char*,const char*,...);
void fn_801FA014(void*,const char*,...);
}
struct Name_800A59D4 {GlyphWord value;Name_800A59D4(){value=0;}Name_800A59D4(const char*text){value=fn_801F948C(this,text);}Name_800A59D4&operator=(const char*text){value=fn_801F948C(this,text);return *this;}};
struct GlyphParseZero:Handle_801F7F10{GlyphParseZero(){value=0;}};
struct GlyphParseBitmap:GlyphParseZero{GlyphParseBitmap(){value=0;}
 GlyphParseBitmap&operator=(const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);return *this;}
};
struct GlyphParseReturned:Handle_801F7F10{~GlyphParseReturned(){}};
struct GlyphParseColor{float r,g,b;void set(float x,float y,float z){r=x;g=y;b=z;}};
extern "C" {
 GlyphParseReturned fn_802631B0(void*,const Name_800A59D4&);
 unsigned char fn_80262AB4(void*,Name_800A59D4);
 unsigned char fn_8026248C(void*,Name_800A59D4,Name_800A59D4);
 extern const float lbl_8037AB30,lbl_8037AB34,lbl_8037ABA8;
 extern const char lbl_8037AB38[4];
 extern const char lbl_8037AB3C[5];
 extern const char lbl_8037AB44[6];
 extern const char lbl_8037AB4C[8];
 extern const char lbl_8037AB54[6];
 extern const char lbl_8037AB5C[5];
 extern const char lbl_8037AB64[6];
 extern const char lbl_8037AB6C[8];
 extern const char lbl_8037AB74[4];
 extern const char lbl_8037AB78[7];
 extern const char lbl_8037AB80[8];
 extern const char lbl_8037AB88[5];
 extern const char lbl_8037AB90[5];
 extern const char lbl_8037AB98[5];
 extern const char lbl_8037ABA0[5];
 extern const char lbl_8037ABAC[5];
 extern const char lbl_8037ABB4[6];
 extern const char lbl_8037ABBC[7];
 extern const char lbl_8037ABC4[6];
}
struct GlyphParseRecord{
 GlyphParseBitmap bitmap;Name_800A59D4 name;char text[128];Name_800A59D4 actions[4];GlyphWord actionValues[4];unsigned char count,flags;char unknownAA[10];unsigned char line,unknownB5,font;char unknownB7;GlyphParseColor start,end;float speed;
 GlyphParseRecord(){name=Name_800A59D4("NO_DATAS");sprintf(text,"NO_DATAS");flags=0;count=0;start.set(lbl_8037AB30,lbl_8037AB30,lbl_8037AB30);end.set(lbl_8037AB34,lbl_8037AB34,lbl_8037AB34);font=0;speed=lbl_8037AB30;line=255;for(int i=0;i<4;++i){actions[i]=Name_800A59D4(lbl_8037AB38);actionValues[i]=0;}}
};
extern "C" void fn_8020FFF0(void*,GlyphParseRecord*);
static inline void readGlyphActions(void*stream,Name_800A59D4*actions,unsigned char&count){
 char action[128];fn_801F372C(stream,action);
 while(!strcmp(action,lbl_8037AB18))fn_801F372C(stream,action);
 while(strcmp(action,lbl_8037AB1C)){actions[count++]=Name_800A59D4(action);fn_801F372C(stream,action);}
}
extern "C" void fn_8020F8BC(void*self,void*stream){
 GlyphParseRecord item;
 char token[128];
 fn_801F372C(stream,token);
 while(strcmp(token,lbl_8037AB18))fn_801F372C(stream,token);
 char mask[128];
 while(strcmp(token,lbl_8037AB1C)){
  if(!strcmp(token,lbl_8037AB3C))fn_8020F488(self,stream,item.text);
  if(!strcmp(token,lbl_8037AB44)){
   readGlyphActions(stream,item.actions,item.count);
  }
  if(!strcmp(token,lbl_8037AB4C)){
   while(fn_801F2F3C(stream)!='{'){}
   fn_801F372C(stream,token);item.name=token;
   while(fn_801F2F3C(stream)!='}'){}
  }
  if(!strcmp(token,lbl_8037AB54)){
   fn_801F372C(stream,token);
   if(!strcmp(token,lbl_8037AB5C))item.flags|=4;
   else if(!strcmp(token,lbl_8037AB64))item.flags|=8;
   else if(!strcmp(token,lbl_8037AB6C))item.flags|=12;
   else if(!strcmp(token,lbl_8037AB74))item.flags|=16;
   else if(!strcmp(token,lbl_8037AB78))item.flags|=32;
   else if(!strcmp(token,lbl_8037AB80))item.flags|=48;
  }
  if(!strcmp(token,lbl_8037AB88)){fn_801F372C(stream,token);if(!strcmp(token,lbl_8037AB90))item.flags|=1;}
  if(!strcmp(token,lbl_8037AB98)){fn_801F372C(stream,token);if(!strcmp(token,lbl_8037AB90))item.flags|=2;}
  if(!strcmp(token,lbl_8037ABA0)){
   while(fn_801F2F3C(stream)!='{'){}
   fn_801F372C(stream,token);item.bitmap=fn_802631B0(lbl_801E9D24.fonts,Name_800A59D4(token));
   while(fn_801F2F3C(stream)!='}'){}
  }
  if(!strcmp(token,"START_COLOR")){long r,g,b;fn_801F34B0(stream,&r);fn_801F34B0(stream,&g);fn_801F34B0(stream,&b);item.start.set(r/lbl_8037ABA8,g/lbl_8037ABA8,b/lbl_8037ABA8);}
  if(!strcmp(token,"END_COLOR")){long r,g,b;fn_801F34B0(stream,&r);fn_801F34B0(stream,&g);fn_801F34B0(stream,&b);item.end.set(r/lbl_8037ABA8,g/lbl_8037ABA8,b/lbl_8037ABA8);}
  if(!strcmp(token,lbl_8037ABAC)){
   while(fn_801F2F3C(stream)!='{'){}
   fn_801F372C(stream,token);item.font=fn_80262AB4(lbl_801E9D24.fonts,Name_800A59D4(token));
   if(item.font==255){fn_801FA014(lbl_801E9D24.console,"Making font %s",token);strcpy(mask,token);strcat(mask,lbl_8037ABB4);item.font=fn_8026248C(lbl_801E9D24.fonts,Name_800A59D4(token),Name_800A59D4(mask));}
   while(fn_801F2F3C(stream)!='}'){}
  }
  if(!strcmp(token,lbl_8037ABBC)){GlyphWord line,next;fn_801F3374(stream,&line);item.line=line;fn_801F3374(stream,&next);item.unknownB5=next;item.flags|=64;}
  if(!strcmp(token,lbl_8037ABC4))fn_801F35EC(stream,&item.speed);
  fn_801F372C(stream,token);
 }
 fn_8020FFF0(self,&item);
}
