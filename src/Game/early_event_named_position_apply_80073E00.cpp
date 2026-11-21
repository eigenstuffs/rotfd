/* Event-driven named actor position apply; see docs/notes/game-early-event-named-position-apply.md. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Return_80073E00:Handle_801F7F10{Return_80073E00();~Return_80073E00(){}};
struct Name{Word word;Name(const char*);};
struct Vec3{float x,y,z;Vec3(float a,float b,float c):x(a),y(b),z(c){}};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct NodePrefix{char unknown0[8];};
struct Node:NodePrefix{
 virtual void unknown08();virtual void unknown0C();virtual void unknown10();virtual void unknown14();virtual void unknown18();virtual void unknown1C();virtual void unknown20();virtual void unknown24();virtual void unknown28();virtual void unknown2C();virtual void unknown30();virtual void event34();virtual void event38();
 char unknownC[0x38-0xC];unsigned long long flags;char unknown40[0x18];Handle_801F7F10 related;char unknown5C[0x14];Handle_801F7F10 actor;char unknown74[0x124-0x74];Geometry*geometry;char unknown128[0x1F8-0x128];char control;
};
struct SourceNode:Node{};
struct SourceEntry{SourceNode*object;char unknown4[8];signed char tag;char unknownD[3];};struct SourceManager{int count,capacity;SourceEntry*entries;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Mode{};
struct Scene{char unknown0[0x15058];Mode*root;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
extern "C"{Word fn_801F948C(Name*,const char*);signed char fn_8025E9FC(Node*,int);void fn_8007D6A0(void*,int);Return_80073E00 fn_80058778(Mode*,const Name&,signed char);void fn_8023D100(Node*,const Vec3&);void fn_8025E8F8(Node*);void fn_802554F4(Node*);extern const char lbl_8029CAA0[];}
inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
inline SourceNode*resolveSource(const Handle_801F7F10&h){SourceEntry*e=&((SourceManager*)lbl_801E9D24.manager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
inline Vec3 position(Node*n){return Vec3(n->geometry->position.x,n->geometry->position.y,n->geometry->position.z);}
extern "C"void fn_80073E00(Node*self){if(fn_8025E9FC(self,0x51))self->event34();if(fn_8025E9FC(self,0xA8))fn_8007D6A0(&resolve(self->actor)->control,1);if(fn_8025E9FC(self,0x3A)||fn_8025E9FC(self,0x39)||fn_8025E9FC(self,0x86)){Node*target=resolve(fn_80058778(lbl_801E9D24.scene->root,Name(lbl_8029CAA0),0));if(target){Node*destination=resolve(target->related);SourceNode*source=resolveSource(self->related);fn_8023D100(destination,position(source));target->event38();target->flags|=0x20000;fn_8025E8F8(target);fn_802554F4(target);}}}
