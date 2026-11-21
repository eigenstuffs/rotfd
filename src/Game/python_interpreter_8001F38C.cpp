/* PythonInterpreter_Z translation unit (0x8001F38C..0x80020DC4).
 * Interpreter startup/shutdown, the Python resource module lifecycle, the
 * resource factory callback, the two 200-entry name caches and their
 * compiler-generated static initialization.
 * Emission order: a function that first instantiates an implicit member
 * (Name copy/assignment, ResourceRecord copy) and the inline handle
 * destructors stay pending until the next class definition, so type
 * definitions are placed directly after fn_8001F834, fn_8001F90C,
 * fn_8001FB04 and fn_800201B0 to emit everything in original order. */
typedef unsigned long Word;
struct EventPyObject;
struct EventPyType{char unknown00[0x18];void(*destroy)(EventPyObject*);};
struct EventPyObject{int references;EventPyType*type;};
typedef EventPyObject PyObject;
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);extern char lbl_8028F698[];}

struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;Word key;int references;signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct ManagerPrefix{int count,capacity;Entry*entries;char unknown0C[0x18];};
struct Manager:ManagerPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual Handle_801F7F10 load(const char*);char unknown28[0xA0];signed char compiled,packed;};
struct Scene;struct CacheList;struct CacheRoot;struct CacheObject;
struct CacheEntry{CacheObject*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct CacheManager{int count,capacity;CacheEntry*entries;};
struct Globals{char unknown00[0x110];void*console;char unknown114[4];union{Manager*manager;CacheManager*cacheManager;};CacheRoot*root;char unknown120[4];union{Scene*scene;CacheList*list;};};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(void*,const void*,short);void*fn_801F7EB8(const Handle_801F7F10*);Word fn_801F948C(void*,const char*);
}

struct Name{Word value;Name():value(0){}Name(const char*text){value=fn_801F948C(this,text);}bool operator==(const Name&o)const{return value==o.value;}};
struct ResourceRecord {char name[64];Name hash;EventPyObject*value;const Name&key()const{return hash;}EventPyObject*object()const{return value;}};
inline void*operator new(unsigned long,void*p){return p;}
extern "C" {void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);}
struct ResourceArray {
 int count,capacity;ResourceRecord*data;
 ResourceArray():count(0),capacity(0),data(0){}
 ~ResourceArray(){if(data){for(int i=0;i<count;i++){}if(data){fn_8028FD50(lbl_8028F698,data,capacity*0x48);data=0;}data=0;}}
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 ResourceRecord&at(const int&i){return data[i];}
 void remove(const int&i);
 void resizeStorage(int n);
 void append(const ResourceRecord&record);
 void release();
 void reset();
};
struct CacheObject{char unknown00[0x58];Handle_801F7F10 related;};
struct CacheNode{Name name;char unknown04[0x12C];Handle_801F7F10 owner;};
struct CacheSlot{Name name;CacheNode*node;};

extern "C" {
 ResourceArray lbl_802F346C;
 CacheSlot lbl_802F3478[200];
 CacheSlot lbl_802F3AB8[200];
 extern EventPyObject*lbl_80377540,*lbl_80377544,*lbl_80377548,*lbl_8037754C,*lbl_80377550;
 extern unsigned short lbl_80377554,lbl_80377556;
}

/* ---- 0x8001F38C interpreter startup ---- */
struct StartupSingleton;
inline void ResourceArray::release(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ResourceRecord));data=0;}capacity=0;}
inline void ResourceArray::reset(){if(count<0){release();for(int i=count;i<0;++i)new(data+i)ResourceRecord;count=0;}else if(count>0){for(int i=count-1;i>=0;--i)data[i].~ResourceRecord();release();count=0;}}
extern "C" {
 void Py_Initialize();EventPyObject*PyDict_New();void fn_800E023C();void fn_8001F614();void fn_800204E8();void fn_800204F4();
}
inline void resetSlots(CacheSlot*slots){for(int i=0;i<200;++i)slots[i].node=0;}
extern "C" StartupSingleton*fn_8001F38C(void*self){
 lbl_80377540=0;lbl_80377544=0;lbl_80377548=0;lbl_8037754C=0;lbl_80377550=0;
 lbl_802F346C.reset();
 lbl_80377554=0;resetSlots(lbl_802F3478);lbl_80377556=0;resetSlots(lbl_802F3AB8);
 Py_Initialize();lbl_80377540=PyDict_New();fn_800E023C();fn_8001F614();fn_800204E8();fn_800204F4();return static_cast<StartupSingleton*>(self);
}

