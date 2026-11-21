/* Agent init: log, run the base init (fn_8002B824), scale the two range
 * thresholds (+0x94/+0x98) from the resolved controller's radius (+0x370),
 * set controller flag 0x200 in its 64-bit flags (+0x30), then create three
 * named Handles under the related scene object (lbl_801E9D24+0x13C -> +0x1C)
 * and keep each resolved node in nodes[0..2] (+0xA0) when non-null.
 * The first half is the body of fn_8006F44C (early_agent_operation_8006f44c).
 * Class shapes follow actor_named_target_setup_80073BE0.
 * Register notes: the parent resolve must use the `r=0; if(..) r=obj;` helper
 * (otherwise self and the zero/parent web swap r27/r28), and the controller
 * flags must be the 64-bit field (a 32-bit field puts the resolved pointer
 * in r4 instead of r5). */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Object{char opaque[0x30];unsigned long long flags30;char opaque38[0x370-0x38];float radius370;};
struct Entry{Object*object;char opaque4[8];signed char tag;char opaqueD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char opaque[0x1C];Handle_801F7F10*handle;};
struct Globals{char opaque[0x110];void*logger;char opaque114[4];Manager*manager;char opaque11C[0x20];Related*related;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];extern const char lbl_8029C7A8[];extern const float lbl_803788AC,lbl_803788B0;void fn_801EF610(void*,void*);Word fn_801F948C(void*,const char*);void fn_801FA014(void*,const char*,...);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Name { Word word; Name(const char*text) { word=fn_801F948C(this,text); } };
extern "C" Handle_80020834 fn_801FCF20(Object*,const Name&,Name,const Handle_80020B90&);
inline Object*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Object*resolveOrNull(const Handle_801F7F10&h){Object*r=0;Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)r=e->object;return r;}
struct Agent{char opaque[0x70];Handle_801F7F10 controller;char opaque74[0x94-0x74];float high94;float low98;char opaque9C[4];Object*nodes[3];};
extern "C" void fn_8002B824(Agent*,void*);
extern "C" void fn_8007079C(Agent*self,void*input){
    const char*strings=lbl_8029C7A8;
    fn_801FA014(lbl_801E9D24.logger,strings+0x10);
    fn_8002B824(self,input);
    self->high94=lbl_803788AC*resolve(self->controller)->radius370;
    self->low98=lbl_803788B0*resolve(self->controller)->radius370;
    resolve(self->controller)->flags30|=0x200ULL;
    Object*parent;
    Object*node;
    node=resolve(fn_801FCF20((parent=resolveOrNull(*lbl_801E9D24.related->handle),parent),Name(strings+0x30),Name(strings+0x44),Handle_80020B90()));
    if(node)self->nodes[0]=node;
    node=resolve(fn_801FCF20((parent=resolveOrNull(*lbl_801E9D24.related->handle),parent),Name(strings+0x58),Name(strings+0x44),Handle_80020B90()));
    if(node)self->nodes[1]=node;
    node=resolve(fn_801FCF20((parent=resolveOrNull(*lbl_801E9D24.related->handle),parent),Name(strings+0x6c),Name(strings+0x44),Handle_80020B90()));
    if(node)self->nodes[2]=node;
}
