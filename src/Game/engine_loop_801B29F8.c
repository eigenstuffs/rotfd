extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

struct Record {char pad[140];};

struct Array {int count,capacity;struct Record *records;};

extern const char lbl_8028F698[];

extern void fn_8028FD50(const void *,void *,int);

extern void fn_801B2AC8(void *,int);

void *fn_801B29F8(struct Array *object,short release) {if(object){if(object->records){int i;for(i=0;i<object->count;++i)fn_801B2AC8(&object->records[i],-1);if(object->records){fn_8028FD50(lbl_8028F698,object->records,object->capacity*140);object->records=0;}object->records=0;}if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
