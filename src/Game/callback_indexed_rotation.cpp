struct IndexedRotationHandle {signed int generation:8;signed int index:24;};
struct IndexedRotationQuaternion {
    float w,x,y,z;
    void operator=(const IndexedRotationQuaternion&q){w=q.w;x=q.x;y=q.y;z=q.z;}
    void fromX(float angle);
    void fromY(float angle);
};
struct IndexedRotationTarget {
    char unknown0[0xC];IndexedRotationHandle parent;
    char unknown10[0x18];IndexedRotationHandle*handles;
    char unknown2C[4];float basis[9],matrix[9];
    char unknown78[0x50];IndexedRotationQuaternion rotation;
    char unknownD8[0x48];unsigned long flags;
    char unknown124[0xCC];IndexedRotationHandle related;
};
struct IndexedRotationEntry {IndexedRotationTarget*object;char unknown4[8];signed char generation;char unknownD[3];signed char getGeneration()const{return generation;}};
struct IndexedRotationManager {char unknown0[8];IndexedRotationEntry*entries;};
struct IndexedRotationIndices {char unknown0[0x94];int*indices;};
extern "C" {
extern struct {char unknown0[0x118];IndexedRotationManager*manager;char unknown11C[0x28];IndexedRotationIndices*records;}lbl_801E9D24;
extern const float lbl_8037B508,lbl_8037B50C,lbl_8037B510;
float fn_8028506C(float);float fn_80284FA8(float);
void fn_801F1BB0(IndexedRotationQuaternion*,const IndexedRotationQuaternion*);
void fn_801F20F4(IndexedRotationQuaternion*,const float*);
void fn_801F2124(const float*,float*);
}
inline void IndexedRotationQuaternion::fromX(float angle){
    float half=angle*lbl_8037B508;
    w=fn_8028506C(half);
    float sine=fn_80284FA8(half);
    y=lbl_8037B50C*sine;
    x=lbl_8037B510*sine;
    z=lbl_8037B50C*sine;
}
inline void IndexedRotationQuaternion::fromY(float angle){
    float half=angle*lbl_8037B508;
    w=fn_8028506C(half);
    float sine=fn_80284FA8(half);
    x=lbl_8037B50C*sine;
    y=lbl_8037B510*sine;
    z=lbl_8037B50C*sine;
}
inline IndexedRotationTarget*resolveIndexedRotation(const IndexedRotationHandle&h){
 int index=h.index;IndexedRotationManager*m=lbl_801E9D24.manager;
 int generation=m->entries[index].getGeneration();
 return generation==h.generation?m->entries[index].object:0;
}
struct IndexedRotationOwner {char unknown0[0x64];IndexedRotationHandle handle64;};
extern "C" signed char fn_80256F98(IndexedRotationOwner*self,int index,const IndexedRotationQuaternion*input,float angleY,float angleX){
    IndexedRotationTarget*first=resolveIndexedRotation(self->handle64);
    IndexedRotationTarget*second=resolveIndexedRotation(first->related);
    int mapped=lbl_801E9D24.records->indices[index];
    IndexedRotationTarget*object=resolveIndexedRotation(second->handles[mapped]);
    IndexedRotationTarget*parent=resolveIndexedRotation(object->parent);
    if(object&&parent){
        IndexedRotationQuaternion x;
        x.fromX(angleX);
        IndexedRotationQuaternion y;
        y.fromY(angleY);
        fn_801F1BB0(&x,input);
        fn_801F1BB0(&y,&x);
        IndexedRotationQuaternion original;
        fn_801F20F4(&original,parent->basis);
        fn_801F1BB0(&original,&y);
        if(parent->flags&0x40){fn_801F2124(parent->basis,parent->matrix);parent->flags&=~0x40;}
        IndexedRotationQuaternion result;
        fn_801F20F4(&result,parent->matrix);
        fn_801F1BB0(&result,&original);
        object->rotation=result;
        return 1;
    }
    return 0;
}
