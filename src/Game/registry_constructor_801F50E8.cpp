/* auto_03_801F50E8_text (s4), constructor-only split 0x801F50E8..0x801F551C. fn_801F50E8 -> __ct__17Registry_801F50E8Fv is
 * EXACT as the real C++ constructor Registry_801F50E8::Registry_801F50E8()
 * (flags of registry_destructor.cpp: -O4,p, -Cpp_exceptions off, -bool off).
 * fn_801F551C (Pool<HandleArray> dtor) 98.99%: the original has a second
 * `beq` on the element this-check CR (add.; beq; beq) that every nested /
 * explicit-check spelling turns into a separate cmplwi.
 * fn_801F56A8 (RegistryBase dtor) 99.40%: i / word-offset volatile registers
 * (r7/r5) swapped in the two leaf Pool<u32> loops.
 * The original header comment of the session-2 file follows. */
/* Variant of final.cpp in which fn_801F50E8 is written as the real C++
 * constructor Registry_801F50E8::Registry_801F50E8() (mangled
 * __ct__17Registry_801F50E8Fv). Its code and relocations are identical to
 * the original (objdiff 100% after renaming the symbol to fn_801F50E8):
 * the inlined base constructor of a class with destructible members keeps
 * the two `this` copies (mr r6,r28; mr r29,r6) that no extern "C" function
 * reproduces. Using it requires renaming fn_801F50E8 in symbols.txt.
 * The vtable stores stay on the existing labels: the root member's
 * constructor stores the base vtable before calling fn_80208830 (the
 * original vptr-before-members order) and the first derived array's
 * constructor stores the derived vtable before its own fields.
 * fn_801F551C / fn_801F56A8 are unchanged from final.cpp. */
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[],lbl_801EF5C8[];
extern const char lbl_802EAA80[],lbl_802EAA98[];
extern const char lbl_802AD4F8[],lbl_802AD504[];
extern const char lbl_8037A768[5];
extern const char lbl_8037A770[7];
extern const char lbl_8037A778[7];
extern const char lbl_8037A780[7];
extern const char lbl_8037A788[7];
extern const char lbl_8037A790[7];
extern const char lbl_8037A798[6];
extern const char lbl_8037A7A0[4];
extern const char lbl_8037A7A4[5];
extern const char lbl_8037A7AC[5];
extern const char lbl_8037A7B4[7];
extern const char lbl_8037A7BC[5];
extern const char lbl_8037A7C4[6];
extern const char lbl_8037A7CC[5];
extern const char lbl_8037A7D4[6];
extern const char lbl_8037A7DC[7];
extern const char lbl_8037A7E4[6];
extern const char lbl_8037A7EC[6];
extern const char lbl_8037A7F4[5];
void fn_8028FD50(void*,void*,u32);
void fn_801EF610(void*,void*);
void fn_80208768(void*,short);
void fn_80208830(void*,int);
u32 fn_801F948C(void*,const char*);
void fn_80287CA8(void*);
int sprintf(char*,const char*,...);
}
struct Name { u32 value; Name(const char*text){value=fn_801F948C(this,text);} };
struct Handle_801F7F10 {
    u32 value;
    ~Handle_801F7F10();
};
struct HandleZero:Handle_801F7F10 {};
struct HandleRef:HandleZero {};
struct WordArray {
    int count,capacity; u32*data;
};
struct BitSet_80207EE8:WordArray {
    int bits;
    BitSet_80207EE8();
    ~BitSet_80207EE8();
    const u32& word(int i) const { u32* base=data; return base[i]; }
    signed char test(int index) const { if (word(index >> 5) & (1UL << (index & 31))) return 1; return 0; }
};
template<class T>struct Array {
    int size,capacity;T*data;
    void releaseStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
    ~Array(){if(data){for(int i=0;i<size;++i)data[i].~T();releaseStorage();data=0;}}
};
template<class T>struct Storage {
    int size,capacity;T*data;
    void releaseStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
    ~Storage(){if(data){releaseStorage();data=0;}}
};
struct HandleArray {
    int size,capacity;HandleRef*data;int extra[2];
    void releaseStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(HandleRef));data=0;}}
    ~HandleArray(){if(data){for(int i=0;i<size;++i)data[i].~HandleRef();releaseStorage();data=0;}}
};
struct HashTable {int cursor,capacity,count;void**slots;};
template<class T>struct Pool:Storage<T> {
    BitSet_80207EE8 flags;int limit,count;
    void erase(int index){
        if(flags.test(index)){
            destroyAt(index);
            flags.data[index>>5]=flags.data[index>>5]&~(1UL<<(index&31));
            --count;
        }
    }
    void destroyAt(int index){this->data[static_cast<unsigned int>(index)].~T();}
    ~Pool(){for(int i=0;i<limit;++i)erase(i);}
};
template<>inline void Pool<u32>::destroyAt(int){}
template<>inline void Pool<HashTable>::destroyAt(int index){fn_80208768(&this->data[static_cast<unsigned int>(index)],-1);}
struct RegistryBase {
    HashTable root;Pool<u32>first,second;Pool<HashTable>tables;const void*vtable;
};
/* Constructor-side class views (destructors declared, defined elsewhere). */
template<class T>struct ArrayC { int size,capacity;T*data; ArrayC():size(0),capacity(0),data(0){} };
template<class T>struct StorageC { int size,capacity;T*data; StorageC():size(0),capacity(0),data(0){} };
template<class T>struct PoolC:StorageC<T> { BitSet_80207EE8 flags;int limit,count; PoolC():limit(0),count(0){} ~PoolC(); };
struct RegistryRoot { int cursor,capacity,count;void**slots;
    RegistryRoot(const void*vtable,int size){((const void**)this)[0x7c/4]=vtable;fn_80208830(this,size);} };
