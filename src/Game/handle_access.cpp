/* Engine handle initialization and object lookup reconstructed from GSQE78. */
typedef unsigned long u32;
struct Handle_801F7F10 {signed long generation:8;signed long index:24;Handle_801F7F10();~Handle_801F7F10();};
struct Object;
struct Slot {Object*object;u32 unknown[2];signed char generation;char padding[3];};
struct Registry {int size,capacity;Slot*data;};
struct Globals {char unknown[0x118];Registry*context;};
extern "C" Globals lbl_801E9D24;
extern "C" Object*fn_801F7EB8(Handle_801F7F10*h){Slot*s=&lbl_801E9D24.context->data[h->index];return s->generation==h->generation?s->object:0;}
Handle_801F7F10::Handle_801F7F10(){*reinterpret_cast<u32*>(this)=0;}
