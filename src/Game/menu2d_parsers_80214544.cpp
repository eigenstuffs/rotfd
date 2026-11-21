// fn_80214544, fn_80214978, fn_80214F28: 2D menu config parsers (one original
// translation unit with its .sdata2 pool 0x8037AC78..0x8037AD62 and pooled
// .rodata strings 0x802AE588..0x802AE6EF). Same flags as menu3d_parsers.cpp.
// Parse input-symbol tokens into the game's single-byte glyph codes.
struct File;
extern "C" {
char fn_801F372C(File*, char*);
int strcmp(const char*, const char*);
int sprintf(char*, const char*, ...);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
}
static const char glyphFormat[] = "%c";
static const char separator[] = " ";
extern const char beginGroup[] = "{";
extern const char endGroup[] = "}";
inline void appendText(char* output, const char* token) {
    if (!*output) strcpy(output, token);
    else { strcat(output, separator); strcat(output, token); }
}
inline void appendGlyph(char* output, int glyph) {
    char token[128];
    sprintf(token, glyphFormat, glyph);
    appendText(output, token);
}
extern "C" void fn_80214544(void*, File* file, char* output) {
    char token[128];
    *output = 0;
    fn_801F372C(file, token);
    while (strcmp(token,beginGroup) == 0) fn_801F372C(file, token);
    while (strcmp(token,endGroup) != 0) {
        if (strcmp(token,"ITEM_UPDOWN") == 0) appendGlyph(output,0x80);
        else if (strcmp(token,"ITEM_LEFTRIGHT") == 0) appendGlyph(output,0x81);
        else if (strcmp(token,"ITEM_DIRPAD") == 0) appendGlyph(output,0x82);
        else if (strcmp(token,"ITEM_CROSS") == 0) appendGlyph(output,0x7B);
        else if (strcmp(token,"ITEM_CIRCLE") == 0) appendGlyph(output,0x7C);
        else if (strcmp(token,"ITEM_SQUARE") == 0) appendGlyph(output,0x7D);
        else if (strcmp(token,"ITEM_TRIANGLE") == 0) appendGlyph(output,0x7E);
        else if (strcmp(token,"ITEM_L1") == 0) appendGlyph(output,0x83);
        else if (strcmp(token,"ITEM_R1") == 0) appendGlyph(output,0x84);
        else appendText(output,token);
        fn_801F372C(file, token);
    }
}
typedef unsigned long u32;
struct Vec2 { float x,y; };
extern "C" {
extern Vec2 game_vec2_zero;
u32 fn_801F948C(void*,const char*);
char fn_801F2F3C(File*);
char fn_801F3374(File*,int*);
char fn_801F34B0(File*,long*);
}
struct Name_800A59D4 {
 u32 value;
 Name_800A59D4(){value=0;}
 Name_800A59D4(const char*s){value=fn_801F948C(this,s);}
 Name_800A59D4&operator=(const char*s){value=fn_801F948C(this,s);return *this;}
};
struct ItemHeader {
 char name[128];
 Name_800A59D4 keyword,next,previous;
 unsigned short flags;
 ItemHeader() {
  flags=0;
  strcpy(name,"ITEM_NAME");
  keyword="ITEM_KEYWORD";
  next="ITEM_NEXT";
  previous="ITEM_PREC";
 }
};
struct MenuItem:ItemHeader {
 Name_800A59D4 parameters[8];
 unsigned char center0,center1,parameterCount,lineUp;
 Vec2 position;
 MenuItem(){center0=255;parameterCount=0;lineUp=0;position=game_vec2_zero;}
};
extern "C" void fn_80216A40(void*,const MenuItem&);
extern "C" void fn_80214978(void*self,File*file) {
 MenuItem item;
 Name_800A59D4* parameters=item.parameters;
 char token[128];
 fn_801F372C(file,token);
 while(strcmp(token,beginGroup)!=0)fn_801F372C(file,token);
 while(strcmp(token,endGroup)!=0){
  if(strcmp(token,"NAME")==0)fn_80214544(self,file,item.name);
  if(strcmp(token,"PARAM")==0){
   char parameter[128];
   fn_801F372C(file,parameter);
   while(strcmp(parameter,beginGroup)==0)fn_801F372C(file,parameter);
   while(strcmp(parameter,endGroup)!=0){
    parameters[item.parameterCount++]=Name_800A59D4(parameter);
    fn_801F372C(file,parameter);
   }
  }
  if(strcmp(token,"IT_NEXT")==0){
   while(fn_801F2F3C(file)!='{'){}
   fn_801F372C(file,token);item.next=token;
   while(fn_801F2F3C(file)!='}'){}
  }
  if(strcmp(token,"IT_PREC")==0){
   while(fn_801F2F3C(file)!='{'){}
   fn_801F372C(file,token);item.previous=token;
   while(fn_801F2F3C(file)!='}'){}
  }
  if(strcmp(token,"USE_ALTERNATE_COLOR")==0){
   fn_801F372C(file,token);if(strcmp(token,"TRUE")==0)item.flags|=(unsigned short)0x40;
  }
  if(strcmp(token,"KEYWORD")==0){
   while(fn_801F2F3C(file)!='{'){}
   fn_801F372C(file,token);item.keyword=token;
   while(fn_801F2F3C(file)!='}'){}
  }
  if(strcmp(token,"ALIGN")==0){
   fn_801F372C(file,token);
   if(strcmp(token,"LEFT")==0)item.flags|=(unsigned short)8;
   else if(strcmp(token,"RIGHT")==0)item.flags|=(unsigned short)0x10;
   else if(strcmp(token,"CENTER")==0)item.flags|=(unsigned short)0x18;
   sprintf(token,"ALIGN");
  }
  if(strcmp(token,"LINE_UP")==0){int value;fn_801F3374(file,&value);item.lineUp=value;}
  if(strcmp(token,"ACCESS")==0){fn_801F372C(file,token);if(strcmp(token,"TRUE")==0)item.flags|=(unsigned short)1;}
  if(strcmp(token,"HIDE")==0){fn_801F372C(file,token);if(strcmp(token,"TRUE")==0)item.flags|=(unsigned short)2;}
  if(strcmp(token,"GREY")==0){fn_801F372C(file,token);if(strcmp(token,"TRUE")==0)item.flags|=(unsigned short)4;}
  if(strcmp(token,"CENTER")==0){
   int x,y;fn_801F3374(file,&x);item.center0=x;fn_801F3374(file,&y);item.center1=y;item.flags|=(unsigned short)0x38;
  }
  if(strcmp(token,"POSITION")==0){
   long x,y;fn_801F34B0(file,&x);fn_801F34B0(file,&y);item.position.x=x;item.position.y=y;item.flags|=(unsigned short)0x80;
  }
  if(strcmp(token,"FOREVERACCESS")==0){fn_801F372C(file,token);if(strcmp(token,"TRUE")==0)item.flags|=(unsigned short)0x100;}
  fn_801F372C(file,token);
 }
 fn_80216A40(self,item);
}

