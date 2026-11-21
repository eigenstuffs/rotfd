// Spatial-grid sphere collection; verified partial text reconstruction.
struct SphereCollectHandle {union {unsigned long value;struct {signed int generation:8;signed int index:24;} bits;};};
#pragma fp_contract on
struct SphereCollectPoint {float x,y,z;};
struct SphereCollectPair {float x,y;SphereCollectPair(float a,float b):x(a),y(b){}};
inline void* operator new(unsigned long,void* p){return p;}
struct SphereCollectRecord {char unknown00[0x1C];unsigned long word;char unknown20[8];SphereCollectRecord(){word=0;}~SphereCollectRecord(){} };
struct SphereCollectPool {
 unsigned long storage[0xA00];int count;
 SphereCollectPool():count(0){}
 SphereCollectRecord* records(){return reinterpret_cast<SphereCollectRecord*>(storage);}
 SphereCollectRecord& operator[](unsigned int i){return records()[i];}
 void resize(int n){
  if(n>count){for(int i=count;i<n;++i)new(&(*this)[i])SphereCollectRecord();}
  else if(n<count) {for(int i=count-1;i>=n;--i)(*this)[i].~SphereCollectRecord();}
  count=n;
 }
 ~SphereCollectPool(){for(int i=0;i<count;++i)(*this)[i].~SphereCollectRecord();}
};
struct SphereCollectSphere:SphereCollectPoint {float radius;};
struct SphereCollectCandidate {
 char unknown000[0x1C];
 SphereCollectHandle handle;
 SphereCollectHandle peer;char unknown024[0xFC];unsigned long flags;
};
struct SphereCollectStorage {char unknown00[8];};
struct SphereCollectObject:SphereCollectStorage {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void test(SphereCollectCandidate*,SphereCollectObject*,const SphereCollectSphere*,SphereCollectPool*,unsigned long long,unsigned long long);
};
struct SphereCollectEntry {SphereCollectObject* object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct SphereCollectManager {char unknown00[8];SphereCollectEntry* entries;};
extern "C" {extern struct {char unknown00[0x118];SphereCollectManager* manager;}lbl_801E9D24;int fn_80266C78(void*,const SphereCollectPair*,const SphereCollectPair*);}
inline SphereCollectObject* resolveSphereCollect(const SphereCollectHandle& h) {
 int index=h.bits.index;SphereCollectManager* manager=lbl_801E9D24.manager;
 int generation=manager->entries[index].getGeneration();
 if(generation==h.bits.generation)return manager->entries[index].object;
 return 0;
}
inline SphereCollectObject* resolvePeerSphereCollect(const SphereCollectHandle& h) {
 int index=h.bits.index;SphereCollectManager* manager=lbl_801E9D24.manager;
 SphereCollectEntry& entry=manager->entries[index];
 int generation=entry.getGeneration();
 if(generation==h.bits.generation)return entry.object;
 return 0;
}

struct SphereCollectGrid {char unknown00[0x40];SphereCollectCandidate* candidates[4096];};
struct SphereCollectSelf {char unknown0000[0x80BC];SphereCollectGrid grid;SphereCollectGrid& getGrid(){return grid;} };
extern "C" {void fn_80268CCC(SphereCollectPool*,SphereCollectPool*);void fn_80268B80(SphereCollectPool*,SphereCollectPool*);}
extern "C" int fn_80268918(SphereCollectSelf* self,const SphereCollectSphere* sphere,SphereCollectPool* output,unsigned long long firstMask,unsigned long long secondMask) {
 output->resize(0);
 SphereCollectPair minimum(sphere->x-sphere->radius,sphere->z-sphere->radius);
 SphereCollectPair maximum(sphere->x+sphere->radius,sphere->z+sphere->radius);
 int count=fn_80266C78(&self->grid,&minimum,&maximum);
 SphereCollectPool temporary;
 SphereCollectCandidate** current=self->getGrid().candidates;
 for(int i=0;i<count;++i) {
  SphereCollectCandidate* candidate=*current++;
  if(candidate->flags&0x10000)continue;
  if(!(candidate->flags&0x40000))continue;
  SphereCollectObject* object=resolveSphereCollect(candidate->handle);
  if(object)object->test(candidate,resolvePeerSphereCollect(candidate->peer),sphere,&temporary,firstMask,secondMask);
 }
 if(firstMask&0x0002000000000000ULL)fn_80268CCC(&temporary,output);
 else fn_80268B80(output,&temporary);
 return output->count!=0;
}
