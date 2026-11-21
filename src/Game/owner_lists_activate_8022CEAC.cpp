/* fn_8022CEAC: activate the three owner handle lists; the third list also
   re-attaches eligible objects to the root target.  All loops share
   `int count,i;` (declared in that order) for the original register coloring. */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int generation:8; signed int index:24;}bits;};};
struct Vec3{float x,y,z;};
struct Object;
struct ObjectPrefix{Word unknown00[2];};
struct Object:ObjectPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void activate();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual int query();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual Vec3 position(int);virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();virtual void apply(Object*,const Vec3*,const Vec3*,int,int);char unknown0C[0x24];unsigned long long flags;};
struct Channel{char unknown00[0x12];unsigned short flags;char unknown14[0x60];};
struct Action{char unknown00[0x20];Channel channels[4];};
struct RootObject{char unknown00[0xC];Handle handle;};
struct HandleIndex {const int value;HandleIndex(int v):value(v){}operator int()const{return value;}};
struct Slot{Object*object;Word unknown04[2];signed char generation;char unknown0D[3];bool matchesTag(signed char tag)const{return generation==tag;}Object*getObject()const{return object;}};
struct EntryArray {Slot* data; Slot& operator[](const HandleIndex&i) const {return data[i];} operator Slot*() const{return data;}};
struct Manager{Word unknown00[2];EntryArray entries;};
struct Context{char unknown00[0x118];Manager*manager;};extern "C"Context lbl_801E9D24;
struct Owner{char unknown00[0x28];Handle root;int count2C,capacity30;Handle*handles34;Word unknown38[2];Word*flags40;char unknown44[0x1C];int count60,capacity64;Handle*handles68;int count6C,capacity70;Handle*handles74;};
static inline Object*resolve(const Handle&h){Slot*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->generation==h.bits.generation)return e->object;return 0;}
struct RootSlot{RootObject*object;Word unknown04[2];signed char generation;char unknown0D[3];};struct RootManager{Word unknown00[2];RootSlot*entries;};static inline RootObject*rootLookup(const Handle&h){RootObject*result=0;RootSlot*e=((RootManager*)lbl_801E9D24.manager)->entries+h.bits.index;if(e->generation==h.bits.generation)result=e->object;return result;}
static inline Object*resolveTyped(const Handle&h){Manager*manager=lbl_801E9D24.manager;const HandleIndex index(h.bits.index);signed char generation=h.bits.generation;if(manager->entries[index].matchesTag(generation))return manager->entries[index].getObject();return 0;}
extern "C" void fn_8022CEAC(Owner*self){
 int count,i;
 count=self->count6C;
 for(i=0;i<count;++i){
  Object*object=resolveTyped(self->handles74[i]);
  object->activate();
 }
 count=self->count60;
 for(i=0;i<count;++i){
  Object*object=resolveTyped(self->handles68[i]);
  object->activate();
  Action*action=(Action*)resolveTyped(self->handles68[i]);
  action->channels[0].flags|=0x80;
  action->channels[1].flags|=0x80;
  action->channels[2].flags|=0x80;
  action->channels[3].flags|=0x80;
 }
 count=self->count2C;
 for(i=0;i<count;++i){
  Object*object=resolve(self->handles34[i]);
  object->activate();
  if(!object->query()&&!(self->flags40[i]&2)&&(object->flags&0x1000ULL)!=0){
   RootObject*root=rootLookup(self->root);
   Object*target=resolve(root->handle);
   object->apply(target,&object->position(0),&object->position(0),0,1);
  }
 }
}
