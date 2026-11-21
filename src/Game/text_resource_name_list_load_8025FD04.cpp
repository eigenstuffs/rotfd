// fn_8025FD04: read a "{ name, name, ... }" list from a text resource
// (skipping /* */ and // comments) and insert each name key into a hash table.
typedef unsigned long u32;
typedef signed long s32;
struct File {
    u32 words[23];
    File();
    ~File();
};
struct Name {
    u32 word;
    Name(const char*text);
};
struct HashKey;
struct HashTable {
    char unknown0[8];
    s32 tag;
};
struct PointerKey {
    s32 tag;
    const void*vt;
    u32 value;
    PointerKey(const Name&name);
    ~PointerKey();
    PointerKey&operator=(const Name&name);
};
extern "C" {
    extern struct {
        char unknown0[0x118];
        void*manager;
    }
    lbl_801E9D24;
    extern const char lbl_8037B558[4];
    extern const char lbl_8037B55C[2];
    extern const char lbl_8037B560[3];
    extern const char lbl_8037B564[3];
    extern const char lbl_8037B568[3];
    extern const char lbl_8037B56C[2];
    extern const char lbl_8037B570[2];
    void __ct__13File_801F3E1CFv(File*);
    void __dt__13File_801F3E1CFv(File*,short);
    signed char fn_801B4FDC(void*,const void*,File*);
    signed char fn_801F372C(File*,char*);
    signed char fn_801F2E04(File*);
    signed char fn_801F2F3C(File*);
    u32 fn_801F948C(Name*,const char*);
    void fn_80208A90(PointerKey*,const Name*);
    void fn_80208A7C(PointerKey*,const Name*);
    PointerKey*fn_80208A28(PointerKey*,short);
    signed char fn_802083C8(HashTable*,PointerKey*,HashKey**,signed char);
    char*strstr(const char*,const char*);
    unsigned long strlen(const char*);
    char*strncpy(char*,const char*,unsigned long);
}
inline File::File(){
    __ct__13File_801F3E1CFv(this);
}
inline File::~File(){
    __dt__13File_801F3E1CFv(this,-1);
}
inline Name::Name(const char*text){
    word=fn_801F948C(this,text);
}
inline PointerKey::PointerKey(const Name&name){
    fn_80208A90(this,&name);
}
inline PointerKey::~PointerKey(){
    fn_80208A28(this,-1);
}
inline PointerKey&PointerKey::operator=(const Name&name){
    fn_80208A7C(this,&name);
    return *this;
}
extern "C" void fn_8025FD04(void*,const void*path,void*,HashTable*table){
    File file;
    if(!fn_801B4FDC(lbl_801E9D24.manager,path,&file))return;
    char token[128];
    PointerKey key((Name(lbl_8037B558)));
    HashKey*found;
    do{
        if(!fn_801F372C(&file,token))break;
    }while(!strstr(token,lbl_8037B55C));
    while(!fn_801F2E04(&file)){
        if(!fn_801F372C(&file,token))break;
        if(strstr(token,lbl_8037B560)){
            while(!fn_801F2E04(&file)){
                if(!fn_801F372C(&file,token))break;
                char*end=strstr(token,lbl_8037B564);
                if(end){
                    int length=strlen(end)-2;
                    strncpy(token,end+2,length);
                    token[length]=0;
                    break;
                }
            }
            if(!strlen(token))continue;
        }else if(strstr(token,lbl_8037B568)){
            while(fn_801F2F3C(&file)!='\n'){}
            continue;
        }
        if(strstr(token,lbl_8037B56C))break;
        if(strstr(token,lbl_8037B570))continue;
        int last=strlen(token)-1;
        while(token[last]==' '||token[last]=='\t'||token[last]==',')last--;
        token[(unsigned long)(last+1)]=0;
        key=Name(token);
        key.tag=table->tag;
        fn_802083C8(table,&key,&found,1);
    }
}
