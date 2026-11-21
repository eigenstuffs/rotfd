/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void __ct__14Agent_80044118Fv(void*);
    extern char lbl_802C9024[];
}

struct Agent_800E75B0 {
    char unknown00[0x8];
    void* field08;
    Agent_800E75B0();
};

Agent_800E75B0::Agent_800E75B0() {
    __ct__14Agent_80044118Fv(this);
    field08 = lbl_802C9024;
}
