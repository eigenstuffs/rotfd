/* main: platform startup, reset-monitor thread creation and the soft-reset
 * shutdown sequence. Its translation unit owns the reset thread, its 0x2000-byte
 * stack and the 32-byte DVD read buffer (.bss 0x8033E748..0x80340A90), which the
 * compiler addresses through one pooled base. */
typedef unsigned long Word;
struct Logger {char unknown00[0xB10];void*table;Word zeroB14,zeroB18,zeroB1C;};
struct LoggerPrefix {char unknown00[0xB10];};struct LoggerDispatch:LoggerPrefix {virtual void destroy(int);virtual signed char start();};
struct Context {char unknown00[0x10C];Word zero10C;Logger*logger;void*window;char unknown118[0x3C];void*render;char unknown158[0x30];void*indexBlock;Word unknown18C;char path[172];};
struct GlobalDestructorRecord {void*next;void*destructor;void*object;};
struct OSThreadStorage {double align;char rest[0x318-8];};
extern "C" {GlobalDestructorRecord lbl_8033E748;OSThreadStorage lbl_8033E758;unsigned char lbl_8033EA70[0x2000];unsigned char lbl_80340A70[0x20];}
struct File {char data[0x3C];};
extern "C" {
extern Context lbl_801E9D24;extern char lbl_801EF5C8[],lbl_802EA8D8[];
extern const char platform_type_registry_End_Frame_required_a_SoftReset[];extern __declspec(section ".sdata2") const char lbl_8037A614[],lbl_8037A61C[];
extern int*lbl_80377FB0;extern signed char lbl_80377FB4,lbl_80377FB5,lbl_80377FC8,lbl_80377FC9;extern Word lbl_80377FB8;extern char*lbl_80377FBC;
void OSInit();void fn_8007EF48();void*fn_801EFA1C(void*,Word,const char*,const char*,int,int);void fn_801FB2D4(Logger*);void exit(int);void fn_801FB17C(Logger*);void fn_80285234();char*strcpy(char*,const char*);void DVDInit();void fn_801E9FDC();int OSCreateThread(void*,void(*)(),void*,void*,Word,int,Word);Word OSGetResetCode();void*OSGetArenaHi();void OSReport(const char*,...);
int fn_801EBB54();int fn_801EBAD0();int fn_801EC490();int fn_801EC488();void fn_801FAC64(Logger*,const char*,int(*)(),const char*);int OSGetResetSwitchState();void fn_8020C0F8();void __dt__27PlatformIndexBlock_8028310CFv(void*,short);unsigned int DVDOpen(const char*,File*);void fn_8028EEEC(void*,File*,void*,int,int);void fn_801EA0FC();void VISetBlack(int);void VIFlush();void VIWaitForRetrace();void GXDrawDone();void GXAbortFrame();void fn_801EF610(void*,void*);void OSSetSaveRegion(void*,void*);int __PADDisableRecalibration(int);void LCDisable();void OSResetSystem(int,Word,int);
}
extern "C" int main(){
const char*strings=platform_type_registry_End_Frame_required_a_SoftReset;
 OSInit();lbl_801E9D24.zero10C=0;fn_8007EF48();
 Logger*logger=(Logger*)fn_801EFA1C(lbl_801EF5C8,0xB20,strings+0x20,strings+0x30,0x235,4);
 if(logger){fn_801FB2D4(logger);logger->table=lbl_802EA8D8;logger->zeroB14=0;logger->zeroB18=0;logger->zeroB1C=0;}
 lbl_801E9D24.logger=logger;if(!((LoggerDispatch*)logger)->start())exit(20);
 fn_801FB17C(lbl_801E9D24.logger);fn_80285234();strcpy(lbl_801E9D24.path,lbl_8037A614);DVDInit();
 OSCreateThread(&lbl_8033E758,fn_801E9FDC,0,lbl_8033EA70+sizeof(lbl_8033EA70),sizeof(lbl_8033EA70),8,1);
 if(OSGetResetCode()==0x80000000UL){
  lbl_80377FB0=(int*)((char*)OSGetArenaHi()-0xFA00);
  if(*lbl_80377FB0!=0&&(Word)*lbl_80377FB0!=8){OSReport(strings+0x308);lbl_80377FB5=1;lbl_80377FBC=(char*)(lbl_80377FB0+1);lbl_80377FB4=1;}
  else if((Word)*lbl_80377FB0==8){OSReport(strings+0x344);lbl_80377FB5=1;lbl_80377FBC=(char*)(lbl_80377FB0+1);lbl_80377FB4=1;}
 }else{lbl_80377FB4=0;lbl_80377FB8=0;lbl_80377FBC=0;}
 fn_801FAC64(lbl_801E9D24.logger,lbl_8037A61C,fn_801EBB54,strings+0x388);
 fn_801FAC64(lbl_801E9D24.logger,strings+0x394,fn_801EBAD0,strings+0x388);
 fn_801FAC64(lbl_801E9D24.logger,strings+0x3A0,fn_801EC490,strings+0x388);
 fn_801FAC64(lbl_801E9D24.logger,strings+0x3B0,fn_801EC488,strings+0x388);
 lbl_80377FC9=OSGetResetSwitchState();fn_8020C0F8();
 if(lbl_801E9D24.logger)((LoggerDispatch*)lbl_801E9D24.logger)->destroy(1);
 __dt__27PlatformIndexBlock_8028310CFv(lbl_801E9D24.indexBlock,1);lbl_801E9D24.indexBlock=0;
 char path[32];File file;Word request;strcpy(path,strings+0x260);if(DVDOpen(path,&file))fn_8028EEEC(&request,&file,lbl_80340A70,32,0);
 fn_801EA0FC();lbl_80377FB4=1;lbl_80377FC8=0;
 if(lbl_801E9D24.window){VISetBlack(1);VIFlush();VIWaitForRetrace();GXDrawDone();GXAbortFrame();fn_801EF610(lbl_801EF5C8,lbl_801E9D24.window);lbl_801E9D24.window=0;}
 if(lbl_801E9D24.render){fn_801EF610(lbl_801EF5C8,lbl_801E9D24.render);lbl_801E9D24.render=0;}
 void*hi=OSGetArenaHi();OSSetSaveRegion((char*)OSGetArenaHi()-0xFA00,(char*)hi-1);__PADDisableRecalibration(1);LCDisable();OSResetSystem(0,0,0);return 1;
}
