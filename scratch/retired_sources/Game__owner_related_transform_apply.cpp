#pragma fp_contract on
struct RelatedTransformApplyHandle{signed int generation:8;signed int index:24;};struct RelatedTransformApplyPoint{float x,y,z;RelatedTransformApplyPoint(){}RelatedTransformApplyPoint(float a,float b,float c):x(a),y(b),z(c){}};struct RelatedTransformApplyQuat{float x,y,z,w;};struct RelatedTransformApplyBasis{float v[9];};struct RelatedTransformApplyMatrix{float m[16];};
struct RelatedTransformApplyStorage{char unknown00[8];};struct RelatedTransformApplyOwner:RelatedTransformApplyStorage{
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
virtual const RelatedTransformApplyHandle*getHandle(int);
char unknown0C[0x19C];RelatedTransformApplyHandle related;};
struct RelatedTransformApplyObject{char unknown00[0xC];RelatedTransformApplyHandle owner;char unknown10[0x20];RelatedTransformApplyBasis rotation,basis;char unknown78[0xA8];unsigned long flags;RelatedTransformApplyMatrix*matrix,*inverse;short unknown12C,index;};
struct RelatedTransformApplyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct RelatedTransformApplyManager{char unknown00[8];RelatedTransformApplyEntry*entries;};struct RelatedTransformApplyPool{RelatedTransformApplyMatrix*pages[6];unsigned char active;};extern "C"{extern struct{char unknown00[0x118];RelatedTransformApplyManager*manager;char unknown11C[0x18];RelatedTransformApplyPool*pool;}lbl_801E9D24;void fn_801F2124(const RelatedTransformApplyBasis*,RelatedTransformApplyBasis*);RelatedTransformApplyQuat*fn_801F20F4(RelatedTransformApplyQuat*,const RelatedTransformApplyBasis*);void fn_801F1BB0(RelatedTransformApplyQuat*,const RelatedTransformApplyQuat*);void fn_801F230C(const RelatedTransformApplyMatrix*,RelatedTransformApplyMatrix*);void fn_8023D120(void*,const RelatedTransformApplyPoint*,const RelatedTransformApplyQuat*);void fn_8023D100(void*,const RelatedTransformApplyPoint*);unsigned long fn_801F7EB8(const void*);}
inline char*resolveRelatedTransformApply(const RelatedTransformApplyHandle&h){int index=h.index;RelatedTransformApplyManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void refreshRelatedTransformApplyInverse(RelatedTransformApplyObject*object){if(object->flags&0x20){object->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];fn_801F230C(object->matrix,object->inverse);object->flags&=~0x20;}}
inline RelatedTransformApplyPoint transformRelatedTransformApply(const RelatedTransformApplyMatrix&m,const RelatedTransformApplyPoint&v){float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];return RelatedTransformApplyPoint(X,Y,Z);}
extern "C" void fn_8022DC80(RelatedTransformApplyOwner*self,const RelatedTransformApplyPoint*point,const RelatedTransformApplyQuat*rotation,int index){RelatedTransformApplyObject*object=(RelatedTransformApplyObject*)resolveRelatedTransformApply(*self->getHandle(index));RelatedTransformApplyOwner*related=(RelatedTransformApplyOwner*)resolveRelatedTransformApply(self->related);RelatedTransformApplyObject*primary=(RelatedTransformApplyObject*)resolveRelatedTransformApply(*related->getHandle(0));if(primary->flags&0x40){fn_801F2124(&primary->rotation,&primary->basis);primary->flags&=~0x40;}RelatedTransformApplyQuat composed;fn_801F20F4(&composed,&primary->basis);fn_801F1BB0(&composed,rotation);refreshRelatedTransformApplyInverse(primary);RelatedTransformApplyPoint transformed=transformRelatedTransformApply(*primary->inverse,*point);fn_8023D120(object,&transformed,&composed);}
