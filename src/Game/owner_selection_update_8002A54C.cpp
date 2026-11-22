typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Object;
struct Entry{Object*object;char unknown4[8];signed char tag;char unknownD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Object{char unknown0[0x318];char record[0x440-0x318];Object*selected;Word mode;};
struct SceneMode{char unknown0[0x1C8];short count;};
struct Scene{char unknown0[0x15058];SceneMode*root;};
struct Service{char unknown0[0x2D];char enabled;};
struct MonitorPrefix{char unknown0[4];};
struct Monitor:MonitorPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual Object*current();};
struct Self{char unknown0[0x58];Handle handle;};
extern "C"{
 extern struct Global{char unknown0[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x164-0x128];Service*service;}lbl_801E9D24;
 extern Monitor*lbl_803776B8;
 extern const float lbl_803782E8;
 Object*fn_8005E90C();void fn_8006CCF4(int);void fn_8007D6A0(void*,int);
 int fn_800596E4(SceneMode*,short,short);void fn_802073E8(Self*,int,void*,float);
}
inline Object*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
extern "C"void fn_8002A54C(Self*self){
 SceneMode*mode=lbl_801E9D24.scene->root;
 ++mode->count;
 Object*object=fn_8005E90C();fn_8006CCF4(0);fn_8007D6A0(&object->record,6);
 object->selected=resolve(self->handle);object->mode=6;fn_8007D6A0(&object->record,0x33);
 if(lbl_803776B8)fn_802073E8(self,0xDE,lbl_803776B8->current(),lbl_803782E8);
 else{lbl_801E9D24.service->enabled=0;int count=fn_800596E4(mode,0,2);fn_802073E8(self,0x56,mode,(float)count);}
}
