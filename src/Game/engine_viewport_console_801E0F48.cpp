/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-viewport-console.md. */
typedef unsigned int u32;
struct Console_801E0F48 {
    char unknown000[0x860];
    int argc;
    char unknown864[4];
    char*arg868;
    char unknown86C[0x39];
    signed char valid8A5,valid8A6;
    char unknown8A7[17];
    float value8B8,index8BC;
};
struct Viewport_801E0F48 {
    char data[0x4c];
};
struct Viewports_801E0F48 {
    Viewport_801E0F48 records[7];
    signed char count;
    char unknown215[0x13];
    u32 mode;
};
struct Global_801E0F48 {
    char unknown000[0x110];
    Console_801E0F48*console;
    Viewports_801E0F48*viewports;
    void*manager;
};
extern "C" {
    extern Global_801E0F48 lbl_801E9D24;
    extern char lbl_802ACD70[],lbl_802ACD84[];
    void fn_801FA014(void*,const char*,...);
    u32 fn_801F948C(u32*,const char*);
    void fn_801E1AC4(Viewport_801E0F48*,u32*);
    void fn_801E81AC(void*);
}
extern "C" int fn_801E0F48() {
    Console_801E0F48*console=lbl_801E9D24.console;
    if(console->argc<2) {
        fn_801FA014(console,lbl_802ACD70);
        return 0;
    }
    int index=0;
    if(console->argc==3&&console->valid8A6)index=(int)console->index8BC;
    if(index<0||index>=lbl_801E9D24.viewports->count) {
        fn_801FA014(console,lbl_802ACD84,index);
        return 0;
    }
    u32 key;
    key=fn_801F948C(&key,console->arg868);
    u32 copy=key;
    fn_801E1AC4(&lbl_801E9D24.viewports->records[index],&copy);
    return 1;
}
