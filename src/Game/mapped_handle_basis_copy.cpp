// Native handle layers preserve construction, retention and automatic cleanup.
struct Handle_801F7F10 {union {unsigned long value;struct {signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct MappedBasisNativeHandle:Handle_801F7F10 {MappedBasisNativeHandle(){value=0;}};
struct MappedBasisHandle:MappedBasisNativeHandle {MappedBasisHandle(const MappedBasisHandle&);};
struct MappedBasisObject {char unknown00[0x30];float basis[9];};
struct MappedBasisEntry {MappedBasisObject*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct MappedBasisManager {char unknown00[8];MappedBasisEntry*entries;};
struct MappedBasisMap {char unknown00[0x94];int*indices;};
struct MappedBasisOwner {char unknown00[0x28];MappedBasisHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];MappedBasisManager*manager;char unknown11C[0x28];MappedBasisMap*map;}lbl_801E9D24;
void fn_801F86C8(void*,const void*,int);
void fn_801F1E78(void*,const void*);
}
inline MappedBasisHandle::MappedBasisHandle(const MappedBasisHandle&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
static inline MappedBasisObject*resolveMappedBasis(const MappedBasisHandle&h){MappedBasisEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
extern "C" signed char fn_8024BEA8(MappedBasisOwner*self,int index,void*output){
 const MappedBasisHandle&input=self->handles[lbl_801E9D24.map->indices[index]];
 MappedBasisHandle handle(input);
 MappedBasisObject*object=resolveMappedBasis(handle);
 if(!object){return 0;}
 fn_801F1E78(output,object->basis);
 return 1;
}
