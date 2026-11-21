#include "Game/callback_time_dispatch.h"

typedef unsigned long long u64;
struct Handle {signed generation:8;signed index:24;};
struct Action {
    char unknown00[0x38];
    u64 flags38;
    int state40;
    signed char hasFlags(u64 mask){if(flags38&mask)return 1;return 0;}
};
struct Entry {Action*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct Manager {int count,capacity;Entry*entries;};
struct Globals {char unknown00[0x118];Manager*manager;char unknown11C[0x28];void*audio;};
struct Node {Handle handle;int key;Node*next;float time;};
struct CallbackTimeOwner {
    int currentIndex;
    Action*current;
    signed char result,active,paused,filter;
    float time,delta;
    int tick;
    int unknown18;
    Node*pending;
    char unknown20[0x14];
    int count,capacity;
    Handle*actions;
    Action*next();
    unsigned char update(float);
};
extern "C" {
extern Globals lbl_801E9D24;
extern const float lbl_8037B578,lbl_8037B57C;
void fn_801F7914(void*,const void*);
void __dt__15Handle_801F7F10Fv(void*,int);
void fn_8025EA74(Action*,Node*);
void fn_80287BAC(void*);
void fn_8025E910(Action*);
void fn_80286158(Action*);
}
static inline Action*resolve(const Handle&h)
{
    Entry*e=&lbl_801E9D24.manager->entries[h.index];
    if(e->generation==h.generation)return e->object;
    return 0;
}
inline Action*CallbackTimeOwner::next()
{
    while(currentIndex<count){
        int i=currentIndex++;
        Action*a=resolve(actions[i]);
        if(a->state40==2)return a;
        fn_80286158(a);
    }
    return 0;
}
inline unsigned char CallbackTimeOwner::update(float delta)
{
    if(!this->active)return 0;
    ++this->tick;
    if(this->time<lbl_8037B578)this->time=lbl_8037B57C;
    if(!this->paused){
        this->time+=delta;
        this->delta=delta;
    }
    Node*n=this->pending;
    while(n){
        if(!(n->time<=this->time))break;
        this->pending=n->next;
        Action*a=resolve(n->handle);
        {
            Handle empty;
            empty.index=0;
            empty.generation=0;
            fn_801F7914(&n->handle,&empty);
            __dt__15Handle_801F7F10Fv(&empty,-1);
        }
        fn_8025EA74(a,n);
        n=this->pending;
    }
    fn_80287BAC(lbl_801E9D24.audio);
    this->result=0;
    this->currentIndex=0;
    int count=this->count;
    for(int i=0;i<count;++i){
        Action*a=resolve(this->actions[i]);
        if(a->state40==3&&(!this->filter||(a->flags38&0x20000ULL)!=0)&&(!this->filter||(a->flags38&0x800000ULL)==0))a->state40=2;
    }
    while((this->current=this->next())!=0){
        if(!this->filter||(this->current->hasFlags(0x20000ULL)&&(this->current->flags38&0x800000ULL)==0)){
            this->result=1;
            fn_8025E910(this->current);
        }
    }
    return this->result;
}

extern "C" unsigned char fn_802603E8(CallbackTimeOwner*self,float delta){return self->update(delta);}

typedef char CallbackTimeHandleSize[sizeof(Handle)==4?1:-1];
typedef char CallbackTimeEntrySize[sizeof(Entry)==16?1:-1];
typedef char CallbackTimeActionFlags[((unsigned int)&((Action*)0)->flags38==0x38)?1:-1];
typedef char CallbackTimeActionState[((unsigned int)&((Action*)0)->state40==0x40)?1:-1];
typedef char CallbackTimeOwnerPending[((unsigned int)&((CallbackTimeOwner*)0)->pending==0x1C)?1:-1];
typedef char CallbackTimeOwnerActions[((unsigned int)&((CallbackTimeOwner*)0)->actions==0x3C)?1:-1];
