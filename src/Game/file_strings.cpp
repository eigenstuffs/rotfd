/* Game string compatibility helpers, reconstructed from GSQE78. */
struct GameVarArgs {
    unsigned char gpr;
    unsigned char fpr;
    unsigned char reserved0;
    unsigned char reserved1;
    void *stack;
    void *saved;
};
extern "C" int vsprintf(char*,const char*,GameVarArgs*);
extern "C" {
int fn_801F44DC(char *dst,const char *format,void *arguments)
{
    GameVarArgs args;
    args.gpr=0;args.fpr=0;args.reserved0=0;args.reserved1=0;
    args.stack=arguments;args.saved=arguments;
    vsprintf(dst,format,&args);
    return 0;
}
int fn_801F4520(const char *a,const char *b)
{
    for(;;){
        if(!*a)return *b!=0;
        if(!*b)return 1;
        char difference=*b-*a;
        if(difference>0){if(difference-32)return 1;}
        else if(difference<0){if(difference+32)return 1;}
        ++a;++b;
    }
}
char *fn_801F459C(char *text)
{
    char *p=text;
    while(*p){
        if(*p>='a' && *p<='z')*p=*(unsigned char*)p-32;
        ++p;
    }
    return text;
}
}
