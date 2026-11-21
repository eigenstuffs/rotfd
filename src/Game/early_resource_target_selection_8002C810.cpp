/* Select two named resource targets and forward scene selection state.
 * Observed field views only; original strings, globals and tables remain external.
 * See docs/notes/game-early-resource-target-selection.md. */
typedef unsigned long Word;
struct Handle_C810{union{Word word;struct{signed int tag:8,index:24;}bits;};};
extern "C"Word fn_801F948C(void*,const char*);
struct Name_C810{Word word;Name_C810(const char*s){word=fn_801F948C(this,s);}Name_C810(const Name_C810&n){word=n.word;}};
struct NameHolder_C810{Name_C810 name;NameHolder_C810(const Name_C810&n):name(n){}};
struct Node_C810{Name_C810 name;char unknown04[0x38C];signed char selected;char unknown391[0x33];Node_C810*target;};
struct Resource_C810{char unknown00[0x38];unsigned long long flags;char unknown40[0x18];Handle_C810 related;char unknown5C[0x14];Handle_C810 own;signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct Entry_C810{Node_C810*object;char unknown04[8];signed char tag;char unknown0D[3];};struct Manager_C810{int count,capacity;Entry_C810*entries;};struct Globals_C810{char unknown00[0x114];char*lists;Manager_C810*manager;};
struct Current_C810{char unknown00[0x20];int index;char unknown24[0x204];int active;};
struct ActorSystem_C810{char unknown00[0x1AC];Handle_C810 query;char unknown1B0[0x168];char controller[0x128];Node_C810*target;Word state;};
extern "C"{extern Globals_C810 lbl_801E9D24;extern Resource_C810*lbl_803775C8,*lbl_803775CC;extern const char lbl_80378344[8],lbl_8037834C[8],lbl_8029A000[];Resource_C810*fn_80020500(const Name_C810&);Current_C810*fn_8007D074();ActorSystem_C810*fn_8005E90C();void*fn_8005E9A0();void*fn_8005EE10(Resource_C810*);void fn_8006954C(void*,int,short);void*fn_801F7EB8(const Handle_C810*);void fn_80257828(void*,Word,Word,int);void fn_8007D6A0(void*,int);void fn_8002C31C();}
inline Node_C810*resolve(const Handle_C810&h){Entry_C810*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline const Handle_C810&currentHandle(){int index=fn_8007D074()->index;return *(const Handle_C810*)(lbl_801E9D24.lists+index*0x4C+0x14);}
extern "C"void fn_8002C810(const Name_C810&first,Word firstSelection,const Name_C810&second,Word secondSelection){
NameHolder_C810 h(second);Name_C810&other=h.name;
if(first.word==other.word)other=Name_C810(lbl_80378344);
if(first.word==Name_C810(lbl_80378344).word)lbl_803775C8=(Resource_C810*)-1;
else if(first.word!=Name_C810(lbl_8037834C).word)lbl_803775C8=fn_80020500(Name_C810(first));
else if(!lbl_803775C8)lbl_803775C8=(Resource_C810*)-1;
if(other.word==Name_C810(lbl_80378344).word)lbl_803775CC=(Resource_C810*)-1;
else if(other.word!=Name_C810(lbl_8037834C).word)lbl_803775CC=fn_80020500(Name_C810(other));
else if(!lbl_803775CC)lbl_803775CC=(Resource_C810*)-1;
if(lbl_803775C8!=(Resource_C810*)-1){
Node_C810*target;
if(lbl_803775CC!=(Resource_C810*)-1)target=resolve(lbl_803775CC->related);else target=resolve(currentHandle());
if(lbl_803775C8->hasFlags(0x10000000ULL)){
Node_C810*source=resolve(lbl_803775C8->own);source->target=target;
if(target&&target->name.word==Name_C810(lbl_8029A000).word)source->selected=1;else source->selected=0;
fn_8006954C(fn_8005EE10(lbl_803775C8),0xE,(short)firstSelection);
}else{
if(fn_801F7EB8(&fn_8005E90C()->query))fn_80257828(fn_8005E9A0(),0xB9,0x8D,0);else fn_80257828(fn_8005E9A0(),firstSelection,0x8D,0);
ActorSystem_C810*s=fn_8005E90C();s->target=target;s->state=0x31;fn_8007D6A0(fn_8005E90C()->controller,0x33);
}}
if(lbl_803775CC!=(Resource_C810*)-1){
Node_C810*target;
if(lbl_803775C8!=(Resource_C810*)-1)target=resolve(lbl_803775C8->related);else target=resolve(currentHandle());
if(lbl_803775CC->hasFlags(0x10000000ULL)){
Node_C810*source=resolve(lbl_803775CC->own);source->target=target;
if(target&&target->name.word==Name_C810(lbl_8029A000).word)source->selected=1;else source->selected=0;
fn_8006954C(fn_8005EE10(lbl_803775CC),0x11,(short)secondSelection);
}else{
if(fn_801F7EB8(&fn_8005E90C()->query))fn_80257828(fn_8005E9A0(),0x7B,0x8D,0);else fn_80257828(fn_8005E9A0(),secondSelection,0x8D,0);
ActorSystem_C810*s=fn_8005E90C();s->target=target;s->state=0x32;fn_8007D6A0(fn_8005E90C()->controller,0x33);
}}
if(!fn_8007D074()->active)fn_8002C31C();
}
