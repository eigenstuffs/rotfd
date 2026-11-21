/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C" {
    void __ct__18Breakable_802EC810Fv(void*);
    extern char lbl_802C8C80[];
}

struct Agent_800E3798 {
    char unknown00[0x8];
    void* field08;
    Agent_800E3798();
};

Agent_800E3798::Agent_800E3798() {
    __ct__18Breakable_802EC810Fv(this);
    field08 = lbl_802C8C80;
}