/* ---- 0x8001F518 interpreter shutdown ---- */
static inline void dispose(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
extern "C" void Py_Finalize();
extern "C" void*fn_8001F518(void*self,int flag){
 if(self){
  if(lbl_8037754C&&--lbl_8037754C->references==0)lbl_8037754C->type->destroy(lbl_8037754C);
  if(lbl_80377550&&--lbl_80377550->references==0)lbl_80377550->type->destroy(lbl_80377550);
  if(lbl_80377540&&--lbl_80377540->references==0)lbl_80377540->type->destroy(lbl_80377540);
  Py_Finalize();
  if((short)flag>0)dispose(self);
 }
 return self;
}

/* ---- 0x8001F614 module lifecycle ---- */
inline void releaseEventObject(EventPyObject*p){if(p&&--p->references==0)p->type->destroy(p);}
inline void release(EventPyObject*p){releaseEventObject(p);}
extern "C" EventPyObject*PyObject_GetAttrString(EventPyObject*,const char*);
struct File_801F3E1C;
extern "C"{
extern const char lbl_803781D8[4],lbl_803781DC[8];
void*fn_801EFA1C(void*,Word,const char*,const char*,int,int);void*memcpy(void*,const void*,Word);int sprintf(char*,const char*,...);
Word fn_801F2E28(File_801F3E1C*);void fn_801FA014(void*,const char*,...);void fn_801F2CB4(File_801F3E1C*,void*,Word);void fn_801F2A98(File_801F3E1C*);
PyObject*PyImport_ImportModule(const char*);PyObject*PyModule_GetDict(PyObject*);PyObject*PyMapping_GetItemString(PyObject*,const char*);int PyMapping_HasKeyString(PyObject*,const char*);int PyMapping_SetItemString(PyObject*,const char*,PyObject*);
PyObject*PyMarshal_ReadObjectFromString(const char*,int);PyObject*Py_CompileString(const char*,const char*,int);PyObject*PyImport_ExecCodeModule(const char*,PyObject*);void PyErr_Print();signed char fn_8001FFE8(PyObject*,const char*,const char*);
}
inline void*resolveResource(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" {
 extern const char lbl_803781C0[6];
 EventPyObject* fn_8001FAE0(const char*);
 void fn_8001F834(void*);
 EventPyObject* PyDict_Copy(EventPyObject*);
 void fn_800200F8(const char*);
 extern const char lbl_803781C8[6],lbl_803781D0[7];void fn_801B55E4(void*,const Word*);EventPyObject*fn_8001FB04(const char*,const char*);
 PyObject*PyString_FromString(const char*);PyObject*PyInt_FromLong(long);int PyDict_SetItem(PyObject*,PyObject*,PyObject*);
 const char*strchr(const char*,int);char*strcpy(char*,const char*);void*fn_800201B0();void fn_801B5664(Manager*,const char*,const char*,void*(*)());
}
inline void ResourceArray::resizeStorage(int n){if(n){if(data)data=(ResourceRecord*)fn_8028FAF4(lbl_8028F698,data,capacity*72,n*72);else data=(ResourceRecord*)fn_8028FF24(lbl_8028F698,n*72);}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*72);data=0;}}
inline void ResourceArray::append(const ResourceRecord&record){if(count+1>capacity){resizeStorage(capacity+16);capacity+=16;}new(&data[count++])ResourceRecord(record);}
#define RELEASE_GLOBAL(object) if(object) { if(--object->references==0)object->type->destroy(object); }
inline void ResourceArray::remove(const int&i){
  Name id=at(i).key();
  fn_801B55E4(lbl_801E9D24.manager,&id.value);
  if(at(i).object()){
   if(--at(i).object()->references==0)
    at(i).object()->type->destroy(at(i).object());
  }
  fn_800200F8(at(i).name);
  memcpy(&at(i),&at(i)+1,(--count-i)*sizeof(ResourceRecord));
}
extern "C" {
    void fn_80207A14(const char*,char*);
    signed char fn_801F3918(File_801F3E1C*,const char*,int);
    EventPyObject* PyMarshal_WriteObjectToString(EventPyObject*);
    int PyString_Size(EventPyObject*);
    char* PyString_AsString(EventPyObject*);
    void fn_801F2BD4(File_801F3E1C*,const void*,int);
    void fn_801F2B58(File_801F3E1C*);
}

