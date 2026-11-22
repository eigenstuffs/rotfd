struct SourceRecord {
    char bytes[0x68];
};
struct TargetRecord {
    char bytes[0x90];
};
struct Source {
    int count,capacity;
    struct SourceRecord *records;
};
struct Target {
    char pad[0xac];
    struct TargetRecord *records;
};
extern void fn_801D84F4(struct Target *,struct TargetRecord *,struct SourceRecord *,void *);
void fn_801D890C(struct Target *self,struct Source *source,void *context){
    int i;
    for(i=0;i<source->count;++i)fn_801D84F4(self,&self->records[i],&source->records[i],context);
}
