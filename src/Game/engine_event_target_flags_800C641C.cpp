typedef unsigned long u32;typedef unsigned long long u64;
struct Handle{union{u32 word;struct{signed int tag:8,index:24;}bits;};};
struct Target{char opaque00[0x30];u64 flags30;bool hasFlag(u64 mask)const{return(flags30&mask)!=0;}};
struct Entry{Target*object;u32 opaque04,opaque08;signed char generation;char opaque0D[3];};
struct Manager{char opaque00[8];Entry*entries;};
extern "C" struct Global{char opaque00[0x118];Manager*manager118;}lbl_801E9D24;
struct Actor{char opaque000[0x318];};
struct Owner{char opaque00[0x70];Handle handle70;char opaque74[0x2C];Actor*actorA0;};
extern "C" signed char fn_8025E9FC(Owner*,int);
extern "C" signed char fn_8007D604(void*,int);
extern "C" void fn_8007D6A0(void*,int);
inline Target*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.tag?e->object:0;}
inline Target*resolveWrite(const Handle&h){struct WriteHandleView{union{u32 word;struct{signed int tag:8,index:24;}bits;};};struct ByteRegistryView{char opaque00[8];char*entries;};const WriteHandleView&view=(const WriteHandleView&)h;Entry*e=(Entry*)(((ByteRegistryView*)lbl_801E9D24.manager118)->entries+view.bits.index*16);return e->generation==view.bits.tag?e->object:0;}
extern "C" void fn_800C641C(Owner*self){
    if(fn_8025E9FC(self,0x83)){
        if(!resolve(self->handle70)->hasFlag(0x1000000000000000ULL)){
            if(!fn_8007D604((char*)self->actorA0+0x318,2))fn_8007D6A0((char*)self->actorA0+0x318,1);
            resolveWrite(self->handle70)->flags30|=0x1000000000000000ULL;
        }
    }else if(resolve(self->handle70)->hasFlag(0x1000000000000000ULL))
        resolveWrite(self->handle70)->flags30&=~0x1000000000000000ULL;
    if(fn_8025E9FC(self,0x8d))fn_8007D6A0((char*)self->actorA0+0x318,2);
}