extern "C" void fn_8001F614()
{
EventPyObject* module;EventPyObject* second;EventPyObject* first;EventPyObject* other;
    module=fn_8001FAE0("LibPython");
    other=fn_8001FAE0(lbl_803781C0);
    if(module) {
        first=PyObject_GetAttrString(module,"PythonInterpreter_Z_StoreObject");
        if(first)lbl_8037754C=first;
        else { PyErr_Print();releaseEventObject(first); }
        second=PyObject_GetAttrString(module,"PythonInterpreter_Z_GetStoredObject");
        if(second)lbl_80377550=second;
        else { PyErr_Print();releaseEventObject(second); }
        releaseEventObject(module);
        releaseEventObject(other);
    }
}
static const char unusedIndexModule[]="GenerateIndex";

extern "C" int fn_8001F754(void* self,const char* argument)
{
    fn_8001F834(self);
    RELEASE_GLOBAL(lbl_80377540);
    lbl_80377540=PyDict_New();
    EventPyObject* result=fn_8001FB04(lbl_803781C8,argument);
    releaseEventObject(result);
    fn_800200F8(lbl_803781C8);
    RELEASE_GLOBAL(lbl_80377544);
    lbl_80377544=PyDict_Copy(lbl_80377540);
    return 1;
}

extern "C" void fn_8001F834(void*){for(int i=0;i<lbl_802F346C.count;++i)lbl_802F346C.remove(i--);}
/* Typed handles used by the module loader. */
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8001FF04:Handle_8001FF78{Handle_8001FF04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8001FF04(){}signed char valid()const{return fn_801F7EB8(this)!=0;}};

extern "C" void fn_8001F90C(const char*kind,const char*name,const char*path){
 EventPyObject*value=fn_8001FB04(name,kind);
 Name key;Word hash=fn_801F948C(&key,name);
 PyDict_SetItem(lbl_80377540,PyInt_FromLong(hash),PyString_FromString(name));
 const char*dot=strchr(path,'.');const char*suffix=dot==0?path:dot+1;
 fn_801B5664(lbl_801E9D24.manager,name,suffix,fn_800201B0);
 ResourceRecord record;record.hash=Name(name);strcpy(record.name,name);record.value=value;lbl_802F346C.append(record);
}
/* File stream view used by the module loader and bytecode writer. */
struct Block{Word words[12];};
struct File_801F3E1C{Block block;Word start,length;void*callback;Word host;void*stream;char dvdOpen;char unknown45[3];char*buffer;Word size,position,buffered,extra;
 File_801F3E1C();~File_801F3E1C();
 File_801F3E1C&copy(const File_801F3E1C&other){block=other.block;start=other.start;length=other.length;callback=other.callback;host=other.host;buffer=other.buffer;size=other.size;position=other.position;buffered=other.buffered;extra=other.extra;dvdOpen=other.dvdOpen;if(size){buffer=(char*)fn_801EFA1C(lbl_801EF5C8,size,"Anonymous Alloc","File_Z.h",0x7B,4);memcpy(buffer,other.buffer,size);}return*this;}
};
struct Resource{char unknown00[0xC];File_801F3E1C value;File_801F3E1C&file(){return value;}};

extern "C" EventPyObject*fn_8001FAE0(const char*self){return fn_8001FB04(self,lbl_803781D0);}

extern "C" PyObject*fn_8001FB04(const char*name,const char*directory){
 File_801F3E1C file;PyObject*code=0;PyObject*result=0;
 PyObject*module=PyImport_ImportModule(lbl_803781D8);
 PyObject*modules=PyMapping_GetItemString(PyModule_GetDict(module),lbl_803781DC);
 if(PyMapping_HasKeyString(modules,name))result=PyMapping_GetItemString(modules,name);
 if(!result){
  char path[256];
  if(lbl_801E9D24.manager->packed||lbl_801E9D24.manager->compiled)sprintf(path,"DB:>%s>%s.pyc",directory,name);
  else sprintf(path,"DB:>%s>%s.py",directory,name);
  Handle_8001FF04 resource(lbl_801E9D24.manager->load(path));
  signed char available=resource.valid();if(available){
   file.copy(((Resource*)resolveResource(resource))->file());
   Word count=fn_801F2E28(&file);fn_801FA014(lbl_801E9D24.console,"Python file size is %u",count);
   char*data=(char*)fn_801EFA1C(lbl_801EF5C8,count+1,"Anonymous Alloc","PythonInterpreter_Z.cpp",0x2B0,4);
   fn_801F2CB4(&file,data,count);data[count]=0;
   if(lbl_801E9D24.manager->packed||lbl_801E9D24.manager->compiled)code=PyMarshal_ReadObjectFromString(data,count);
   else code=Py_CompileString(data,name,0x101);
   if(code){result=PyImport_ExecCodeModule(name,code);if(result){PyMapping_SetItemString(modules,name,result);if(!lbl_801E9D24.manager->packed&&!lbl_801E9D24.manager->compiled)fn_8001FFE8(code,name,directory);}}
   if(!code||!result)PyErr_Print();
   fn_801EF610(lbl_801EF5C8,data);fn_801F2A98(&file);
  }
 }
 release(code);release(module);release(modules);return result;
}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};

