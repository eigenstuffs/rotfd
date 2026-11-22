struct Handle_801F7F10{union{unsigned long value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct RelatedOriginPoint{float x,y,z;RelatedOriginPoint&operator=(const RelatedOriginPoint&v){x=v.x;y=v.y;z=v.z;return *this;}};struct RelatedOriginMatrix{float values[16];};struct RelatedOriginSelf{char unknown00[0x1F8];Handle_801F7F10 related;char unknown1FC[0xC];RelatedOriginPoint origin;};
struct RelatedOriginObject{char unknown00[0x20];Handle_801F7F10 parent;Handle_801F7F10&getParent(){return parent;}};
struct RelatedOriginStorage{char unknown00[8];};struct RelatedOriginOwner:RelatedOriginStorage{
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
};
struct RelatedOriginEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];};struct RelatedOriginManager{char unknown00[8];RelatedOriginEntry*entries;};extern "C"{extern struct{char unknown00[0x118];RelatedOriginManager*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);unsigned long fn_801F7EB8(const void*);void fn_8024BFB4(void*,int,RelatedOriginMatrix*);extern const RelatedOriginPoint game_vec3_zero;}
inline char*resolveRelatedOrigin(const Handle_801F7F10&h){RelatedOriginEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
struct RelatedOriginHandle1:Handle_801F7F10{RelatedOriginHandle1(){value=0;}};struct RelatedOriginHandle2:RelatedOriginHandle1{RelatedOriginHandle2(){value=0;}};struct RelatedOriginCopy2:RelatedOriginHandle2{RelatedOriginCopy2(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
inline void assignRelatedOrigin(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
inline void setRelatedOrigin(RelatedOriginPoint&point,float x,float y,float z){point.x=x;point.y=y;point.z=z;}
extern "C" void fn_80224038(RelatedOriginSelf*self,const Handle_801F7F10*input){assignRelatedOrigin(self->related,*input);if(fn_801F7EB8(&self->related)){RelatedOriginOwner*owner=(RelatedOriginOwner*)resolveRelatedOrigin(self->related);char*primary=resolveRelatedOrigin(*owner->getHandle(0));char*object=resolveRelatedOrigin(RelatedOriginCopy2(((RelatedOriginObject*)primary)->getParent()));RelatedOriginCopy2 copy(**(Handle_801F7F10**)(object+0x28));RelatedOriginMatrix matrix;fn_8024BFB4(resolveRelatedOrigin(copy),6,&matrix);float y=matrix.values[13];float z=matrix.values[14];float x=matrix.values[12];setRelatedOrigin(self->origin,x,y,z);}else self->origin=game_vec3_zero;}
