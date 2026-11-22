struct Key_801B5054  {
    unsigned int value;
    bool operator==(const Key_801B5054&other)const {
        return value==other.value;
    }
};
extern "C" void fn_801F7CB4(void *,const void *);
struct Handle_801B5054  {
    signed int tag:8;
    signed int index:24;
    Handle_801B5054() {
        index=0;
        tag=0;
    }
    Handle_801B5054(const Handle_801B5054&other) {
        fn_801F7CB4(this,&other);
    }
};
struct Object_801B5054  {
    Key_801B5054 name;
    Handle_801B5054 handle;
};
struct Entry_801B5054  {
    Object_801B5054*object;
    unsigned int name;
    short type,references;
    char tail[4];
};
struct Record_801B5054  {
    Key_801B5054 key,parent;
    void *factory;
    unsigned short references,pad;
};
struct Table_801B5054  {
    int count,capacity;
    Entry_801B5054 *entries;
    char pad[0x1c];
    int typeCount,typeCapacity;
    Record_801B5054 *types;
    int find(const Key_801B5054&key) {
        int i;
        for(i=0;i<typeCount;++i)if(types[i].key==key)return i;
        return -1;
    }
    Entry_801B5054&operator[](int i) {
        return entries[i];
    }
};
extern "C" void fn_801B5054(Handle_801B5054*out,Table_801B5054*table,const Key_801B5054&key,const Key_801B5054&type) {
    if(type.value==0) {
        int i;
        for(i=0;i<table->count;++i) {
            if((*table)[i].object && (*table)[i].object->name==key) {
                fn_801F7CB4(out,&(*table)[i].object->handle);
                return;
            }
        }
    }
    else  {
        int typeIndex=table->find(type);
        int i;
        for(i=0;i<table->count;++i) {
            if((*table)[i].object && (*table)[i].object->name==key && (*table)[i].type==typeIndex) {
                fn_801F7CB4(out,&(*table)[i].object->handle);
                return;
            }
        }
    }
    out->index=0;
    out->tag=0;
}
