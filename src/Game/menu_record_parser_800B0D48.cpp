/* Ordinary menu record parser; see docs/notes/game-menu-record-parser.md. */
typedef unsigned long Word;
struct Manager;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct File;
extern "C"{
extern const char lbl_802A0250[];extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);
Word fn_801F948C(void*,const char*);
char*strcpy(char*,const char*);int strcmp(const char*,const char*);int sprintf(char*,const char*,...);
void fn_801F372C(File*,char*);char fn_801F2F3C(File*);void fn_801F3374(File*,int*);void fn_801F35EC(File*,float*);
extern const float lbl_80379240;
extern const char lbl_80379194[2];
extern const char lbl_803791A4[5];
extern const char lbl_803791CC[2];
extern const char lbl_803791D8[5];
extern const char lbl_80379244[5];
extern const char lbl_8037924C[6];
extern const char lbl_80379254[6];
extern const char lbl_8037925C[8];
extern const char lbl_80379264[8];
extern const char lbl_8037926C[8];
extern const char lbl_80379274[6];
extern const char lbl_8037927C[5];
extern const char lbl_80379284[6];
extern const char lbl_8037928C[7];
extern const char lbl_80379294[8];
extern const char lbl_8037929C[7];
extern const char lbl_803792A4[5];
extern const char lbl_803792AC[5];
}
struct Point2{float x,y;};extern "C"Point2 game_vec2_zero;
struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[0x30];void*fonts;};extern "C"Globals lbl_801E9D24;
struct ParserZero_B0D48:Handle_801F7F10{ParserZero_B0D48(){word=0;}~ParserZero_B0D48(){}};
struct Handle_800723F4:ParserZero_B0D48{Handle_800723F4(){word=0;}~Handle_800723F4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_800723F4&operator=(const Handle_800723F4&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}};
struct NameValue{Word value;NameValue(){value=0;}NameValue(const char*s){value=fn_801F948C(this,s);}NameValue&operator=(const char*s){value=fn_801F948C(this,s);return *this;}};
struct Name_800A59D4{Word value;Name_800A59D4();};
inline const char*poolText(Word offset){return (const char*)((Word)lbl_802A0250+offset);}
struct TextView{const char*text;TextView(const char*p):text(p){}operator const char*()const{return text;}};
struct Header{char name[128];NameValue keyword,next,previous;unsigned short flags;Header(const TextView&text){flags=0;strcpy(name,text);keyword=poolText(0x10C);next=poolText(0x11C);previous=poolText(0x128);}};
struct HandleOwner_800B12B4:Header{Name_800A59D4 parameters[8];unsigned char center0,center1,parameterCount,lineUp;Point2 position;float speed;Handle_800723F4 bitmap;
HandleOwner_800B12B4():Header(TextView(poolText(0x100))){lineUp=0;position=game_vec2_zero;speed=lbl_80379240;parameterCount=0;center0=255;strcpy(name,poolText(0x134));}~HandleOwner_800B12B4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{void fn_800B1338(void*,File*,char*);void fn_800B1564(void*,File*,Name_800A59D4*,unsigned char*);void fn_800B2F48(void*,HandleOwner_800B12B4*);Handle_800723F4 fn_802631B0(void*,const NameValue&);}
extern "C"void fn_800B0D48(void*self,File*file){
HandleOwner_800B12B4 item;char token[128];
fn_801F372C(file,token);while(strcmp(token,lbl_80379194))fn_801F372C(file,token);
while(strcmp(token,lbl_803791CC)){
if(!strcmp(token,lbl_80379244))fn_800B1338(self,file,item.name);
if(!strcmp(token,lbl_8037924C))fn_800B1564(self,file,item.parameters,&item.parameterCount);
if(!strcmp(token,lbl_80379254))fn_801F35EC(file,&item.speed);
if(!strcmp(token,lbl_8037925C)){while(fn_801F2F3C(file)!='{'){}fn_801F372C(file,token);item.next=token;while(fn_801F2F3C(file)!='}'){} }
if(!strcmp(token,lbl_80379264)){while(fn_801F2F3C(file)!='{'){}fn_801F372C(file,token);item.previous=token;while(fn_801F2F3C(file)!='}'){} }
if(!strcmp(token,lbl_8037926C)){while(fn_801F2F3C(file)!='{'){}fn_801F372C(file,token);item.keyword=token;while(fn_801F2F3C(file)!='}'){} }
if(!strcmp(token,lbl_80379274)){fn_801F372C(file,token);if(!strcmp(token,lbl_8037927C))item.flags|=8;else if(!strcmp(token,lbl_80379284))item.flags|=0x10;else if(!strcmp(token,lbl_8037928C))item.flags|=0x18;sprintf(token,lbl_80379274);}
if(!strcmp(token,lbl_80379294)){int value;fn_801F3374(file,&value);item.lineUp=value;}
if(!strcmp(token,lbl_8037929C)){fn_801F372C(file,token);if(!strcmp(token,lbl_803791D8))item.flags|=1;}
if(!strcmp(token,lbl_803792A4)){fn_801F372C(file,token);if(!strcmp(token,lbl_803791D8))item.flags|=2;}
if(!strcmp(token,lbl_803792AC)){fn_801F372C(file,token);if(!strcmp(token,lbl_803791D8))item.flags|=4;}
if(!strcmp(token,lbl_8037928C)){int x,y;fn_801F3374(file,&x);item.center0=x;fn_801F3374(file,&y);item.center1=y;item.flags|=0x38;}
if(!strcmp(token,lbl_803791A4)){while(fn_801F2F3C(file)!='{'){}fn_801F372C(file,token);item.bitmap=fn_802631B0(lbl_801E9D24.fonts,NameValue(token));while(fn_801F2F3C(file)!='}'){} }
fn_801F372C(file,token);
}
fn_800B2F48(self,&item);
}
