// Menu record style parser (fn_800A5080): reads one "{ ... }" record block of
// NAME/PARAM/KEYWORD/ALIGN/HIDE/GREY/ICON/START_COLOR/END_COLOR/FONT/SCALE
// tokens into a 0xD4-byte record and appends it to the owner's record array.
// Short tokens are the existing .sdata2 string labels; the long tokens live in
// the existing .rodata pool lbl_8029EBF0, reached through one base pointer.
// The record constructor reads the pool's first string through a data-member
// pointer so the native "addi rX,base,0" form survives; its by-reference pool
// parameter preserves the native argument scheduling around sprintf.
// The only private data is the compiler's signed int->float bias (lbl_80378F58).
typedef unsigned long Word;
struct Manager;
struct Globals{char unknown00[0x110];void*console;char unknown114[4];Manager*manager;char unknown11C[0x30];void*fonts;};
extern "C"{
 extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];extern const char lbl_8029EBF0[];
 void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,short);Word fn_801F948C(void*,const char*);
 void fn_801F372C(void*,char*);signed char fn_801F2F3C(void*);void fn_801F34B0(void*,long*);void fn_801F3374(void*,Word*);void fn_801F35EC(void*,float*);
 int strcmp(const char*,const char*);int sprintf(char*,const char*,...);void fn_801FA014(void*,const char*,...);
 extern const float lbl_80378EB0,lbl_80378EB4,lbl_80378F2C;
 extern const char lbl_80378EB8[4],lbl_80378EBC[2],lbl_80378EC0[5],lbl_80378EC8[6],lbl_80378ED0[8],lbl_80378ED8[6],
  lbl_80378EE0[5],lbl_80378EE8[6],lbl_80378EF0[8],lbl_80378EF8[4],lbl_80378EFC[7],lbl_80378F04[8],lbl_80378F0C[5],
  lbl_80378F14[5],lbl_80378F1C[5],lbl_80378F24[5],lbl_80378F30[5],lbl_80378F38[8],lbl_80378F40[7],lbl_80378F48[6],lbl_80378F50[2];
}

// Leading strings of the native pool at lbl_8029EBF0.
struct MenuStrings{char noDatas[0xc];char startColor[0xc];char endColor[0xc];char makingFont[0x10];};
inline const char*noDatas(const MenuStrings*s){const char(MenuStrings::*m)[12]=&MenuStrings::noDatas;return s->*m;}

struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8001FF78:Handle_801F7F10{
 Handle_8001FF78(){word=0;}~Handle_8001FF78(){}
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Handle_800723F4:Handle_8001FF78{
 Handle_800723F4(){word=0;}
 Handle_800723F4(const Handle_800723F4&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Handle_800723F4(){}
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_800723F4&operator=(const Handle_800723F4&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct ParseName{
 Word word;
 ParseName(){word=0;}
 ParseName(const char*s){word=fn_801F948C(this,s);}
 ParseName(const ParseName&n):word(n.word){}
 ParseName&operator=(const ParseName&n){word=n.word;return*this;}
 ParseName&operator=(const char*s){word=fn_801F948C(this,s);return*this;}
};
struct Name_800A59D4{Word word;Name_800A59D4();Name_800A59D4&operator=(const ParseName&n){word=n.word;return*this;}};
struct Color3{float r,g,b;Color3(){}Color3(const Color3&c):r(c.r),g(c.g),b(c.b){}void set(float x,float y,float z){r=x;g=y;b=z;}};
struct RecordText{union{char bytes[128];Word words[32];};operator char*(){return bytes;}};
struct Handle_800A595C{
 Handle_800723F4 bitmap;ParseName name;RecordText text;Name_800A59D4 actions[4];Word actionValues[4];
 unsigned char count,flags;float unknownAC,unknownB0;unsigned char line,next,font;Color3 start,end;float speed;
 Handle_800A595C(const MenuStrings*const&strings){
  const MenuStrings*pool=strings;
  name=ParseName(noDatas(pool));sprintf(text,noDatas(strings));
  flags=0;count=0;
  start.set(lbl_80378EB0,lbl_80378EB0,lbl_80378EB0);end.set(lbl_80378EB4,lbl_80378EB4,lbl_80378EB4);
  font=0;speed=lbl_80378EB0;line=255;
  for(int i=0;i<4;++i){actions[i]=ParseName(lbl_80378EB8);actionValues[i]=0;}
 }
 ~Handle_800A595C(){}
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
typedef char StyleSize[sizeof(Handle_800A595C)==0xD4?1:-1];
extern "C"{
 void fn_800A59E0(void*,void*,char*);void fn_800A5BEC(void*,void*,Name_800A59D4*,unsigned char*);
 int fn_800A5750(void*,const Handle_800A595C*);
 Handle_800723F4 fn_802631B0(void*,const ParseName&);
 unsigned char fn_80262AB4(void*,const ParseName&);unsigned char fn_8026248C(void*,const ParseName&,const ParseName&);
}

extern "C" void fn_800A5080(void*self,void*stream){
 const MenuStrings*strings=(const MenuStrings*)lbl_8029EBF0;
 Handle_800A595C item(strings);char token[128];
 fn_801F372C(stream,token);while(strcmp(token,lbl_80378EBC))fn_801F372C(stream,token);
 char mask[128];
 while(strcmp(token,lbl_80378F50)){
  if(!strcmp(token,lbl_80378EC0))fn_800A59E0(self,stream,item.text);
  if(!strcmp(token,lbl_80378EC8))fn_800A5BEC(self,stream,item.actions,&item.count);
  if(!strcmp(token,lbl_80378ED0)){
   while(fn_801F2F3C(stream)!='{'){}
   fn_801F372C(stream,token);item.name=token;
   while(fn_801F2F3C(stream)!='}'){}
  }
  if(!strcmp(token,lbl_80378ED8)){
   fn_801F372C(stream,token);
   if(!strcmp(token,lbl_80378EE0))item.flags|=4;
   else if(!strcmp(token,lbl_80378EE8))item.flags|=8;
   else if(!strcmp(token,lbl_80378EF0))item.flags|=12;
   else if(!strcmp(token,lbl_80378EF8))item.flags|=16;
   else if(!strcmp(token,lbl_80378EFC))item.flags|=32;
   else if(!strcmp(token,lbl_80378F04))item.flags|=48;
  }
  if(!strcmp(token,lbl_80378F0C)){fn_801F372C(stream,token);if(!strcmp(token,lbl_80378F14))item.flags|=1;}
  if(!strcmp(token,lbl_80378F1C)){fn_801F372C(stream,token);if(!strcmp(token,lbl_80378F14))item.flags|=2;}
  if(!strcmp(token,lbl_80378F24)){
   while(fn_801F2F3C(stream)!='{'){}
   fn_801F372C(stream,token);item.bitmap=fn_802631B0(lbl_801E9D24.fonts,ParseName(token));
   while(fn_801F2F3C(stream)!='}'){}
  }
  if(!strcmp(token,strings->startColor)){
   long r,g,b;fn_801F34B0(stream,&r);fn_801F34B0(stream,&g);fn_801F34B0(stream,&b);
   item.start.set(r/lbl_80378F2C,g/lbl_80378F2C,b/lbl_80378F2C);
  }
  if(!strcmp(token,strings->endColor)){
   long r,g,b;fn_801F34B0(stream,&r);fn_801F34B0(stream,&g);fn_801F34B0(stream,&b);
   item.end.set(r/lbl_80378F2C,g/lbl_80378F2C,b/lbl_80378F2C);
  }
  if(!strcmp(token,lbl_80378F30)){
   while(fn_801F2F3C(stream)!='{'){}
   fn_801F372C(stream,token);item.font=fn_80262AB4(lbl_801E9D24.fonts,ParseName(ParseName(token)));
   if(item.font==255){
    fn_801FA014(lbl_801E9D24.console,strings->makingFont,token);
    sprintf(mask,lbl_80378F38,token);
    item.font=fn_8026248C(lbl_801E9D24.fonts,ParseName(ParseName(token)),ParseName(ParseName(mask)));
   }
   while(fn_801F2F3C(stream)!='}'){}
  }
  if(!strcmp(token,lbl_80378F40)){Word line,next;fn_801F3374(stream,&line);item.line=line;fn_801F3374(stream,&next);item.next=next;item.flags|=64;}
  if(!strcmp(token,lbl_80378F48))fn_801F35EC(stream,&item.speed);
  fn_801F372C(stream,token);
 }
 fn_800A5750(self,&item);
}
