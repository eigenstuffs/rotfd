/* Per-frame record/timer update (fn_800A6D90): owner timers, fade colour push, scene
 * handle tick, per-record scene-flag gating, periodic callback, and the 2D offset
 * (clamped to +-40) of the tracked actor in the related target's basis.
 * The second target resolve reads the handle through a distinct view type so the
 * original reload is kept; records use the TU's (record=&records[i])->member idiom. */
#pragma fp_contract on
typedef unsigned long Word;
struct Manager;
struct Handle{signed int tag:8,index:24;};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Child{char unknown00[0x238];float color[4];};
struct Parent{char unknown00[0x48];Child*child;};
struct SceneRecord{char unknown00[0x20];signed char flags[9];char unknown29[0x6B];};
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Scene{char unknown00[0x68];Handle_801F7F10 handle68;char unknown6C[0x84];int selected;char unknownF4[0x38];float x,y,z;SceneRecord*records;};
struct World{char unknown00[0x15058];Scene*scene;};
struct Holder{char unknown00[0x1C];Handle*handle;};
extern "C" struct Globals{char unknown00[0x114];Parent*parent;Manager*manager;char unknown11C[8];World*world;char unknown128[0x14];Holder*holder;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);Word fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_80052930:Handle_801F7F10{Handle_80052930(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80052930(){}};
inline Node*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Name{Word value;Name(const char*s){value=fn_801F948C(this,s);}Name(const Name&n){value=n.value;}bool operator==(const Name&n)const{return value==n.value;}};
struct Record{Word unknown00;Name key;char unknown08[0xA1];unsigned char flags;char unknownAA[0x2A];bool hidden()const{return flags&1;}};
struct Owner{char unknown00[0x20];int count;char unknown24[4];Record*records;char unknown2C[0xC];float timer;signed char locked;signed char active;char unknown3E[2];float delay;char unknown44[4];int state;float decay;float color[4];float wait;char unknown64[0xC];float step;};
struct Position{char unknown00[0x30];float x,y,z;};
struct Matrix3{float m[9];};
struct Target{char unknown00[0x30];Matrix3 basis30;Matrix3 transpose54;char unknown78[0xA8];unsigned int flags120;Position*position;};
struct Link{char unknown00[0x58];Handle handle58;};
struct Actor{char unknown00[0xB0];Handle*link;};
struct Handle2{signed int tag:8,index:24;};
inline Node*resolve2(const Handle2&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Color{unsigned char a,b,c,d;};
extern "C"{extern const char lbl_8029EC80[];extern const char lbl_80378F90[4];extern const float lbl_80378F78,lbl_80378F80,lbl_80378FB0,lbl_80378FB4,lbl_80378FB8,lbl_80378FBC;extern float lbl_80377780;extern signed char lbl_803777E4;
void fn_800A6234(Owner*,signed char,const Name&);void fn_800A84D8(Owner*);void fn_800ACB3C(Node*,float);void fn_800C0874();void fn_800C0EBC(Word);int fn_80055D90(Scene*);void fn_801F2124(const Matrix3*,Matrix3*);float fn_800A8E8C(float,float,float);}
extern "C" void fn_800A6D90(Owner*self,float dt){
    const char*pool=lbl_8029EC80;
    Scene*scene=lbl_801E9D24.world->scene;
    self->step=dt;
    self->timer-=dt;
    if(self->timer<=lbl_80378F78){self->timer=*(const float*)&lbl_80378F78;fn_800A6234(self,1,Name(Name(lbl_80378F90)));}
    if(self->active&&self->delay>lbl_80378F78){self->delay-=dt;if(self->delay<=lbl_80378F78){self->delay=lbl_80378F78;self->active=0;}}
    if(!self->active)self->decay-=dt;
    if(self->decay<lbl_80378FB0)self->state=0;
    if(self->wait>lbl_80378F78)self->wait-=dt;
    else if(self->color[3]<lbl_80378F80){
        self->color[3]+=dt;
        Child*child=lbl_801E9D24.parent->child;
        child->color[0]=self->color[0];child->color[1]=self->color[1];child->color[2]=self->color[2];child->color[3]=self->color[3];
        if(self->color[3]>=lbl_80378F80)fn_800A84D8(self);
    }
    Handle_80052930 handle(lbl_801E9D24.world->scene->handle68);
    if(fn_801F7EB8(&handle))fn_800ACB3C(resolve(*(Handle*)&handle),dt);
    if(!self->locked){
        for(int i=0;i<self->count;i++){
            Record*record;if((record=&self->records[i])->hidden())continue;
            if((record=&self->records[i])->key==Name(pool+0xD4)){if(!scene->records[scene->selected].flags[0])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0xE4)){if(!scene->records[scene->selected].flags[1])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0xF4)){if(!scene->records[scene->selected].flags[2])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x104)){if(!scene->records[scene->selected].flags[3])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x114)){if(!scene->records[scene->selected].flags[4])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x124)){if(!scene->records[scene->selected].flags[5])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x134)){if(!scene->records[scene->selected].flags[6])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x144)){if(!scene->records[scene->selected].flags[7])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x154)){if(!scene->records[scene->selected].flags[8])record->flags&=~2;}
        }
    }
    lbl_80377780-=dt;
    if(lbl_80377780<=lbl_80378F78){fn_800C0874();lbl_80377780=lbl_80378FB4;}
    Color color;color.a=0;color.b=0;color.c=0;color.d=0;
    if(lbl_803777E4&&fn_80055D90(scene)==1){
        color.a=1;
        Node*actor=resolve(*lbl_801E9D24.holder->handle);
        Link*link=(Link*)resolve(*((Actor*)actor)->link);
        Target*t=(Target*)resolve(link->handle58);
        float dx,dy,dz;
        dz=t->position->z-scene->z;
        dx=t->position->x-scene->x;
        dy=t->position->y-scene->y;
        Target*target=(Target*)resolve2(*(Handle2*)&link->handle58);
        if(target->flags120&0x40){fn_801F2124(&target->basis30,&target->transpose54);target->flags120&=~0x40;}
        const float*m=target->transpose54.m;
        float x=m[0]*dx+m[3]*dy+m[6]*dz;
        float z=m[2]*dx+m[5]*dy+m[8]*dz;
        float cx=fn_800A8E8C(x,lbl_80378FB8,lbl_80378FBC);
        float cz=fn_800A8E8C(z,lbl_80378FB8,lbl_80378FBC);
        color.b=(int)cx;color.c=(int)cz;
    }
    fn_800C0EBC(*(Word*)&color);
}
