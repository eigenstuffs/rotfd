// Native queue Handle selector; borrowed receiver views preserve original constructors.
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct {
            signed int tag:8,index:24;
        }
        bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" unsigned long fn_801F948C(void*,const char*);
struct QueueBindName {
    unsigned long value;
    QueueBindName(const char*text) {
        value=fn_801F948C(this,text);
    }
};
struct QueueBindOwner {
    QueueBindName name;
    char unknown04[0x1EC];
    Handle_801F7F10 first,second,third;
};
struct QueueSelectObject {
    char unknown00[0x1C];
    Handle_801F7F10 owner,related;
    char unknown24[4];
    Handle_801F7F10 *source;
    char unknown2C[0x40];
    unsigned short type;
    char unknown6E[0x5A];
    Handle_801F7F10 *delegates;
};
struct QueueSelectIndex {
    const int value;
    QueueSelectIndex(int v):value(v) {
    }
    operator int()const {
        return value;
    }
};
struct QueueSelectEntry {
    QueueSelectObject*object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char t)const {
        return tag==t;
    }
    QueueSelectObject*getObject()const {
        return object;
    }
};
struct QueueSelectEntries {
    QueueSelectEntry*p;
    QueueSelectEntry&operator[](const QueueSelectIndex&i)const {
        return p[i];
    }
};
struct QueueSelectManager {
    int count,capacity;
    QueueSelectEntries entries;
};
extern "C" {
    extern struct QueueSelectContext {
        char unknown00[0x118];
        QueueSelectManager *manager;
    } lbl_801E9D24;
    void fn_801F86C8(QueueSelectManager*,const Handle_801F7F10*,short);
    QueueSelectObject*fn_801F7EB8(const Handle_801F7F10*);
    void fn_802326F4(QueueBindOwner*,const Handle_801F7F10*);
} struct QueueSelectZero : Handle_801F7F10 {
    QueueSelectZero() {
        value=0;
    }
};
struct QueueSelectZero2 : QueueSelectZero {
    QueueSelectZero2() {
        value=0;
    }
};
struct QueueSelectZero3 : QueueSelectZero2 {
    QueueSelectZero3() {
        value=0;
    }
};
struct QueueSelectCopy : QueueSelectZero2 {
    QueueSelectCopy(const Handle_801F7F10 &source) {
        value=source.value;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
};
static inline QueueSelectObject*resolve(const Handle_801F7F10&h) {
    QueueSelectManager*m=lbl_801E9D24.manager;
    const QueueSelectIndex index(h.bits.index);
    const signed char tag(h.bits.tag);
    if(m->entries[index].matchesTag(tag))return m->entries[index].getObject();
    return 0;
} static inline void assign(Handle_801F7F10 &out,const Handle_801F7F10 &input) {
    fn_801F86C8(lbl_801E9D24.manager,&out,-1);
    out.value=input.value;
    fn_801F86C8(lbl_801E9D24.manager,&input,1);
} extern "C" signed char fn_80232458(QueueBindOwner*self) {
    QueueSelectObject *target=resolve(self->second);
    QueueSelectZero3 selected;
    QueueSelectObject *related=resolve(target->owner);
    int type=related->type;
    if(type==5) {
        if(resolve(*related->delegates)->type==3) {
            const Handle_801F7F10 *source=resolve(target->related)->source;
            assign(selected,QueueSelectCopy(*source));
        }
    } else if(type==3) {
        const Handle_801F7F10 &source=target->related;
        assign(selected,QueueSelectCopy(source));
    } else return 0;
    if(!fn_801F7EB8(&selected))return 0;
    fn_802326F4(self,&selected);
    return 1;
} typedef char QueueSelectHandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char QueueSelectOwnerSize[(sizeof(QueueBindOwner)==0x1FC)?1:-1];
typedef char QueueSelectEntrySize[(sizeof(QueueSelectEntry)==16)?1:-1];
