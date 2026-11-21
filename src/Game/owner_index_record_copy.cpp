struct IndexRecordHandle {signed int generation:8;signed int index:24;};
struct IndexRecordObject {char unknown00[0x20];int count,capacity;IndexRecordHandle*handles;};
struct IndexRecordEntry {IndexRecordObject*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct IndexRecordManager {char unknown00[8];IndexRecordEntry*entries;};
struct IndexCopyRecord {unsigned long unknown00;short index;char unknown06[0x4A];};
struct IndexCopyInput {char unknown00[0xC];int count,capacity;IndexCopyRecord*records;};
struct IndexCopyOutput {char unknown00[0x14];char buffer[0x14];IndexCopyRecord*records;char unknown2C[0x18];float value;};
struct IndexRecordOwner {char unknown00[0x1F0];IndexRecordHandle handle;};
extern "C" {extern struct {char unknown00[0x118];IndexRecordManager*manager;}lbl_801E9D24;extern const float lbl_8037B1E4;void fn_80232290(void*,int);void fn_801AE2D0(IndexCopyRecord*,IndexRecordObject*,const IndexCopyRecord*,float);}
static inline IndexRecordObject*resolveIndexRecord(const IndexRecordHandle&h){IndexRecordEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C" void fn_80232158(IndexRecordOwner*self,const IndexCopyInput*input,IndexCopyOutput*output){
 IndexRecordObject*object=resolveIndexRecord(self->handle);
 int count=input->count;
 fn_80232290(output->buffer,count);
 for(int i=0;i<count;++i){
  short index=input->records[i].index;
  output->records[i].index=index;
  if(index>=0&&index<object->count){IndexRecordObject*target=resolveIndexRecord(object->handles[index]);if(target)fn_801AE2D0(&output->records[i],target,&input->records[i],lbl_8037B1E4);}
 }
 output->value=lbl_8037B1E4;
}
