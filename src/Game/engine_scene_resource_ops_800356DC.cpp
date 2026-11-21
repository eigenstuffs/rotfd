/* Original scene resource position operation; see docs/notes/game-engine-scene-resource-ops.md. */
typedef unsigned long u32;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{union{u32 word;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Resource;
struct Entry{Resource*object;u32 opaque04,opaque08;signed char generation;char opaque0D[3];};struct Manager{u32 opaque00,opaque04;Entry*entries;};
extern "C"{extern struct{char opaque00[0x118];Manager*manager;}lbl_801E9D24;extern const float lbl_80378420;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&source){word=source.word;fn_801F86C8(lbl_801E9D24.manager,&source,1);}~Handle_80020B90(){}static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}};
struct Point{float x,y,z;Point&operator=(const Point&p){x=p.x;y=p.y;z=p.z;return*this;}};
struct Resource{char opaque00[0x144];Point first144;char opaque150[0xC];Point second15C;char opaque168[0x318-0x168];char component318[0x3F0-0x318];Point saved3F0;};
struct Owner{char opaque00[0x58];Handle_801F7F10 handle58;char opaque5C[0x14];Handle_801F7F10 handle70;};
inline Resource*resolve(const Handle_801F7F10&h){Entry*entry=lbl_801E9D24.manager->entries+h.bits.index;return entry->generation==h.bits.generation?entry->object:0;}
extern "C"{void fn_8023D100(Resource*,const Point*);void fn_8023DE28(Resource*);void fn_8007D6A0(void*,int);}
extern "C" void fn_800356DC(Owner*self){Resource*r=resolve(self->handle70);r->first144.x=lbl_80378420;r->first144.y=lbl_80378420;r->first144.z=lbl_80378420;r->second15C.x=lbl_80378420;r->second15C.y=lbl_80378420;r->second15C.z=lbl_80378420;Point p;p=r->saved3F0;const Handle_801F7F10&original=self->handle58;Handle_80020B90 h(original);fn_8023D100(resolve(h),&p);fn_8023DE28(resolve(h));fn_8007D6A0(r->component318,3);}
