struct Record {unsigned int key,parent;char pad[8];};

struct Lookup {char pad[0x28];int count;char tail[4];struct Record *records;};

extern void *memcpy(void *,const void *,unsigned int);

void fn_801B55E4(struct Lookup *object,const unsigned int *key) {int i;for(i=0;i<object->count;++i)if(*key==object->records[i].key){struct Record *record=&object->records[i];memcpy(record,record+1,(--object->count-i)*16);break;}}
