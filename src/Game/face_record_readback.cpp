typedef unsigned long u32;
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    extern struct {
        char unknown0[0x118];
        void*manager;
    }
    lbl_801E9D24;
}
struct FaceHandle {
    u32 value;
    FaceHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~FaceHandle(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
    FaceHandle&operator=(const FaceHandle&source){
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=source.value;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
        return *this;
    }
};
struct FaceZero1:FaceHandle {
    FaceZero1(){
        value=0;
    }
    ~FaceZero1(){
    }
};
struct FaceZero2:FaceZero1 {
    FaceZero2(){
        value=0;
    }
    ~FaceZero2(){
    }
};
struct FaceZero3:FaceZero2 {
    FaceZero3(){
        value=0;
    }
    ~FaceZero3(){
    }
};
struct FaceZero4:FaceZero3 {
    FaceZero4(){
        value=0;
    }
    ~FaceZero4(){
    }
};
struct FaceCopy:FaceZero4 {
    FaceCopy(const FaceHandle&source){
        value=source.value;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
    ~FaceCopy(){
    }
};
struct FaceRecord {
    float first[11];
    unsigned short middle[4];
    float last[4];
    FaceRecord&operator=(const FaceRecord&source){
        first[0]=source.first[0];
        first[1]=source.first[1];
        first[2]=source.first[2];
        first[3]=source.first[3];
        first[4]=source.first[4];
        first[5]=source.first[5];
        first[6]=source.first[6];
        first[7]=source.first[7];
        first[8]=source.first[8];
        first[9]=source.first[9];
        first[10]=source.first[10];
        middle[0]=source.middle[0];
        middle[1]=source.middle[1];
        middle[2]=source.middle[2];
        middle[3]=source.middle[3];
        last[0]=source.last[0];
        last[1]=source.last[1];
        last[2]=source.last[2];
        last[3]=source.last[3];
        return *this;
    }
};
struct FaceIndices {
    int count,capacity;
    unsigned short*data;
};
template<class T>struct FaceArray {
    int count,capacity;
    T*data;
    T&operator[](int index){
        return data[index];
    }
};
struct FaceRecordOwner {
    u32 unknown0;
    FaceHandle handle4;
    char unknown8[0xD0];
    FaceArray<FaceRecord> records;
    FaceArray<FaceIndices> faces;
};
struct FaceReadback {
    int index;
    FaceHandle handle4;
    int count;
    int indices[4];
    FaceRecord records[4];
};
extern "C" signed char fn_8024E200(FaceRecordOwner*,const void*,FaceReadback*);
extern "C" signed char fn_80242C70(FaceRecordOwner*self,const void*query,FaceReadback*out){
    if(!fn_8024E200(self,query,out))return 0;
    const FaceIndices*face=&self->faces[out->index];
    int count=face->count;
    if(count>4)return 0;
    out->count=count;
    for(int i=0;
    i<count;
    ++i){
        int index=face->data[i];
        out->indices[i]=index;
        out->records[i]=self->records[index];
    }
    const FaceHandle&source=self->handle4;
    FaceCopy handle(source);
    out->handle4=handle;
    return 1;
}
