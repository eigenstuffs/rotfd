// Lazy LoadingScreen resource binding and mark propagation.
// Address-based handle classes express observed ABI layers, not original names.
typedef unsigned long u32;
struct Registry;struct Resource;
struct Globals{char unknown[0x114];char*renderer;Registry*registry;};
extern "C" {extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);extern const char lbl_802A26B8[];u32 fn_801F948C(void*,const char*);}
struct Handle_801F7F10{
 union{u32 value;struct{signed int generation:8;signed int index:24;}bits;};
 Handle_801F7F10();~Handle_801F7F10();Resource*resolve()const;
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
extern "C" void fn_801F86C8(Registry*,const void*,int);
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){value=0;}~Handle_80020478(){}};
struct Handle_80021BCC:Handle_80020478{Handle_80021BCC(){value=0;}~Handle_80021BCC(){}};
struct Handle_800B92F0:Handle_80021BCC{
 Handle_800B92F0(){value=0;}~Handle_800B92F0(){}
 Handle_800B92F0(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.registry,&h,1);}
 Handle_800B92F0&operator=(const Handle_800B92F0&h){fn_801F86C8(lbl_801E9D24.registry,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.registry,&h,1);return *this;}
};
struct HandleRef{u32 value;};
struct Handle_800C5F40:Handle_80020478{
 Handle_800C5F40(){value=0;}~Handle_800C5F40(){}
 Handle_800C5F40(const HandleRef&h){value=h.value;fn_801F86C8(lbl_801E9D24.registry,&h,1);}
};
struct Handle_800C5EC8:Handle_800C5F40{
 ~Handle_800C5EC8(){}
 Handle_800C5EC8(const Handle_800C5F40&h){value=h.value;fn_801F86C8(lbl_801E9D24.registry,&h,1);}
 Handle_800C5EC8&operator=(const Handle_800C5EC8&h){fn_801F86C8(lbl_801E9D24.registry,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.registry,&h,1);return *this;}
};
struct Handle_8002F6B0:Handle_80021BCC{
 ~Handle_8002F6B0(){}
 Handle_8002F6B0(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.registry,&h,1);}
};
struct NameHash{u32 value;NameHash(const char*s){value=fn_801F948C(this,s);}};
struct Prefix{u32 unknown,identity;};
struct Resource:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void mark();
 char unknown0C[0x14];Handle_800C5EC8 owner;
 void setOwner(const Handle_800C5F40&h){owner=Handle_800C5EC8(h);}
};
struct Entry{Resource*object;u32 unknown[2];signed char generation;char padding[3];};
struct Registry{int size,capacity;Entry*entries;};
inline Resource*Handle_801F7F10::resolve()const{Entry*e=&lbl_801E9D24.registry->entries[bits.index];return e->generation==bits.generation?e->object:0;}
struct LoadingScreen{u32 unknown0;HandleRef identity;char unknown8[0x48];Handle_800B92F0 resource;const HandleRef&getIdentity()const{return identity;}};
extern "C" {
Resource*fn_801F7EB8(const Handle_801F7F10*);
Handle_801F7F10 fn_801B550C(Registry*,const NameHash&,const NameHash&);
void fn_80213A18(Resource*);void fn_801E2074(void*,const Handle_8002F6B0&,int);
signed char fn_802537A8(LoadingScreen*);
signed char fn_800C5BB0(LoadingScreen*self){if(!fn_802537A8(self))return 0;if(fn_801F7EB8(&self->resource))self->resource.resolve()->mark();return 1;}
void fn_800C5C58(LoadingScreen*self){
 if(!fn_801F7EB8(&self->resource))self->resource=Handle_800B92F0(fn_801B550C(lbl_801E9D24.registry,NameHash(lbl_802A26B8),NameHash(lbl_802A26B8)));
 fn_80213A18(self->resource.resolve());
 self->resource.resolve()->setOwner(Handle_800C5F40(self->getIdentity()));
 fn_801E2074(lbl_801E9D24.renderer+0x1C8,Handle_8002F6B0(self->resource),0);
}
}
