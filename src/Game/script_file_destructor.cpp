/* Script-file interpreter destruction, reconstructed from GSQE78.
 * Partial class ABI; see docs/notes/game-script-files.md. */
typedef unsigned long u32;
struct DVDCommandBlock {u32 words[12];};
struct DVDFileInfo {DVDCommandBlock block;u32 start,length;void*callback;};
struct File {DVDFileInfo dvd;u32 host;void*stream;char dvdOpen;char padding[3];char*buffer;u32 size,position,buffered,extra;};
extern "C" {
extern char lbl_8028F698[],lbl_801EF5C8[];
extern const char lbl_802EAED0[],__vt__13Manipulator_Z[];
void*fn_8028FAF4(void*,void*,u32,u32);void*fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);void fn_801EF610(void*,void*);
void __dt__11Activable_ZFv(void*,short);
void __dt__13File_801F3E1CFv(File*,short);
void __ct__13File_801F3E1CFv(File*);
File*fn_801F3CE8(File*,const File*);
void*memcpy(void*,const void*,u32);
void*fn_801EFA1C(void*,u32,const char*,const char*,int,int);
extern const char lbl_802AD510[];
}
struct Name64{char text[64];};
struct FileRecord {File file;int line;Name64 name;
 FileRecord(){__ct__13File_801F3E1CFv(&file);line=1;name.text[0]=0;}
 FileRecord(const FileRecord&r){fn_801F3CE8(&file,&r.file);line=r.line;name=r.name;}
 FileRecord&operator=(const FileRecord&r){
  file.dvd.block=r.file.dvd.block;file.dvd.start=r.file.dvd.start;file.dvd.length=r.file.dvd.length;file.dvd.callback=r.file.dvd.callback;
  file.host=r.file.host;file.buffer=r.file.buffer;file.size=r.file.size;file.position=r.file.position;file.buffered=r.file.buffered;file.extra=r.file.extra;file.dvdOpen=r.file.dvdOpen;
  if(file.size){file.buffer=(char*)fn_801EFA1C(lbl_801EF5C8,file.size,lbl_802AD510+0x18,lbl_802AD510+0x28,123,4);memcpy(file.buffer,r.file.buffer,file.size);}
  line=r.line;name=r.name;return *this;
 }
 ~FileRecord(){__dt__13File_801F3E1CFv(&file,-1);}
};
inline void*operator new(unsigned long,void*p){return p;}
template<class T>struct ArrayStorage {
 int size,capacity;T*data;
 void storage(int count){if(count){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),count*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 void releaseStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 ~ArrayStorage(){if(data){for(int i=0;i<size;++i)data[i].~T();releaseStorage();data=0;}}
};
template<class T>struct Array:ArrayStorage<T>{
 T&operator[](int i){return data[i];}
 void remove(int i){data[i].~T();memcpy(data+i,data+i+1,(--size-i)*sizeof(T));}
 void append(const T&t){if(size+1>capacity){storage(capacity+8);capacity+=8;}new(data+size++)T(t);}
};
struct ScriptFilesPrefix {u32 id,handle;};
struct ScriptFiles:ScriptFilesPrefix {
 virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void step(float);
 u32 unknown[5];Array<FileRecord>files;int current;
};

extern "C" ScriptFiles*fn_801F9598(ScriptFiles*s,short flag){
 if(s){
 *(void**)((char*)s+8)=(void*)lbl_802EAED0;
 s->files.~Array<FileRecord>();
 if(s){*(void**)((char*)s+8)=(void*)__vt__13Manipulator_Z;__dt__11Activable_ZFv(s,0);}
 if(flag>0)fn_801EF610(lbl_801EF5C8,s);
 }
 return s;
}
