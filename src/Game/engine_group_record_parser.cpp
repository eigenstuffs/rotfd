#pragma readonly_strings on
#include "Game/engine_group_record_parser.h"

extern "C" void fn_8021A340(void* self, void* stream) {
    GroupRecord_FQ record;
    char token[128];
    unsigned char flags = 0;
    fn_801F372C(stream, token);
    while (strcmp(token, lbl_8037AF20))
        fn_801F372C(stream, token);
    while (strcmp(token, lbl_8037AF64)) {
        if (!strcmp(token, lbl_8037AF24)) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.next = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (!strcmp(token, lbl_8037AF2C)) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.previous = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (!strcmp(token, lbl_8037AF34)) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.keyword = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (!strcmp(token, lbl_8037AF3C)) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 1;
        }
        if (!strcmp(token, lbl_8037AF4C)) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 2;
        }
        if (!strcmp(token, lbl_8037AF54)) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 4;
        }
        if (!strcmp(token, lbl_8037AF5C)) {
            fn_801F2F54(stream, token);
            record.handle90 = GroupWrappedHandle_FQ(
                fn_80263308(lbl_801E9D24.resources, &GroupName_FQ(token)));
        }
        if (!strcmp(token, "FOREVERACCESS")) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 0x100;
        }
        fn_801F372C(stream, token);
    }
    record.flags = flags;
    fn_8021AFE0(self, &record);
}

/* Menu file loader fn_8021A7AC: reads ITEM/OBJECT/WORLD/MENU_LOOP tokens, binds
 * the world, object and font handles, then calls the owner virtual select. Its
 * MENU_LOOP literal follows the parser's string pool; the short tokens stay
 * extern .sdata2 labels. The loader's local views are kept in their own
 * namespace so they do not collide with the parser's declarations. */
namespace menu_file_loader {
typedef unsigned long Word;
struct File {
    char opaque[4];
};
struct Resource {
    char unknown00[0xC];
    File file;
};
struct Entry {
    void*object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag()const{
        return tag;
    }
};
struct ManagerPrefix {
    int count,capacity;
    Entry*entries;
    char unknown0C[0x18];
};
struct Manager:ManagerPrefix {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual Handle_801F7F10 load(const char*);
};
struct Globals {
    char unknown00[0x118];
    Manager*manager;
    char unknown11C[0x30];
    void*fonts;
};
extern "C" {
    extern Globals lbl_801E9D24;
    void fn_801F86C8(Manager*,const void*,short);
    Word fn_801F7EB8(const Handle_801F7F10*);
    Word fn_801F948C(void*,const char*);
    void fn_801F372C(File*,char*);
    void fn_801F2F54(File*,char*);
    signed char fn_801F2E04(File*);
    int strcmp(const char*,const char*);
    char*strcpy(char*,const char*);
    extern const char lbl_8037AF68[8],lbl_8037AF70[5],lbl_8037AF78[7],lbl_8037AF80[6],lbl_8037AF88[6],lbl_8037AF44[5];
}
struct Handle_8001FF78:Handle_801F7F10 {
    Handle_8001FF78(){
        word=0;
    }
    ~Handle_8001FF78(){
    }
};
struct Handle_8001FF04:Handle_8001FF78 {
    Handle_8001FF04(const Handle_801F7F10&h){
        word=h.word;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
    ~Handle_8001FF04(){
    }
};
struct Handle_80020B90:Handle_8001FF78 {
    ~Handle_80020B90(){
    }
};
struct StoredHandle:Handle_801F7F10 {
    StoredHandle&operator=(const Handle_801F7F10&h){
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        word=h.word;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
        return*this;
    }
};
struct Name {
    Word value;
    Name(){
        value=0;
    }
    Name(const char*s){
        value=fn_801F948C(this,s);
    }
};
struct NameType {
    Word value;
    NameType(const Name&n):value(n.value){
    }
};
struct OwnerPrefix {
    char unknown00[8];
};
struct Owner:OwnerPrefix {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void select(int);
    char unknown0C[0x14];
    StoredHandle world;
    char unknown24[0x24];
    unsigned char loop;
    char unknown49[0xF];
    StoredHandle object;
    StoredHandle bitmap;
};
extern "C" {
    void fn_8021A340(Owner*,File*);
    Handle_801F7F10 fn_801B5054(Manager*,const Name&,NameType);
    Handle_80020B90 fn_8026A494(void*,const Name&);
    Handle_80020B90 fn_80263308(void*,const Name&);
}
inline void*resolve(const Handle_801F7F10&h){
    int index=h.bits.index;
    Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[index].getTag();
    return tag==h.bits.tag?m->entries[index].object:0;
}
extern "C" signed char fn_8021A7AC(Owner*self,const char*name,int selection){
    Handle_8001FF04 resource(lbl_801E9D24.manager->load(name));
    if(!fn_801F7EB8(&resource))return 0;
    File*file=&((Resource*)resolve(resource))->file;
    char token[128],object[128],world[128];
    strcpy(object,lbl_8037AF68);
    strcpy(world,lbl_8037AF68);
    fn_801F372C(file,token);
    while(!fn_801F2E04(file)){
        if(!strcmp(token,lbl_8037AF70))fn_8021A340(self,file);
        if(!strcmp(token,lbl_8037AF78))fn_801F2F54(file,object);
        if(!strcmp(token,lbl_8037AF80))fn_801F2F54(file,world);
        if(!strcmp(token,"MENU_LOOP")){
            fn_801F372C(file,token);
            if(!strcmp(token,lbl_8037AF44))self->loop=1;
        }
        fn_801F372C(file,token);
    }
    self->world=Handle_8001FF04(fn_801B5054(lbl_801E9D24.manager,Name(world),NameType(Name())));
    if(fn_801F7EB8(&self->world)){
        void*worldObject;
        int index=self->world.bits.index;
        Manager*m=lbl_801E9D24.manager;
        int tag=m->entries[index].getTag();
        if(tag==self->world.bits.tag)worldObject=m->entries[index].object;
        else worldObject=0;
        self->object=fn_8026A494(worldObject,Name(object));
    }
    self->select(selection);
    self->bitmap=Handle_8001FF04(fn_80263308(lbl_801E9D24.fonts,Name(lbl_8037AF88)));
    return 1;
}
} // namespace menu_file_loader