extern "C" signed char fn_8001FFE8(EventPyObject* object,const char* name,const char* directory)
{
    char path[256],converted[256];
    signed char result;
    EventPyObject* bytes=0;
    sprintf(path,"DB:>%s>%s.pyc",directory,name);
    fn_80207A14(path,converted);
    File_801F3E1C file;
    result=fn_801F3918(&file,converted,2);
    if(result) {
        bytes=PyMarshal_WriteObjectToString(object);
        fn_801F2BD4(&file,PyString_AsString(bytes),PyString_Size(bytes));
        fn_801F2B58(&file);
        fn_801F2A98(&file);
    } else fn_801FA014(lbl_801E9D24.console,"WARNING: Bytecode file %s not saved!",converted);
    releaseEventObject(bytes);
    return result;
}

/* ---- 0x800200F8 module cache entry removal ---- */
extern "C" int PyDict_DelItemString(EventPyObject*,const char*);
extern "C" void fn_800200F8(const char*name){
 EventPyObject*module=PyImport_ImportModule(lbl_803781D8);
 EventPyObject*mapping=PyMapping_GetItemString(PyModule_GetDict(module),lbl_803781DC);
 if(PyMapping_HasKeyString(mapping,name))PyDict_DelItemString(mapping,name);
 releaseEventObject(module);
 releaseEventObject(mapping);
}

/* ---- 0x800201B0 resource factory callback ---- */
namespace callback {
struct Node{};
inline PyObject*toInteger(const Name&n){PyObject*object=PyInt_FromLong(n.value);return object;}
inline void decref(PyObject*p){if(p&&!--p->references)p->type->destroy(p);}
}
extern "C"{extern Name*lbl_80377F98;PyObject*PyDict_GetItem(PyObject*,PyObject*);unsigned long strlen(const char*);PyObject*PyObject_CallObject(PyObject*,PyObject*);PyObject*PyObject_CallFunction(PyObject*,const char*,...);PyObject*PyErr_Occurred();Handle_80020478 fn_80260868(Scene*,const Name&,int);extern const char lbl_803781E4[2];extern char lbl_80299A94[];}
namespace callback {
inline PyObject*lookupCallable(const char*name){if(strlen(name)){PyObject*module=fn_8001FB04(name,lbl_803781D0);if(module){PyObject*callable=PyObject_GetAttrString(module,name);decref(module);if(callable)return callable;}}return 0;}
inline PyObject*copyDictionaryAndBoxName(Word selected){lbl_80377540=PyDict_Copy(lbl_80377544);PyObject*object=PyInt_FromLong(selected);return object;}
}
extern "C" void*fn_800201B0(){
 using namespace callback;
 PyObject*wrapper=0;PyObject*key=copyDictionaryAndBoxName(lbl_80377F98->value);PyObject*nameObject=PyDict_GetItem(lbl_80377540,key);const char*name=PyString_AsString(nameObject);PyObject*callable=lookupCallable(name);decref(key);decref(nameObject);
 Node*node;
 if(callable){PyObject*created=PyObject_CallObject(callable,0);if(created){wrapper=PyObject_CallFunction(lbl_8037754C,lbl_803781E4,created);if(wrapper&&lbl_80377548)node=(Node*)lbl_80377548;else{node=(Node*)fn_801F7EB8(&fn_80260868(lbl_801E9D24.scene,Name(lbl_80299A94),0));PyErr_Print();}}else{node=(Node*)fn_801F7EB8(&fn_80260868(lbl_801E9D24.scene,Name(lbl_80299A94),0));PyErr_Print();}}
 else{node=(Node*)fn_801F7EB8(&fn_80260868(lbl_801E9D24.scene,Name(lbl_80299A94),0));if(PyErr_Occurred())PyErr_Print();}
 decref(wrapper);decref(callable);return node;
}


