// Hierarchy camera/list setup (GSQE78 0x80202A18): sizes the per-view lists and
// creates a camera agent, viewport node and camera node for each view.
// Hierarchy handle array specializations reconstructed from GSQE78.
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void fn_8028FD50(void*, void*, u32);
}
inline void* operator new(unsigned long, void* p) { return p; }
struct Handle_801F7F10 {
    union { u32 value; struct { signed int generation:8; signed int index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
template<int Depth> struct HierarchyResizeHandle : HierarchyResizeHandle<Depth - 1> {
    HierarchyResizeHandle() { value = 0; }
    ~HierarchyResizeHandle() {}
};
template<> struct HierarchyResizeHandle<1> : Handle_801F7F10 {
    HierarchyResizeHandle() { value = 0; }
    ~HierarchyResizeHandle() {}
};
template<class T> struct ResizeArray {
    int count, capacity;
    T* data;
    void storage(int size) {
        if (size) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data, capacity * sizeof(T), size * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }
};

struct Object;
struct Entry { Object* object; u32 unknown[2]; signed char generation; char padding[3]; };
struct Manager { u32 unknown[2]; Entry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; char unknown11C[8]; void* dispatcher; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
u32 fn_801F948C(void*,const char*);
u32 fn_801F7EB8(const void*);
void fn_8023D648(Object*);
}
struct NameHash { u32 value; NameHash(const char* s) { value = fn_801F948C(this,s); } };
struct FoundHandle : Handle_801F7F10 {};
template<int N> struct SetupOwnedHandle : HierarchyResizeHandle<N> {
    SetupOwnedHandle() {}
    SetupOwnedHandle(const Handle_801F7F10& h) {
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
    SetupOwnedHandle& operator=(const SetupOwnedHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
        return *this;
    }
    void assign(const SetupOwnedHandle<1>& h) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
};
template<class T> struct SetupArray : ResizeArray<T> {
    void resize(int n, char keepCapacity) {
        void*p;
        int i;
        if(n>count) {
            if(n>capacity || !keepCapacity) {storage(n);capacity=n;}
            for(i=count;i<n;++i){p=&data[i];new(p) T;}
            count=n;
        } else if(n<count) {
            for(i=count-1;i>=n;--i)data[i].~T();
            if(keepCapacity)count=n;
            else {storage(n);capacity=n;count=n;}
        }
    }
};
struct Vec3 { float x,y,z; void set(float a,float b,float c){x=a;y=b;z=c;} };
struct Object {
    char unknown00[0x1C];
    SetupOwnedHandle<1> child;
    char unknown20[0x10];
    Handle_801F7F10 parent;
    char unknown34[0xB8-0x34];
    Vec3 position;
    void setChild(const SetupOwnedHandle<1>& h) {child=h;fn_8023D648(this);}
};
inline Object* resolve(const Handle_801F7F10& h) {
    Entry* e=lbl_801E9D24.manager->entries+h.bits.index;
    if(e->generation==h.bits.generation)return e->object;
 return 0;
}
struct OwnerManager {u32 unused[2];Entry* entries;};
inline Object* resolveOwner(const Handle_801F7F10&h) {
 Entry* e=((OwnerManager*)lbl_801E9D24.manager)->entries+h.bits.index;
 if(e->generation==h.bits.generation)return e->object;
 return 0;
}
struct HierarchySetup {
    char unknown00[0x0C]; Handle_801F7F10 owner;
    char name[0x80];
    ResizeArray<Handle_801F7F10> first;
    ResizeArray<HierarchyResizeHandle<5> > second;
    ResizeArray<HierarchyResizeHandle<7> > third;
    SetupArray<HierarchyResizeHandle<2> > fourth;
    char unknownC0[0x1C];
    int count, width, offset;
};
struct HierarchyStringPool {
    char player[12]; char lod[12]; char start[12];
    char cameraAgent[12]; char cameraClass[16]; char viewportFormat[16];
};
extern "C" {
extern const HierarchyStringPool lbl_802AD8F8;
extern const char lbl_8037A904[5],lbl_8037A910[7];
extern const float lbl_8037A8DC,lbl_8037A90C;
void fn_802032B8(ResizeArray<HierarchyResizeHandle<5> >*,int,char);
void fn_802030C4(ResizeArray<HierarchyResizeHandle<7> >*,int,char);
FoundHandle fn_80260868(void*,const NameHash&,const char*);
Handle_801F7F10 fn_801B550C(Manager*,const NameHash&,const NameHash&);
void fn_801FC998(HierarchySetup*,const SetupOwnedHandle<2>&);
void fn_801BA714(char*,const char*,...);
void fn_802408BC(Object*,SetupOwnedHandle<1>,int);
void fn_80269FE0(Object*);
inline void assign(HierarchyResizeHandle<2>& destination,const SetupOwnedHandle<1>& h) {
 fn_801F86C8(lbl_801E9D24.manager,&destination,-1);
 destination.value=h.value;
 fn_801F86C8(lbl_801E9D24.manager,&h,1);
}
void fn_80202A18(HierarchySetup* self,int count,signed char shared,const NameHash& cameraType) {
    const HierarchyStringPool& pool=lbl_802AD8F8;
    if(self->count)return;
    self->count=count;
    fn_802032B8(&self->second,self->count,0);
    fn_802030C4(&self->third,self->count,0);
    self->fourth.resize(self->count,0);
    self->width=shared?1:self->count;
    for(int i=0;i<self->count;++i) {
        SetupOwnedHandle<2> camera(fn_80260868(lbl_801E9D24.dispatcher,cameraType,pool.cameraAgent));
        if(!fn_801F7EB8(&camera))
            camera=SetupOwnedHandle<2>(fn_80260868(lbl_801E9D24.dispatcher,NameHash(pool.cameraClass),pool.cameraAgent));
        fn_801FC998(self,camera);
        char name[128];
        fn_801BA714(name,pool.viewportFormat,self->name,i);
        assign(self->fourth.data[i],SetupOwnedHandle<1>(fn_801B550C(lbl_801E9D24.manager,NameHash(lbl_8037A904),NameHash(name))));
        resolve(self->fourth.data[i])->position.set(lbl_8037A8DC,lbl_8037A8DC,lbl_8037A90C);
        resolve(self->fourth.data[i])->setChild(SetupOwnedHandle<1>(fn_801B550C(lbl_801E9D24.manager,NameHash(lbl_8037A910),NameHash(name))));
        fn_8023D648(resolve(self->fourth.data[i]));
        fn_802408BC(resolve(resolveOwner(self->owner)->parent),SetupOwnedHandle<1>(self->fourth.data[i]),0);
    }
    fn_80269FE0(resolve(self->owner));
}
}
