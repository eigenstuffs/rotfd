#include "Game/record_handle_stream_read_801D2538.h"

/* Partial serialized owner views; all storage and native Handle identities remain external. */
typedef unsigned long Read2538Word;
struct Handle_801F7F10 {
    union { Read2538Word value; struct { signed int tag:8; signed int index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Read2538Node;
struct Read2538Entry { Read2538Node* object; Read2538Word unused[2]; signed char tag; char tail[3]; };
struct Read2538Manager { char unknown[8]; Read2538Entry* entries; };
struct Read2538Globals { char unknown[0x118]; Read2538Manager* manager; };
struct Read2538Name { Read2538Word value; Read2538Name(const char*); };
extern "C" {
extern Read2538Globals lbl_801E9D24;
extern char lbl_8028F698[];
extern const char lbl_8037A470[5];
void fn_80243DE4(void*,RecordHandleStream*);
void* fn_801E9F40(void*,const void*,int);
Read2538Word fn_801F948C(void*,const char*);
Handle_801F7F10 fn_801B550C(Read2538Manager*,const Read2538Name&,const Read2538Word&);
void fn_801F86C8(Read2538Manager*,const void*,short);
void fn_801B41F4(Read2538Manager*,Read2538Word*,RecordHandleStream*);
void fn_801B41B8(Read2538Manager*,Handle_801F7F10*,RecordHandleStream*);
void fn_801B3FD0(Read2538Manager*,Handle_801F7F10*,RecordHandleStream*);
void fn_801B3D80(Read2538Manager*,Handle_801F7F10*,const void*);
void fn_80025954(void*,int,signed char);
void fn_801D3088(void*,int,signed char);
void* fn_8028FAF4(void*,void*,Read2538Word,Read2538Word);
void* fn_8028FF24(void*,Read2538Word);
void fn_8028FD50(void*,void*,Read2538Word);
}
inline Read2538Name::Read2538Name(const char*s) { value=fn_801F948C(this,s); }
inline void* operator new(Read2538Word,void*p) { return p; }
struct Read2538Zero:Handle_801F7F10 {
    Read2538Zero() { value=0; }
    ~Read2538Zero() {}
};
struct Read2538Copy:Read2538Zero {
    Read2538Copy(const Handle_801F7F10& h) { value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1); }
    ~Read2538Copy() {}
};
struct Read2538Value:Read2538Zero {
    Read2538Value() { value=0; }
    ~Read2538Value() {}
    Read2538Value& operator=(const Read2538Copy&h) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=h.value;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
        return *this;
    }
};
struct Read2538Third:Read2538Value {Read2538Third(){value=0;}~Read2538Third(){}};
struct Read2538Cell {Read2538Word value;Read2538Cell(){}~Read2538Cell(){}};
template<class T> struct Read2538Array {
    int count,capacity;T* data;
    T& operator[](int i){return data[i];}
    void reserve(int n) {
        if(n) {
            if(data) data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
        } else if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;
        }
        capacity=n;
    }
    /* Native count parameter is a signed 32-bit long; serialized counts are int. */
    void resize(long n) {
        int i;
        if(n>count) {
            reserve(n);
            for(i=count;i<n;i++) new(data+i)T;
            count=n;
        } else if(n<count) {
            for(i=count-1;i>=n;i--) data[i].~T();
            reserve(n);count=n;
        }
    }
};
struct Read2538Record {Read2538Word key;Handle_801F7F10 handle;char payload[16];};
struct Read2538Node {
    char unknown00[0xC];Handle_801F7F10 h0C,h10,h14,h18;
    char unknown1C[0x10];Handle_801F7F10 h2C;
    char raw30[36],raw54[36],raw78[64];
    char rawB8[32],rawD8[12];
    char unknownE4[0x40];void* buffer;
};
struct RecordHandleStreamOwner {
    char unknown00[0x20];Read2538Array<Read2538Value> first;
    Handle_801F7F10 handle2C;Read2538Array<Read2538Value> second;
    char unknown3C[4];Read2538Array<Read2538Record> a,b,c;Read2538Array<Read2538Third> third;
    Read2538Array<Read2538Array<Read2538Cell> > nested;
};
inline Read2538Node* read2538Resolve(const Handle_801F7F10&h) {
    Read2538Entry*e=lbl_801E9D24.manager->entries+h.bits.index;
    return e->tag==h.bits.tag ? e->object : 0;
}
extern "C" void fn_801D2538(RecordHandleStreamOwner*self,RecordHandleStream*stream) {
    fn_80243DE4(self,stream);
    int count;
    int i;
    stream->position=fn_801E9F40(&count,stream->position,4);
    self->first.resize(count);
    Read2538Word key=0;
    for(i=0;i<count;i++) {
        fn_801B41F4(lbl_801E9D24.manager,&key,stream);
        self->first[i]=Read2538Copy(fn_801B550C(lbl_801E9D24.manager,Read2538Name(lbl_8037A470),key));
        Read2538Node*node=read2538Resolve(self->first[i]);
        fn_801B41B8(lbl_801E9D24.manager,&node->h0C,stream);
        fn_801B41B8(lbl_801E9D24.manager,&node->h10,stream);
        fn_801B41B8(lbl_801E9D24.manager,&node->h18,stream);
        fn_801B41B8(lbl_801E9D24.manager,&node->h14,stream);
        fn_801B3FD0(lbl_801E9D24.manager,&node->h2C,stream);
        stream->position=fn_801E9F40(node->rawB8,stream->position,(Read2538Word)node->rawD8-(Read2538Word)node->rawB8+12);
        stream->position=fn_801E9F40(node->raw30,stream->position,sizeof(node->raw30));
        stream->position=fn_801E9F40(node->raw54,stream->position,sizeof(node->raw54));
        stream->position=fn_801E9F40(node->raw78,stream->position,sizeof(node->raw78));
        stream->position=fn_801E9F40(node->buffer,stream->position,64);
    }
    for(i=0;i<count;i++) {
        Read2538Node*node=read2538Resolve(self->first[i]);
        fn_801B3D80(lbl_801E9D24.manager,&node->h0C,&self->first);
        fn_801B3D80(lbl_801E9D24.manager,&node->h10,&self->first);
        fn_801B3D80(lbl_801E9D24.manager,&node->h18,&self->first);
        fn_801B3D80(lbl_801E9D24.manager,&node->h14,&self->first);
    }
    fn_801B41B8(lbl_801E9D24.manager,&self->handle2C,stream);
    fn_801B3D80(lbl_801E9D24.manager,&self->handle2C,&self->first);
    stream->position=fn_801E9F40(&count,stream->position,4);
    self->second.resize(count);
    for(i=0;i<count;i++) fn_801B3FD0(lbl_801E9D24.manager,&self->second[i],stream);
    stream->position=fn_801E9F40(&count,stream->position,4);
    fn_80025954(&self->a,count,0);
    for(i=0;i<self->a.count;i++) {
        stream->position=fn_801E9F40(self->a.data[i].payload,stream->position,16);
        fn_801B41B8(lbl_801E9D24.manager,&self->a.data[i].handle,stream);
        fn_801B41F4(lbl_801E9D24.manager,&self->a.data[i].key,stream);
    }
    stream->position=fn_801E9F40(&count,stream->position,4);
    fn_80025954(&self->b,count,0);
    for(i=0;i<self->b.count;i++) {
        stream->position=fn_801E9F40(self->b.data[i].payload,stream->position,16);
        fn_801B41B8(lbl_801E9D24.manager,&self->b.data[i].handle,stream);
        fn_801B41F4(lbl_801E9D24.manager,&self->b.data[i].key,stream);
    }
    stream->position=fn_801E9F40(&count,stream->position,4);
    fn_80025954(&self->c,count,0);
    for(i=0;i<self->c.count;i++) {
        stream->position=fn_801E9F40(self->c.data[i].payload,stream->position,16);
        fn_801B41B8(lbl_801E9D24.manager,&self->c.data[i].handle,stream);
        fn_801B41F4(lbl_801E9D24.manager,&self->c.data[i].key,stream);
    }
    stream->position=fn_801E9F40(&count,stream->position,4);
    self->third.resize(count);
    for(i=0;i<count;i++) fn_801B3FD0(lbl_801E9D24.manager,&self->third[i],stream);
    fn_801D3088(&self->nested,count,0);
    for(i=0;i<count;i++) {
        int n;
        stream->position=fn_801E9F40(&n,stream->position,4);
        Read2538Array<Read2538Cell>&row=self->nested[i];
        row.resize(n);
        stream->position=fn_801E9F40(self->nested[i].data,stream->position,n*sizeof(Read2538Cell));
    }
}

typedef char Read2538NativeCountABI[(sizeof(long)==4 && sizeof(int)==4)?1:-1];
