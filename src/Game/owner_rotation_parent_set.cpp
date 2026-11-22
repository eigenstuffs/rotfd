struct Handle_801F7F10{union{unsigned long value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct RotParentQuat{float x,y,z,w;RotParentQuat&operator=(const RotParentQuat&v){x=v.x;y=v.y;z=v.z;w=v.w;return *this;}};
struct RotParentObject{char unknown00[0x1C];Handle_801F7F10 owner,parent;char unknown24[4];Handle_801F7F10*items;char unknown2C[0x9C];RotParentQuat rotation;char unknownD8[0x48];unsigned long flags;Handle_801F7F10&getOwner(){return owner;}};
struct RotParentStorage{char unknown00[8];};struct RotParentSelf:RotParentStorage{
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
virtual const Handle_801F7F10*getHandle(int);
char unknown0C[0x15C];Handle_801F7F10 owner,parent;char unknown170[0x18];RotParentQuat current,target;float phase;};
struct RotParentEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];};struct RotParentManager{char unknown00[8];RotParentEntry*entries;};extern "C"{extern struct{char unknown00[0x118];RotParentManager*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);void slot84__12ObjectMove_ZFv(void*,const Handle_801F7F10*);extern const float lbl_8037B140,lbl_8037B17C;}
inline char*resolveRotParent(const Handle_801F7F10&h){RotParentEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
struct RotParentHandle1:Handle_801F7F10{RotParentHandle1(){value=0;}};struct RotParentHandle2:RotParentHandle1{RotParentHandle2(){value=0;}};struct RotParentCopy2:RotParentHandle2{RotParentCopy2(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
inline void assignRotParent(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
extern "C" void slot84__13ObjectThrow_ZFv(RotParentSelf*self,const Handle_801F7F10*input){slot84__12ObjectMove_ZFv(self,input);RotParentObject*primary=(RotParentObject*)resolveRotParent(*self->getHandle(0));self->current=primary->rotation;self->target=primary->rotation;self->phase=lbl_8037B140;self->phase=lbl_8037B17C;RotParentObject*object=(RotParentObject*)resolveRotParent(*input);{RotParentCopy2 copy(object->getOwner());assignRotParent(self->owner,copy);}if(object->flags&0x800){RotParentObject*parent=(RotParentObject*)resolveRotParent(object->parent);RotParentCopy2 copy(*parent->items);assignRotParent(self->parent,copy);}}
