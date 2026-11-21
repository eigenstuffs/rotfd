/* Registry pair removal (fn_801F5CA4), GSQE78. Same RegistryBase/Pool layout
 * and flags as src/Game/registry_lookup.cpp and registry_cleanup.cpp.
 * Finds the pair slot with fn_801F5F28 (no create), and if the table slot is
 * occupied clears its hash table (fn_802086C8(..,1)), then erases the slot
 * from the first, second and table pools (bit clear + count decrement; the
 * table element is destroyed through fn_80208768(..,-1)).
 * The occupancy test is an if/return 1/return 0 helper over a const-ref word
 * accessor (as in sparse_handle_erase.cpp): it stays normalized in the range
 * check and the first erase and folds to `and.` once the bit/word offset are
 * CSE temps. Erase indexes the element with static_cast<unsigned int>, which
 * keeps the original separate i*16. The removal is an inline method taking
 * the found index by value (keeps i in r31). */
typedef unsigned long u32;
struct HashTable {
    int cursor,capacity,count; void**slots;
};
extern "C" {
void fn_802086C8(HashTable*,int);
void fn_80208768(HashTable*,short);
}
struct BitFlags {
    int size,capacity; u32*words; int bits;
    const u32& word(int i) const { u32* base=words; return base[i]; }
    signed char test(int index) const { if (word(index >> 5) & (1UL << (index & 31))) return 1; return 0; }
};
inline void destroy(u32*){}
inline void destroy(HashTable*t){fn_80208768(t,-1);}
template<class T>struct Pool {
    int size,capacity;T*data;BitFlags flags;int limit,count;
    signed char exists(int i){if(i<0||i>=limit)return 0;return flags.test(i);}
    void erase(int index){
        if(flags.test(index)){
            destroy(&data[static_cast<unsigned int>(index)]);
            flags.words[index>>5]&=~(1UL<<(index&31));
            --count;
        }
    }
};
struct RegistryBase {HashTable root;Pool<u32>first,second;Pool<HashTable>tables;const void*vtable;
 void removeAt(int i){
  if(tables.exists(i)){
   fn_802086C8(&tables.data[i],1);
   first.erase(i);
   second.erase(i);
   tables.erase(i);
  }
 }
};
extern "C" {
char fn_801F5F28(RegistryBase*,const u32*,const u32*,long*,char);
void fn_801F5CA4(RegistryBase*r,const u32*a,const u32*b){
 long index;
 if(fn_801F5F28(r,a,b,&index,0))r->removeAt(index);
}
}
