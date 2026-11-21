/* Hook registration: binds the hooked target, copies the source anchor and
 * marks the actor attached when the source group is flagged. Private layout
 * views; the first source lookups read the manager through an indexed entry
 * view, and the group-link lookup reads the source handle through a second
 * handle view so its index is reloaded. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct HookLinkHandle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct HookEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct HookManager{int count,capacity;HookEntry*entries;};
struct HookIndexedEntries{HookEntry*p;HookEntry&operator[](int i)const{return p[i];}};
struct HookIndexedManager{int count,capacity;HookIndexedEntries entries;};
struct HookRoot{char unknown00[8];const Handle_801F7F10*handle;};
struct HookGlobals{char unknown00[0x110];void*logger;char unknown114[4];HookManager*manager;HookRoot*root;};
extern "C"{extern HookGlobals lbl_801E9D24;void fn_801FA014(void*,const char*,...);extern const char lbl_80299C74[];}
template<class T>inline T*resolve(const Handle_801F7F10&h){HookEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return (T*)e->object;return 0;}
template<class T>inline T*resolveLink(const HookLinkHandle&h){HookEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return (T*)e->object;return 0;}
template<class T>inline T*resolveIndexed(const Handle_801F7F10&h){HookEntry*e=&((HookIndexedManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(e->tag==h.bits.tag)return (T*)e->object;return 0;}
struct Vec3{float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}};
struct HookTransform{char unknown00[0x30];Vec3 position;};
struct HookGroup{char unknown00[0xBC];unsigned short flagsBC;char unknownBE[0x62];Word flags120;};
struct HookSource{char unknown00[0xC];Handle_801F7F10 link;char unknown10[0x110];Word flags120;HookTransform*transform;};
struct HookActor{char unknown00[0x318];char controller[0x30];Vec3 anchor;char unknown354;unsigned char attached;};
struct HookOwner{char unknown00[0x58];Handle_801F7F10 source;char unknown5C[0x14];Handle_801F7F10 actor;char unknown74[0xC];void*target;};
extern "C"{void fn_8025A0A4(HookOwner*,const Handle_801F7F10*);void fn_80027B3C(HookActor*,HookOwner*);const Handle_801F7F10&fn_80268080(HookGroup*,const Handle_801F7F10&);void fn_8007D6A0(void*,int);}
extern "C" void fn_80024FF4(HookOwner*self,const Handle_801F7F10*handle){
fn_801FA014(lbl_801E9D24.logger,lbl_80299C74);
fn_8025A0A4(self,handle);
self->target=resolve<void>(*handle);
fn_80027B3C(resolve<HookActor>(self->actor),self);
const Vec3&position=resolveIndexed<HookSource>(self->source)->transform->position;
resolve<HookActor>(self->actor)->anchor.set(position.x,position.y,position.z);
HookGroup*group=0;
HookSource*source=resolveIndexed<HookSource>(self->source);
if(!(source->flags120&0x80)){
if(resolve<HookGroup>(source->link)->flags120&0x80)
group=resolve<HookGroup>(fn_80268080(resolve<HookGroup>(*lbl_801E9D24.root->handle),resolveLink<HookSource>(*(const HookLinkHandle*)&self->source)->link));
}else group=resolve<HookGroup>(fn_80268080(resolve<HookGroup>(*lbl_801E9D24.root->handle),self->source));
if(group&&(group->flagsBC&1))resolve<HookActor>(self->actor)->attached=1;
fn_8007D6A0(resolve<HookActor>(self->actor)->controller,0);
}
