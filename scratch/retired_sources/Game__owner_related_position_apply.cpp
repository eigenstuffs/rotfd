#pragma fp_contract on
struct RelatedPositionApplyHandle{signed int generation:8;signed int index:24;};struct RelatedPositionApplyPoint{float x,y,z;RelatedPositionApplyPoint(){}RelatedPositionApplyPoint(float a,float b,float c):x(a),y(b),z(c){}};struct RelatedPositionApplyQuat{float x,y,z,w;};struct RelatedPositionApplyBasis{float v[9];};struct RelatedPositionApplyMatrix{float m[16];};
struct RelatedPositionApplyStorage{char unknown00[8];};struct RelatedPositionApplyOwner:RelatedPositionApplyStorage{
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
virtual const RelatedPositionApplyHandle*getHandle(int);
char unknown0C[0x19C];RelatedPositionApplyHandle related;};
struct RelatedPositionApplyObject{char unknown00[0xC];RelatedPositionApplyHandle owner;char unknown10[0x20];RelatedPositionApplyBasis rotation,basis;char unknown78[0xA8];unsigned long flags;RelatedPositionApplyMatrix*matrix,*inverse;short unknown12C,index;const RelatedPositionApplyHandle&getOwner()const{return owner;}};
struct RelatedPositionApplyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct RelatedPositionApplyManager{char unknown00[8];RelatedPositionApplyEntry*entries;};struct RelatedPositionApplyPool{RelatedPositionApplyMatrix*pages[6];unsigned char active;};extern "C"{extern struct{char unknown00[0x118];RelatedPositionApplyManager*manager;char unknown11C[0x18];RelatedPositionApplyPool*pool;}lbl_801E9D24;void fn_801F2124(const RelatedPositionApplyBasis*,RelatedPositionApplyBasis*);RelatedPositionApplyQuat*fn_801F20F4(RelatedPositionApplyQuat*,const RelatedPositionApplyBasis*);void fn_801F1BB0(RelatedPositionApplyQuat*,const RelatedPositionApplyQuat*);void fn_801F230C(const RelatedPositionApplyMatrix*,RelatedPositionApplyMatrix*);void fn_8023D120(void*,const RelatedPositionApplyPoint*,const RelatedPositionApplyQuat*);void fn_8023D100(void*,const RelatedPositionApplyPoint*);unsigned long fn_801F7EB8(const void*);}
inline char*resolveRelatedPositionApply(const RelatedPositionApplyHandle&h){int index=h.index;RelatedPositionApplyManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void refreshRelatedPositionApplyInverse(RelatedPositionApplyObject*object){if(object->flags&0x20){object->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];fn_801F230C(object->matrix,object->inverse);object->flags&=~0x20;}}
inline RelatedPositionApplyPoint transformRelatedPositionApply(const RelatedPositionApplyMatrix&m,const RelatedPositionApplyPoint&v){float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];return RelatedPositionApplyPoint(X,Y,Z);}
extern "C" void fn_8022DEB0(RelatedPositionApplyOwner*self,const RelatedPositionApplyPoint*point,int index){RelatedPositionApplyObject*object=(RelatedPositionApplyObject*)resolveRelatedPositionApply(*self->getHandle(index));RelatedPositionApplyOwner*related=(RelatedPositionApplyOwner*)resolveRelatedPositionApply(self->related);RelatedPositionApplyObject*primary=(RelatedPositionApplyObject*)resolveRelatedPositionApply(*related->getHandle(0));if(fn_801F7EB8(&object->owner)&&((RelatedPositionApplyObject*)resolveRelatedPositionApply(object->getOwner()))->flags&4)((RelatedPositionApplyObject*)resolveRelatedPositionApply(object->getOwner()))->flags&=~4;refreshRelatedPositionApplyInverse(primary);RelatedPositionApplyPoint transformed=transformRelatedPositionApply(*primary->inverse,*point);fn_8023D100(object,&transformed);}
