/* Python module import through native resource/File lifetimes.
 * See docs/notes/game-python-resource-module.md. */
/* Private ordinary module loader; native File identities remain pending adoption. */
typedef unsigned long Word;
struct PyObject;
struct PyType{char unknown00[0x18];void(*destroy)(PyObject*);};
struct PyObject{int references;PyType*type;};
inline void release(PyObject*p){if(p&&--p->references==0)p->type->destroy(p);}
struct Handle_801F7F10{union{Word word;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Resource;struct Entry{void*object;Word key;int references;signed char generation;char unknown0D[3];};
struct ManagerPrefix{int count,capacity;Entry*entries;char unknown0C[0x18];};
struct Manager:ManagerPrefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual Handle_801F7F10 load(const char*);char unknown28[0xA0];signed char compiled,packed;};
struct Globals{char unknown00[0x110];void*console;char unknown114[4];Manager*manager;};
struct File_801F3E1C;
extern "C"{
extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];extern const char lbl_802999A0[];extern const char lbl_803781D8[4],lbl_803781DC[8];
void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,short);Word fn_801F7EB8(const Handle_801F7F10*);
void*fn_801EFA1C(void*,Word,const char*,const char*,int,int);void*memcpy(void*,const void*,Word);int sprintf(char*,const char*,...);
Word fn_801F2E28(File_801F3E1C*);void fn_801FA014(void*,const char*,...);void fn_801F2CB4(File_801F3E1C*,void*,Word);void fn_801F2A98(File_801F3E1C*);
PyObject*PyImport_ImportModule(const char*);PyObject*PyModule_GetDict(PyObject*);PyObject*PyMapping_GetItemString(PyObject*,const char*);int PyMapping_HasKeyString(PyObject*,const char*);int PyMapping_SetItemString(PyObject*,const char*,PyObject*);
PyObject*PyMarshal_ReadObjectFromString(const char*,int);PyObject*Py_CompileString(const char*,const char*,int);PyObject*PyImport_ExecCodeModule(const char*,PyObject*);void PyErr_Print();signed char fn_8001FFE8(PyObject*,const char*,const char*);
}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8001FF04:Handle_8001FF78{Handle_8001FF04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8001FF04(){}signed char valid()const{return fn_801F7EB8(this)!=0;}};
struct Block{Word words[12];};
struct File_801F3E1C{Block block;Word start,length;void*callback;Word host;void*stream;char dvdOpen;char unknown45[3];char*buffer;Word size,position,buffered,extra;
 File_801F3E1C();~File_801F3E1C();
 File_801F3E1C&copy(const File_801F3E1C&other,Word strings){block=other.block;start=other.start;length=other.length;callback=other.callback;host=other.host;buffer=other.buffer;size=other.size;position=other.position;buffered=other.buffered;extra=other.extra;dvdOpen=other.dvdOpen;if(size){buffer=(char*)fn_801EFA1C(lbl_801EF5C8,size,(const char*)(strings+0x80),(const char*)(strings+0x90),0x7B,4);memcpy(buffer,other.buffer,size);}return*this;}
};
struct Resource{char unknown00[0xC];File_801F3E1C value;File_801F3E1C&file(){return value;}};
inline void*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
extern "C" PyObject*fn_8001FB04(const char*name,const char*directory){
 Word strings=(Word)lbl_802999A0;
 File_801F3E1C file;PyObject*code=0;PyObject*result=0;
 PyObject*module=PyImport_ImportModule(lbl_803781D8);
 PyObject*modules=PyMapping_GetItemString(PyModule_GetDict(module),lbl_803781DC);
 if(PyMapping_HasKeyString(modules,name))result=PyMapping_GetItemString(modules,name);
 if(!result){
  char path[256];
  if(lbl_801E9D24.manager->packed||lbl_801E9D24.manager->compiled)sprintf(path,(const char*)(strings+0x60),directory,name);
  else sprintf(path,(const char*)(strings+0x70),directory,name);
  Handle_8001FF04 resource(lbl_801E9D24.manager->load(path));
  signed char available=resource.valid();if(available){
   file.copy(((Resource*)resolve(resource))->file(),strings);
   Word count=fn_801F2E28(&file);fn_801FA014(lbl_801E9D24.console,(const char*)(strings+0x9C),count);
   char*data=(char*)fn_801EFA1C(lbl_801EF5C8,count+1,(const char*)(strings+0x80),(const char*)(strings+0xB4),0x2B0,4);
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
