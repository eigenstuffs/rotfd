/* Original nested Handle return flag operations; see docs/notes/game-engine-scene-return-flags.md. */
typedef unsigned long u32;
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ReturnHandle_80041F30:Handle_801F7F10{~ReturnHandle_80041F30(){}};
struct Node{char opaque00[0x120];u32 flags120;char opaque124[0xCC];Handle_801F7F10 handle1F0;};struct Owner{char opaque00[0x64];Handle_801F7F10 handle64;};struct Entry{Node*object;u32 opaque04,opaque08;signed char generation0C;char opaque0D[3];};struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Global{char opaque00[0x118];Manager*manager;}lbl_801E9D24;
struct Key{u32 word;Key(const char*);};extern "C"{u32 fn_801F948C(Key*,const char*);ReturnHandle_80041F30 fn_8024BDA0(Node*,const Key&);extern const char lbl_80378544[5],lbl_8037854C[4],lbl_80378550[7];}
inline Key::Key(const char*text){word=fn_801F948C(this,text);}
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->generation0C==h.bits.tag?e->object:0;}
struct ByteManager{int count,capacity;char*entries;};inline Node*resolveAlternate(const Handle_801F7F10&h){Entry*e=(Entry*)(((ByteManager*)lbl_801E9D24.manager)->entries+h.bits.index*16);return e->generation0C==h.bits.tag?e->object:0;}
inline void mark(const Handle_801F7F10&h){resolve(h)->flags120|=0x2000000;}
extern "C" void fn_80041F30(Owner*self){Node*n=resolve(resolveAlternate(self->handle64)->handle1F0);mark(fn_8024BDA0(n,Key(lbl_80378544)));mark(fn_8024BDA0(n,Key(lbl_8037854C)));}
