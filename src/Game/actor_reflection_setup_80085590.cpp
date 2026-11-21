/* Bounded native reflection-control setup and value-lifetime views.
 * One erased resource registry supplies actual typed object pointers.
 * Native Copy return storage is4 bytes; its temporary releases exactly once.
 * Distinct C-entry pointer/return views describe machine ABI, not complete
 * original C++ source-class identity. No original data is owned here. */
struct ReflectionVector{float x,y,z;ReflectionVector(){}ReflectionVector(float a,float b,float c):x(a),y(b),z(c){}ReflectionVector(const ReflectionVector&v):x(v.x),y(v.y),z(v.z){}ReflectionVector&operator=(const ReflectionVector&v){x=v.x;y=v.y;z=v.z;return*this;}ReflectionVector operator*(float a)const{return ReflectionVector(x*a,y*a,z*a);}ReflectionVector operator-(const ReflectionVector&v)const{return ReflectionVector(x-v.x,y-v.y,z-v.z);}float dot(const ReflectionVector&v)const{return x*v.x+y*v.y+z*v.z;}};
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ReflectionH1:Handle_801F7F10{~ReflectionH1(){}};struct Handle_80020834:ReflectionH1{~Handle_80020834(){}};struct ReflectionH3:Handle_80020834{~ReflectionH3(){}};struct Handle_8004A72C:ReflectionH3{~Handle_8004A72C(){}};struct ReflectionCopy:Handle_8004A72C{ReflectionCopy();~ReflectionCopy(){}};
struct ReflectionActor{char unknown00[0x30];unsigned long long flags;char unknown38[0x10C];ReflectionVector velocity;char unknown150[0xC];ReflectionVector position;char unknown168[0x50];ReflectionVector normal;char unknown1C4[0x15C];void*record;char unknown324[0x30];float speed;char unknown358[0xB4];signed char enabled40C;char unknown40D[0x17];float magnitude;float getSpeed(){return speed;}void setSpeed(float v){speed=v;}};
struct ReflectionOwner{void*vtable;unsigned char enabled;char unknown05[3];ReflectionActor*actor;void*controller;char unknown10[0x30];ReflectionVector vector;float speed;};
struct ReflectionIndex{int value;ReflectionIndex(int v):value(v){}operator int()const{return value;}};
struct ReflectionEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}void*getObject()const{return object;}};struct ReflectionEntries{ReflectionEntry*p;ReflectionEntry&operator[](const ReflectionIndex& i)const{return p[i];}};
struct ReflectionManager{int count,capacity;ReflectionEntries entries;};struct ReflectionNode{char unknown00[0x1C];const Handle_801F7F10*handle;};struct ReflectionContext{char unknown00[0x118];ReflectionManager*manager;char unknown11C[0x20];ReflectionNode*node;};
struct ReflectionMonitor{char unknown00[0x130];void*first,*second;};
extern "C"{extern ReflectionContext lbl_801E9D24;extern ReflectionMonitor*lbl_803776B8;extern const float lbl_80378AEC;void fn_8006803C(ReflectionMonitor*,void*);void fn_8025795C(void*,int,void*);void fn_80255D88(void*,int,unsigned int,void*,void*);void fn_80077330(ReflectionActor*,ReflectionVector*);ReflectionCopy fn_8004A6C8(const void*);}
inline ReflectionActor*resolve(const Handle_801F7F10&h){ReflectionManager*manager=lbl_801E9D24.manager;ReflectionIndex index(h.bits.index);signed char tag=h.bits.tag;if(manager->entries[index].matchesTag(tag))return static_cast<ReflectionActor*>(manager->entries[index].getObject());return 0;}
struct ReflectionRelated{char unknown00[0x98];const Handle_801F7F10*handle;};inline ReflectionRelated*resolveRelated(const Handle_801F7F10&h){ReflectionManager*manager=lbl_801E9D24.manager;ReflectionIndex index(h.bits.index);signed char tag=h.bits.tag;if(manager->entries[index].matchesTag(tag))return static_cast<ReflectionRelated*>(manager->entries[index].getObject());return 0;}


extern "C"void fn_80085590(ReflectionOwner*self){
 ReflectionActor*target=resolve(fn_8004A6C8(resolve(*resolveRelated(*lbl_801E9D24.node->handle)->handle)));
 fn_80077330(target,&self->vector);
 self->actor->velocity=self->vector*self->actor->magnitude;
 self->actor->setSpeed(lbl_80378AEC*self->actor->getSpeed());
 self->actor->flags&=~0x1000000000ULL;self->actor->flags&=~0x8000000000ULL;
 fn_8025795C(self->controller,0x71,0);
 fn_80255D88(self->controller,0x7D,0xF,0,0);fn_80255D88(self->controller,0x7E,0xF,0,0);fn_80255D88(self->controller,0x7F,0xF,0,0);
 if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->record);
}

typedef char ReflectionHandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char ReflectionEntrySize[(sizeof(ReflectionEntry)==16)?1:-1];
typedef char ReflectionManagerSize[(sizeof(ReflectionManager)==12)?1:-1];
