typedef unsigned long u32;
union Handle{u32 word;struct{signed int generation:8,index:24;}bits;};
struct Node{char unknown00[0x38];unsigned long long flags38;};struct Entry{Node*object;u32 unknown04,unknown08;signed char generation;char unknown0D[3];};struct Manager{char unknown00[8];Entry*entries;};
struct Context{char unknown00[0x118];Manager*manager;};extern "C" Context lbl_801E9D24;
struct Child{char unknown00[0x24];Handle handle24;};struct Owner{char unknown00[8];Child*child08;};
inline Node*resolve(const Handle&h){Entry*entry=lbl_801E9D24.manager->entries+h.bits.index;return entry->generation==h.bits.generation?entry->object:0;}
extern "C" void fn_80081210(Owner*self){resolve(self->child08->handle24)->flags38|=0x20000ULL;}
