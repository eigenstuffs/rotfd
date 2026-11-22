struct Key_801B550C  {
    unsigned int value;
    bool operator==(const Key_801B550C&other)const {
        return value==other.value;
    }
};
struct Record_801B550C  {
    Key_801B550C key,parent;
    void *(*factory)();
    unsigned short references,pad;
};
struct Table_801B550C  {
    char pad[0x28];
    int count,capacity;
    Record_801B550C *records;
    Record_801B550C&operator[](int index) {
        return records[index];
    }
};
struct Handle_801B550C  {
    signed int tag:8;
    signed int index:24;
    Handle_801B550C() {
        index=0;
        tag=0;
    }
};
extern "C" Handle_801B550C fn_801F9144(Table_801B550C*,void *,const Key_801B550C&,short);
extern "C" Handle_801B550C fn_801B550C(Table_801B550C *table,const Key_801B550C&key,const Key_801B550C&name) {
    short i;
    for(i=0;i<table->count;++i) {
        if((*table)[i].key==key) {
            Record_801B550C&record=(*table)[i];
            ++record.references;
            return fn_801F9144(table,(*table)[i].factory(),name,i);
        }
    }
    return Handle_801B550C();
}