/* ---- lookup views; 0x800204E8 cache counters; 0x80020500 named resource lookup (first cache) ---- */
struct CacheList{char unknown00[0x18];Handle_801F7F10 owner;char unknown1C[0x18];int count;char unknown38[4];Handle_801F7F10*entries;};
struct CacheRoot{char unknown00[8];const Handle_801F7F10*handle;};
/* ---- 0x800204E8 cache counters ---- */
extern "C" void fn_800204E8(void) { lbl_80377554 = 0; }
extern "C" void fn_800204F4(void) { lbl_80377556 = 0; }
extern "C"{extern const char lbl_80299AA0[],lbl_80299AAC[];extern CacheObject*lbl_803776D0;CacheObject*fn_8005E9A0();}
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.cacheManager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
void operator=(const Handle_80020834&h){fn_801F86C8(lbl_801E9D24.cacheManager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.cacheManager,&h,1);}};
namespace lookup1 {
struct CacheIndexedEntries{CacheEntry*p;CacheEntry&operator[](int i)const{return p[i];}};
struct CacheIndexedManager{int count,capacity;CacheIndexedEntries entries;};
struct CacheIndex{int value;CacheIndex(int v):value(v){}operator const int&()const{return value;}};
template<class T>inline T*resolve(const Handle_801F7F10&h){CacheEntry*e=&lbl_801E9D24.cacheManager->entries[h.bits.index];if(e->tag==h.bits.tag)return (T*)e->object;return 0;}
template<class T>inline T*resolveChecked(const Handle_801F7F10&h){CacheManager*m=lbl_801E9D24.cacheManager;const CacheIndex index(h.bits.index);signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return (T*)m->entries[index].object;return 0;}
template<class T>inline T*resolveIndexed(const Handle_801F7F10&h){CacheIndexedManager*m=(CacheIndexedManager*)lbl_801E9D24.cacheManager;const CacheIndex index(h.bits.index);signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return (T*)m->entries[index].object;return 0;}
inline bool differ(const Handle_801F7F10&a,const Handle_801F7F10&b){return resolveIndexed<CacheObject>(a)!=resolveChecked<CacheObject>(b);}
inline CacheNode*findCached(Name name){for(unsigned short i=0;i<lbl_80377554;i++){if(lbl_802F3478[i].name==name)return lbl_802F3478[i].node;}return 0;}
inline void addCached(const Name&name,CacheNode*node){if(lbl_80377554<200){lbl_802F3478[lbl_80377554].name=name;lbl_802F3478[lbl_80377554].node=node;lbl_80377554++;}}
inline const Handle_801F7F10&listEntry(int i){return lbl_801E9D24.list->entries[i];}
}
extern "C" CacheObject*fn_80020500(const Name&name){
using namespace lookup1;
if(name.value==Name(lbl_80299AA0).value)return fn_8005E9A0();
if(name.value==Name(lbl_80299AAC).value)return lbl_803776D0;
CacheNode*cached=findCached(name);
if(!cached){
Handle_80020834 h;
for(int i=0;i<lbl_801E9D24.list->count;i++){
h=Handle_80020834(listEntry(i));
if(differ(h,lbl_801E9D24.list->owner)){
CacheNode*node=resolve<CacheNode>(resolveChecked<CacheObject>(h)->related);
if(node&&node->name==name){addCached(node->name,node);return resolveChecked<CacheObject>(h);}
}}
return 0;
}
return resolve<CacheObject>(cached->owner);
}

/* ---- 0x800208A8 named resource-node lookup (second cache) ---- */
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_80020B90&h){word=h.word;fn_801F86C8(lbl_801E9D24.cacheManager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.cacheManager,&h,1);}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{Handle_80020B90 fn_8026A494(CacheObject*,const Name&);}
namespace lookup2 {
template<class T>inline T*resolve(const Handle_801F7F10&h){CacheEntry*e=&lbl_801E9D24.cacheManager->entries[h.bits.index];if(e->tag==h.bits.tag)return (T*)e->object;return 0;}
inline CacheNode*findCached(Name name){for(unsigned short i=0;i<lbl_80377556;i++){if(lbl_802F3AB8[i].name==name)return lbl_802F3AB8[i].node;}return 0;}
inline void addCached(const Name&name,CacheNode*node){if(lbl_80377556<200){lbl_802F3AB8[lbl_80377556].name=name;lbl_802F3AB8[lbl_80377556].node=node;lbl_80377556++;}}
}
extern "C" CacheNode*fn_800208A8(const Name&name){
using namespace lookup2;
if(name.value==Name(lbl_80299AA0).value)return resolve<CacheNode>(fn_8005E9A0()->related);
if(name.value==Name(lbl_80299AAC).value)return resolve<CacheNode>(lbl_803776D0->related);
CacheNode*cached=findCached(name);
if(!cached){
Handle_80020C04 owner(*lbl_801E9D24.root->handle);
Handle_80020B90 child(fn_8026A494(resolve<CacheObject>(owner),name));
if(!fn_801F7EB8(&child))return 0;
CacheNode*node=resolve<CacheNode>(child);
addCached(node->name,node);
return node;
}
return cached;
}
