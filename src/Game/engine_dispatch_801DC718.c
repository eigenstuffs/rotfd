struct Record {
    char bytes[0x28];
};
struct Object {
    struct Record records[255];
    char pad[0x1c];
    void *last;
    char padF8[8];
    int count;
};
extern void fn_801DC5E8(struct Record *,int,void *);
int fn_801DC718(struct Object *self,int index,void *context){
    if(index==0x100 && self->last==0){
        fn_801DC5E8((struct Record *)((char *)self+0x27d8),1,context);
    }
    else if(index!=self->count){
        fn_801DC5E8(&self->records[index],self->count-index,context);
    }
    else{
        return 0;
    }
    return 1;
}
