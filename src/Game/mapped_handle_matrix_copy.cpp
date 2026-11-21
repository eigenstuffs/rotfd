// Native handle layers preserve construction, retention and automatic cleanup.
struct Handle_801F7F10 {union {unsigned long value;struct {signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct MappedMatrixNativeHandle:Handle_801F7F10 {MappedMatrixNativeHandle(){value=0;}};
struct MappedMatrixHandle:MappedMatrixNativeHandle {MappedMatrixHandle(const MappedMatrixHandle&);};
struct MappedMatrix {unsigned long words[16];};
struct MappedMatrixObject {char unknown00[0x124];MappedMatrix*matrix;};
struct MappedMatrixEntry {MappedMatrixObject*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct MappedMatrixManager {char unknown00[8];MappedMatrixEntry*entries;};
struct MappedMatrixMap {char unknown00[0x94];int*indices;};
struct MappedMatrixOwner {char unknown00[0x28];MappedMatrixHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];MappedMatrixManager*manager;char unknown11C[0x28];MappedMatrixMap*map;}lbl_801E9D24;
void fn_801F86C8(void*,const void*,int);
}
inline MappedMatrixHandle::MappedMatrixHandle(const MappedMatrixHandle&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
static inline MappedMatrixObject*resolveMappedMatrix(const MappedMatrixHandle&h){MappedMatrixEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
extern "C" signed char fn_8024BFB4(MappedMatrixOwner*self,int index,MappedMatrix*output){
 const MappedMatrixHandle&input=self->handles[lbl_801E9D24.map->indices[index]];
 MappedMatrixHandle handle(input);
 MappedMatrixObject*object=resolveMappedMatrix(handle);
 if(!object){return 0;}
 *output=*object->matrix;
 return 1;
}
