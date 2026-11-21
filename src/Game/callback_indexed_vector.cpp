struct IndexedVectorHandle {signed int generation:8;signed int index:24;};
struct IndexedVectorTarget {
    char unknown0[0xC];float vectorC[3];char unknown18[0x20];IndexedVectorHandle*handles38;
    char unknown3C[0x1B4];IndexedVectorHandle handle1F0;
};
struct IndexedVectorEntry {IndexedVectorTarget*object;char unknown4[8];signed char generation;char unknownD[3];signed char getGeneration()const{return generation;}};
struct IndexedVectorManager {char unknown0[8];IndexedVectorEntry*entries;};
struct IndexedVectorRecords {char unknown0[0xAC];int*indices;};
extern "C" {
    extern struct {char unknown0[0x118];IndexedVectorManager*manager;char unknown11C[0x28];IndexedVectorRecords*records;}lbl_801E9D24;
    void*fn_801F7EB8(const IndexedVectorHandle*);
}
inline IndexedVectorTarget*resolveIndexedVector(const IndexedVectorHandle&h){int index=h.index;IndexedVectorManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.generation?m->entries[index].object:0;}
struct IndexedVectorOwner {char unknown0[0x64];IndexedVectorHandle handle64;};
inline void indexedVectorBody(IndexedVectorOwner*self,const float*value,int index){
    if(fn_801F7EB8(&self->handle64)){
        int mapped=lbl_801E9D24.records->indices[index];
        if(mapped>=0){
            const IndexedVectorHandle&handle=resolveIndexedVector(resolveIndexedVector(self->handle64)->handle1F0)->handles38[mapped];
            if(fn_801F7EB8(&handle)){
                IndexedVectorTarget*object=resolveIndexedVector(handle);
                object->vectorC[0]=value[0];object->vectorC[1]=value[1];object->vectorC[2]=value[2];
            }
        }
    }
}

extern "C" void fn_80256674(IndexedVectorOwner*self,const float*value,int index){indexedVectorBody(self,value,index);}
