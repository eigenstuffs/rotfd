/* Game indexed value registries, reconstructed from GSQE78. */
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[];
void *fn_8028FAF4(void*,void*,u32,u32);
void *fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
}
inline void *operator new(unsigned long,void *p){return p;}
struct RegistryValue {
    u32 value;
    RegistryValue(){}
    RegistryValue(const RegistryValue &other):value(other.value){}
    int operator==(const RegistryValue &other) const{return value==other.value;}
};
template<class T> struct RegistryArray {
    int size,capacity;
    T *data;
    void storage(int count){
        if(count){
            if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),count*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,count*sizeof(T));
        } else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}
    }
    void resize(int count){
        if(count>size){
            storage(count);capacity=count;
            for(int i=size;i<count;++i)new(data+i) T;
            size=count;
        } else if(count<size){
            for(int i=size-1;i>=count;--i)data[i].~T();
            storage(count);capacity=count;size=count;
        }
    }
    int intern(const T &value){
        for(int i=0;i<size;++i)if(data[i]==value)return i;
        if(size+1>capacity){storage(capacity+32);capacity+=32;}
        new(data+size++) T(value);
        return size-1;
    }
    T &at(int i){if(i>=size)resize(i+1);return data[i];}
};
struct GameRegistry {
    char unknown[0x80];
    RegistryArray<RegistryValue> first;
    RegistryArray<int> firstIndex;
    RegistryArray<RegistryValue> second;
    RegistryArray<int> secondIndex;
};
extern "C" {
void fn_801F4728(GameRegistry *r,const RegistryValue *v,long index)
{
    if(r->secondIndex.size<=index)r->secondIndex.resize(index+1);
    int &slot=r->secondIndex.data[index];
    slot=r->second.intern(*v);
}
void fn_801F49B8(GameRegistry *r,const RegistryValue *v){r->second.intern(*v);}
int fn_801F4AC8(GameRegistry *r,const RegistryValue *v){
        for(int i=0;i<r->second.size;++i)if(r->second.data[i]==*v)return i;
        if(r->second.size+1>r->second.capacity){r->second.storage(r->second.capacity+32);r->second.capacity+=32;}
        new(r->second.data+r->second.size++) RegistryValue(*v);
        return r->second.size-1;
}

void fn_801F4BEC(GameRegistry *r,const RegistryValue *v,long index)
{
    if(r->firstIndex.size<=index)r->firstIndex.resize(index+1);
    r->firstIndex.data[index]=r->first.intern(*v);
}
void fn_801F4E7C(GameRegistry *r,const RegistryValue *v){r->first.intern(*v);}
int fn_801F4F8C(GameRegistry *r,const RegistryValue *v){
        for(int i=0;i<r->first.size;++i)if(r->first.data[i]==*v)return i;
        if(r->first.size+1>r->first.capacity){r->first.storage(r->first.capacity+32);r->first.capacity+=32;}
        new(r->first.data+r->first.size++) RegistryValue(*v);
        return r->first.size-1;
}

}
