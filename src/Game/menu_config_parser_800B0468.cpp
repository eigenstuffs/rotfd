/* Menu configuration parser. Partial views contain only the observed fields.
 * Handle lifetimes use the existing native handle families; naturally emitted
 * weak destructors resolve to their accepted strong native providers.
 * The shared token prefix stays GLOBAL. The compiler owns the adjacent 255.0f,
 * FONT, _MASK and signed-conversion literals in their original order.
 */
typedef unsigned long Word;
struct Handle_801F7F10 {
    union{
        Word word;
        struct{
            signed int tag:8,index:24;
        } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
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
struct WorldList {
    int count,capacity;
    Handle_801F7F10*items;
    Handle_801F7F10&operator[](int i){
        return items[i];
    }
};
struct Globals {
    char unknown00[0x110];
    void*console;
    char unknown114[4];
    Manager*manager;
    WorldList*worlds;
    char unknown120[0x2C];
    void*fonts;
};
extern "C" {
    extern Globals lbl_801E9D24;
    extern char lbl_801EF5C8[];
    extern const char lbl_802A0250[];
    void fn_801EF610(void*,void*);
    void fn_801F86C8(Manager*,const void*,short);
    Word fn_801F7EB8(const Handle_801F7F10*);
    Word fn_801F948C(void*,const char*);
    void fn_801F372C(File*,char*);
    void fn_801F3238(File*,unsigned short*);
    void fn_801F2F54(File*,char*);
    void fn_801F34B0(File*,int*);
    signed char fn_801F2E04(File*);
    char fn_801F2F3C(File*);
    int strcmp(const char*,const char*);
    char*strcpy(char*,const char*);
    char*strcat(char*,const char*);
    void fn_801FA014(void*,const char*,...);
    extern const char lbl_803791F0[8],lbl_803791F8[8],lbl_80379200[7],lbl_80379208[7],lbl_8037919C[6],lbl_80379210[7],lbl_8037918C[5],lbl_803791D8[5];
}
struct Handle_8001FF78:Handle_801F7F10 {
    Handle_8001FF78(){
        word=0;
    }
    ~Handle_8001FF78(){
    }
    static void operator delete(void*p)throw(){
        fn_801EF610(lbl_801EF5C8,p);
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
struct BitmapZero:Handle_801F7F10 {
    BitmapZero(){
        word=0;
    }
    ~BitmapZero(){
    }
};
struct Handle_800723F4:BitmapZero {
    Handle_800723F4(){
        word=0;
    }
    ~Handle_800723F4(){
    }
    static void operator delete(void*p)throw(){
        fn_801EF610(lbl_801EF5C8,p);
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
    Name(const char*s){
        value=fn_801F948C(this,s);
    }
    Name(const Name&n):value(n.value){
    }
};
struct NameArgument{
    Word value;
    NameArgument(const Name&n):value(n.value){
    }
};
struct RGB {
    float r,g,b;
    void set(float a,float bb,float c){
        r=(float)a/255.0f;
        g=(float)bb/255.0f;
        b=(float)c/255.0f;
    }
};
struct RGBA {
    float r,g,b,a;
    RGBA(float aa,float bb,float cc,float dd):r(aa),g(bb),b(cc),a(dd){
    }
    RGBA&operator=(const RGBA&x){
        r=x.r;
        g=x.g;
        b=x.b;
        a=x.a;
        return *this;
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
    char unknown24[0x20];
    unsigned short count;
    char unknown46[2];
    unsigned char loop;
    char unknown49[3];
    StoredHandle object;
    unsigned char line;
    char unknown51[0x23];
    StoredHandle bitmap;
    char unknown78[4];
    unsigned char font;
    char unknown7D[3];
    RGB startColor,endColor,startSelect,endSelect;
    RGBA grey;
};
extern "C" {
    void fn_800B0CB0(Owner*,File*);
    void fn_800B0D48(Owner*,File*);
    unsigned char fn_80262AB4(void*,const NameArgument&);
    unsigned char fn_8026248C(void*,const NameArgument&,const NameArgument&);
    int fn_8026BC50(WorldList*,const Name&);
    Handle_80020B90 fn_8026A494(void*,const Name&);
    Handle_800723F4 fn_802631B0(void*,const Name&);
}
inline void*resolve(const Handle_801F7F10&h){
    int index=h.bits.index;
    Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[index].getTag();
    return tag==h.bits.tag?m->entries[index].object:0;
}
extern "C" {
    /* Shared menu/resource tokens retain their existing GLOBAL names and extents. */
    __declspec(section ".sdata2") extern const char lbl_80379178[] __attribute__((aligned(4))) = "CFSM";
    __declspec(section ".sdata2") extern const char lbl_80379180[] __attribute__((aligned(4))) = "/*";
    __declspec(section ".sdata2") extern const char lbl_80379184[] __attribute__((aligned(4))) = "*/";
    __declspec(section ".sdata2") extern const char lbl_80379188[] __attribute__((aligned(4))) = "//";
    __declspec(section ".sdata2") extern const char lbl_8037918C[] __attribute__((aligned(4))) = "ITEM";
    __declspec(section ".sdata2") extern const char lbl_80379194[] __attribute__((aligned(4))) = "{";
    __declspec(section ".sdata2") extern const char lbl_80379198[] __attribute__((aligned(4))) = "ID";
    __declspec(section ".sdata2") extern const char lbl_8037919C[] __attribute__((aligned(4))) = "WORLD";
    __declspec(section ".sdata2") extern const char lbl_803791A4[] __attribute__((aligned(4))) = "ICON";
    __declspec(section ".sdata2") extern const char lbl_803791AC[] __attribute__((aligned(4))) = "TEXT";
    __declspec(section ".sdata2") extern const char lbl_803791B4[] __attribute__((aligned(4))) = "%c";
    __declspec(section ".sdata2") extern const char lbl_803791B8[] __attribute__((aligned(4))) = "ITEM_L1";
    __declspec(section ".sdata2") extern const char lbl_803791C0[] __attribute__((aligned(4))) = "ITEM_R1";
    __declspec(section ".sdata2") extern const char lbl_803791C8[] __attribute__((aligned(4))) = " ";
    __declspec(section ".sdata2") extern const char lbl_803791CC[] __attribute__((aligned(4))) = "}";
    __declspec(section ".sdata2") extern const char lbl_803791D0[] __attribute__((aligned(4))) = "VISIBLE";
    __declspec(section ".sdata2") extern const char lbl_803791D8[] __attribute__((aligned(4))) = "TRUE";
    __declspec(section ".sdata2") extern const char lbl_803791E0[] __attribute__((aligned(4))) = "<PAGE>";
    __declspec(section ".sdata2") extern const char lbl_803791E8[] __attribute__((aligned(4))) = "<BLANK>";
    __declspec(section ".sdata2") extern const char lbl_803791F0[] __attribute__((aligned(4))) = "-------";
    __declspec(section ".sdata2") extern const char lbl_803791F8[] __attribute__((aligned(4))) = "NB_ELEM";
    __declspec(section ".sdata2") extern const char lbl_80379200[] __attribute__((aligned(4))) = "OBJECT";
    __declspec(section ".sdata2") extern const char lbl_80379208[] __attribute__((aligned(4))) = "BITMAP";
    __declspec(section ".sdata2") extern const char lbl_80379210[] __attribute__((aligned(4))) = "EFFECT";
}
extern "C" signed char fn_800B0468(Owner*self,const char*name){
    Word strings=(Word)lbl_802A0250;
    Handle_8001FF04 resource(lbl_801E9D24.manager->load(name));
    if(!fn_801F7EB8(&resource))return 0;
    File*file=&((Resource*)resolve(resource))->file;
    unsigned short count=0;
    char token[128],bitmap[128],object[128],world[128];
    fn_801F372C(file,token);
    bitmap[0]=0;
    strcpy(object,lbl_803791F0);
    strcpy(world,lbl_803791F0);
    while(!fn_801F2E04(file)){
        if(!strcmp(token,(const char*)(strings+0x68)))fn_800B0CB0(self,file);
        if(!strcmp(token,lbl_803791F8)){
            fn_801F3238(file,&count);
            self->count=count;
        }
        if(!strcmp(token,lbl_80379200))fn_801F2F54(file,object);
        if(!strcmp(token,lbl_80379208))fn_801F2F54(file,bitmap);
        if(!strcmp(token,lbl_8037919C))fn_801F2F54(file,world);
        if(!strcmp(token,(const char*)(strings+0x74))){
            int line;
            fn_801F34B0(file,&line);
            self->line=line;
        }
        strcmp(token,lbl_80379210);
        if(!strcmp(token,lbl_8037918C))fn_800B0D48(self,file);
        if(!strcmp(token,(const char*)(strings+0x80))){
            int r,g,b;
            fn_801F34B0(file,&r);
            fn_801F34B0(file,&g);
            fn_801F34B0(file,&b);
            self->startColor.set((float)r,(float)g,(float)b);
        }
        if(!strcmp(token,(const char*)(strings+0x8C))){
            int r,g,b;
            fn_801F34B0(file,&r);
            fn_801F34B0(file,&g);
            fn_801F34B0(file,&b);
            self->endColor.set((float)r,(float)g,(float)b);
        }
        if(!strcmp(token,(const char*)(strings+0x98))){
            int r,g,b;
            fn_801F34B0(file,&r);
            fn_801F34B0(file,&g);
            fn_801F34B0(file,&b);
            self->startSelect.set((float)r,(float)g,(float)b);
        }
        if(!strcmp(token,(const char*)(strings+0xAC))){
            int r,g,b;
            fn_801F34B0(file,&r);
            fn_801F34B0(file,&g);
            fn_801F34B0(file,&b);
            self->endSelect.set((float)r,(float)g,(float)b);
        }
        if(!strcmp(token,"FONT")){
            while(fn_801F2F3C(file)!='{'){
            }
            fn_801F372C(file,token);
            self->font=fn_80262AB4(lbl_801E9D24.fonts,Name(token));
            if(self->font==255){
                fn_801FA014(lbl_801E9D24.console,(const char*)(strings+0xC0),token);
                char mask[128];
                strcpy(mask,token);
                strcat(mask,"_MASK");
                self->font=fn_8026248C(lbl_801E9D24.fonts,Name(token),Name(mask));
            }
            while(fn_801F2F3C(file)!='}'){
            }
        }
        if(!strcmp(token,(const char*)(strings+0xD0))){
            fn_801F372C(file,token);
            if(!strcmp(token,lbl_803791D8))self->loop=1;
        }
        if(!strcmp(token,(const char*)(strings+0xDC))){
            int r,g,b,a;
            fn_801F34B0(file,&r);
            fn_801F34B0(file,&g);
            fn_801F34B0(file,&b);
            fn_801F34B0(file,&a);
            self->grey=RGBA((float)r/255.0f,(float)g/255.0f,(float)b/255.0f,(float)a/255.0f);
        }
        fn_801F372C(file,token);
    }
    Name worldName(world);
    int index=fn_8026BC50(lbl_801E9D24.worlds,worldName);
    if(index>=0){
        self->world=(*lbl_801E9D24.worlds)[index];
        void*worldObject=resolve(self->world);
        self->object=fn_8026A494(worldObject,Name(object));
    }
    if(bitmap[0])self->bitmap=fn_802631B0(lbl_801E9D24.fonts,Name(bitmap));
    self->select(0);
    return 1;
}
