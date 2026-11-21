/* Original engine registry and handle stream routines.
 * See docs/notes/game-engine-handle-stream.md. */
typedef unsigned int u32;
extern "C" {
    extern char lbl_8028F698[];
    void*fn_8028FAF4(void*,void*,int,int);
    void*fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void*fn_801E9F40(void*,const void*,int);
    void fn_80208BFC(void*,int);
    signed char fn_802082E8(void*,void*,void*);
    void fn_801F7CB4(void*,const void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void*fn_801F7EB8(void*);
}
inline void*operator new(unsigned long,void*p) {
    return p;
}
struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct CopyHandle_801B4634 {
    u32 word;
    CopyHandle_801B4634(const Handle_801F7F10&h) {
        fn_801F7CB4(this,&h);
    }
    CopyHandle_801B4634(const CopyHandle_801B4634&h) {
        fn_801F7CB4(this,&h);
    }
    ~CopyHandle_801B4634() {
        __dt__15Handle_801F7F10Fv(this,-1);
    }
};
struct Stream_801B4634 {
    void*current;
    void read(void*p,int n) {
        current=fn_801E9F40(p,current,n);
    }
};
struct RegistryKey_801B4634 {
    u32 words[3];
    RegistryKey_801B4634(int n) {
        fn_80208BFC(this,n);
    }
};
struct Entry_801B4634 {
    void*object;
    char unknown4[12];
};
struct HandleArray_801B4634 {
    int count,capacity;
    CopyHandle_801B4634*data;
    void reserveMore(int n) {
        if(capacity+n) {
            if(data)data=(CopyHandle_801B4634*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(CopyHandle_801B4634),(capacity+n)*sizeof(CopyHandle_801B4634));
            else data=(CopyHandle_801B4634*)fn_8028FF24(lbl_8028F698,(capacity+n)*sizeof(CopyHandle_801B4634));
        }
        else if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(CopyHandle_801B4634));
            data=0;
        }
        capacity+=n;
    }
    void append(const CopyHandle_801B4634&h) {
        if(count+1>capacity)reserveMore(32);
        new(&data[count++])CopyHandle_801B4634(h);
    }
};
struct Owner_801B4634 {
    int count,capacity;
    Entry_801B4634*entries;
    char unknownC[0xB8-0xC];
    HandleArray_801B4634 handles;
    void*registry;
};
struct ObjectStorage_801B4634 {
    char unknown[8];
};
struct Object_801B4634:ObjectStorage_801B4634 {
    virtual void slot08();
    virtual void slot0C(Stream_801B4634*);
};
extern "C" Handle_801F7F10 fn_801B550C(Owner_801B4634*,u32*,u32*);
extern "C" void fn_801B4634(Owner_801B4634*self,Stream_801B4634*stream) {
    u32 first=0,second=0;
    u32 size;
    stream->read(&size,4);
    stream->read(&first,4);
    stream->read(&second,4);
    RegistryKey_801B4634 key(second);
    int*entry;
    if(fn_802082E8(self->registry,&key,&entry)&&self->entries[*entry].object) {
        stream->current=(char*)stream->current+size-12;
    }
    else {
        CopyHandle_801B4634 handle(fn_801B550C(self,&first,&second));
        Object_801B4634*object=(Object_801B4634*)fn_801F7EB8(&handle);
        object->slot0C(stream);
        self->handles.append(handle);
    }
}
