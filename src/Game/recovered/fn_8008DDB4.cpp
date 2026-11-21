/* The loops run over a reference to the model's handle array (offset 0x30); see fn_8008DB20. */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Object;
struct Entry{Object*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}Object*get(int expected)const{int current=getTag();return current==expected?object:0;}};
struct Manager{int count,capacity;Entry*entries;};
struct Prefix{char unknown00[8];};
struct Object:Prefix{
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void stop(int);virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();virtual const Handle&getHandle(int);
 float f0C,f10,f14;char unknown18[4];float f1C;Handle handle20;float f24;char unknown28[8];int count30,capacity34;Handle*items38;char unknown3C[0x28];Handle handle64;char unknown68[0x188];Handle handle1F0;
};
struct HandleArray{int count30,capacity34;Handle*items38;};
struct Vec3f{float x,y,z;};
struct Self{char unknown00[8];Object*owner;Object*actor;char unknown10[0x3C];float x4C,y50,z54;};
struct State{char unknown00[0xD0];int mode;};
extern "C"{
extern struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern const float lbl_80378B7C,lbl_80378B80;
Word fn_801F7EB8(const Handle*);
State*fn_8007D074();
}
inline Object*resolveA(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Object*resolveB(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Object*resolveC(const Handle&h){int tag=h.bits.tag;return lbl_801E9D24.manager->entries[h.bits.index].get(tag);}
inline Object*getModel(Self*self){return resolveB(resolveB(self->actor->handle64)->handle1F0);}
extern "C" void fn_8008DDB4(Self*self){
    HandleArray*model=(HandleArray*)&resolveB(resolveB(self->actor->handle64)->handle1F0)->count30;
    for(int i=0;i<model->count30;++i){
        if(fn_801F7EB8(&model->items38[i])){
            Object*item=resolveB(model->items38[i]);
            item->f0C=lbl_80378B7C;
            item->f10=lbl_80378B7C;
            item->f14=lbl_80378B80;
        }
    }
    for(int i=0;i<model->count30;++i){
        if(fn_801F7EB8(&model->items38[i])){
            Object*item=resolveB(model->items38[i]);
            item->f1C=self->x4C;
            *(float*)&item->handle20=self->y50;
            item->f24=self->z54;
        }
    }
    State*state=fn_8007D074();
    if(state->mode!=3&&state->mode!=2){
        resolveB(resolveB(self->owner->getHandle(0))->handle20)->stop(-1);
    }
}
