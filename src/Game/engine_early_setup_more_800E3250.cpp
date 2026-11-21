/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void __ct__23CallbackSingle_802ECA18Fv(void*);
    extern char lbl_802C8D50[];
}

struct Agent_800E3250 {
    char unknown00[0x8];
    void* field08;
    Agent_800E3250();
};

Agent_800E3250::Agent_800E3250() {
    __ct__23CallbackSingle_802ECA18Fv(this);
    field08 = lbl_802C8D50;
}
