/* Script-file interpreter step, reconstructed from GSQE78. */
typedef unsigned long u32;
struct DVDCommandBlock {u32 words[12];};
struct DVDFileInfo {DVDCommandBlock block;u32 start,length;void*callback;};
struct File {DVDFileInfo dvd;u32 host;void*stream;char dvdOpen;char padding[3];char*buffer;u32 size,position,buffered,extra;};
struct Pool {char error[0x18];char anonymous[0x10];char header[0xC];};
extern "C" {
extern char lbl_8028F698[],lbl_801EF5C8[];
void fn_8028FD50(void*,void*,u32);
void __dt__13File_801F3E1CFv(File*,short);
void __ct__13File_801F3E1CFv(File*);
void*memcpy(void*,const void*,u32);
void*fn_801EFA1C(void*,u32,const char*,const char*,int,int);
extern const Pool lbl_802AD510;
}
inline const char*anonymousName(const Pool*pool){const char(Pool::*m)[0x10]=&Pool::anonymous;return pool->*m;}
inline const char*errorText(const Pool*pool){return anonymousName(pool)-sizeof(pool->error);}
struct Name64{char text[64];};
struct FileRecord {File file;int line;Name64 name;
 FileRecord(){__ct__13File_801F3E1CFv(&file);line=1;name.text[0]=0;}
 FileRecord&assign(const FileRecord&r,const Pool*pool){
  file.dvd.block=r.file.dvd.block;file.dvd.start=r.file.dvd.start;file.dvd.length=r.file.dvd.length;file.dvd.callback=r.file.dvd.callback;
  file.host=r.file.host;file.buffer=r.file.buffer;file.size=r.file.size;file.position=r.file.position;file.buffered=r.file.buffered;file.extra=r.file.extra;file.dvdOpen=r.file.dvdOpen;
  if(file.size){file.buffer=(char*)fn_801EFA1C(lbl_801EF5C8,file.size,pool->anonymous,pool->header,123,4);memcpy(file.buffer,r.file.buffer,file.size);}
  line=r.line;name=r.name;return *this;
 }
 ~FileRecord(){__dt__13File_801F3E1CFv(&file,-1);}
};
template<class T>struct ArrayStorage {
 int size,capacity;T*data;
};
template<class T>struct Array:ArrayStorage<T>{
 T&operator[](int i){return data[i];}
 void remove(int i){data[i].~T();memcpy(data+i,data+i+1,(--size-i)*sizeof(T));}
};
struct ScriptFilesPrefix {u32 id,handle;};
struct ScriptFiles:ScriptFilesPrefix {
 virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void step(float);
 u32 unknown[5];Array<FileRecord>files;int current;
};

struct InterpreterPrefix {char unknown[0xB08];u32 flags,unknownB0C;};
struct Interpreter:InterpreterPrefix {virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void command(int);};
struct Globals {char unknown[0x110];Interpreter*interpreter;};
extern "C" {
extern Globals lbl_801E9D24;
extern const char lbl_8037A828[3],lbl_8037A82C[3];
char fn_801F3168(File*,char*,int*);char fn_801F2E04(File*);void fn_801F2A98(File*);
char fn_801FAA0C(Interpreter*,const char*);
void fn_801F9D68(Interpreter*,const char*,...);
void fn_802139D8(ScriptFiles*);
int strlen(const char*);int strcmp(const char*,const char*);int strncmp(const char*,const char*,u32);
}
inline char&end(char*p){return p[strlen(p)];}
inline char&last(char*p){return p[strlen(p)-1];}
extern "C" void fn_801F96A8(ScriptFiles*s){
 const Pool*const pool=&lbl_802AD510;
 FileRecord&record=s->files[s->current];
 File*file=&s->files[s->current].file;
 const char*name=record.name.text;
 if((char)((lbl_801E9D24.interpreter->flags>>1)&1))return;
 if(!(lbl_801E9D24.interpreter->flags&4)){
  char comment=0;
  while(!fn_801F2E04(file)){
   char line[128];int length;
   line[0]=0;
   if(!fn_801F3168(file,line,&length))break;
   if(strlen(line)==0){++record.line;continue;}
   record.line+=length;
   if(strcmp(line,lbl_8037A828)==0)comment=1;
   else if(strcmp(line,lbl_8037A82C)==0)comment=0;
   if(last(line)=='\n'||last(line)=='\r')last(line)=0;
   else end(line)=0;
   if(strncmp(line,lbl_8037A828,2)==0)++comment;
   if(!comment && line[0]!='/' && line[1]!='/'){
    if(!fn_801FAA0C(lbl_801E9D24.interpreter,line))fn_801F9D68(lbl_801E9D24.interpreter,errorText(pool),record.line,name);
   }
   if(strncmp(line,lbl_8037A82C,2)==0&&comment>0)--comment;
   if(lbl_801E9D24.interpreter->flags&2)return;
  }
 }else lbl_801E9D24.interpreter->command(4);
 fn_801F2A98(&record.file);
 FileRecord copy;
 copy.assign(s->files[s->current],pool);
 s->files.remove(s->current);
 --s->current;
 if(s->current==-1)fn_802139D8(s);
}
