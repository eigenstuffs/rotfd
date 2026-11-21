/* Transform record snapshot and array append; see docs/notes/game-transform-record-append.md. */
typedef unsigned int u32;
extern "C" { extern char lbl_8028F698[]; void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int); }
inline void*operator new(unsigned long,void*p){return p;}
struct Entry {void*object;u32 key;char unknown8[4];signed char generation;char padD[3];signed char getGeneration()const{return generation;}};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown[0x118];Manager*manager;char unknown11C[0x28];void*resource;char unknown148[0x10];void*other;};
extern "C" Globals lbl_801E9D24;
struct Handle {signed int generation:8;signed int index:24;template<class T>T*get()const{int i=index;Manager*m=lbl_801E9D24.manager;int gen=m->entries[i].getGeneration();return gen==generation?(T*)m->entries[i].object:0;}};
struct Vec3 {float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};struct Quat {float x,y,z,w;};
struct Transform{char unknown[0x30];Vec3 position;Vec3 getPosition()const{return Vec3(position.x,position.y,position.z);}};struct Child{char unknown[0x124];Transform*transform;};
extern "C" void fn_801F1E78(Quat*,const void*);
template<class T>struct Array {int count,capacity;T*data;void allocate(int n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}} void append(const T&v){if(count+1>capacity){allocate(capacity+64);capacity+=64;}new(&data[count++])T(v);}};
struct Record {float time;Vec3 position;Quat rotation;Record(const Record&v){time=v.time;position.x=v.position.x;position.y=v.position.y;position.z=v.position.z;rotation.x=v.rotation.x;rotation.y=v.rotation.y;rotation.z=v.rotation.z;rotation.w=v.rotation.w;}Record(){}};
struct Owner{char unknown[0x1C];float time;char unknown20[4];Handle handle;char unknown28[0xC];Array<Record>records;};
typedef char RecordSize[(sizeof(Record)==32)?1:-1];
extern "C" void fn_801C3B2C(Owner*self){Record record;record.position=self->handle.get<Child>()->transform->getPosition();fn_801F1E78(&record.rotation,(char*)self->handle.get<Child>()+0x30);record.time=self->time;self->records.append(record);}
