typedef unsigned long u32;
struct Console {char unknown[0x860];int argc;char*argv[16];signed char numeric[16];float values[16];};
struct GameStorage {char unknown[0x278];};
struct Game:GameStorage {
 virtual void unknown0();virtual void unknown1();virtual void unknown2();virtual void unknown3();virtual void unknown4();virtual void unknown5();virtual void unknown6();
 virtual void screenshot(const char*);virtual void unknown8();virtual void ramp(float,float,float);virtual void brightness(float);virtual void contrast(float);virtual void gamma(float);
};
struct GameGlobals {char unknown[0x108];signed char job;char unknown109[7];Console*console;Game*game;};
struct File {u32 fields[23];};
extern "C" {
extern GameGlobals lbl_801E9D24;
extern float lbl_80377FA8;
extern const float lbl_8037A8A0[1];
extern const char lbl_802AD658[],lbl_802AD66C[];
void fn_801FA014(void*,const char*,...);
int sprintf(char*,const char*,...);
int strcmp(const char*,const char*);
char*fn_801F459C(char*);
void __ct__13File_801F3E1CFv(File*);
void __dt__13File_801F3E1CFv(File*,short);
signed char fn_801F3918(File*,const char*,int);
void fn_801F2A98(File*);
void fn_801FAC64(Console*,const char*,int(*)(),const char*);
extern const char lbl_802AD628[]="NbHandle: %d";
extern const char lbl_802AD638[]="Invalid Parameter";
extern const char lbl_802AD64C[]="DB:>%s.TGA";
extern const char lbl_802AD658[]="Too much parameters";
extern const char lbl_802AD66C[]="Invalid parameters";
extern const char lbl_802AD680[]="Too much or invalid parameters";
extern const char lbl_802AD6A0[]="PROGRAMER";
extern const char lbl_802AD6AC[]="GRAPHIST";
extern const char lbl_802AD6B8[]="SCRIPTER";
extern const char lbl_802AD6C4[]="MUSICIAN";
extern const char lbl_802AD6D0[]="Unknown Job (Programer/Graphist/Scripter/Musician)";
extern const char lbl_802AD704[]="%sZOUNA_%03d.TGA";
extern const char lbl_802AD718[]="SetFullScreen";
extern const char lbl_802AD728[]="No Comment";
extern const char lbl_802AD734[]="DisplayWire";
extern const char lbl_802AD740[]="PosPersoDebug";
extern const char lbl_802AD750[]="MakeRenderDebug";
extern const char lbl_802AD760[]="ScreenShot";
extern const char lbl_802AD76C[]="SetGammaRamp";
extern const char lbl_802AD77C[]="No param restore default";
extern const char lbl_802AD798[]="SetBrightness";
extern const char lbl_802AD7A8[]="SetContrast";
extern const char lbl_802AD7B4[]="SetGAmma";
extern const char lbl_802AD7C0[]="SwapStartButton";
extern const char lbl_802AD7D0[]="CleanTempPic";
extern const char lbl_802AD7E0[]="EnableProfiler";
extern const char lbl_802AD7F0[]="[JobName]";
extern const char lbl_802AD7FC[]="SwitchScreenMode";
extern const char lbl_802AD810[]="DisplayFps";
extern const char lbl_802AD81C[]="DisplayFrameBar";
extern const char lbl_802AD82C[]="DisableConsole";
extern const char lbl_802AD83C[]="NbHandle";
extern const float lbl_8037A8A0[1]={0.0f};
extern const float lbl_8037A8A4[1]={1.0f};
extern const float lbl_8037A8A8[1]={1.33333337306976318359375f};
extern const float lbl_8037A8AC[1]={1.77777779102325439453125f};
extern const char lbl_8037A8B0[]="PLAYER";
extern const char lbl_8037A8B8[]="/";
extern const char lbl_8037A8BC[]="SetJob";
int fn_801FB594();
int fn_801FB50C();
int fn_801FB714();
int fn_801FB5DC();
int fn_801FBCE4();
int fn_801FBA44();
int fn_801FB99C();
int fn_801FB8F4();
int fn_801FB84C();
int fn_801FB79C();
int fn_801FB504();
int fn_801FB68C();
int fn_801FBB94();
int fn_801FBB14();
int fn_801FB4E8();
int fn_801FB4CC();
int fn_801FB4B0();
int fn_801FB338();
void fn_801FBDE4(){
fn_801FAC64(lbl_801E9D24.console,lbl_802AD718,fn_801FB594,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD734,fn_801FB50C,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD740,fn_801FB714,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD750,fn_801FB5DC,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD760,fn_801FBCE4,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD76C,fn_801FBA44,lbl_802AD77C);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD798,fn_801FB99C,lbl_802AD77C);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD7A8,fn_801FB8F4,lbl_802AD77C);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD7B4,fn_801FB84C,lbl_802AD77C);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD7C0,fn_801FB79C,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD7D0,fn_801FB504,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD7E0,fn_801FB68C,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_8037A8BC,fn_801FBB94,lbl_802AD7F0);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD7FC,fn_801FBB14,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD810,fn_801FB4E8,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD81C,fn_801FB4CC,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD82C,fn_801FB4B0,lbl_802AD728);
fn_801FAC64(lbl_801E9D24.console,lbl_802AD83C,fn_801FB338,lbl_802AD728);
}
int fn_801FBCE4(){
 if(lbl_801E9D24.console->argc==2){lbl_801E9D24.game->screenshot(lbl_801E9D24.console->argv[1]);}
 else{
  char filename[128];File file;__ct__13File_801F3E1CFv(&file);int index=1;
  sprintf(filename,lbl_802AD704,lbl_8037A8B8,index);
  while(fn_801F3918(&file,filename,1)){fn_801F2A98(&file);++index;sprintf(filename,lbl_802AD704,lbl_8037A8B8,index);}
  lbl_801E9D24.game->screenshot(filename);__dt__13File_801F3E1CFv(&file,-1);
 }
 return 1;
}
int fn_801FBB94(){
 if(lbl_801E9D24.console->argc!=2){fn_801FA014(lbl_801E9D24.console,lbl_802AD66C);return 0;}
 char*job=lbl_801E9D24.console->argv[1];fn_801F459C(job);
 if(!strcmp(job,lbl_802AD6A0))lbl_801E9D24.job=0;
 else if(!strcmp(job,lbl_802AD6AC))lbl_801E9D24.job=1;
 else if(!strcmp(job,lbl_802AD6B8))lbl_801E9D24.job=2;
 else if(!strcmp(job,lbl_802AD6C4))lbl_801E9D24.job=3;
 else if(!strcmp(job,lbl_8037A8B0))lbl_801E9D24.job=4;
 else fn_801FA014(lbl_801E9D24.console,lbl_802AD6D0);
 return 1;
}
int fn_801FBB14(){
 if(lbl_801E9D24.console->argc!=2){fn_801FA014(lbl_801E9D24.console,lbl_802AD658);return 0;}
 if(lbl_801E9D24.console->numeric[1]){if(lbl_8037A8A0[0]==lbl_801E9D24.console->values[1])lbl_80377FA8=lbl_8037A8A8[0];else lbl_80377FA8=lbl_8037A8AC[0];}
 return 1;
}
int fn_801FBA44(){
 int argc=lbl_801E9D24.console->argc;
 if(argc==4&&lbl_801E9D24.console->numeric[1]&&lbl_801E9D24.console->numeric[2]&&lbl_801E9D24.console->numeric[3]){lbl_801E9D24.game->ramp(lbl_801E9D24.console->values[1],lbl_801E9D24.console->values[2],lbl_801E9D24.console->values[3]);return 1;}
 if(argc==1){lbl_801E9D24.game->ramp(lbl_8037A8A0[0],lbl_8037A8A4[0],lbl_8037A8A4[0]);return 1;}
 fn_801FA014(lbl_801E9D24.console,lbl_802AD680);return 0;
}
int fn_801FB99C(){
 if(lbl_801E9D24.console->argc==2&&lbl_801E9D24.console->numeric[1]){lbl_801E9D24.game->brightness(lbl_801E9D24.console->values[1]);return 1;}
 if(lbl_801E9D24.console->argc==1){lbl_801E9D24.game->brightness(lbl_8037A8A0[0]);return 1;}
 fn_801FA014(lbl_801E9D24.console,lbl_802AD680);return 0;
}
int fn_801FB8F4(){
 if(lbl_801E9D24.console->argc==2&&lbl_801E9D24.console->numeric[1]){lbl_801E9D24.game->contrast(lbl_801E9D24.console->values[1]);return 1;}
 if(lbl_801E9D24.console->argc==1){lbl_801E9D24.game->contrast(lbl_8037A8A4[0]);return 1;}
 fn_801FA014(lbl_801E9D24.console,lbl_802AD680);return 0;
}
int fn_801FB84C(){
 if(lbl_801E9D24.console->argc==2&&lbl_801E9D24.console->numeric[1]){lbl_801E9D24.game->gamma(lbl_801E9D24.console->values[1]);return 1;}
 if(lbl_801E9D24.console->argc==1){lbl_801E9D24.game->gamma(lbl_8037A8A4[0]);return 1;}
 fn_801FA014(lbl_801E9D24.console,lbl_802AD680);return 0;
}
}
