struct SphereVisitHandle {union {unsigned long value;struct {signed int generation:8;signed int index:24;} bits;};};
#pragma fp_contract on
struct SphereVisitPoint {float x,y,z;};
struct SphereVisitPair {float x,y;SphereVisitPair(float a,float b):x(a),y(b){}};
struct SphereVisitResult {char unknown00[0x48];};
struct SphereVisitCandidate {
 char unknown000[0x1C];
 SphereVisitHandle handle;
 char unknown020[0x100];unsigned long flags;
};
struct SphereVisitStorage {char unknown00[8];};
struct SphereVisitObject:SphereVisitStorage {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
 virtual int test(SphereVisitCandidate*,const SphereVisitPoint*,void*,SphereVisitResult*,int,unsigned long long,unsigned long long,float);
};
struct SphereVisitEntry {SphereVisitObject* object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct SphereVisitManager {char unknown00[8];SphereVisitEntry* entries;};
extern "C" {extern struct {char unknown00[0x118];SphereVisitManager* manager;}lbl_801E9D24;int fn_80266C78(void*,const SphereVisitPair*,const SphereVisitPair*);}
inline SphereVisitObject* resolveSphereVisit(const SphereVisitHandle& h) {
 int index=h.bits.index;SphereVisitManager* manager=lbl_801E9D24.manager;
 int generation=manager->entries[index].getGeneration();
 if(generation==h.bits.generation)return manager->entries[index].object;
 return 0;
}
struct SphereVisitGrid {char unknown00[0x40];SphereVisitCandidate* candidates[4096];};
struct SphereVisitSelf {char unknown0000[0x80BC];SphereVisitGrid grid;SphereVisitGrid& getGrid(){return grid;} };
extern "C" int fn_80268794(SphereVisitSelf* self,const SphereVisitPoint* center,void* other,SphereVisitResult* results,int capacity,int unused,unsigned long long firstMask,unsigned long long secondMask,signed char includeOther,float radius) {
 SphereVisitPair minimum(center->x-radius,center->z-radius);
 SphereVisitPair maximum(center->x+radius,center->z+radius);
 int hits=0;
 int count=fn_80266C78(&self->grid,&minimum,&maximum);
 SphereVisitCandidate** current=self->getGrid().candidates;
 for(int i=0;i<count;++i) {
  SphereVisitCandidate* candidate=*current++;
  if(candidate->flags&0x10000)continue;
  if(!(candidate->flags&0x40000)&&!includeOther)continue;
  SphereVisitObject* object=resolveSphereVisit(candidate->handle);
  if(object){
   hits+=object->test(candidate,center,other,results+hits,capacity-hits,firstMask,secondMask,radius);
   if(capacity==0)break;
  }
 }
 return hits!=0;
}
