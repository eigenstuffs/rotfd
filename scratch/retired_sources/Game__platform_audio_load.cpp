#include "Game/platform_audio_update_internal.h"
struct AudioResourceName {char normalized[128];char basename[16];};
extern "C" {
extern const char lbl_8037B8C0[4]="DSP";
extern const char lbl_8037B8C4[4]="WAV";
extern const char lbl_802AF448[];
unsigned long strlen(const char*);char*strcat(char*,const char*);
int fn_801F4520(const char*,const char*);
void fn_801F2A4C(const char*,char*);
void fn_802077B4(const char*,char*,char*,char*,char*);
void fn_801F459C(char*);
int fn_8028A31C(void*,const char*,int,int,int);
int fn_8023B864(PlatformAudioUpdateOwner*);
void fn_801FA014(void*,const char*,...);
int fn_80289968(void*,const char*);
void fn_80286D9C(PlatformAudioUpdateOwner*self,const char*name,u32 flags,const OwnerHandle&first,const OwnerHandle&second){
 AudioResourceName resource;char suffix[16];char*basename;
 const char*extension=name+strlen(name)-3;int kind;
 if(!fn_801F4520(extension,lbl_8037B8C0))kind=1;
 else if(!fn_801F4520(extension,lbl_8037B8C4))kind=2;
 else kind=0;
 basename=resource.basename;
 fn_801F2A4C(name,resource.normalized);
 fn_802077B4(name,0,0,basename,suffix);
 strcat(basename,suffix);fn_801F459C(basename);
 int stream=fn_8028A31C(self->secondary,resource.normalized,kind,(flags>>1)&1,0);
 if(stream>=0&&kind==1){
  int index=fn_8023B864(self);
  if(index<0){
   fn_801FA014(*reinterpret_cast<void**>(reinterpret_cast<char*>(&lbl_801E9D24)+0x110),lbl_802AF448,resource);
   fn_80289968(self->secondary,basename);
  }else{
   self->tracks[index].running=1;self->tracks[index].timer=lbl_8037B898;
   {OwnerHandle empty;empty.value=0;self->tracks[index].owner=empty;}
   self->tracks[index].first=first;self->tracks[index].second=second;
   self->channels[index].flags=0x381;
   self->channels[index].field04=lbl_8037B898;
   self->channels[index].field08=lbl_8037B898;
   self->channels[index].field0C=lbl_8037B89C;
   self->channels[index].field00=lbl_8037B89C;
   self->channels[index].field1C=stream;
  }
 }
}
}
