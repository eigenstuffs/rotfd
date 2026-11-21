struct IndexedMatrixHandle {signed int generation:8;signed int index:24;};
struct IndexedMatrixTarget {
 char unknown0[0x28];
 IndexedMatrixHandle*handles28;
 char unknown2C[0x1C4];
 IndexedMatrixHandle handle1F0;
};
struct IndexedMatrixEntry {IndexedMatrixTarget*object;char unknown4[8];signed char generation;char unknownD[3];signed char getGeneration()const{return generation;}};
struct IndexedMatrixManager {char unknown0[8];IndexedMatrixEntry*entries;};
struct IndexedMatrixIndices {char unknown0[0x94];int*indices;};
extern "C" {
 extern struct {char unknown0[0x118];IndexedMatrixManager*manager;char unknown11C[0x28];IndexedMatrixIndices*records;}lbl_801E9D24;
 void fn_801F1E78(void*,const void*);
}
inline IndexedMatrixTarget*resolveIndexedMatrix(const IndexedMatrixHandle&h){
 int index=h.index;
 IndexedMatrixManager*m=lbl_801E9D24.manager;
 int generation=m->entries[index].getGeneration();
 return generation==h.generation?m->entries[index].object:0;
}
struct IndexedMatrixOwner {char unknown0[0x64];IndexedMatrixHandle handle64;};
struct IndexedMatrixView {char unknown0[0x30];float matrix30[9];};
extern "C" signed char fn_80257220(IndexedMatrixOwner*self,int index,void*output){
 IndexedMatrixTarget*first=resolveIndexedMatrix(self->handle64);
 int mapped=lbl_801E9D24.records->indices[index];
 IndexedMatrixTarget*second=resolveIndexedMatrix(first->handle1F0);
 IndexedMatrixTarget*object=resolveIndexedMatrix(second->handles28[mapped]);
 if(object){fn_801F1E78(output,((IndexedMatrixView*)object)->matrix30);return 1;}
 return 0;
}
