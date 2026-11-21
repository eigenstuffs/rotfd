/* Merged TU: .text 0x800AD3C8-0x800AE2B4 (VoiceOverData loader). */
namespace part_800AD3C8 {
struct Handle_AD3C8{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct Entry_AD3C8{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager_AD3C8{int count,capacity;Entry_AD3C8*entries;};
struct Monitor_AD3C8{char unknown00[4];virtual void slot08();virtual void slot0C();virtual void slot10();virtual void*slot14();};
struct Record_AD3C8{int key;unsigned long unknown04;int index,count,current;signed char first,second,special;char unknown17[0x31];int a48;int a4C;int a50;int a54;};
struct Self_AD3C8{char unknown00[0x14];int count,capacity;Record_AD3C8*records;int current;int pending;char unknown28[0x128];Handle_AD3C8 handle;};
extern "C"{
extern struct Global_AD3C8{char unknown00[0x118];Manager_AD3C8*manager;}lbl_801E9D24;
extern Monitor_AD3C8*lbl_803776B8;
void*fn_801F7EB8(Handle_AD3C8*);
void fn_802073E8(void*,int,void*,float);
void fn_8002C810(int*,int,int*,int);
}
#pragma opt_common_subs off
inline void*resolve(const Handle_AD3C8&h){Entry_AD3C8*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Record_AD3C8*find(Self_AD3C8*self,int key){Record_AD3C8*r;for(int i=0;i<self->count;++i){r=&self->records[i];if(key==r->key)return r;}return 0;}
inline Record_AD3C8*current(Self_AD3C8*self){if(self->current>-1)return find(self,self->current);return 0;}
extern "C" void fn_800AD3C8(Self_AD3C8*self){
    if(fn_801F7EB8(&self->handle)){
        fn_802073E8(self,0xA2,resolve(self->handle),(float)self->current);
    }
    if(lbl_803776B8){
        fn_802073E8(self,0xA2,lbl_803776B8->slot14(),(float)self->current);
    }
    Record_AD3C8*r=current(self);
    if(r&&r->index<0&&self->pending<0&&r->special){
        fn_8002C810(&r->a48,r->a50,&r->a4C,r->a54);
    }
}
#pragma opt_common_subs reset

}
namespace part_800AD54C {
/* VoiceOverData neighbour: compiled with common-subexpression elimination off, like fn_800AC260. */
struct Handle_AD54C{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct Entry_AD54C{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager_AD54C{int count,capacity;Entry_AD54C*entries;};
struct Monitor_AD54C{char unknown00[4];virtual void slot08();virtual void slot0C();virtual void slot10();virtual void*slot14();};
struct Self_AD54C{char unknown00[0x20];int value;char unknown24[0x12C];Handle_AD54C handle;};
extern "C"{
extern struct Global_AD54C{char unknown00[0x110];void*log;char unknown114[4];Manager_AD54C*manager;}lbl_801E9D24;
extern Monitor_AD54C*lbl_803776B8;
extern const char lbl_8029F0DC[];
void fn_801FA014(void*,const char*,...);
void*fn_801F7EB8(Handle_AD54C*);
void fn_802073E8(void*,int,void*,float);
}
#pragma opt_common_subs off
/* First resolve: the handle tag must stay a named local (coloured after the backend temps, giving tag r5 / entry r3);
   a single-use local is forward-substituted by the frontend, so it is read twice through a selector on a constant local, which the optimizer folds only after forward substitution. */
inline void*getChecked(Entry_AD54C*entries,const Handle_AD54C&h){Entry_AD54C*e=&entries[h.bits.index];signed char tag=h.bits.tag;int checked=1;if(e->tag==(checked?tag:tag))return e->object;return 0;}
inline void*get(Entry_AD54C*entries,const Handle_AD54C&h){Entry_AD54C*e=&entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" void fn_800AD54C(Self_AD54C*self){
    fn_801FA014(lbl_801E9D24.log,lbl_8029F0DC);
    if(fn_801F7EB8(&self->handle)){
        Entry_AD54C*entries=lbl_801E9D24.manager->entries;fn_802073E8(getChecked(entries,self->handle),0xA3,get(entries,self->handle),(float)self->value);
    }
    if(lbl_803776B8){
        fn_802073E8(self,0xA3,lbl_803776B8->slot14(),(float)self->value);
    }
}
#pragma opt_common_subs reset

}
/* ---- .sdata2 named strings (first block) ---- */
extern "C" {
extern const char lbl_803790D0[] = "ITEM";
extern const char lbl_803790D8[] = "anim_";
extern const char lbl_803790E0[] = "ID";
extern const char lbl_803790E4[] = "NEXTVO";
extern const char lbl_803790EC[] = "SOUND";
extern const char lbl_803790F4[] = "PLAYRTC";
extern const char lbl_803790FC[] = "NO";
extern const char lbl_80379100[] = "TALKER";
}
extern "C" {
extern const char lbl_8037910C[6];
extern const char lbl_80379114[6];
extern const char lbl_8037911C[7];
extern const char lbl_80379124[6];
extern const char lbl_8037912C[5];
extern const char lbl_80379134[5];
extern const char lbl_8037913C[5];
extern const char lbl_80379144[2];
extern const char lbl_80379148[8];
}
/* ---- part_800AD694 (global: mangled handle/file classes) ---- */
/* VoiceOverData file loader (fn_800AD694): opens the resource, checks the VOICE_OVER_DATA header,
   parses every ITEM record with fn_800AD990 and registers the scene mode handle with the record service. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;Word key;int references;signed char tag;char unknown0D[3];};
struct ManagerPrefix{int count,capacity;Entry*entries;char unknown0C[0x18];};
struct Manager:ManagerPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual Handle_801F7F10 load(const char*);};
struct Mode{char unknown00[4];Handle_801F7F10 handle;};
struct Scene{char unknown00[0x15058];Mode*mode;};
struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x3C];void*records;};
extern "C"{
extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];struct Pool{char allocName[0x10];char sourceName[0x11C];char fileName[0xC];char header[0x10];};extern const Pool lbl_8029EFC0;extern Word lbl_803777AC;
void fn_801EF610(void*,void*);void fn_801F86C8(void*,const void*,short);void*fn_801F7EB8(const Handle_801F7F10*);
void*fn_801EFA1C(void*,Word,const char*,const char*,int,int);void*memcpy(void*,const void*,Word);int strcmp(const char*,const char*);
}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8001FF04:Handle_8001FF78{Handle_8001FF04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8001FF04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&o){word=o.word;fn_801F86C8(lbl_801E9D24.manager,&o,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline const char*sourceText(const Pool*p){const char(Pool::*m)[0x11C]=&Pool::sourceName;return p->*m;}
inline const char*allocText(const Pool*p){return sourceText(p)-sizeof(p->allocName);}
struct Block{Word words[12];};
struct File_801F3E1C{Block block;Word start,length;void*callback;Word host;void*stream;char dvdOpen;char unknown45[3];char*buffer;Word size,position,buffered,extra;
 File_801F3E1C();~File_801F3E1C();
 File_801F3E1C&copy(const File_801F3E1C&other,const Pool*pool){block=other.block;start=other.start;length=other.length;callback=other.callback;host=other.host;buffer=other.buffer;size=other.size;position=other.position;buffered=other.buffered;extra=other.extra;dvdOpen=other.dvdOpen;if(size){buffer=(char*)fn_801EFA1C(lbl_801EF5C8,size,allocText(pool),pool->fileName,0x7B,4);memcpy(buffer,other.buffer,size);}return*this;}
};
struct Resource{char unknown00[0xC];File_801F3E1C value;File_801F3E1C&file(){return value;}};
struct VoiceOverData;
extern "C"{void fn_801F372C(File_801F3E1C*,char*);signed char fn_801F2E04(File_801F3E1C*);void fn_801F2A98(File_801F3E1C*);void fn_800AD990(VoiceOverData*,File_801F3E1C*);
void fn_800B6F70(void*,Word,int,Handle_80020478);void fn_800B6DA8(void*,Word,int,Handle_80020478);}
inline void*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" int fn_800AD694(VoiceOverData*self,const char*path){
 const Pool*const pool=&lbl_8029EFC0;
 Handle_8001FF04 resource(lbl_801E9D24.manager->load(path));
 if(!fn_801F7EB8(&resource))return 0;
 File_801F3E1C file;
 file.copy(((Resource*)resolve(resource))->file(),pool);
 char token[256];
 fn_801F372C(&file,token);
 if(strcmp(pool->header,token)!=0)return 0;
 while(!fn_801F2E04(&file)){
  if(strcmp(token,lbl_803790D0)==0)fn_800AD990(self,&file);
  fn_801F372C(&file,token);
 }
 fn_801F2A98(&file);
 fn_800B6F70(lbl_801E9D24.records,lbl_803777AC,0,Handle_80020478(lbl_801E9D24.scene->mode->handle));
 fn_800B6DA8(lbl_801E9D24.records,lbl_803777AC,0,Handle_80020478(lbl_801E9D24.scene->mode->handle));
 return 1;
}

inline void*operator new(unsigned long,void*p){return p;}
namespace part_800AD990 {
/* VoiceOverData ITEM record parser (fn_800AD990): reads one "{ ... }" ITEM block into a local
   0x58-byte record (two 0x800-byte token/text buffers are struct-copied from the .rodata pool
   lbl_8029EFC0) and appends it to the owner's growable record array.
   Matching notes: the TAG strncpy goes through a record pointer declared before the loop, which
   keeps its address out of loop-invariant hoisting (the Name addresses are hoisted natively);
   the RGB divisions use the 255.0f literal (the TU's own .sdata2 constant lbl_80379108, which
   sits between this TU's string literals) and function-scope float temporaries, which give the
   native FPR assignment. */
typedef unsigned long Word;
struct Vec3{float x,y,z;};
struct Name{Word value;Name(){value=0;}void set(const char*s);};
struct NameEntry{char name[0x20];int value;};
struct Buffer{char text[2048];};
struct Pool{char unknown000[0x148];Buffer text;Buffer token;char s1148[12];char s1154[12];char s1160[12];char s116C[16];char s117C[12];char s1188[12];};
struct TextRef{char*text;char tag[10];TextRef(){text=0;tag[0]=0;}};
struct Record{
 int a00,a04,a08,lines,a10;char b14,b15,b16;float c1r,c1g,c1b,c2r,c2g,c2b;float f30,f34;TextRef t;Name n48,n4C;int a50,a54;
 Record(){a00=-1;a04=-1;a08=-1;lines=0;a10=-1;b14=0;b15=0;b16=1;a50=0x50;a54=1;}
};
struct Self{char unknown00[0x10];char*cursor;int count,capacity;Record*records;};
extern "C"{
extern const Pool lbl_8029EFC0;extern NameEntry lbl_802BCFB8[33];extern Vec3 lbl_802F41A8[4],lbl_802F41D8[4];extern char lbl_8028F698[];
void fn_801F372C(void*,char*);signed char fn_801F2E04(void*);void fn_801F34B0(void*,int*);void fn_801F35EC(void*,float*);void fn_801F3168(void*,char*,int);
Word fn_801F948C(void*,const char*);
int strcmp(const char*,const char*);char*strcpy(char*,const char*);char*strcat(char*,const char*);char*strncpy(char*,const char*,Word);Word strlen(const char*);char*strchr(char*,int);char*strrchr(char*,int);
void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);
}
inline void Name::set(const char*s){value=fn_801F948C(this,s);}
inline int lookup(const char*name){int v=-1;for(int i=0;i<33;i++){if(strcmp(name,lbl_802BCFB8[i].name)==0){v=lbl_802BCFB8[i].value;break;}}return v;}
inline int lookupPrefixed(const char*token){char name[64];strcpy(name,lbl_803790D8);strcat(name,token);return lookup(name);}
inline void resize(Self*self,int capacity){
 if(capacity){
  if(self->records)self->records=(Record*)fn_8028FAF4(lbl_8028F698,self->records,self->capacity*sizeof(Record),capacity*sizeof(Record));
  else self->records=(Record*)fn_8028FF24(lbl_8028F698,capacity*sizeof(Record));
 }else if(self->records){fn_8028FD50(lbl_8028F698,self->records,self->capacity*sizeof(Record));self->records=0;}
}
inline void setColors(Record&r,const Vec3&a,const Vec3&b){float ax=a.x,ay=a.y,az=a.z,bx=b.x,by=b.y,bz=b.z;r.c1r=ax;r.c1g=ay;r.c1b=az;r.c2r=bx;r.c2g=by;r.c2b=bz;}
extern "C" int fn_800AD990(Self*self,void*stream){
 const Pool*const pool=&lbl_8029EFC0;
 Record rec;
 Record*p=&rec;
 float red,green,blue;
 Buffer text=pool->text;
 Buffer token=pool->token;
 fn_801F372C(stream,token.text);
 while((unsigned char)token.text[0]!='{'){
  fn_801F372C(stream,token.text);
  if(fn_801F2E04(stream))return 0;
 }
 while((unsigned char)token.text[0]!='}'){
  fn_801F372C(stream,token.text);
  if(strcmp(token.text,lbl_803790E0)==0){int v;fn_801F34B0(stream,&v);rec.a00=v;}
  else if(strcmp(token.text,lbl_803790E4)==0){int v;fn_801F34B0(stream,&v);rec.a04=v;}
  else if(strcmp(token.text,lbl_803790EC)==0){fn_801F372C(stream,token.text);strncpy(p->t.tag,token.text,10);}
  else if(strcmp(token.text,lbl_803790F4)==0){int v;fn_801F34B0(stream,&v);rec.a08=v;}
  else if(strcmp(token.text,pool->s1148)==0){fn_801F372C(stream,token.text);if(strcmp(token.text,lbl_803790FC)==0)rec.b16=0;}
  else if(strcmp(token.text,lbl_80379100)==0){fn_801F372C(stream,token.text);rec.n48.set(token.text);}
  else if(strcmp(token.text,pool->s1154)==0){fn_801F372C(stream,token.text);rec.n4C.set(token.text);}
  else if(strcmp(token.text,pool->s1160)==0){fn_801F372C(stream,token.text);int v=lookupPrefixed(token.text);int t=v;if(v==-1)t=0x50;rec.a50=t;}
  else if(strcmp(token.text,pool->s116C)==0){fn_801F372C(stream,token.text);int v=lookupPrefixed(token.text);int t=v;if(v==-1)t=1;rec.a54=t;}
  else if(strcmp(token.text,pool->s117C)==0){
   int r,g,b;fn_801F34B0(stream,&r);fn_801F34B0(stream,&g);fn_801F34B0(stream,&b);
   blue=b/255.0f;green=g/255.0f;red=r/255.0f;
   rec.c1r=red;rec.c1g=green;rec.c1b=blue;
  }
  else if(strcmp(token.text,pool->s1188)==0){
   int r,g,b;fn_801F34B0(stream,&r);fn_801F34B0(stream,&g);fn_801F34B0(stream,&b);
   blue=b/255.0f;green=g/255.0f;red=r/255.0f;
   rec.c2r=red;rec.c2g=green;rec.c2b=blue;
  }
  else if(strcmp(token.text,lbl_8037910C)==0){
   fn_801F372C(stream,token.text);
   if(strcmp(token.text,lbl_80379114)==0)setColors(rec,lbl_802F41A8[0],lbl_802F41D8[0]);
   else if(strcmp(token.text,lbl_8037911C)==0)setColors(rec,lbl_802F41A8[1],lbl_802F41D8[1]);
   else if(strcmp(token.text,lbl_80379124)==0)setColors(rec,lbl_802F41A8[2],lbl_802F41D8[2]);
   else if(strcmp(token.text,lbl_8037912C)==0)setColors(rec,lbl_802F41A8[3],lbl_802F41D8[3]);
  }
  else if(strcmp(token.text,lbl_80379134)==0){float v;fn_801F35EC(stream,&v);rec.f30=v;rec.f34=v;}
  else if(strcmp(token.text,lbl_8037913C)==0){
   token.text[0]=0;
   fn_801F3168(stream,token.text,0);
   while(strcmp(token.text,lbl_80379148)!=0){
    strlen(token.text);strlen(text.text);
    strcat(text.text,token.text);strcat(text.text,lbl_80379144);
    fn_801F3168(stream,token.text,0);
   }
   if(strcmp(token.text,lbl_80379148)==0){
    char*nl=strrchr(text.text,10);
    if(nl){nl[0]=' ';nl[1]=0;}
    char*start=text.text;char*cur=text.text;char*sp;
    while((sp=strchr(cur,' '))!=0){
     if(sp-start<=0x34)cur=sp+1;
     else{cur[-1]=10;start=cur;}
    }
    rec.t.text=self->cursor;
    strcpy(rec.t.text,text.text);
    self->cursor+=strlen(text.text)+1;
    text.text[0]=0;
    rec.lines++;
   }
  }
 }
 if(self->count+1>self->capacity){resize(self,self->capacity+8);self->capacity+=8;}
 new(self->records+self->count++)Record(rec);
 return 1;
}

}
struct Flush1;
/* ---- .sdata2 named strings (after the pooled 255.0f) ---- */
extern "C" {
__declspec(section ".sdata2") extern const char lbl_8037910C[] = "COLOR";
__declspec(section ".sdata2") extern const char lbl_80379114[] = "WHITE";
__declspec(section ".sdata2") extern const char lbl_8037911C[] = "YELLOW";
__declspec(section ".sdata2") extern const char lbl_80379124[] = "GREEN";
__declspec(section ".sdata2") extern const char lbl_8037912C[] = "BLUE";
__declspec(section ".sdata2") extern const char lbl_80379134[] = "TIME";
__declspec(section ".sdata2") extern const char lbl_8037913C[] = "TEXT";
__declspec(section ".sdata2") extern const char lbl_80379144[] = "\n";
__declspec(section ".sdata2") extern const char lbl_80379148[] = "ENDTEXT";
}
