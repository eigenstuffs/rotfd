// Transform the primary resource sphere and include an accepted parent collision sphere.
struct PrimaryBoundsHandle{signed int generation:8;signed int index:24;};struct PrimaryBoundsSphere{float x,y,z,radius;PrimaryBoundsSphere&operator=(const PrimaryBoundsSphere&v){x=v.x;y=v.y;z=v.z;radius=v.radius;return *this;}};struct PrimaryBoundsStorage{char unknown00[8];};struct PrimaryBoundsOwner:PrimaryBoundsStorage{
virtual void slot8();
virtual void slotC();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual const PrimaryBoundsHandle*getHandle(int);
char unknown0C[0x24];unsigned long long flags;};
struct PrimaryBoundsCollision:PrimaryBoundsStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual signed char accepts(void*,int,int);virtual const PrimaryBoundsSphere*getPrimaryBounds();};
struct PrimaryBoundsResource{char unknown00[0xC];PrimaryBoundsSphere bounds;};struct PrimaryBoundsEntry{void*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct PrimaryBoundsManager{char unknown00[8];PrimaryBoundsEntry*entries;};extern "C"{extern struct{char unknown00[0x118];PrimaryBoundsManager*manager;}lbl_801E9D24;PrimaryBoundsSphere fn_80099A00(const void*,const PrimaryBoundsSphere*);PrimaryBoundsSphere fn_801F0A20(const PrimaryBoundsSphere&,const PrimaryBoundsSphere&);}
inline void*resolvePrimaryBounds(const PrimaryBoundsHandle&h){int index=h.index;PrimaryBoundsManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
struct PrimaryBoundsObject{char unknown00[0x1C];PrimaryBoundsHandle resource,parent;char unknown24[0x100];void*matrix;PrimaryBoundsResource*getResource()const{return static_cast<PrimaryBoundsResource*>(resolvePrimaryBounds(resource));}PrimaryBoundsCollision*getCollision()const{return static_cast<PrimaryBoundsCollision*>(resolvePrimaryBounds(parent));}};extern "C" int slot80__12ObjectMove_ZFv(PrimaryBoundsOwner*self,PrimaryBoundsSphere*out){PrimaryBoundsObject*object=static_cast<PrimaryBoundsObject*>(resolvePrimaryBounds(*self->getHandle(0)));PrimaryBoundsResource*resource=object->getResource();PrimaryBoundsCollision*collision=static_cast<PrimaryBoundsCollision*>(resolvePrimaryBounds(object->parent));void*matrix=object->matrix;*out=fn_80099A00(matrix,&resource->bounds);if((self->flags&0x2000ULL)&&collision->accepts(object,0,0))*out=fn_801F0A20(fn_80099A00(matrix,collision->getPrimaryBounds()),*out);return 1;}
