// Actor completion reset: clears the actor flag, resets its float slot,
// restores the controller and scene mode, and notifies the monitor.
struct CompletionResetActorPrefix { char unknown00[8]; };
struct CompletionResetActor : CompletionResetActorPrefix {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26();
    virtual void slot29(int, float);
    char unknown0C[0x314];
    int record320;
    char unknown324[0xE7];
    bool enabled40B;
};
struct CompletionResetController { char unknown00[0x84]; int mode; };
struct CompletionResetOwner {
    char unknown00[8];
    CompletionResetActor* actor;
    CompletionResetController* controller;
};
struct CompletionResetSceneMode;
struct CompletionResetScene { char unknown00[0x15058]; CompletionResetSceneMode* mode; };
struct CompletionResetSystem { char unknown00[0x2D]; bool active; };
struct CompletionResetContext {
    char unknown00[0x124];
    CompletionResetScene* scene;
    char unknown128[0x3C];
    CompletionResetSystem* system;
};
struct CompletionResetInput { char unknown00[0x1DC]; bool active; };
struct CompletionResetMonitor { char unknown00[0x130]; void* first; void* second; };
extern "C" {
extern CompletionResetContext lbl_801E9D24;
extern CompletionResetMonitor* lbl_803776B8;
extern const float lbl_80378AD0;
extern const int lbl_80378598;
void fn_80068158(CompletionResetMonitor*, int);
CompletionResetInput* fn_8007D074();
void fn_80056434(CompletionResetSceneMode*, int);
}

extern "C" void fn_80089150(CompletionResetOwner* self) {
    self->actor->enabled40B = false;
    self->actor->slot29(0, lbl_80378AD0);
    self->controller->mode = lbl_80378598;
    fn_80056434(lbl_801E9D24.scene->mode, lbl_80378598);
    lbl_801E9D24.system->active = true;
    CompletionResetInput* input = fn_8007D074();
    input->active = false;
    if (lbl_803776B8 && lbl_803776B8->second)
        fn_80068158(lbl_803776B8, self->actor->record320);
}
