// Append two resource-name keys and their factory to the type registry.
typedef unsigned int u32;
typedef void* (*RegistryFactory)();
extern "C" {extern char lbl_8028F698[];u32 fn_801F948C(void*,const char*);void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);}
inline void*operator new(unsigned long,void*p){return p;}
struct RegistryNameKey{u32 value;RegistryNameKey(){value=0;}};
struct RegistryFactoryRecord{RegistryNameKey first,second;RegistryFactory value;unsigned short index;char unknownE[2];RegistryFactoryRecord(){}RegistryFactoryRecord(const RegistryFactoryRecord&r):first(r.first),second(r.second),value(r.value),index(r.index){}};
struct RegistryFactoryArray{int count,capacity;RegistryFactoryRecord*data;void reserveMore(int n){if(capacity+n){if(data)data=(RegistryFactoryRecord*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(RegistryFactoryRecord),(capacity+n)*sizeof(RegistryFactoryRecord));else data=(RegistryFactoryRecord*)fn_8028FF24(lbl_8028F698,(capacity+n)*sizeof(RegistryFactoryRecord));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(RegistryFactoryRecord));data=0;}capacity+=n;}
 void append(const RegistryFactoryRecord&r){if(count+1>capacity)reserveMore(16);new(&data[count++])RegistryFactoryRecord(r);}
};
struct RegistryFactoryOwner{char unknown[0x28];RegistryFactoryArray records;};
extern "C" void fn_801B5664(RegistryFactoryOwner*self,const char*first,const char*second,RegistryFactory value){RegistryFactoryRecord r;r.first.value=fn_801F948C(&r.first,first);r.second.value=fn_801F948C(&r.second,second);r.value=value;r.index=0;for(int i=0;i<self->records.count;++i){}self->records.append(r);}