typedef unsigned long u32;
struct Handle_801F7F10 {
 u32 value;
 Handle_801F7F10(); ~Handle_801F7F10();
};
struct File;

struct MenuConfigToken {union {u32 value;struct {signed int generation:8; signed int index:24;}bits;};};
struct MenuConfigFileObject {char unknown[12]; File& file(){return *(File*)((char*)this+12);} };
struct MenuConfigEntry {void*object;char unknown[8];signed char generation;char tail[3];};
struct MenuConfigManager;
struct MenuConfigHash {u32 value;MenuConfigHash(const char*);};
struct MenuConfigWorldList {int count,capacity;Handle_801F7F10*data;};
struct MenuConfigGlobals {char unknown[0x110];void*console;void*render;MenuConfigManager*manager;MenuConfigWorldList*worlds;char unknown120[0x2c];void*fonts;};
extern "C" MenuConfigGlobals lbl_801E9D24;
extern "C" void fn_801F86C8(MenuConfigManager*,const void*,short);
extern "C" void*fn_801F7EB8(const void*);
struct MenuConfigManagerStorage {int count,capacity;MenuConfigEntry*entries;char unknownC[0x18];};
struct MenuConfigManager : MenuConfigManagerStorage {
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual Handle_801F7F10 load(const MenuConfigHash&);
 void*get(const Handle_801F7F10&h){const MenuConfigToken&t=*(const MenuConfigToken*)&h;MenuConfigEntry*e=&entries[t.bits.index];if(e->generation==t.bits.generation)return e->object;return 0;}
};
struct MenuConfigFileZero : Handle_801F7F10 {MenuConfigFileZero(){value=0;}~MenuConfigFileZero(){}};
struct MenuConfigFileHandle : MenuConfigFileZero {
 MenuConfigFileHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~MenuConfigFileHandle(){}
 MenuConfigFileObject*get(){return (MenuConfigFileObject*)lbl_801E9D24.manager->get(*this);}
};
struct MenuConfigStoredHandle {u32 value;
 MenuConfigStoredHandle&operator=(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}
 void*get(){return lbl_801E9D24.manager->get(*(const Handle_801F7F10*)this);}
};
struct MenuConfigColor3 {float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}};
struct MenuConfigColor4 {float x,y,z,w;void set(float a,float b,float c,float d){x=a;y=b;z=c;w=d;}};
struct MenuConfigMenu;
struct MenuConfigMenuStorage {u32 word0,word4;};
struct MenuConfigMenu : MenuConfigMenuStorage {
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
 virtual void finish(int);
char unknownC[0x14];MenuConfigStoredHandle world;char unknown24[12];int type;char unknown34[16];unsigned short count;char unknown46[2];unsigned char loop;char unknown49[3];MenuConfigStoredHandle object;unsigned char startLine;char unknown51[0x23];MenuConfigStoredHandle bitmap;float pulse;unsigned char font;char unknown7D[3];MenuConfigColor3 alternate,start,end,startSelect,endSelect;MenuConfigColor4 grey;};
struct MenuConfigResultHandle : Handle_801F7F10 {~MenuConfigResultHandle(){}};
extern "C" {

 int strcmp(const char*,const char*);char*strcpy(char*,const char*);char*strcat(char*,const char*);
 char fn_801F372C(File*,char*);char fn_801F2E04(File*);char fn_801F2F3C(File*);char fn_801F2F54(File*,char*);char fn_801F3238(File*,unsigned short*);char fn_801F34B0(File*,long*);
 u32 fn_801F948C(void*,const char*);
 void fn_80214978(void*,File*);
 unsigned char fn_80262AB4(void*,MenuConfigHash);unsigned char fn_8026248C(void*,MenuConfigHash,MenuConfigHash);
 void fn_801FA014(void*,const char*,...);
 int fn_8026BC50(MenuConfigWorldList*,const MenuConfigHash&);
 MenuConfigResultHandle fn_8026A494(void*,const MenuConfigHash&);
 MenuConfigResultHandle fn_802631B0(void*,const MenuConfigHash&);
}
inline MenuConfigHash::MenuConfigHash(const char*s){value=fn_801F948C(this,s);}
static const char normalStyle[]="NORMAL";
static const char scrollFixed[]="SCROLL_FIXE";
static const char scrollAnimated[]="SCROLL_ANIM";
extern "C" int fn_80214F28(MenuConfigMenu*self,const MenuConfigHash&name){
 MenuConfigFileHandle handle(lbl_801E9D24.manager->load(name));
 if(!fn_801F7EB8(&handle))return 0;
 File*file=&handle.get()->file();
 unsigned short count=0;
 char token[128];
 fn_801F372C(file,token);
 char bitmap[128];bitmap[0]=0;
 char object[128];strcpy(object,"-------");
 char world[128];strcpy(world,"-------");
 char mask[128];
 while(!fn_801F2E04(file)){
  if(!strcmp(token,"MENU_TYPE")){
   char type[128];fn_801F372C(file,type);
   if(!strcmp(type,scrollFixed))self->type=1;
   else if(!strcmp(type,scrollAnimated))self->type=2;
   else if(!strcmp(type,normalStyle))self->type=0;
  }
  if(!strcmp(token,"NB_ELEM")){fn_801F3238(file,&count);self->count=count;}
  if(!strcmp(token,"OBJECT"))fn_801F2F54(file,object);
  if(!strcmp(token,"BITMAP"))fn_801F2F54(file,bitmap);
  if(!strcmp(token,"WORLD"))fn_801F2F54(file,world);
  if(!strcmp(token,"START_LINE")){long line;fn_801F34B0(file,&line);self->startLine=line;}
  strcmp(token,"EFFECT");
  if(!strcmp(token,"ITEM"))fn_80214978(self,file);
  if(!strcmp(token,"START_COLOR")){long r,g,b;fn_801F34B0(file,&r);fn_801F34B0(file,&g);fn_801F34B0(file,&b);self->start.set(r/255.0f,g/255.0f,b/255.0f);}
  if(!strcmp(token,"END_COLOR")){long r,g,b;fn_801F34B0(file,&r);fn_801F34B0(file,&g);fn_801F34B0(file,&b);self->end.set(r/255.0f,g/255.0f,b/255.0f);}
  if(!strcmp(token,"ALTERNATE_COLOR")){long r,g,b;fn_801F34B0(file,&r);fn_801F34B0(file,&g);fn_801F34B0(file,&b);self->alternate.set(r/255.0f,g/255.0f,b/255.0f);}
  if(!strcmp(token,"START_COLOR_SELECT")){long r,g,b;fn_801F34B0(file,&r);fn_801F34B0(file,&g);fn_801F34B0(file,&b);self->startSelect.set(r/255.0f,g/255.0f,b/255.0f);}
  if(!strcmp(token,"END_COLOR_SELECT")){long r,g,b;fn_801F34B0(file,&r);fn_801F34B0(file,&g);fn_801F34B0(file,&b);self->endSelect.set(r/255.0f,g/255.0f,b/255.0f);}
  if(!strcmp(token,"FONT")){
   while(fn_801F2F3C(file)!='{'){}
   fn_801F372C(file,token);
   self->font=fn_80262AB4(lbl_801E9D24.fonts,MenuConfigHash(token));
   if(self->font==255){
    fn_801FA014(lbl_801E9D24.console,"Making font %s",token);
    strcpy(mask,token);strcat(mask,"_MASK");
    self->font=fn_8026248C(lbl_801E9D24.fonts,MenuConfigHash(token),MenuConfigHash(mask));
   }
   while(fn_801F2F3C(file)!='}'){}
  }
  if(!strcmp(token,"MENU_LOOP")){fn_801F372C(file,token);if(!strcmp(token,"TRUE"))self->loop=1;}
  if(!strcmp(token,"GREY_COLOR")){long r,g,b,a;fn_801F34B0(file,&r);fn_801F34B0(file,&g);fn_801F34B0(file,&b);fn_801F34B0(file,&a);self->grey.set(r/255.0f,g/255.0f,b/255.0f,a/255.0f);}
  fn_801F372C(file,token);
 }
 MenuConfigHash worldName(world);
 int index=fn_8026BC50(lbl_801E9D24.worlds,worldName);
 if(index>=0){self->world=lbl_801E9D24.worlds->data[index];self->object=fn_8026A494(self->world.get(),MenuConfigHash(object));}
 if(bitmap[0])self->bitmap=fn_802631B0(lbl_801E9D24.fonts,MenuConfigHash(bitmap));
 self->finish(0);
 return 1;
}


