typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;
struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];int generation()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown00[0x118];Manager*manager;};
struct Name;
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(Name*,const char*);
void fn_80229C30(Node*,const Name&);
void fn_80229BBC(Node*,const Name&);
extern const char lbl_80378814[8];
extern const char lbl_8037881C[8];
extern const char lbl_80378824[8];
extern const char lbl_8037882C[8];
extern const char lbl_80378834[8];
extern const char lbl_8037883C[8];
extern const char lbl_80378844[8];
extern const char lbl_8037884C[8];
extern const char lbl_80378854[8];
extern const char lbl_8037885C[8];
extern const char lbl_80378864[8];
extern const char lbl_8037886C[8];
extern const char lbl_80378874[8];
extern const char lbl_8037887C[8];
extern const char lbl_80378884[8];
extern const char lbl_8037888C[8];
extern const char lbl_80378894[8];
extern const char lbl_8037889C[8];}
struct Name{Word value;Name(const char*s){value=fn_801F948C(this,s);}};
struct ModeZero1_D8B8:Handle_801F7F10{ModeZero1_D8B8(){word=0;}~ModeZero1_D8B8(){}};
struct ModeZero2_D8B8:ModeZero1_D8B8{ModeZero2_D8B8(){word=0;}~ModeZero2_D8B8(){}};
struct Handle_80021B54:ModeZero2_D8B8{Handle_80021B54(){word=0;}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025BF4:Handle_80021B54{Handle_80025BF4(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80025BF4(const Handle_80025BF4&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ParentPrefix{char unknown00[0x1C];Handle_801F7F10 parent;};
struct Node:ParentPrefix{char unknown20[0x100];Word flags;};
struct Resource{char unknown00[0x58];Handle_801F7F10 related;char unknown5C[0x14];Handle_801F7F10 own;};
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].generation();if(generation==h.bits.tag)return(Word)m->entries[index].object;return 0;}
inline Node*resolve(const Handle_801F7F10&h){return(Node*)resolveWord(h);}
inline void addName(const Handle_801F7F10&h,const char*s){Node*n=resolve(h);fn_80229C30(n,Name(s));}
inline void removeName(const Handle_801F7F10&h,const char*s){Node*n=resolve(h);fn_80229BBC(n,Name(s));}
struct ParentEntry{ParentPrefix*object;char unknown04[8];signed char tag;char unknown0D[3];int generation()const{return tag;}};
struct ParentManager{int count,capacity;ParentEntry*entries;};
struct ParentHandle{union{Word word;
struct{signed int tag:8,index:24;}bits;};};
struct ParentResource{char unknown00[0x58];ParentHandle related;};
inline ParentPrefix*resolvePrefix(const ParentHandle&h){ParentManager*m=(ParentManager*)lbl_801E9D24.manager;int index=h.bits.index;int generation=m->entries[index].generation();if(generation==h.bits.tag)return m->entries[index].object;return 0;}
extern "C" void fn_8006D8B8(void*,Resource*resource,unsigned char mode,signed char remove){if(resolve(resolvePrefix(((ParentResource*)resource)->related)->parent)&& (resolve(resource->related)->flags&0x800)){const Handle_801F7F10&original=resource->own;Handle_80025BF4 selected((Handle_80025BF4(original)));if (!remove) {
        switch (mode) {

        case 0:break;
        case 1:addName(selected,lbl_80378814);
            addName(selected,lbl_8037881C);
            break;

        case 2:addName(selected,lbl_80378824);
            addName(selected,lbl_8037882C);
            break;

        case 3:addName(selected,lbl_80378834);
            addName(selected,lbl_8037883C);
            break;

        case 4:addName(selected,lbl_80378844);
            addName(selected,lbl_8037884C);
            break;

        case 5:addName(selected,lbl_80378854);
            addName(selected,lbl_8037885C);
            break;

        case 6:addName(selected,lbl_80378864);
            addName(selected,lbl_8037886C);
            break;

        case 7:addName(selected,lbl_80378874);
            addName(selected,lbl_8037887C);
            break;

        case 8:addName(selected,lbl_80378884);
            addName(selected,lbl_8037888C);
            break;

        case 9:addName(selected,lbl_80378894);
            addName(selected,lbl_8037889C);
            break;

        default:break;}
    } else {
        switch (mode) {

        case 0:break;
        case 1:removeName(selected,lbl_80378814);
            removeName(selected,lbl_8037881C);
            break;

        case 2:removeName(selected,lbl_80378824);
            removeName(selected,lbl_8037882C);
            break;

        case 3:removeName(selected,lbl_80378834);
            removeName(selected,lbl_8037883C);
            break;

        case 4:removeName(selected,lbl_80378844);
            removeName(selected,lbl_8037884C);
            break;

        case 5:removeName(selected,lbl_80378854);
            removeName(selected,lbl_8037885C);
            break;

        case 6:removeName(selected,lbl_80378864);
            removeName(selected,lbl_8037886C);
            break;

        case 7:removeName(selected,lbl_80378874);
            removeName(selected,lbl_8037887C);
            break;

        case 8:removeName(selected,lbl_80378884);
            removeName(selected,lbl_8037888C);
            break;

        case 9:removeName(selected,lbl_80378894);
            removeName(selected,lbl_8037889C);
            break;

        default:break;}
    }
}
}

