/* Original engine type registry and lookup routines.
 * See docs/notes/game-engine-registry.md. */
extern "C" int fn_80207B94(void *,int,int);
struct Record_801B57F8  {
    char data[128];
    char active;
};
struct Table_801B57F8  {
    char pad[0xd4];
    Record_801B57F8 *records;
    char bitset[16];
    int limit;
    int first() {
        if(limit==0)return -1;
        return fn_80207B94(bitset,1,0);
    }
    int next(int index) {
        ++index;
        if(index>=limit)return -1;
        return fn_80207B94(bitset,1,index);
    }
    Record_801B57F8 &operator[](int index) {
        return records[index];
    }
};
extern "C" void fn_801B57F8(Table_801B57F8 *table) {
    int index=table->first();
    while(index>=0) {
        (*table)[index].active=0;
        index=table->next(index);
    }
}
