/* Springboard agent registration: log "Registering Springboard Agent", forward
 * to the base setup (fn_80257E04, fn_80257700), create the "SLEEPINGZZ" /
 * "ParticlesAgent_Z" named child under the related root object, keep it at
 * +0x70 when valid and set flag 0x02000000 on the object behind handle +0x58.
 *
 * The strings stay external in the shared SpringboardAgent.cpp pool
 * lbl_8029BC90 (+0x0 message, +0x20, +0x2C; owned by
 * native_readable_pools_8029BC90.cpp, also used by fn_80064848), viewed as
 * one const pool struct.  One pool pointer used in both blocks keeps the base
 * materialized first (original lis register order, base in r29).  The
 * offset-0 message is (member pointer to +0x20) minus 0x20 at the use: that
 * keeps the original `addi r4,r29,0` and schedules it before the logger load,
 * unlike a direct offset-0 member pointer. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Object{char opaque[0x120];unsigned int flags120;};
struct Entry{Object*object;char opaque4[8];signed char tag;char opaqueD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char opaque[0x1C];Handle_801F7F10*handle;};
struct Globals{char opaque[0x110];void*logger;char opaque114[4];Manager*manager;char opaque11C[0x20];Related*related;};
struct Pool{char message[0x20];char sleeping[0xC];char particles[0x14];};
extern "C"{
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
extern const Pool lbl_8029BC90;
void fn_801EF610(void*,void*);
void fn_801FA014(void*,const char*,...);
Word fn_801F948C(void*,const char*);
void fn_80257E04(void*,void*);
void fn_80257700(void*,int,int);
}
inline const char*sleepingName(const Pool*pool){const char(Pool::*m)[0xC]=&Pool::sleeping;return pool->*m;}
inline const char*messageText(const Pool*pool){return sleepingName(pool)-sizeof(pool->message);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Name{Word word;Name(const char*text){word=fn_801F948C(this,text);}};
extern "C" Handle_80020834 fn_801FCF20(Object*,const Name&,Name,const Handle_80020B90&);
inline Object*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;int i=h.bits.index;int tag=m->entries[i].getTag();if(tag==h.bits.tag)return m->entries[i].object;return 0;}
struct View{char opaque[0x58];Handle_801F7F10 handle58;char opaque5C[0x14];Object*field70;};
extern "C" void fn_80064DE0(View*self,void*value){
    const Pool*const pool=&lbl_8029BC90;
    fn_801FA014(lbl_801E9D24.logger,messageText(pool));
    fn_80257E04(self,value);
    fn_80257700(self,0,0);
    Object*parent;
    Object*child=resolve(fn_801FCF20((parent=resolve(*lbl_801E9D24.related->handle),parent),Name(pool->sleeping),Name(pool->particles),Handle_80020B90()));
    if(child)self->field70=child;
    resolve(self->handle58)->flags120|=0x02000000;
}
