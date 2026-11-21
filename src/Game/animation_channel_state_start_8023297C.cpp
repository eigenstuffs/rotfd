/* Starts an animation channel state from a borrowed record handle. */
typedef unsigned long Word;
typedef unsigned short Half;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Object;
struct Entry{Object*object;char unknown04[8];signed char tag;char pad[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Object*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Active{char unknown00[0x30];float duration;Half flags;};
struct Cursors{char data[0x24];};
struct State{Active*active;float age,weight,loopTime;Half loopCount,flags;char unknown14[0x38];Cursors cursors;Word end;};
struct Owner{char unknown00[0x20];State states[4];Handle target;};
typedef char StateSize[sizeof(State)==0x74?1:-1];
extern "C" {
void fn_80233450(Owner*,int);
void fn_8023203C(Active*,void*,float,float,float);
void fn_80232158(Owner*,void*,State*);
void fn_80232BB0(Cursors*,Active*);
extern const float lbl_8037B1E0,lbl_8037B1E8;
}

extern "C" void fn_8023297C(Owner*self,const Handle*handle,int index,char flag){
 State*state=&self->states[index];
 if(!(state->flags&0x81))fn_80233450(self,index);
 state->flags&=~0x80;
 state->flags|=1;
 state->flags|=flag?8:0;
 for(int i=0;i<4;i++)self->states[i].flags&=~0x16;
 Active*active=(Active*)resolve(*handle);
 if(!active){state->active=0;return;}
 if(active->flags&2)state->flags&=~8;
 if(state->flags&0x200){state->flags&=~0x208;fn_8023203C(active,resolve(self->target),*(const float*)&lbl_8037B1E0,lbl_8037B1E0,active->duration);}
 if(state->flags&8)fn_80232158(self,resolve(*handle),state);
 state->active=active;
 state->age=lbl_8037B1E0;
 self->states[index].weight=lbl_8037B1E8;
 if(lbl_8037B1E0==state->active->duration)state->active=0;
 fn_80232BB0(&state->cursors,active);
}
