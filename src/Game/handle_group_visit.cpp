struct GroupVisitHandle {signed int generation:8;signed int index:24;};
struct GroupVisitEntry {void*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct GroupVisitManager {char unknown00[8];GroupVisitEntry*entries;};
struct GroupVisitOwner {int count,capacity;GroupVisitHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];GroupVisitManager*manager;}lbl_801E9D24;
void fn_80239A7C(void*);
}
static inline void*resolveGroupVisit(const GroupVisitHandle&handle){GroupVisitEntry*entry=&lbl_801E9D24.manager->entries[handle.index];if(entry->generation==handle.generation)return entry->object;return 0;}
extern "C" void fn_8023A9FC(GroupVisitOwner*self){for(int i=0;i<self->count;++i)fn_80239A7C(resolveGroupVisit(self->handles[i]));}
