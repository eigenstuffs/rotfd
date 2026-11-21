// Recovered GSQE78 group creation, including native handle ownership and placement construction.
typedef unsigned long u32;
struct Handle { union { u32 value; struct { signed int generation:8; signed int index:24; } bits; }; };
struct Handle_801F7F10 { Handle_801F7F10(); ~Handle_801F7F10(); Handle token; };
struct NameHash { u32 value; NameHash(const char*); };
struct Object { NameHash name; char unknown04[8]; Handle owner; };
struct Entry { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct Manager { u32 unused[2]; Entry* entries; };
struct RelatedManagerView { u32 unused[2]; Entry* entries; };
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(const void*);
void fn_801F86C8(Manager*,const void*,short);
u32 fn_801F948C(void*,const char*);
extern char lbl_8028F698[];
void* fn_8028FAF4(void*,void*,u32,u32);
void* fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
}
inline NameHash::NameHash(const char* text) { value=fn_801F948C(this,text); }
inline Object* resolve(const Handle& h) {
    Entry* e=lbl_801E9D24.manager->entries+h.bits.index;
    if(e->generation==h.bits.generation)return e->object;
    return 0;
}
inline Object* resolveRelated(const Handle& h) {
    Entry* e=((RelatedManagerView*)lbl_801E9D24.manager)->entries+h.bits.index;
    if(e->generation==h.bits.generation)return e->object;
    return 0;
}
inline bool equal(const Handle& a,const Handle& b) {
    Object* object=resolve(b);
    return object==resolveRelated(a);
}
struct GroupHandle : Handle_801F7F10 {
    GroupHandle(const Handle_801F7F10& h) { token=h.token;fn_801F86C8(lbl_801E9D24.manager,&h,1); }
    GroupHandle(const GroupHandle& h) { token=h.token;fn_801F86C8(lbl_801E9D24.manager,&h,1); }
};
inline void* operator new(unsigned long,void* p) {return p;}
template<class T> struct Array {
    int count,capacity; T* data;
    void storage(int n) {
        if(n) {
            if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
        } else if(data) {fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}
    }
    void append(const T& h) {
        if(count+1>capacity) {storage(capacity+8);capacity+=8;}
        void* slot=data+count++; new(slot) T(h);
    }
};
struct Groups { char unknown[0x14]; Array<GroupHandle> entries; };
inline int findGroup(Groups* self,const Handle& target) {
    for(int i=0;i<self->entries.count;++i) {
        Object* object=resolve(self->entries.data[i].token);
        if(object && fn_801F7EB8(&object->owner) && equal(target,object->owner))return i;
    }
    return -1;
}
extern "C" {
extern const char lbl_8037A8C8[8],lbl_8037A8D0[5];
Handle_801F7F10 fn_801B550C(Manager*,const NameHash&,const NameHash&);
void fn_802072D4(Object*,const NameHash&,signed char);
void fn_80203890(Object*,const Handle&,const char*);
void fn_80202A18(Object*,int,signed char,const NameHash&);
void fn_801FDD60(Object*);
void fn_801FF4F8(Groups* self,const Handle& world,const char* name,int count,signed char shared,const NameHash& cameraType) {
    if(findGroup(self,world)<0) {
        GroupHandle created(fn_801B550C(lbl_801E9D24.manager,NameHash(lbl_8037A8D0),NameHash(lbl_8037A8C8)));
        self->entries.append(created);
        Object* group=resolve(created.token);
        fn_802072D4(group,resolveRelated(world)->name,1);
        fn_80203890(group,world,name);
        fn_80202A18(group,count,shared,cameraType);
        fn_801FDD60(group);
    }
}
}
