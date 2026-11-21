/* Named resource path setup and retained callback registration.
 * See docs/notes/game-early-named-resource-callback.md. */
typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Name{Word word;Name(const char*s);};
struct Node{char opaque00[0x128];char name[1];};
struct Entry{Node*object;Word key;int references;signed char generation;char opaque0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct ServicePrefix{char opaque00[0x7C];};
struct Service:ServicePrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void bind(const char*,void*);};
extern "C" struct Globals{char opaque00[0x118];Manager*manager;char opaque11C[0x3C];Service*service;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];extern const char lbl_8029ACA8[],lbl_803785E8[2],lbl_803785EC[5],lbl_803785F4[8];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(Name*,const char*);Handle_801F7F10 fn_801B550C(Manager*,const Name&,const Name&);char*strcpy(char*,const char*);char*strcat(char*,const char*);int sprintf(char*,const char*,...);void fn_800AD694(Node*,const char*);void fn_800CB104();}
inline Name::Name(const char*s){word=fn_801F948C(this,s);}
struct Handle_80052930:Handle_801F7F10{Handle_80052930(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80052930(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80052930&operator=(const Handle_80052930&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Packed{signed int generation:8;signed int index:24;};
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[((const Packed*)&h)->index];if(e->generation==((const Packed*)&h)->generation)return e->object;return 0;}
struct Owner{char opaque00[0x68];Handle_80052930 handle;char name[1];};
extern "C"void fn_80058AB8(Owner*self,const char*name){const Word strings=(Word)lbl_8029ACA8;char path[64];strcpy(path,(const char*)(strings+0x658));strcat(path,(const char*)(strings+0x664));strcat(path,name);strcat(path,lbl_803785E8);strcat(path,name);strcat(path,lbl_803785EC);self->handle=Handle_80052930(fn_801B550C(lbl_801E9D24.manager,Name((const char*)(strings+0x67C)),Name((const char*)(strings+0x670))));strcpy(resolve(self->handle)->name,name);fn_800AD694(resolve(self->handle),path);sprintf(path,lbl_803785F4,(const char*)(strings+0x68C),name,name);strcpy(self->name,path);lbl_801E9D24.service->bind(self->name,(void*)fn_800CB104);}
