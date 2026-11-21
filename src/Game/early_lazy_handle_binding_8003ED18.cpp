/* Lazy named-handle binding; verified temporary and node assignment lifetimes.
 * See docs/notes/game-early-lazy-handle-binding.md. */
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char opaque4[8];signed char tag;char opaqueD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Owner;
struct Scene{char opaque[0x15058];Owner*owner;};
struct Globals{char opaque[0x118];Manager*manager;char opaque11C[8];Scene*scene;};
extern "C" {extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Handle_801F7F10 fn_801B52EC(Manager*,const char*);Word fn_801F7EB8(const Handle_801F7F10*);void fn_800A7798(Node*);extern const char lbl_8029A914[],lbl_8029A920[];}
struct LazyBindingZero_ED18:Handle_801F7F10{LazyBindingZero_ED18(){word=0;}~LazyBindingZero_ED18(){}};
struct LazyBindingLayer_ED18:LazyBindingZero_ED18{LazyBindingLayer_ED18(){word=0;}~LazyBindingLayer_ED18(){}};
struct Handle_8002F6B0:LazyBindingLayer_ED18{Handle_8002F6B0(){word=0;}~Handle_8002F6B0(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002F634:Handle_8002F6B0{
 Handle_8002F634(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002F634(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_8002F634&operator=(const Handle_8002F634&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Handle_80020478:Handle_801F7F10{
 Handle_80020478(){word=0;}Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Handle_80020834:Handle_80020478{
 Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_80020834&operator=(const Handle_80020478&h){Handle_80020834 copy(h);fn_801F86C8(lbl_801E9D24.manager,this,-1);word=copy.word;fn_801F86C8(lbl_801E9D24.manager,&copy,1);return*this;}
};
struct Prefix{char opaque[8];};
struct Node:Prefix{
 virtual void unknown08();virtual void unknown0C();virtual void unknown10();virtual void unknown14();virtual void unknown18();virtual void unknown1C();virtual void unknown20();virtual void unknown24();virtual void unknown28();virtual void unknown2C();virtual void unknown30();virtual void unknown34();virtual void unknown38();virtual void unknown3C();virtual void unknown40();virtual void setName(const char*);
 char opaqueC[0x24];Handle_80020834 handle30;
 void setHandle(const Handle_80020478&h){Handle_80020834 copy(h);fn_801F86C8(lbl_801E9D24.manager,&handle30,-1);handle30.word=copy.word;fn_801F86C8(lbl_801E9D24.manager,&copy,1);}
};
struct Owner{char opaque[4];Handle_801F7F10 self;char opaque8[0x58];Handle_8002F634 target;};
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" int fn_8003ED18(void*){
 Owner*owner=lbl_801E9D24.scene->owner;
 if(!fn_801F7EB8(&owner->target)){
  owner->target=Handle_8002F634(fn_801B52EC(lbl_801E9D24.manager,lbl_8029A914));
  {const Handle_801F7F10&original=owner->self;resolve(owner->target)->setHandle(Handle_80020478(original));}
  resolve(owner->target)->setName(lbl_8029A920);
 }
 {const Handle_801F7F10&original=owner->self;resolve(owner->target)->setHandle(Handle_80020478(original));}
 fn_800A7798(resolve(owner->target));
 return 1;
}
