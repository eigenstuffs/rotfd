struct Handle_801F7F10{union{unsigned long value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct LookupEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct LookupManager{char unknown00[8];LookupEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];LookupManager*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);unsigned long fn_801F7EB8(const void*);}
inline char*resolveLookupHandle(const Handle_801F7F10&h){int index=h.bits.index;LookupManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return m->entries[index].object;return 0;}
struct LookupZero1:Handle_801F7F10{LookupZero1(){value=0;}};struct LookupZero2:LookupZero1{LookupZero2(){value=0;}};struct LookupCopy1:LookupZero1{LookupCopy1(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
struct LookupArray{int count;int capacity;Handle_801F7F10*data;};
struct LookupSelf{LookupArray first;LookupArray second;};
extern "C" LookupCopy1 fn_8026420C(char*,const unsigned long*);
inline void assignLookupHandle(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
extern "C" LookupCopy1 fn_80263308(LookupSelf*self,const unsigned long*key){
    LookupZero2 handle;
    int i;
    for(i=0;i<self->second.count;++i){
        assignLookupHandle(handle,fn_8026420C(resolveLookupHandle(self->second.data[i]),key));
        if(fn_801F7EB8(&handle))return LookupCopy1(handle);
    }
    for(i=0;i<self->first.count;++i){
        assignLookupHandle(handle,fn_8026420C(resolveLookupHandle(self->first.data[i]),key));
        if(fn_801F7EB8(&handle))break;
    }
    return LookupCopy1(handle);
}
