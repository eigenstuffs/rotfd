extern "C" {
void fn_801F372C(void*,char*);
int strcmp(const char*,const char*);
char*strcpy(char*,const char*);
void fn_800B1670(void*,char*,unsigned char);
void fn_800B1610(void*,char*,const char*);
extern const char lbl_80379194[2],lbl_803791B8[8],lbl_803791C0[8],lbl_803791CC[2];
}
struct Strings{char itemUpDown[0xC];char itemLeftRight[0x10];char itemDirpad[0xC];char itemCross[0xC];
 char itemCircle[0xC];char itemSquare[0xC];char itemTriangle[0x10];char unknown5C[0xE4];char vibrations[0xC];char vibration[0xC];};
extern "C" const Strings lbl_802A0250;
inline const char*itemUpDown(const Strings*s){const char(Strings::*m)[0xC]=&Strings::itemUpDown;return s->*m;}
extern "C"void fn_800B1338(void*self,void*input,char*output){char token[128];const Strings*const s=&lbl_802A0250;*output=0;fn_801F372C(input,token);while(!strcmp(token,lbl_80379194))fn_801F372C(input,token);if(!strcmp(s->vibrations,token))strcpy(token,s->vibration);while(strcmp(token,lbl_803791CC)){if(!strcmp(token,itemUpDown(s)))fn_800B1670(self,output,0x80);else if(!strcmp(token,s->itemLeftRight))fn_800B1670(self,output,0x81);else if(!strcmp(token,s->itemDirpad))fn_800B1670(self,output,0x82);else if(!strcmp(token,s->itemCross))fn_800B1670(self,output,0x7B);else if(!strcmp(token,s->itemCircle))fn_800B1670(self,output,0x7C);else if(!strcmp(token,s->itemSquare))fn_800B1670(self,output,0x7D);else if(!strcmp(token,s->itemTriangle))fn_800B1670(self,output,0x7E);else if(!strcmp(token,lbl_803791B8))fn_800B1670(self,output,0x83);else if(!strcmp(token,lbl_803791C0))fn_800B1670(self,output,0x84);else fn_800B1610(self,output,token);fn_801F372C(input,token);}}
