typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Object;
struct Entry{Object*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}Object*get(int expected)const{int current=getTag();return current==expected?object:0;}};
struct Manager{int count,capacity;Entry*entries;};
struct Prefix{char unknown00[8];};
struct Object:Prefix{
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual const Handle&getHandle(int);
 char unknown0C[0x20];float value2C;char unknown30[0xA0];int mode;
 signed char isActiveMode()const{signed char r=0;if(mode==1||mode==2)r=1;return r;}
};
struct Self{char unknown00[0x24];Handle owner;char unknown28[0x138];float f160;char unknown164[0x48];Handle handle1AC;char unknown1B0[0x168];char controls;char unknown319[0x2F];Handle handle348;char unknown34C[0x10];float f35C;char unknown360[0x84];float f3E4;char unknown3E8[0x1C];signed char flag404;char unknown405[0x1F];float f424;};
extern "C"{
extern struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x48];void*input;}lbl_801E9D24;
extern const float lbl_80378BEC,lbl_80378C20;
signed char fn_8025E9FC(Object*,int);
void fn_80093D44(Self*,Object*);
void fn_800942B0(Self*,Object*);
void fn_80094110(Self*,Object*);
void fn_800B7214(void*,int,unsigned char*,int);
signed char fn_8007D604(void*,int);
void fn_8007D6A0(void*,int);
Word fn_801F7EB8(const Handle*);
void*fn_8007D074();
signed char fn_800774AC(Object*);
void fn_802073E8(void*,int,void*,float);
}
inline Object*resolveA(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Object*resolveB(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Object*resolveC(const Handle&h){int tag=h.bits.tag;return lbl_801E9D24.manager->entries[h.bits.index].get(tag);}
struct State{char unknown00[0xD0];int mode;bool isActive()const{return mode==1||mode==2;}};
extern "C" void fn_80093958(Self*self){
    Object*owner=resolveA(self->owner);
    if(fn_8025E9FC(owner,0x6D))fn_80093D44(self,owner);
    if(fn_8025E9FC(owner,0x71))fn_800942B0(self,owner);
    unsigned char pressed=0;
    fn_800B7214(lbl_801E9D24.input,3,&pressed,0);
    if(pressed)fn_80094110(self,owner);
    if(fn_8025E9FC(owner,0x73)){
        if(fn_8007D604(&self->controls,0xB)&&!fn_801F7EB8(&self->handle1AC)){
            float limit=lbl_80378BEC*self->f3E4;
            if(self->f160<limit&&self->f35C<limit)fn_8007D6A0(&self->controls,0x13);
        }else if(fn_8007D604(&self->controls,9)||fn_8007D604(&self->controls,0xA)||fn_8007D604(&self->controls,5)||fn_8007D604(&self->controls,0xC)){
            fn_8007D6A0(&self->controls,0x13);
        }
    }
    if(fn_8025E9FC(owner,0x75))self->flag404=1;
    if(fn_8025E9FC(owner,0x63)){
        if(fn_8007D604(&self->controls,0)||fn_8007D604(&self->controls,6)||fn_8007D604(&self->controls,0x35)){
            fn_8007D074();
            Object*target=resolveA(self->handle348);
            if(fn_800774AC(resolveA(target->getHandle(-1)))){
                if(fn_8007D604(&self->controls,0)||fn_8007D604(&self->controls,0x35)){
                    fn_8007D6A0(&self->controls,6);
                    fn_802073E8(owner,0x64,target,lbl_80378C20);
                }
            }else{
                if(((State*)resolveA(target->getHandle(-1)))->isActive()){
                fn_8007D6A0(&self->controls,0);
                fn_802073E8(owner,0x65,target,lbl_80378C20);
                }
            }
        }
    }
    if(fn_8025E9FC(owner,0xA0)&&!fn_8007D604(&self->controls,0x28)){
        fn_8007D6A0(&self->controls,0x28);
        self->f424=owner->value2C;
    }
}
