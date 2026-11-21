/* Resource path and registry startup; see docs/notes/game-resource-registry-paths.md. */
typedef unsigned long Word;
struct Name {Word word;Name(const char*);bool operator!=(const Name&n)const{return word!=n.word;}};
struct Handle {union{Word word;struct{signed int tag:8;signed int index:24;}bits;};};
struct Entry {void*object;Word key;char unknown08[8];};
struct ManagerEntry {void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager {char unknown00[8];ManagerEntry*entries;};
struct Service {char unknown00[0x18];Handle selected;};
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[8];Service*service;};
struct File {char bytes[0x5C];};
struct RegistryKey {int index,unknown04;Word key;RegistryKey(int);};
struct Owner {int count,capacity;Entry*entries;char unknown0C[0x2C];char path[0x80];char unknownB8[12];void*registry;};
extern "C" {
 extern Context lbl_801E9D24;extern char lbl_801EF5C8[];extern const char lbl_802AC7D0[],lbl_8037A224[8],lbl_8037A22C[8];
 void fn_801E9FB4();void __ct__13File_801F3E1CFv(File*);void __dt__13File_801F3E1CFv(File*,short);
 char*strcpy(char*,const char*);char*strcat(char*,const char*);
 void*fn_801EFA1C(void*,Word,const char*,const char*,int,Word);void*fn_80208888(void*);
 void fn_80208BFC(void*,int);void fn_802083C8(void*,void*,void*,int);
 void*fn_801F7EB8(const Handle*);Handle*fn_8025FF60(Service*,const Name&);Name*fn_801B5190(Owner*,const Handle&);
 void fn_801F86C8(Manager*,const Handle*,short);Word fn_801F948C(void*,const char*);
 void fn_8025361C(void*,const char*);
}
inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline RegistryKey::RegistryKey(int i){fn_80208BFC(this,i);}
static inline void assign(Handle&out,const Handle&in){fn_801F86C8(lbl_801E9D24.manager,&out,-1);out.word=in.word;fn_801F86C8(lbl_801E9D24.manager,&in,1);}
static inline void*resolve(const Handle&h){int i=h.bits.index;ManagerEntry&e=lbl_801E9D24.manager->entries[i];int tag=e.tag;return tag==h.bits.tag?e.object:0;}
extern "C" void fn_801B480C(Owner*self,const char*path,const Name&key){
 const char*pool=(const char*)&lbl_802AC7D0;
 fn_801E9FB4();
 char configName[128],combined[128],alternate[128];
 File file;__ct__13File_801F3E1CFv(&file);
 strcpy(combined,self->path);strcat(combined,path);strcpy(configName,combined);strcpy(alternate,combined);strcat(configName,lbl_8037A224);strcat(alternate,lbl_8037A22C);
 void*registry=fn_801EFA1C(lbl_801EF5C8,16,pool+0x140,pool+0x150,0x47,4);if(registry)registry=fn_80208888(registry);self->registry=registry;
 for(int i=0;i<self->count;++i){if(self->entries[i].object){RegistryKey k(-1);k.key=self->entries[i].key;k.index=i;void*entry;fn_802083C8(self->registry,&k,&entry,1);}}
 Handle&selected=lbl_801E9D24.service->selected;
 if(!fn_801F7EB8(&selected))assign(selected,*fn_8025FF60(lbl_801E9D24.service,key));
 else if(*fn_801B5190(self,selected)!=key)assign(selected,*fn_8025FF60(lbl_801E9D24.service,key));
 if(!fn_801F7EB8(&selected))assign(selected,*fn_8025FF60(lbl_801E9D24.service,Name(pool+0x114)));
 fn_8025361C(resolve(selected),configName);
 __dt__13File_801F3E1CFv(&file,-1);
}
