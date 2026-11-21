/* Timed actor event and state/flag control with native Handle lifetimes.
 * See docs/notes/game-timed-actor-event-control.md. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char opaque00[0x38];unsigned long long flags;};
struct Entry{Node*object;char opaque04[8];signed char tag;char opaque0D[3];signed char getTag()const{return tag;}};struct Manager{char opaque00[8];Entry*entries;};
extern "C"{extern struct Global{char opaque00[0x118];Manager*manager;}lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];extern const float lbl_803794EC;void fn_80257828(Node*,int,int,int);void fn_8007F860(void*,float);}
template<int Depth>struct EventZero_C152C:EventZero_C152C<Depth-1>{EventZero_C152C(){word=0;}~EventZero_C152C(){}};
template<>struct EventZero_C152C<1>:Handle_801F7F10{EventZero_C152C(){word=0;}~EventZero_C152C(){}};
struct Handle_800C17F8:EventZero_C152C<6>{Handle_800C17F8(){word=0;}~Handle_800C17F8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_800C176C:Handle_800C17F8{Handle_800C176C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_800C176C();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Point{float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}};extern "C"Point game_vec3_zero;
struct Owner{char opaque00[0x24];Handle_801F7F10 handle;char opaque28[0x11C];Point velocity;char opaque150[0x1D0];int field320;char opaque324[0xEC];float timer;char mode;unsigned char state;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
extern "C"void fn_800C152C(Owner*self,float delta){self->timer-=delta;if(self->mode==1&&self->state==1&&self->timer<=lbl_803794EC){self->state=2;const Handle_801F7F10&source=self->handle;Handle_800C176C h(source);fn_80257828(resolve(h),0x9A,0x8D,0);}if(self->state==4){float y=game_vec3_zero.y;float z=game_vec3_zero.z;self->velocity.set(game_vec3_zero.x,y,z);};fn_8007F860(self,delta);if(self->state==0&&self->field320==0)resolve(self->handle)->flags&=~0x20000ULL;else resolve(self->handle)->flags|=0x20000ULL;}
