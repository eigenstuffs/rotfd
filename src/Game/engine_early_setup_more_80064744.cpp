extern "C" {
    void __ct__21CallbackPair_802EC798Fv(void*);
    extern char lbl_802B6774[];
}

struct Agent_80064744 {
    char unknown00[0x8];
    void* field08;
    Agent_80064744();
};

Agent_80064744::Agent_80064744() {
    __ct__21CallbackPair_802EC798Fv(this);
    field08 = lbl_802B6774;
}
