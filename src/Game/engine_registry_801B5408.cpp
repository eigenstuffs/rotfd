extern "C" unsigned int fn_801F948C(void *,const char *);
struct Key_801B5408  {
    unsigned int value;
    Key_801B5408(const char *text) {
        value=fn_801F948C(this,text);
    }
    bool operator==(const Key_801B5408&other)const {
        return value==other.value;
    }
};
struct Record_801B5408  {
    Key_801B5408 key,parent;
    void *(*factory)();
    unsigned short references,pad;
};
struct Table_801B5408  {
    char pad[0x28];
    int count,capacity;
    Record_801B5408 *records;
    Record_801B5408&operator[](int index) {
        return records[index];
    }
};
struct Handle_801B5408  {
    signed int tag:8;
    signed int index:24;
    Handle_801B5408() {
        index=0;
        tag=0;
    }
};
extern "C" Handle_801B5408 fn_801F9144(Table_801B5408*,void *,const Key_801B5408&,short);
extern "C" int sprintf(char *,const char *,...);
extern "C" const char lbl_802AC964[];
extern "C" Handle_801B5408 fn_801B5408(Table_801B5408 *table,const Key_801B5408&key) {
    short i;
    for(i=0;i<table->count;++i) {
        if((*table)[i].key==key) {
            char text[128];
            {
                Record_801B5408&entry=(*table)[i];
                sprintf(text,lbl_802AC964,entry.references);
            }
            ++(*table)[i].references;
            Key_801B5408 name(text);
            return fn_801F9144(table,(*table)[i].factory(),name,i);
        }
    }
    return Handle_801B5408();
}
