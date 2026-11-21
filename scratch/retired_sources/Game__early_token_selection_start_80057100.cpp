/* Token selection start and native Handle cleanup; verified private layout views.
 * See docs/notes/game-early-token-selection-start.md. */
struct Handle_801F7F10 {
    union { unsigned long word; struct { signed long tag:8,index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" { extern char lbl_801EF5C8[]; void fn_801EF610(void*,void*); }
struct TokenHandleLayer:Handle_801F7F10 {
    TokenHandleLayer() { word=0; }
    ~TokenHandleLayer() {}
};
struct Handle_80020B90:TokenHandleLayer {
    Handle_80020B90() { word=0; }
    ~Handle_80020B90() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8,p); }
};
struct TokenStartPrefix { char unknown00[0x7C]; };
struct TokenStartManager:TokenStartPrefix {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15();
    virtual void play(const char*,int,const Handle_80020B90&,const Handle_80020B90&);
    virtual void stop(const char*);
    virtual signed char active(const char*);
};
struct TokenStartActor {
    char unknown00[0xF0]; int mode; char unknownF4[0xC];
    int fallback; char unknown104[4]; int selection;
    char unknown10C[0x1EA]; unsigned char enabled;
};
struct TokenStartContext {
    char unknown00[0x110]; void* diagnostics;
    char unknown114[0x44]; TokenStartManager* manager;
};
extern "C" {
    extern TokenStartContext lbl_801E9D24;
    extern const char lbl_8029ACA8[][20],lbl_8029B22C[];
    void fn_80057294(TokenStartActor*);
    signed char fn_8005B0F0(TokenStartActor*);
    void fn_801FA014(void*,const char*,...);
}
extern "C" void fn_80057100(TokenStartActor* self,int requested)
{
    self->enabled=1;
    int selected=-1;
    int mode=0;
    if(self->selection!=-1 && !lbl_801E9D24.manager->active(lbl_8029ACA8[self->selection]))
        self->selection=-1;
    if(requested>-1) {
        fn_80057294(self);
        selected=requested;
    } else if(self->selection==-1) {
        selected=self->fallback;
        if(self->mode==2)selected=6;
        else if(self->mode==5)selected=7;
        if(fn_8005B0F0(self))selected=12;
        mode=2;
    }
    if(selected>-1) {
        const char* name;
        fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029B22C,name=lbl_8029ACA8[selected]);
        self->selection=selected;
        Handle_80020B90 first;
        Handle_80020B90 second;
        lbl_801E9D24.manager->play(name,mode,first,second);
    }
}
