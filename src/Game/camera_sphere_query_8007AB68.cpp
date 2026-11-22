typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
extern "C"struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];extern const float lbl_80378A5C;}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Collected{char unknown00[0x28];~Collected(){}};
struct Object_8007A280{Word storage[0xA00];int count;Object_8007A280():count(0){}~Object_8007A280(){for(int i=0;i<count;++i)reinterpret_cast<Collected*>(storage)[i].~Collected();}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Point{float x,y,z;};struct Sphere:Point{float radius;Sphere(const Point&p,float r){x=p.x;y=p.y;z=p.z;radius=r;}};
struct Camera{char unknown00[0xF4];Point point;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
extern "C"{const Handle_801F7F10*fn_80235C08(Camera*);int fn_80268918(Node*,const Sphere*,Object_8007A280*,unsigned long long,unsigned long long);}
extern "C"int fn_8007AB68(Camera*self){Handle_80020C04 target(*fn_80235C08(self));Object_8007A280 results;Sphere sphere(self->point,lbl_80378A5C);if((signed char)fn_80268918(resolve(target),&sphere,&results,0x00008FE000000004ULL,0ULL))return 1;return 0;}
