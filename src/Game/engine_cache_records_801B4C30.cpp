/* Original engine normalized string lookup.
 * See docs/notes/game-engine-cache-records.md. */
typedef unsigned int u32;
struct Bitset_801B4C30 {
    int count,capacity;
    u32*words;
    int size;
};
extern "C" {
    char*strcpy(char*,const char*);
    int strcmp(const char*,const char*);
    void fn_801F459C(char*);
    int fn_80207B94(Bitset_801B4C30*,int,int);
    int fn_801B4D14(void*);
}
struct Pool_801B4C30 {
    int count,capacity;
    char(*data)[129];
    Bitset_801B4C30 bits;
    int limit,used;
    int first() {
        return limit==0?-1:fn_80207B94(&bits,1,0);
    }
    int next(int previous) {
        int n=previous+1;
        return n>=limit?-1:fn_80207B94(&bits,1,n);
    }
};
struct Owner_801B4C30 {
    char unknown[0xCC];
    Pool_801B4C30 pool;
};
extern "C" int fn_801B4C30(Owner_801B4C30*self,const char*name) {
    char normalized[128];
    strcpy(normalized,name);
    fn_801F459C(normalized);
    int i=self->pool.first();
    while(i>=0) {
        if(strcmp(normalized,self->pool.data[i])==0)return i;
        i=i+1>=self->pool.limit?-1:fn_80207B94(&self->pool.bits,1,i+1);
    }
    i=fn_801B4D14(&self->pool);
    strcpy(self->pool.data[i],normalized);
    return i;
}
