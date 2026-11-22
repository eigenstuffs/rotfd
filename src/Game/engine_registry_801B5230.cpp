extern "C" unsigned long fn_801F948C(void *,const char *);
struct Key_801B5230  {
    unsigned int value;
    Key_801B5230(const char *name) {
        value=fn_801F948C(this,name);
    }
    bool operator==(const Key_801B5230&other)const {
        return value==other.value;
    }
};
struct Record_801B5230  {
    Key_801B5230 key,parent;
    void *factory;
    unsigned short references,pad;
};
struct Table_801B5230  {
    char pad[0x28];
    int count,capacity;
    Record_801B5230 *records;
    Record_801B5230 &operator[](int index) {
        return records[index];
    }
    int find(const Key_801B5230&key) {
        int i;
        for(i=0;i<count;++i)if(records[i].key==key)return i;
        return -1;
    }
};
extern "C" int fn_801B5230(Table_801B5230 *table,const Key_801B5230&key,const Key_801B5230&parent) {
    int index=table->find(key);
    while(index>0) {
        if((*table)[index].parent==parent)return 1;
        index=table->find((*table)[index].parent);
    }
    return 0;
}
