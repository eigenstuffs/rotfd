/* fn_8022B16C: per-step update of the owner list: resolve the root target,
   refresh the enabled bit set, run fn_8022A560, then simulate every flag-2
   enabled owner over its sub-items.  The inline helpers (getTarget, refresh,
   runAll with j passed by reference, simulateAll, simulate) are needed for the
   original stack-slot order and register coloring. */
typedef unsigned long Word;
struct Handle{signed int generation:8;signed int index:24;};
struct Point{float x,y,z;Point(){}Point(const Point&v):x(v.x),y(v.y),z(v.z){}};
struct Storage{char unknown00[8];};
struct Owner:Storage{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();
virtual void apply(float,Point*,Point*,Point*,int);
virtual void prepare(float,Point*,Point*,Point*,int);
virtual void step(float,int);
virtual void collide(float,void*,Point*,Point*,Point*,Point*,int);
virtual void finish(int);
virtual void slot54();
virtual void visit(float,void*,int);
virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();
virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();
virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();
virtual char active(int);
virtual int first();
virtual int next(int);
virtual void slot98();
virtual const Handle*getHandle(int);
virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();
virtual Point getPosition(int);
char unknown0C[0xC];signed char enabled;

};
struct Root{char unknown00[0xC];Handle handle;};
struct Self{char unknown00[0x28];Handle root;int count;int capacity;Handle*items;char unknown38[8];unsigned long*flags;int wordCount;int wordCapacity;unsigned long*words;};
struct Entry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C"{extern struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
void fn_8023DE28(void*);void fn_8026847C(void*,float);void fn_8022A830(Self*,void*);void fn_8022A560(Self*,void*,float);void fn_8028B33C(Self*,void*);void*memset(void*,int,unsigned long);}
inline char*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void simulate(Owner*owner,float delta,char*target,int j){
    Point position(owner->getPosition(j));
    Point a,b;
    owner->prepare(delta,&position,&a,&b,j);
    Point c(a);
    owner->step(delta,j);
    owner->collide(delta,target,&position,&a,&c,&b,j);
    if(owner->active(j)){
     owner->apply(delta,&position,&a,&c,j);
     fn_8023DE28(resolve(*owner->getHandle(j)));
     owner->visit(delta,target,j);
     owner->finish(j);
    }
}
inline void simulateAll(Owner*owner,float delta,char*target,int&j){for(j=owner->first();j>=0;j=owner->next(j))simulate(owner,delta,target,j);}
inline void refresh(Self*self){int count=self->count;
 if(self->wordCount)memset(self->words,0,self->wordCount*4);
 for(int i=0;i<count;++i){
  Owner*owner=(Owner*)resolve(self->items[i]);
  if(owner->enabled)self->words[i>>5]|=1UL<<(i&31);
  else self->words[i>>5]&=~(1UL<<(i&31));
 }
}
inline void runAll(Self*self,float delta,char*target){int count=self->count;int i,j;
 for(i=0;i<count;++i){
  if((self->flags[i]&2)&&(self->words[i>>5]&(1UL<<(i&31)))){
   simulateAll((Owner*)resolve(self->items[i]),delta,target,j);
  }
 }
}
inline char*getTarget(Self*self){return resolve(((Root*)resolve(self->root))->handle);}
extern "C" void fn_8022B16C(Self*self,float delta){
 char*target=getTarget(self);
 fn_8026847C(target,delta);
 fn_8022A830(self,target);
 refresh(self);
 fn_8022A560(self,target,delta);
 runAll(self,delta,target);
 fn_8028B33C(self,target);
}
