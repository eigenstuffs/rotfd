/* Replace the selected related Handle, preserving native retained lifetimes. */
typedef unsigned long u32;
struct Handle_801F7F10 {
    union {
        u32 value;
        struct {
            signed int generation:8,index:24;
        }
        bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct RelatedHandleIndex {
    const int value;
    RelatedHandleIndex(int v):value(v) {
    }
    operator int()const {
        return value;
    }
};
struct RelatedName {
    u32 value;
};
struct RelatedObject;
struct RelatedEntry {
    RelatedObject*object;
    char unknown04[8];
    signed char generation;
    char pad[3];
    bool matchesTag(signed char tag)const {
        return generation==tag;
    }
};
struct RelatedEntryArray {
    RelatedEntry*data;
    RelatedEntry&operator[](const RelatedHandleIndex&i)const {
        return data[i];
    }
};
struct RelatedManager {
    int count,capacity;
    RelatedEntryArray entries;
};
struct RelatedGlobals {
    char unknown00[0x118];
    RelatedManager*manager;
    char unknown11C[8];
    void*dispatcher;
};
struct RelatedReturnedHandle:Handle_801F7F10 {
};
extern "C" {
    extern RelatedGlobals lbl_801E9D24;
    void*fn_801F7EB8(const void*);
    void fn_801F86C8(RelatedManager*,const void*,short);
    RelatedReturnedHandle fn_80260868(void*,const RelatedName&,const char*);
    void*memcpy(void*,const void*,u32);
} struct RelatedHandle {
    union {
        u32 value;
        struct {
            signed int generation:8,index:24;
        }
        bits;
    };
    RelatedHandle&operator=(const Handle_801F7F10&h) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
        return*this;
    }
};
struct RelatedZeroHandle:Handle_801F7F10 {
    RelatedZeroHandle() {
        value=0;
    }
};
struct RelatedDefaultHandle:RelatedZeroHandle {
    RelatedDefaultHandle() {
        value=0;
    }
};
struct RelatedCopyHandle:RelatedZeroHandle {
    RelatedCopyHandle(const Handle_801F7F10&h) {
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
};
struct RelatedArrayIndex {
    int value;
    RelatedArrayIndex(int v):value(v) {
    }
    operator const int&()const {
        return value;
    }
    RelatedArrayIndex&operator++() {
        ++value;
        return*this;
    }
};
struct RelatedHandleArray {
    int count,capacity;
    RelatedReturnedHandle*items;
};
struct RelatedHandleOwner {
    char unknown00[0x18];
    RelatedHandle related;
    char unknown1C[0x18];
    RelatedHandleArray array;
};
template<class H>static inline RelatedObject*resolve(const H&h) {
    RelatedManager*manager=lbl_801E9D24.manager;
    const RelatedHandleIndex index(h.bits.index);
    const signed char tag(h.bits.generation);
    if(manager->entries[index].matchesTag(tag))return manager->entries[index].object;
    return 0;
} static inline void clearRelated(RelatedHandle&to) {
    RelatedDefaultHandle zero;
    to=zero;
} extern "C" RelatedHandle*fn_8025FF60(RelatedHandleOwner*self,const RelatedName&name) {
    if(fn_801F7EB8(&self->related)) {
        for(RelatedArrayIndex i(0);i<self->array.count;++i) {
            const RelatedReturnedHandle&other=self->array.items[i];
            RelatedObject*left=resolve(self->related);
            RelatedObject*right=resolve(other);
            if(left==right) {
                self->array.items[i].~RelatedReturnedHandle();
                RelatedReturnedHandle*destination=&self->array.items[i];
                memcpy(destination,destination+1,(--self->array.count-i)*sizeof(Handle_801F7F10));
                break;
            }
        }
    }  clearRelated(self->related);
    return &(self->related=RelatedCopyHandle(fn_80260868(lbl_801E9D24.dispatcher,name,0)));
} typedef char RelatedHandleSize[(sizeof(RelatedHandle)==4&&sizeof(RelatedReturnedHandle)==4)?1:-1];
typedef char RelatedEntrySize[sizeof(RelatedEntry)==16?1:-1];
typedef char RelatedArraySize[sizeof(RelatedHandleArray)==12?1:-1];
