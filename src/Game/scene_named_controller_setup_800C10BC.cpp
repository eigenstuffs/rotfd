// Bounded native scene setup. Name is copied by value at the C entry;
// EntryArray keeps the signed handle index as a stable typed array position.
struct SceneIndex{int value;SceneIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long Word;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char unknown0[0x84];int state;char unknown88[0xB0-0x88];Handle_801F7F10*related;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct Mode{char unknown0[0x60];Handle_801F7F10 actor;};struct Scene{char unknown0[0x15058];Mode*root;};
struct Registry{char unknown0[0x1C];Handle_801F7F10*handle;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Registry*registry;}lbl_801E9D24;
extern "C"void fn_801F86C8(Manager*,const Handle_801F7F10*,int);
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Return_800C10BC:Handle_801F7F10{Return_800C10BC();~Return_800C10BC(){}};
struct Name{Word value;Name(const char*);Name(const Name&n):value(n.value){}};
struct Self{char unknown0[0x78];Node*selected;};
extern "C"{extern const char lbl_802A18C4[];extern const int lbl_80378598;Word fn_801F948C(Name*,const char*);void fn_800A6234(Node*,signed char,Name);void fn_80056434(Mode*,int);Node*fn_801F7EB8(const Handle_801F7F10*);Return_800C10BC fn_8005863C(Mode*);void fn_8002B0A8(Self*);}
inline Name::Name(const char*s){value=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;SceneIndex index(h.bits.index);signed char generation=h.bits.tag;if(m->entries[index].matchesTag(generation))return m->entries[index].object;return 0;}
inline Node*selected(){Handle_8002B67C handle(*lbl_801E9D24.registry->handle);if(fn_801F7EB8(&handle)){const Handle_801F7F10&related=*resolve(handle)->related;if(fn_801F7EB8(&related))return resolve(related);}return 0;}
extern "C"void fn_800C10BC(Self*self){Node*actor=resolve(lbl_801E9D24.scene->root->actor);fn_800A6234(actor,0,Name(Name(lbl_802A18C4)));fn_80056434(lbl_801E9D24.scene->root,lbl_80378598);selected()->state=lbl_80378598;self->selected=resolve(fn_8005863C(lbl_801E9D24.scene->root));fn_8002B0A8(self);}
