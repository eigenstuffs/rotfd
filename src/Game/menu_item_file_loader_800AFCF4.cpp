/* Menu item file loader (fn_800AFCF4): resets the 300 0x50-byte item records at
 * lbl_802F4208, loads the named resource and parses ITEM { ID WORLD ICON TEXT
 * VISIBLE COMPLETE } blocks, skipping comments. TEXT maps ITEM_* button names to
 * glyph codes via "%c". Strings at lbl_802A0250 are reached through a const pool
 * view; the offset-0 string uses a member-pointer helper (per-use addi rX,base,0). */
typedef unsigned long Word;
struct Reader{char unknown00[4];};
struct Object{char unknown00[0xC];Reader reader;};
struct Entry{Object*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ManagerPrefix{char unknown00[8];Entry*entries;char unknown0C[0x18];};
struct Manager:ManagerPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual Handle_801F7F10 load(const char*);};
struct Context{char unknown00[0x118];Manager*manager;};
extern "C"{extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,short);Word fn_801F7EB8(const Handle_801F7F10*);
void fn_801F372C(Reader*,char*);void fn_801F3168(Reader*,char*,signed char);signed char fn_801F2E04(Reader*);char fn_801F2F3C(Reader*);void fn_801F34B0(Reader*,long*);Word fn_801F948C(void*,const char*);
int strcmp(const char*,const char*);char*strcat(char*,const char*);int sprintf(char*,const char*,...);
extern const char lbl_80379180[3],lbl_80379184[3],lbl_80379188[3],lbl_8037918C[5],lbl_80379194[2],lbl_80379198[3],lbl_8037919C[6],lbl_803791A4[5],lbl_803791AC[5],lbl_803791B4[3],lbl_803791B8[8],lbl_803791C0[8],lbl_803791C8[2],lbl_803791CC[2],lbl_803791D0[8],lbl_803791D8[5];}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8001FF04:Handle_8001FF78{Handle_8001FF04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8001FF04(){} };
inline Object*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Strings{char itemUpDown[0xC];char itemLeftRight[0x10];char itemDirpad[0xC];char itemCross[0xC];
 char itemCircle[0xC];char itemSquare[0xC];char itemTriangle[0x10];char complete[0xC];};
extern "C" const Strings lbl_802A0250;
inline const char*itemUpDown(const Strings*s){const char(Strings::*m)[0xC]=&Strings::itemUpDown;return s->*m;}
struct Record{long id;long world;Word icon;char text[0x40];unsigned char visible,unknown4D,complete,unknown4F;};
extern "C" Record lbl_802F4208[300];
extern "C" void fn_800AFCF4(const char*name){
 const Strings*const s=&lbl_802A0250;
 for(int i=0;i<300;++i){lbl_802F4208[i].id=-1;lbl_802F4208[i].world=-1;lbl_802F4208[i].complete=0;lbl_802F4208[i].visible=0;lbl_802F4208[i].unknown4D=0;lbl_802F4208[i].text[0]=0;lbl_802F4208[i].unknown4F=1;}
 Handle_8001FF04 h(lbl_801E9D24.manager->load(name));
 if(!fn_801F7EB8(&h))return;
 Reader*r=&resolve(h)->reader;
 char token[128];int i=0;fn_801F372C(r,token);
 while(!fn_801F2E04(r)){
  if(!strcmp(token,lbl_80379180)){while(strcmp(token,lbl_80379184))fn_801F372C(r,token);}
  else if(!strcmp(token,lbl_80379188)){fn_801F3168(r,token,0);}
  else if(!strcmp(token,lbl_8037918C)){
   Record*rec=&lbl_802F4208[i++];
   fn_801F372C(r,token);
   while(strcmp(token,lbl_80379194))fn_801F372C(r,token);
   while(strcmp(token,lbl_803791CC)){
    if(!strcmp(token,lbl_80379198))fn_801F34B0(r,&rec->id);
    else if(!strcmp(token,lbl_8037919C))fn_801F34B0(r,&rec->world);
    else if(!strcmp(token,lbl_803791A4)){
     while(fn_801F2F3C(r)!='{');
     fn_801F372C(r,token);
     rec->icon=fn_801F948C(&rec->icon,token);
     while(fn_801F2F3C(r)!='}');
    }else if(!strcmp(token,lbl_803791AC)){
     while(fn_801F2F3C(r)!='{');
     fn_801F372C(r,token);
     while(strcmp(token,lbl_803791CC)){
      if(!strcmp(token,itemUpDown(s)))sprintf(token,lbl_803791B4,0x80);
      else if(!strcmp(token,s->itemLeftRight))sprintf(token,lbl_803791B4,0x81);
      else if(!strcmp(token,s->itemDirpad))sprintf(token,lbl_803791B4,0x82);
      else if(!strcmp(token,s->itemCross))sprintf(token,lbl_803791B4,0x7B);
      else if(!strcmp(token,s->itemCircle))sprintf(token,lbl_803791B4,0x7C);
      else if(!strcmp(token,s->itemSquare))sprintf(token,lbl_803791B4,0x7D);
      else if(!strcmp(token,s->itemTriangle))sprintf(token,lbl_803791B4,0x7E);
      else if(!strcmp(token,lbl_803791B8))sprintf(token,lbl_803791B4,0x83);
      else if(!strcmp(token,lbl_803791C0))sprintf(token,lbl_803791B4,0x84);
      strcat(rec->text,token);
      strcat(rec->text,lbl_803791C8);
      fn_801F372C(r,token);
     }
    }else if(!strcmp(token,lbl_803791D0)){
     fn_801F372C(r,token);
     if(!strcmp(token,lbl_803791D8)){rec->visible=1;rec->unknown4D=1;}
    }else if(!strcmp(token,s->complete)){
     fn_801F372C(r,token);
     if(!strcmp(token,lbl_803791D8))rec->complete=1;
    }
    fn_801F372C(r,token);
   }
  }
  fn_801F372C(r,token);
 }
}
