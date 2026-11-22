/* Actor frame update (fn_800A905C): unless the actor's own resource (handle
 * from virtual slot 0x9C) has property bit 0x10000 set, saves velocity
 * (+0x144) as previous velocity (+0x15C), clears velocity, runs
 * fn_8009B50C and the update virtual (slot 0x198), clears the force
 * accumulator (+0x358) and forwards the velocity to the actor's resource
 * (+0x24 handle, slot 0xB4). Always finishes with fn_80222E44(self, delta).
 * Matching note: the entry-pointer resolve form (as in
 * early_owner_position_transfer_views.h) gives the original context/self/zero
 * callee-saved register assignment (r31/r30/r29). */
typedef unsigned long Word;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Prefix{Word unknown00,unknown04;};
struct Resource:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual void v9C();virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual void vB0();
 virtual void setVelocity(const Vec3&);
 char unknown0C[0x114];unsigned long property;};
struct Entry{Resource*object;char unknown04[8];signed char tag;char pad[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Resource*resolve(const Handle&h){Entry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct Actor:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();
 virtual const Handle*getHandle(int);
 virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual void vB0();virtual void vB4();virtual void vB8();virtual void vBC();virtual void vC0();virtual void vC4();virtual void vC8();virtual void vCC();virtual void vD0();virtual void vD4();virtual void vD8();virtual void vDC();virtual void vE0();virtual void vE4();virtual void vE8();virtual void vEC();virtual void vF0();virtual void vF4();virtual void vF8();virtual void vFC();virtual void v100();virtual void v104();virtual void v108();virtual void v10C();virtual void v110();virtual void v114();virtual void v118();virtual void v11C();virtual void v120();virtual void v124();virtual void v128();virtual void v12C();virtual void v130();virtual void v134();virtual void v138();virtual void v13C();virtual void v140();virtual void v144();virtual void v148();virtual void v14C();virtual void v150();virtual void v154();virtual void v158();virtual void v15C();virtual void v160();virtual void v164();virtual void v168();virtual void v16C();virtual void v170();virtual void v174();virtual void v178();virtual void v17C();virtual void v180();virtual void v184();virtual void v188();virtual void v18C();virtual void v190();virtual void v194();
 virtual void update(float);
 char unknown0C[0x18];Handle resource;char unknown28[0x11C];Vec3 velocity;char unknown150[0xC];Vec3 previousVelocity;
 char unknown168[0x1F0];Vec3 force;};
extern "C" {extern const Vec3 game_vec3_zero;void fn_8009B50C(Actor*);void fn_80222E44(Actor*,float);}
extern "C" void fn_800A905C(Actor*self,float delta){
 if(!(resolve(*self->getHandle(0))->property&0x10000)){
  self->previousVelocity=self->velocity;
  self->velocity=game_vec3_zero;
  fn_8009B50C(self);
  self->update(delta);
  self->force=game_vec3_zero;
  resolve(self->resource)->setVelocity(self->velocity);
 }
 fn_80222E44(self,delta);
}
