struct ParametersHandle {signed int generation:8;signed int index:24;};
struct ParametersEntry {void*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct ParametersManager {char unknown00[8];ParametersEntry*entries;};
struct ParametersOwner {char unknown00[0xD8];int count,capacity;ParametersHandle*handles;char unknownE4[0x10];float value;};
extern "C" {
extern struct {char unknown00[0x118];ParametersManager*manager;}lbl_801E9D24;
extern const float lbl_8037B378,lbl_8037B37C;
void fn_801EDAAC(void*,float,float,float);
}
static inline void*resolveParameters(const ParametersHandle&handle){ParametersEntry*entry=&lbl_801E9D24.manager->entries[handle.index];if(entry->generation==handle.generation)return entry->object;return 0;}
extern "C" void fn_802432A8(ParametersOwner*self){for(int i=0;i<self->count;++i)fn_801EDAAC(resolveParameters(self->handles[i]),self->value,lbl_8037B378,lbl_8037B37C);}
