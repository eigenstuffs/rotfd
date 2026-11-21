struct Point2 {
    float x, y;
    Point2(float a, float b) : x(a), y(b) {}
};
struct Color { float r, g, b, a; };
struct RendererStorage { char unknown000[0x218]; int width; char unknown21C[0x5C]; };
struct Renderer : RendererStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(); virtual void slot24(); virtual void slot28();
    virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40();
    virtual void slot44(); virtual void slot48(); virtual void slot4C();
    virtual void slot50(); virtual void slot54(); virtual void slot58();
    virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70();
    virtual void slot74(); virtual void slot78(); virtual void slot7C();
    virtual void slot80(); virtual void slot84(); virtual void slot88();
    virtual void slot8C();
    virtual void draw(const Point2&, const char*, const Color&);
};
struct UpdateNode {
    virtual void slot08();
    virtual void update(float);
};
struct Storage1C { char unknown[0x1C]; };
struct Node154 : Storage1C {
    virtual void slot08(); virtual void slot0C(); virtual void slot10();
    virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void update(float);
};
struct Storage7C { char unknown[0x7C]; };
struct Node158 : Storage7C {
    virtual void slot08(); virtual void slot0C(); virtual void slot10();
    virtual void slot14(); virtual void update(float);
};
struct StorageB10 { char unknown[0xB10]; };
struct Console : StorageB10 {
    virtual void slot08(); virtual void slot0C(); virtual void slot10();
    virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void slot20(); virtual void update(float);
};
struct Context {
    char unknown000[0x104];
    unsigned flags;
    char unknown108[8];
    Console* console;
    Renderer* renderer;
    char unknown118[0x0C];
    void* root;
    char unknown128[0x10];
    void* node138;
    void* node13C;
    char unknown140[8];
    void* node148;
    char unknown14C[8];
    Node154* node154;
    Node158* node158;
    char unknown15C[8];
    UpdateNode* node164;
    void* node168;
    UpdateNode* node16C;
};
extern "C" {
extern Context lbl_801E9D24;
extern char registry_No_Comment[];
extern float lbl_80377FF4, lbl_80377FFC, lbl_803780A4;
extern signed char lbl_80377FF8, lbl_80378000, lbl_80377FC8;
extern int lbl_80378010, lbl_80377FC4;
extern const float lbl_8037AA48, lbl_8037AA5C, lbl_8037AA60;
extern const float lbl_8037AA64, lbl_8037AA68, lbl_8037AA6C;
extern const float lbl_8037AA70, lbl_8037AA74;
extern const Color lbl_8033E738;
float fn_801F45D8();
float fn_801F463C(Context*);
void fn_802603E8(void*, float);
void fn_801FFBB0(void*, float);
void fn_8021291C(void*, float);
void fn_801B5D00(void*, float);
void fn_801E1430(Renderer*);
void fn_801EA730(float);
int sprintf(char*, const char*, ...);
}
extern "C" void fn_8020C248()
{
    const char* messages = registry_No_Comment;
    if (!lbl_80377FF8) {
        lbl_80377FF4 = lbl_803780A4;
        lbl_80377FF8 = 1;
    }
    if (!lbl_80378000) {
        lbl_80377FFC = lbl_803780A4;
        lbl_80378000 = 1;
    }
    lbl_80378010 = 0;
    lbl_80377FC4 = 0;
    lbl_80377FFC = fn_801F45D8() - lbl_80377FFC;
    Context* context = &lbl_801E9D24;
    context->renderer->slot18();
    lbl_801E9D24.node154->update(lbl_80377FF4);
    lbl_801E9D24.node164->update(lbl_80377FF4);
    fn_802603E8(lbl_801E9D24.root, lbl_80377FF4);
    if (!lbl_80377FC8) {
        fn_801FFBB0(lbl_801E9D24.node13C, lbl_80377FF4);
        fn_8021291C(lbl_801E9D24.node138, lbl_80377FF4);
        if (!lbl_80377FC8) {
            fn_801B5D00(lbl_801E9D24.node148, lbl_80377FF4);
            lbl_801E9D24.node158->update(lbl_80377FF4);
            fn_801E1430(context->renderer);
            lbl_801E9D24.node16C->update(lbl_80377FF4);
            fn_801EA730(lbl_80377FF4);
            lbl_80377FF4 = fn_801F463C(&lbl_801E9D24);
            lbl_801E9D24.console->update(lbl_80377FF4);
            float rate = lbl_8037AA48 / lbl_80377FF4;
            if (lbl_801E9D24.flags & 0x10) {
                char buffer[128];
                int width = context->renderer->width;
                sprintf(buffer, messages + 0x6EC, rate);
                float x = width - lbl_8037AA5C;
                context->renderer->draw(Point2(x, lbl_8037AA60), buffer, lbl_8033E738);
                sprintf(buffer, messages + 0x6F8, lbl_8037AA64 * lbl_80377FFC / lbl_803780A4);
                context->renderer->draw(Point2(x, lbl_8037AA68), buffer, lbl_8033E738);
                sprintf(buffer, messages + 0x708, lbl_80377FC4);
                context->renderer->draw(Point2(lbl_8037AA6C, lbl_8037AA70), buffer, lbl_8033E738);
                sprintf(buffer, messages + 0x714, lbl_80378010);
                context->renderer->draw(Point2(lbl_8037AA6C, lbl_8037AA74), buffer, lbl_8033E738);
            }
            context->renderer->slot1C();
            lbl_80377FFC = fn_801F45D8();
        }
    }
}
