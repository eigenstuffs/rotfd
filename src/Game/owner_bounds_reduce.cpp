struct ReduceBoundsHandle{signed int generation:8;signed int index:24;};struct ReduceBoundsSphere{float x,y,z,radius;ReduceBoundsSphere&operator=(const ReduceBoundsSphere&v){x=v.x;y=v.y;z=v.z;radius=v.radius;return *this;}};struct ReduceBoundsStorage{char unknown00[8];};struct ReduceBoundsOwner:ReduceBoundsStorage{
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
virtual int first();
virtual int next(int);
virtual void slot98();
virtual const ReduceBoundsHandle*getHandle(int);
char unknown0C[0x24];unsigned long long flags;};
struct ReduceBoundsCollision:ReduceBoundsStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual signed char accepts(void*,int,int);virtual const ReduceBoundsSphere*getReduceBounds();};
struct ReduceBoundsObject{char unknown00[0x1C];ReduceBoundsHandle resource,parent;char unknown24[0x100];void*matrix;};struct ReduceBoundsResource{char unknown00[0xC];ReduceBoundsSphere bounds;};struct ReduceBoundsEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct ReduceBoundsManager{char unknown00[8];ReduceBoundsEntry*entries;};extern "C"{extern struct{char unknown00[0x118];ReduceBoundsManager*manager;}lbl_801E9D24;ReduceBoundsSphere fn_80099A00(const void*,const ReduceBoundsSphere*);ReduceBoundsSphere fn_801F0A20(const ReduceBoundsSphere&,const ReduceBoundsSphere&);}
inline char*resolveReduceBounds(const ReduceBoundsHandle&h){int index=h.index;ReduceBoundsManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
extern "C" int fn_802276C8(ReduceBoundsOwner*self,ReduceBoundsSphere*out){const ReduceBoundsSphere*source;ReduceBoundsObject*object;ReduceBoundsCollision*collision;signed char first;int index=self->first();if(index<0)return 0;ReduceBoundsObject*initial=(ReduceBoundsObject*)resolveReduceBounds(*self->getHandle(index));source=&((ReduceBoundsResource*)resolveReduceBounds(initial->resource))->bounds;first=1;for(;index>=0;index=self->next(index)){object=(ReduceBoundsObject*)resolveReduceBounds(*self->getHandle(index));collision=(ReduceBoundsCollision*)resolveReduceBounds(object->parent);void*matrix=object->matrix;if(first)*out=fn_80099A00(matrix,source);else *out=fn_801F0A20(fn_80099A00(matrix,source),*out);if((self->flags&0x2000ULL)&&collision->accepts(object,0,0))*out=fn_801F0A20(fn_80099A00(matrix,collision->getReduceBounds()),*out);first=0;}return 1;}
