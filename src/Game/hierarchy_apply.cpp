/* Selected hierarchy traversal reconstructed from GSQE78.
 * See docs/notes/game-hierarchy-apply.md. */
typedef unsigned long u32;
struct Handle {signed int generation:8;signed int index:24;};
struct HandleList {int count,capacity;Handle*data;};
struct Hierarchy {char unknown[0x90];HandleList second;char unknown9C[0xC];HandleList first;char unknownB4[0x10];HandleList fourth;HandleList third;};
struct ResourceEntry {void*object;u32 unused[2];signed char generation;char padding[3];};
struct Manager {u32 unused[2];ResourceEntry*entries;};
struct Globals {char unknown[0x118];Manager*manager;};
extern "C" {
extern Globals lbl_801E9D24;
void*fn_801F7EB8(Handle*);
signed char fn_80206868(Hierarchy*,int);
void fn_802073E8(void*,void*,void*,float);
}
extern "C" {
void fn_801FC26C(Hierarchy*self,u32 mask,Handle*source,void*context,float value){
 int i;
 void*owner=fn_801F7EB8(source);
 if(mask&1){for(i=0;i<self->first.count;++i)if(fn_801F7EB8(&self->first.data[i])){const Handle&h=self->first.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(owner,context,entry->generation==h.generation?entry->object:0,value);}}
 if(mask&2){for(i=0;i<self->second.count;++i)if(fn_801F7EB8(&self->second.data[i])){const Handle&h=self->second.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(owner,context,entry->generation==h.generation?entry->object:0,value);}}
 if(mask&4){for(i=0;i<self->third.count;++i)if(fn_80206868(self,i)){const Handle&h=self->third.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(owner,context,entry->generation==h.generation?entry->object:0,value);}}
 if(mask&8){for(i=0;i<self->fourth.count;++i)if(fn_801F7EB8(&self->fourth.data[i])){const Handle&h=self->fourth.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(owner,context,entry->generation==h.generation?entry->object:0,value);}}
}
void fn_801FBFD0(Hierarchy*self,u32 mask,void*context,float value){
 int i;
 if(mask&1){for(i=0;i<self->first.count;++i)if(fn_801F7EB8(&self->first.data[i])){const Handle&h=self->first.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(self,context,entry->generation==h.generation?entry->object:0,value);}}
 if(mask&2){for(i=0;i<self->second.count;++i)if(fn_801F7EB8(&self->second.data[i])){const Handle&h=self->second.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(self,context,entry->generation==h.generation?entry->object:0,value);}}
 if(mask&4){for(i=0;i<self->third.count;++i)if(fn_80206868(self,i)){const Handle&h=self->third.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(self,context,entry->generation==h.generation?entry->object:0,value);}}
 if(mask&8){for(i=0;i<self->fourth.count;++i)if(fn_801F7EB8(&self->fourth.data[i])){const Handle&h=self->fourth.data[i];ResourceEntry*entry=lbl_801E9D24.manager->entries+h.index;fn_802073E8(self,context,entry->generation==h.generation?entry->object:0,value);}}
}
}