struct RegistryValues { int size,capacity;u32*data;
    RegistryValues(const void*vtable){((const void**)this)[-1]=vtable;size=0;capacity=0;data=0;} };
struct RegistryBaseC {
    RegistryRoot root;PoolC<u32>first,second;PoolC<HashTable>tables;const void*vtable;
    RegistryBaseC():root(lbl_802EAA98,0x40){}
    ~RegistryBaseC();
};
struct Registry_801F50E8;
extern "C" {
void fn_801F4BEC(Registry_801F50E8*,const Name*,int);
void fn_801F4728(Registry_801F50E8*,const Name*,int);
}
struct Registry_801F50E8:RegistryBaseC {
    RegistryValues values;ArrayC<int>valueIndex;ArrayC<u32>keys;ArrayC<int>keyIndex;
    PoolC<HandleArray>handleArrays;
    Registry_801F50E8();
    void add(const char*name,int index){Name n(name);fn_801F4BEC(this,&n,index);}
    void addSkin(const char*name,int index){Name n(name);fn_801F4728(this,&n,index);}
};
Registry_801F50E8::Registry_801F50E8():values(lbl_802EAA80)
{
    add(lbl_8037A768,0);
    add(lbl_8037A770,1);
    add(lbl_8037A778,2);
    add(lbl_8037A780,3);
    add(lbl_8037A788,4);
    add(lbl_8037A790,5);
    add(lbl_8037A798,6);
    add(lbl_8037A7A0,7);
    add(lbl_8037A7A4,8);
    add(lbl_8037A7AC,9);
    add(lbl_8037A7B4,11);
    add(lbl_8037A7BC,10);
    char buffer[128];
    int i;
    for(i=0;i<16;++i){sprintf(buffer,lbl_8037A7C4,i);add(buffer,i+12);}
    for(i=0;i<16;++i){
        sprintf(buffer,lbl_802AD4F8,i+1);add(buffer,i+0x1c);
        sprintf(buffer,lbl_802AD504,i+1);add(buffer,i+0x2c);
    }
    addSkin(lbl_8037A7CC,0);
    addSkin(lbl_8037A7D4,1);
    addSkin(lbl_8037A7DC,2);
    addSkin(lbl_8037A7E4,3);
    addSkin(lbl_8037A7EC,4);
    addSkin(lbl_8037A7F4,5);
    fn_80287CA8(this);
}
