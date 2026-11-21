/* Register a named resource with Python and the original resource manager. */
typedef unsigned long Word;
struct PyObject{};struct Manager{};
struct Name {Word value;Name(){value=0;}Name(const char*);};
struct ResourceRecord {char name[64];Name hash;void*value;};
extern "C" {
 extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);
 void*fn_8001FB04(const char*,const char*);Word fn_801F948C(Name*,const char*);PyObject*PyString_FromString(const char*);PyObject*PyInt_FromLong(long);int PyDict_SetItem(PyObject*,PyObject*,PyObject*);
 const char*strchr(const char*,int);char*strcpy(char*,const char*);void fn_800201B0();void fn_801B5664(Manager*,const char*,const char*,void(*)());extern PyObject*lbl_80377540;
}
extern "C" struct Context {char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Name::Name(const char*text){value=fn_801F948C(this,text);}
inline void*operator new(unsigned long,void*p){return p;}
extern "C" struct ResourceArray {int count,capacity;ResourceRecord*data;
 void resizeStorage(int n){if(n){if(data)data=(ResourceRecord*)fn_8028FAF4(lbl_8028F698,data,capacity*72,n*72);else data=(ResourceRecord*)fn_8028FF24(lbl_8028F698,n*72);}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*72);data=0;}}
 void append(const ResourceRecord&record){if(count+1>capacity){resizeStorage(capacity+16);capacity+=16;}new(&data[count++])ResourceRecord(record);}
}lbl_802F346C;
extern "C" void fn_8001F90C(const char*kind,const char*name,const char*path){
 void*value=fn_8001FB04(name,kind);
 Name key;Word hash=fn_801F948C(&key,name);
 PyDict_SetItem(lbl_80377540,PyInt_FromLong(hash),PyString_FromString(name));
 const char*dot=strchr(path,'.');const char*suffix=dot==0?path:dot+1;
 fn_801B5664(lbl_801E9D24.manager,name,suffix,fn_800201B0);
 ResourceRecord record;record.hash=Name(name);strcpy(record.name,name);record.value=value;lbl_802F346C.append(record);
}
