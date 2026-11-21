/* Original engine type registry and lookup routines.
 * See docs/notes/game-engine-registry.md. */
extern "C" unsigned long fn_801F948C(void *,const char *);
struct Key_801B51BC  {
    unsigned int value;
    Key_801B51BC(const char *name) {
        value=fn_801F948C(this,name);
    }
    bool operator==(const Key_801B51BC&other)const {
        return value==other.value;
    }
};
struct Record_801B51BC  {
    Key_801B51BC key,parent;
    void *factory;
    unsigned short references,pad;
};
struct Table_801B51BC  {
    char pad[0x28];
    int count,capacity;
    Record_801B51BC *records;
    Record_801B51BC &operator[](int index) {
        return records[index];
    }
    int find(const Key_801B51BC&key) {
        int i;
        for(i=0;i<count;++i)if(records[i].key==key)return i;
        return -1;
    }
};
extern "C" int fn_801B51BC(Table_801B51BC *table,const char *text) {
    Key_801B51BC key(text);
    return table->find(key);
}
