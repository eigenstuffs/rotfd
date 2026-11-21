#pragma fp_contract on
struct TransformHandle{signed int generation:8;signed int index:24;};
struct TransformPoint{float x,y,z;const TransformPoint&get()const{return *this;}TransformPoint(){}TransformPoint(float a,float b,float c):x(a),y(b),z(c){}TransformPoint(const TransformPoint&v):x(v.x),y(v.y),z(v.z){}};struct TransformRotation{float x,y,z,w;};struct TransformBasis{float values[9];};struct TransformMatrix{float m[16];};
struct TransformSelf{char unknown00[0x1AC];TransformHandle secondary;char unknown1B0[0x48];TransformHandle related;};struct TransformStorage{char unknown00[8];};struct TransformOwner:TransformStorage{
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
virtual const TransformHandle*getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void setTransform(const TransformPoint*,const TransformRotation*,int);
};
struct TransformObject{char unknown00[0x20];TransformHandle parent;char unknown24[4];TransformHandle*items;char unknown2C[4];TransformBasis rotation;char unknown54[0xD0];TransformMatrix*matrix;};
struct TransformEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct TransformManager{char unknown00[8];TransformEntry*entries;};struct TransformSelection{char unknown00[0x18];int index;int getIndex()const{return index;}};struct TransformSelector{char unknown00[0x94];TransformSelection*selection;};extern "C"{extern struct{char unknown00[0x118];TransformManager*manager;char unknown11C[0x28];TransformSelector*selector;}lbl_801E9D24;void fn_8023DE28(void*);void fn_801F2170(TransformBasis*,const void*,const void*);void fn_801F20F4(void*,const TransformBasis*);void fn_8021F8F4(void*,const TransformPoint*,const TransformRotation*,int);unsigned long fn_801F7EB8(const void*);void fn_8022352C(void*,const TransformPoint*,const TransformRotation*);}
inline unsigned long resolveTransform(const TransformHandle&h){int index=h.index;TransformManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return (unsigned long)m->entries[index].object;return 0;}
inline TransformPoint transformTranslation(const TransformMatrix&m,const TransformMatrix&v){float z=v.m[14];float y=v.m[13];float x=v.m[12];TransformPoint out;out.x=m.m[0]*x+m.m[4]*y+m.m[8]*z+m.m[12];out.y=m.m[1]*x+m.m[5]*y+m.m[9]*z+m.m[13];out.z=m.m[2]*x+m.m[6]*y+m.m[10]*z+m.m[14];return out.get();}
inline void forwardTransform(void*self,TransformPoint point,const TransformRotation*rotation){fn_8021F8F4(self,&point,rotation,0);}
extern "C" void fn_80222E64(TransformSelf*self,const TransformPoint*point,const TransformRotation*rotation){TransformOwner*related=(TransformOwner*)resolveTransform(self->related);if(related){related->setTransform(point,rotation,0);TransformObject*object=(TransformObject*)resolveTransform(*related->getHandle(0));fn_8023DE28(object);TransformObject*parent=(TransformObject*)resolveTransform(object->parent);TransformObject*node=(TransformObject*)resolveTransform(parent->items[0]);TransformObject*target=(TransformObject*)resolveTransform(node->items[lbl_801E9D24.selector->selection->getIndex()]);TransformBasis basis;fn_801F2170(&basis,&object->rotation,&target->rotation);TransformRotation composed;fn_801F20F4(&composed,&basis);forwardTransform(self,transformTranslation(*object->matrix,*target->matrix),&composed);}else fn_8021F8F4(self,point,rotation,0);if(fn_801F7EB8(&self->secondary))fn_8022352C(self,point,rotation);}
