struct VisitHandle {signed int generation:8;signed int index:24;};
struct VisitEntry {void*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct VisitManager {char unknown00[8];VisitEntry*entries;};
struct VisitOwner {char unknown00[0xE4];int count,capacity;VisitHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];VisitManager*manager;}lbl_801E9D24;
void fn_802397E0(void*);
}
static inline void*resolveVisit(const VisitHandle&handle){VisitEntry*entry=&lbl_801E9D24.manager->entries[handle.index];if(entry->generation==handle.generation)return entry->object;return 0;}
extern "C" void fn_802431F8(VisitOwner*self){for(int i=0;i<self->count;++i)fn_802397E0(resolveVisit(self->handles[i]));}
