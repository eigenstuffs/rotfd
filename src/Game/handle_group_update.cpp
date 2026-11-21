struct GroupUpdateHandle {signed int generation:8;signed int index:24;};
struct GroupUpdateEntry {void*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct GroupUpdateManager {char unknown00[8];GroupUpdateEntry*entries;};
struct GroupUpdateOwner {int count,capacity;GroupUpdateHandle*handles;signed char disabled;};
extern "C" {
extern struct {char unknown00[0x118];GroupUpdateManager*manager;}lbl_801E9D24;
void fn_80239828(void*,double);
}
static inline void*resolveGroupUpdate(const GroupUpdateHandle&handle){GroupUpdateEntry*entry=&lbl_801E9D24.manager->entries[handle.index];if(entry->generation==handle.generation)return entry->object;return 0;}
extern "C" void fn_8023AAAC(GroupUpdateOwner*self,double value){if(!self->disabled){for(int i=0;i<self->count;++i)fn_80239828(resolveGroupUpdate(self->handles[i]),value);}}
