extern "C" unsigned int fn_801F948C(void *,const char *);
struct Key_801B52EC  {
    unsigned int value;
    Key_801B52EC(const char *text) {
        value=fn_801F948C(this,text);
    }
    bool operator==(const Key_801B52EC&other)const {
        return value==other.value;
    }
};
struct Record_801B52EC  {
    Key_801B52EC key,parent;
    void *(*factory)();
    unsigned short references,pad;
};
struct Table_801B52EC  {
    char pad[0x28];
    int count,capacity;
    Record_801B52EC *records;
    Record_801B52EC&operator[](int index) {
        return records[index];
    }
};
struct Handle_801B52EC  {
    signed int tag:8;
    signed int index:24;
    Handle_801B52EC() {
        index=0;
        tag=0;
    }
};
extern "C" Handle_801B52EC fn_801F9144(Table_801B52EC*,void *,const Key_801B52EC&,short);
extern "C" int sprintf(char *,const char *,...);
extern "C" const char lbl_8037A238[8],lbl_802AC950[];
extern "C" struct  {
    char pad[0x110];
    void *logger;
}
lbl_801E9D24;
extern "C" void fn_801F9D68(void *,const char *,...);
extern "C" Handle_801B52EC fn_801B52EC(Table_801B52EC *table,const char *typeName) {
    Key_801B52EC key(typeName);
    short i;
    for(i=0;i<table->count;++i) {
        if((*table)[i].key==key) {
            char text[128];
            {
                Record_801B52EC&entry=(*table)[i];
                sprintf(text,lbl_8037A238,typeName,entry.references);
            }
            ++(*table)[i].references;
            Key_801B52EC name(text);
            return fn_801F9144(table,(*table)[i].factory(),name,i);
        }
    }
    fn_801F9D68(lbl_801E9D24.logger,lbl_802AC950,typeName);
    return Handle_801B52EC();
}
