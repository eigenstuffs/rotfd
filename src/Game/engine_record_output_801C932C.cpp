/* Original engine record and output routines.
 * See docs/notes/game-engine-record-output.md. */
typedef unsigned int u32;
struct File_801C932C {
    u32 words[23];
};
struct Globals_801C932C {
    char unknown[0x110];
    void*logger;
};
extern "C" {
    extern Globals_801C932C lbl_801E9D24;
    extern const char lbl_802ACC58[];
    void __ct__13File_801F3E1CFv(File_801C932C*);
    signed char fn_801F3918(File_801C932C*,const char*,int);
    void __dt__13File_801F3E1CFv(File_801C932C*,short);
    void fn_801FA014(void*,const char*,...);
    void fn_801F2BD4(File_801C932C*,const void*,int);
    void fn_801F2B58(File_801C932C*);
    void fn_801F2A98(File_801C932C*);
}
extern "C" void fn_801C932C(const char*name,const char*pixels,int width,int height,int bits) {
    File_801C932C file;
    __ct__13File_801F3E1CFv(&file);
    if(!fn_801F3918(&file,name,2)) {
        fn_801FA014(lbl_801E9D24.logger,lbl_802ACC58,name);
        __dt__13File_801F3E1CFv(&file,-1);
        return;
    }
    unsigned char header[18];
    header[0]=0;
    header[1]=0;
    header[2]=2;
    header[3]=0;
    header[4]=0;
    header[5]=0;
    header[6]=0;
    header[7]=0;
    header[8]=0;
    header[9]=0;
    header[10]=0;
    header[11]=0;
    header[12]=width;
    header[13]=width>>8;
    header[14]=height;
    header[15]=height>>8;
    header[16]=bits;
    header[17]=32;
    fn_801F2BD4(&file,header,18);
    int bytes=bits>>3;
    for(int i=0; i<height; ++i)fn_801F2BD4(&file,pixels+width*i*bytes,width*bytes);
    fn_801F2B58(&file);
    fn_801F2A98(&file);
    __dt__13File_801F3E1CFv(&file,-1);
}
