inline void *operator new(unsigned long,void *pointer){
    return pointer;
}struct Vector_801C0B48{
    float x,y,z,w;
    Vector_801C0B48(const Vector_801C0B48&v){
        x=v.x;
        y=v.y;
        z=v.z;
        w=v.w;
    }
};
struct Array_801C0B48 {
    Vector_801C0B48 records[10];
    int count;
};
extern "C" int fn_801C0B48(Array_801C0B48 *self,const Vector_801C0B48&value){
    if(self->count>=10){
        new(&self->records[9])Vector_801C0B48(value);
        return 9;
    }new(&self->records[self->count++])Vector_801C0B48(value);
    return self->count-1;
}
